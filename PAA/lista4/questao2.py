def fibonacci(n_elements):
    if (not n_elements):
        return 0
    elif (n_elements==1 or n_elements==2):
        return 1
    else:
        return fibonacci(n_elements-1)+fibonacci(n_elements-2)

print("Fibonacci para ",6, "elementos: ",fibonacci(6))

for i in range(1,10):
    pass
    #print("Fibonacci para ",i, "elementos: ",fibonacci(i))
    
