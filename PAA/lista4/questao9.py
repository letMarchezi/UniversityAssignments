def cut_aux(p, n):
    r = [-1]*(n+1)
    return cutRod(p, n, r)
    

def cutRod(p, n, r):
    if r[n] >= 0:
        return r[n]
    elif not n:
        q = 0
    else:
        q = -1
        for i in range(n):
            a = p[i]+ cutRod(p, n-1, r)
            q = max(q, a)
            print(f"q = max({q}, {a})")
    r[n] = q
    return q



print(cut_aux([2, 6,9,10,12,16], 6))