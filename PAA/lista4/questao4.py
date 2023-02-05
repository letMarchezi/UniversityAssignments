c=[2, 5, 5, 2, 10, 50, 100, 50, 20, 20, 50, 100]
def pegaCedulas(tam):
    if not tam:
        return c[0]
    elif tam == 1:
        return c[1]
    else:
        return max(c[tam]+pegaCedulas(tam-2), pegaCedulas(tam-1))
    
print(pegaCedulas(11))
