c=[2, 5, 5, 2, 10, 50, 100, 50, 20, 20, 50, 100]
def pegaCedulasPD(tam):
    if not tam:
        return 0
    else:
        soma = [c[0]]
        print(f"F[0] = {c[0]}")
        soma.append(c[1])
        print(f"F[1] = {c[1]}")
        for i in range(2,tam):
            soma.append(max(c[i]+soma[i-2], soma[i-1]))
            print(f"F[{i}] = max({c[i]+soma[i-2]}, {soma[i-1]}) = {soma[i]}")
        return soma[tam-1]
print("Resultado: ",pegaCedulasPD(12))
