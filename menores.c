#include <stdio.h> 

void contagem_de_menores(int v[], int tam); 


int main(void) {
    int v[] = {5,8,1,3,10,22, 3}; 
    int tam = sizeof(v)/sizeof(int); 
    contagem_de_menores(v, tam); 

    for(int i = 0; i<tam; i++) 
        printf("%d ", v[i]); 


    return 0; 
}


void contagem_de_menores(int v[], int tam) {
    int A[tam]; 
    int B[tam]; 

    for(int i = 0; i<tam; i++) 
        A[i] = 0; 
    

    for(int i = 1; i<tam; i++) {
        for(int j = i-1; j>=0; j--) {
            if(v[i] < v[j]) {
                A[j]++; 
            }else 
                A[i]++; 
        }
    }


    for(int i = 0; i<tam; i++) 
        B[A[i]] = v[i];
    

    for (int i=0; i<tam; i++) 
        v[i]=B[i];

}