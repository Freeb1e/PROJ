import random

# ----------------- 常量 -----------------
MOD = 3329
ORIGN = [1, 749, 1729, 40, 3328, 2580, 1600, 3289]  # 长度必须为 8
COUNT = 8  # 系数与点数 (固定 8)

# ----------------- 可配置参数 -----------------
NUM = 10000     # 生成数量
SEED = 12345    # 例如 12345
APPEND = False  # True 表示追加

"""核心辅助函数"""

def pack_values(vals):
    # 将 8 个(<4096)值打包成 96 位: vals[0] 低 12bit
    if len(vals) != COUNT:
        raise ValueError("需要 8 个值")
    p = 0
    for i, v in enumerate(vals):
        if not (0 <= v < 4096):
            raise ValueError(f"值 {v} 超出 12-bit 范围")
        p |= (v & 0xFFF) << (12 * i)
    return p

def split_u96_to_3x32(x):
    return (x >> 64) & 0xFFFFFFFF, (x >> 32) & 0xFFFFFFFF, x & 0xFFFFFFFF

def format_3x32(x):
    hi, mid, lo = split_u96_to_3x32(x)
    return f"0x{lo:08X} 0x{mid:08X} 0x{hi:08X}"

# ----------------- 核心计算 -----------------
def compute_outputs(coeffs):
    outputs = []
    for i in range(8):
        res = 0
        for j in range(8):
            res += coeffs[j] * pow(ORIGN[i], j, MOD)       
        outputs.append(res % MOD)
    for v in outputs:
        print(v, end=' ')
    return outputs

# ----------------- 随机生成 -----------------
def gen_coeffs(rng):
     return [rng.randrange(MOD) for _ in range(COUNT)]
    #return 1,2,3,4,5,6,7,8  # 测试固定值

# ----------------- 主流程 -----------------
def generate():
    rng = random.Random(SEED)
    mode = 'a' if APPEND else 'w'
    a_path = 'a.txt'
    b_path = 'b.txt'
    with open(a_path, mode, encoding='utf-8') as fa, open(b_path, mode, encoding='utf-8') as fb:
        for idx in range(1, NUM + 1):
            coeffs = gen_coeffs(rng)
            outputs = compute_outputs(coeffs)
            fa.write(format_3x32(pack_values(coeffs)) + '\n')
            fb.write(format_3x32(pack_values(outputs)) + '\n')
            if NUM <= 20 or idx % max(1, NUM // 10) == 0 or idx == NUM:
                print(f"进度 {idx}/{NUM} ({idx/NUM:.0%})")
    print(f"完成: {NUM} 条测试 -> {a_path} / {b_path}")
    if SEED is not None:
        print(f"随机种子: {SEED}")


if __name__ == '__main__':
    generate()