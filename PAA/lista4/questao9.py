
def cutRodB(p, n):
    r = [0]*(n+1)
    for j in range(1,n):
        q = -1.8e308
        for i in range(1,j):
            q = max(q, float(p[i]+r[j-i]))
        r[j] = q
    return r[n]


a = [2, 6,9,10,12,16]
cutRodB(a,6)