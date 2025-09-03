import math

def is_prime(n):
    """
    检查一个数是否为素数。
    """
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def get_distinct_prime_factors(n):
    """
    获取一个数的所有不同的素因子。
    """
    factors = set()
    # 先处理因子2
    while n % 2 == 0:
        factors.add(2)
        n //= 2
    # 再处理从3开始的奇数因子
    i = 3
    while i <= int(math.sqrt(n)):
        if n % i == 0:
            factors.add(i)
            n //= i
        else:
            i += 2
    # 如果n本身在除法后成为一个大于2的素数
    if n > 2:
        factors.add(n)
    return list(factors)

def find_all_primitive_roots(p):
    """
    寻找素数p的所有原根。
    """
    print(f"开始寻找素数 {p} 的所有原根...")

    # 步骤 1: 验证 p 是否为素数
    if not is_prime(p):
        print(f"{p} 不是一个素数，不存在原根。")
        return []

    # 步骤 2: 计算 phi(p)
    phi = p - 1
    print(f"φ({p}) = {p} - 1 = {phi}")

    # 步骤 3: 找到 phi 的所有不同素因子
    prime_factors_of_phi = get_distinct_prime_factors(phi)
    print(f"{phi} 的所有不同素因子是: {prime_factors_of_phi}")
    print("-" * 30)

    primitive_roots = []
    
    # 步骤 4: 遍历所有可能的 g (从 2 到 p-1)
    for g in range(2, p):
        is_primitive_root = True
        # 步骤 5: 对每个g进行原根检验
        for q in prime_factors_of_phi:
            # pow(g, exp, mod) 是计算 (g^exp) % mod 的高效方法
            if pow(g, phi // q, p) == 1:
                is_primitive_root = False
                break # 如果有一个不满足，则g不是原根，跳出内层循环
        
        if is_primitive_root:
            if not primitive_roots: # 找到第一个原根时立即打印
                 print(f"找到了第一个原根: {g}")
            primitive_roots.append(g)
            
    return primitive_roots

# --- 主程序 ---
p = 3329
all_roots = find_all_primitive_roots(p)

if all_roots:
    print("-" * 30)
    print(f"计算完成！")
    print(f"素数 {p} 共有 {len(all_roots)} 个原根。")
    print("它们是:")
    # 为了方便查看，以列表形式打印所有原根
    print(all_roots)