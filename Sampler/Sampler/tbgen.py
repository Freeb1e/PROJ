import random
from pathlib import Path

# --- 模块的常量定义 ---
Q = 3329

# --- 核心采样逻辑的Python实现 ---

def hamming_weight(n, bits=3):
    """计算一个整数n在指定位宽下的汉明权重（'1'的个数）"""
    count = 0
    for i in range(bits):
        if (n >> i) & 1:
            count += 1
    return count

def binomial_sample(chunk_6bit):
    """
    模拟单个二项采样过程。
    输入一个6-bit整数，返回一个3-bit的（符号位+真值）结果。
    """
    # 分离高3位和低3位
    high_3bit = (chunk_6bit >> 3) & 0b111
    low_3bit = chunk_6bit & 0b111

    # 计算汉明权重
    hw_h = hamming_weight(high_3bit)
    hw_l = hamming_weight(low_3bit)

    # 计算差值
    diff = hw_h - hw_l
    
    # 转换为3-bit符号位+真值格式
    sign = 1 if diff < 0 else 0
    magnitude = abs(diff)
    
    # {sign[1], magnitude[1:0]}
    return (sign << 2) | magnitude

def rejection_sample(chunk_12bit):
    """
    模拟单个拒绝采样过程。
    输入一个12-bit整数，返回一个元组 (采样结果, 是否成功)。
    """
    if chunk_12bit < Q:
        # 成功: 返回原始数值和True
        return (chunk_12bit, True)
    else:
        # 失败: 返回全0和False
        return (0, False)

def simulate_sampler(random_96bit, verbose=True):
    """对一个给定的96-bit随机数，模拟两种模式并返回结果。

    Returns:
        mode0_outputs: 长度8列表，每项是一个6-bit输出 (0..63)
        mode1_outputs: 长度4列表，每项是一个24-bit输出 (0..2^24-1)
        rej_cnt: mode1 成功次数
        fail_flags: 4bit (bit[i]=1 表示该cycle有失败)
    """
    mode0_outputs = []
    if verbose:
        print(f"Input Random (96-bit): 0x{random_96bit:024x}")
        print("-" * 50)
        print(">>> Simulating Mode 0: Binomial Sampling")
    for i in range(8):
        slice_12bit = (random_96bit >> (i * 12)) & 0xFFF
        chunk1_6bit = slice_12bit & 0x3F
        chunk2_6bit = (slice_12bit >> 6) & 0x3F
        coeff1 = binomial_sample(chunk1_6bit)
        coeff2 = binomial_sample(chunk2_6bit)
        bin_sampling_output = (coeff2 << 3) | coeff1  # 6-bit
        mode0_outputs.append(bin_sampling_output)
        if verbose:
            print(f"  Cycle {i+1:2d}: Input Slice[{i*12+11:3d}:{i*12:3d}] = 0x{slice_12bit:03x}")
            print(f"    - Coeffs: [{coeff2:03b}, {coeff1:03b}]  =>  bin_sampling: 0b{bin_sampling_output:06b}")
    mode1_outputs = []
    rej_cnt = 0
    fail_flags = 0
    if verbose:
        print("-" * 50)
        print(">>> Simulating Mode 1: Rejection Sampling")
    for i in range(4):
        slice_24bit = (random_96bit >> (i * 24)) & 0xFFFFFF
        chunk1_12bit = slice_24bit & 0xFFF
        chunk2_12bit = (slice_24bit >> 12) & 0xFFF
        result1, success1 = rejection_sample(chunk1_12bit)
        result2, success2 = rejection_sample(chunk2_12bit)
        rej_sampling_output = (result2 << 12) | result1  # 24-bit
        if success1:
            rej_cnt += 1
        if success2:
            rej_cnt += 1
        if not (success1 and success2):
            fail_flags |= (1 << i)
        mode1_outputs.append(rej_sampling_output)
        if verbose:
            print(f"  Cycle {i+1:2d}: Input Slice[{i*24+23:3d}:{i*24:3d}] = 0x{slice_24bit:06x}")
            print(f"    - Results: [{result2:4d}, {result1:4d}], Success: [{str(success2):>5}, {str(success1):>5}]")
            print(f"    - rej_sampling: 0x{rej_sampling_output:06x}, rej_fail: {int(not (success1 and success2))}")
    if verbose:
        print(f"\n  Final Result: rej_cnt = {rej_cnt} (0x{rej_cnt:x})")
        print("-" * 50)
    return mode0_outputs, mode1_outputs, rej_cnt, fail_flags


if __name__ == "__main__":
    # --- 主程序 ---
    
    # 设置要生成的测试向量数量
    NUM_TEST_VECTORS = 1000
    
    print("=" * 60)
    print("      Python Golden Model for Verilog Sampler")
    print("=" * 60)
    
    # 输出文件路径
    file_inputs = Path("a.txt")
    file_outputs = Path("b.txt")
    # 清空/创建
    file_inputs.write_text("")
    file_outputs.write_text("")

    for i in range(NUM_TEST_VECTORS):
        print(f"\n=============== TEST VECTOR {i+1} ===============\n")
        test_random_num = random.getrandbits(96)

        # 运行仿真（详细打印）
        mode0_outs, mode1_outs, rej_cnt, fail_flags = simulate_sampler(test_random_num, verbose=True)

        # 保存输入到 a.txt: 高 中 低 32 位 (8 hex each, 不带0x)
        word_high = (test_random_num >> 64) & 0xFFFFFFFF
        word_mid  = (test_random_num >> 32) & 0xFFFFFFFF
        word_low  =  test_random_num        & 0xFFFFFFFF
        with file_inputs.open('a', encoding='utf-8') as fa:
            fa.write(f"0 {word_high:08x} {word_mid:08x} {word_low:08x}\n")
            fa.write(f"1 {word_high:08x} {word_mid:08x} {word_low:08x}\n")
        # 期望结果写入 b.txt
        # 约定：每个输入对应两行
        # 行1 (mode0): m0 后跟 8 个 6-bit 输出 (2 hex) 低位cycle先写还是先后? 采用从 cycle0 到 cycle7 顺序
        # 行2 (mode1): m1 后跟 4 个 24-bit 输出 (6 hex) cycle0->cycle3, 然后 rej_cnt (2 hex) fail_flags (1 hex, bit i = cycle i fail)
        with file_outputs.open('a', encoding='utf-8') as fb:
            fb.write(" ".join(f"{v:02x}" for v in mode0_outs) + "\n")
            fb.write(" ".join(f"{v:06x}" for v in mode1_outs) + f" {rej_cnt:02x} {fail_flags:01x}\n")

        # 终端提示 C 数组格式
        print(f"C array init format: {{{word_high:#010x},{word_mid:#010x},{word_low:#010x}}}\n")
        
    print("\n=============== SCRIPT FINISHED ===============\n")