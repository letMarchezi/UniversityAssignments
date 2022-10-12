/**
Nome: Leticia Bossatto Marchezi
Ra: 791003
**/
#include <stdio.h>
#include <stdlib.h>
/**
* Recebe o vetor v de tamanho n e o ordena
**/
void sort(int * v,int n){
    int i, j, aux;

    for(i=1; i<n; i++){
        aux=v[i];
        j=i-1;
        while(j>=0 && aux < v[j]){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=aux;

    }

}

void bubblesort(int * v,int n){
    int i, j, aux;

    for(i=0; i<n; i++){
        j=1;
        while(j<n-i){
            if(v[j-1]>v[j]){
                aux= v[j-1];
                v[j-1]=v[j];
                v[j]=aux;
            }
            j++;
        }
    }
}

void selectionsort(int * v,int n){
    int i, j, aux, pos_min;

    for(i = 0; i < n; i++){

        pos_min = i;
        j = i + i;
        while(j < n){
            if(v[j] < v[pos_min]){
                pos_min=j;
            }
            j++;
        }
        aux = v[i];
        v[i] = v[pos_min];
        v[pos_min] = aux;

    }
}

int main(){
 //entrada 1 numero de elementos do vetor a ser ordenado
 //entrada 2 lista de elementos a ser inserido em sequencia na arvore
    int i, n;
    scanf("%d",&n);
    int * v = (int *)malloc(n*sizeof(int));
    
    for(i = 0; i < n; i++){
        
        scanf("%d",&v[i]);
    }
    
    sort(v,n);
    //imprime o vetor ordenado
    for(i = 0; i < n-1; i++)
    printf("%d,",v[i]);
    printf("%d", v[i]);
    free(v);
    return 0;
}