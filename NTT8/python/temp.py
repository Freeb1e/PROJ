def modmul(a, b, mod):
    return (a * b) % mod
def modadd(a, b, mod):
    return (a + b) % mod
def modsub(a, b, mod):
    return (a - b) % mod


coe = []
butterfly1 = [0]*8
butterfly2 = [0]*8
coe = list(map(int, input("请输入8个系数，用空格分隔: ").split()))
butterfly1 = coe[:]

butterfly2[0] = modadd(butterfly1[0],modmul(butterfly1[4],pow(749,0,3329),3329), 3329)
butterfly2[1] = modsub(butterfly1[0],modmul(butterfly1[4],pow(749,0,3329),3329), 3329)
butterfly2[2] = modadd(butterfly1[2],modmul(butterfly1[6],pow(749,0,3329),3329), 3329)
butterfly2[3] = modsub(butterfly1[2],modmul(butterfly1[6],pow(749,0,3329),3329), 3329)
butterfly2[4] = modadd(butterfly1[1],modmul(butterfly1[5],pow(749,0,3329),3329), 3329)
butterfly2[5] = modsub(butterfly1[1],modmul(butterfly1[5],pow(749,0,3329),3329), 3329)
butterfly2[6] = modadd(butterfly1[3],modmul(butterfly1[7],pow(749,0,3329),3329), 3329)
butterfly2[7] = modsub(butterfly1[3],modmul(butterfly1[7],pow(749,0,3329),3329), 3329)

print("\nframe1变换结果为:")
for i in range(8):
    print(butterfly2[i], end=' ')

butterfly1[0] = modadd(butterfly2[0],modmul(butterfly2[2],pow(749,0,3329),3329), 3329)
butterfly1[1] = modadd(butterfly2[1],modmul(butterfly2[3],pow(749,2,3329),3329), 3329)
butterfly1[2] = modsub(butterfly2[0],modmul(butterfly2[2],pow(749,0,3329),3329), 3329)
butterfly1[3] = modsub(butterfly2[1],modmul(butterfly2[3],pow(749,2,3329),3329), 3329)
butterfly1[4] = modadd(butterfly2[4],modmul(butterfly2[6],pow(749,0,3329),3329), 3329)
butterfly1[5] = modadd(butterfly2[5],modmul(butterfly2[7],pow(749,2,3329),3329), 3329)
butterfly1[6] = modsub(butterfly2[4],modmul(butterfly2[6],pow(749,0,3329),3329), 3329)
butterfly1[7] = modsub(butterfly2[5],modmul(butterfly2[7],pow(749,2,3329),3329), 3329)

print("\nframe2变换结果为:")
for i in range(8):
    print(butterfly1[i], end=' ')

butterfly2[0] = modadd(butterfly1[0],modmul(butterfly1[4],pow(749,0,3329),3329), 3329)
butterfly2[1] = modadd(butterfly1[1],modmul(butterfly1[5],pow(749,1,3329),3329), 3329)
butterfly2[2] = modadd(butterfly1[2],modmul(butterfly1[6],pow(749,2,3329),3329), 3329)
butterfly2[3] = modadd(butterfly1[3],modmul(butterfly1[7],pow(749,3,3329),3329), 3329)
butterfly2[4] = modsub(butterfly1[0],modmul(butterfly1[4],pow(749,0,3329),3329), 3329)
butterfly2[5] = modsub(butterfly1[1],modmul(butterfly1[5],pow(749,1,3329),3329), 3329)
butterfly2[6] = modsub(butterfly1[2],modmul(butterfly1[6],pow(749,2,3329),3329), 3329)
butterfly2[7] = modsub(butterfly1[3],modmul(butterfly1[7],pow(749,3,3329),3329), 3329)

print("\nFNTT变换结果为:")
for i in range(8):
    print(butterfly2[i], end=' ')


orign=[1,749,1729,40,3328,2580,1600,3289]
#直接实现8点NTT的O(n^2)版本
print("\n下面是直接实现8点NTT的O(n^2)版本:")
for i in range(8):
    res = 0
    for j in range(8):
        res += coe[j] * pow(orign[i], j, 3329)
    print(res % 3329, end=' ')
