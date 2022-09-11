#include <stdio.h>
#include <stdlib.h>

#define MAX 100


// primeiro subvetor entre p e q-1, segundo subvetor entre q e r-1
unsigned long long intercala(int v[], int p, int q, int r){
    int i, j, k, tam;
    unsigned long long num_inv = 0;

    // iteradores
    i = p;
    j = q;
    k = 0;
    tam = r - p;

    int *w = malloc(tam*sizeof(int)); // Novo subvetor ordenado
    // Percorre os dois subvetores até alcançar o fim de algum deles
    while(i<q && j<r){
        if(v[i]<=v[j]){ // Se o elemento do primeiro subvetor é menor do que do segundo
            w[k++] = v[i++]; // Adiciona o elemento no vetor ordenado
        }else{ // v[i] > v[j]
            w[k++] = v[j++];
            num_inv += q-i;
        }
    }
    // Garante que os elementos restantes dos subvetores sejam adicionados ao final

    while(i<q){
        w[k++] = v[i++];
    }
    while(j<r){
        num_inv += q-i;
        w[k++] = v[j++];
    } 

    for(k=0; k<tam; k++){
        v[p+k] = w[k];
    }

    free(w);
    return num_inv;
}


// Função recursiva de contagem de inversoes de um vetor 
// Parametros: vetor v[], p é a primeira posição do vetor e r-1 é a última
// Retorno: inteiro correspondente ao numero de inversoes
unsigned long long contarInversoesR(int v[], int p, int r){
    int m;
    unsigned long long num_inv=0;
    if(r - p > 1){ 
        m = (p + r)/2; // calculo do limitante
        num_inv += contarInversoesR(v, p, m);
        num_inv += contarInversoesR(v, m, r);
        num_inv += intercala(v, p, m, r);
    }
    return num_inv;
}

// Conta as inversoes de um vetor 
// Parametros: vetor v[] com n elementos
// Retorno: inteiro correspondente ao numero de inversoes
unsigned long long contarInversoes(int v[], int n){
    return contarInversoesR(v, 0, n);
}


void imprime(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}



//____________________________MAIN_________________________________

int main(int argc, char *argv[])
{
    char file_name[MAX];
    FILE *entrada;
    int i, n;
    unsigned long long num_inv = 0;

    if (argc != 1)
    {
        printf("Numero incorreto de parametros. Ex: .\\nome_arquivo_executavel\n");
        return 0;
    }
    scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if (entrada == NULL)
    {
        printf("\nNao encontrei o arquivo! Informe o nome da instancia\n");
        exit(EXIT_FAILURE);
    }
    // lendo do arquivo da instância
    fscanf(entrada, "%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        fscanf(entrada, "%d", &v[i]);
    
    num_inv = contarInversoes(v,n);

    printf("%llu\n", num_inv);
    //imprime(v, n);

    fclose(entrada);
    return 0;
}
