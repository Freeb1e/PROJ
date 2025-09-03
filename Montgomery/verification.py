def REDC(a,b):
    t=a*b
    m=((t&0xFFF)*3327)&0xFFF
    u=(t+m*3329)>>12
    if u>=3329:
        return u-3329
    else:
        return u

def MENG(A,B):
    A1 = REDC(A, 2385)
    B1 = REDC(B, 2385)
    C1 = REDC(A1, B1)
    C2 = REDC(C1, 1)
    return C2

for i in range(4096):
    for j in range(4096):
        if MENG(i,j) != (i*j)%3329:
            print("Error at i=",i," j=",j)
        else:
            if(i%1000==0 and j%1000==0):
                print("i=",i," j=",j," OK")
        

