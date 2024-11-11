#include <stdio.h> 

void rearranjar_heap(int v[], int i, int tam_heap) {
    int esq, dir, aux, maior; 
    esq = 2*i + 1; 
    dir = 2*i + 2; 

    if(esq < tam_heap && v[esq] > v[i]) 
        maior = esq; 
    else 
        maior = i; 
    
    if(dir < tam_heap && v[dir] > v[maior]) 
        maior = dir; 
    
    if(maior != i ) {
        aux = v[maior]; 
        v[maior] = v[i]; 
        v[i] = aux; 
        rearranjar_heap(v, maior, tam_heap); 
    }
}

void construir_heap(int v[], int n) {
    int i; 
    for(i = n/2 - 1; i >= 0; i--) 
        rearranjar_heap(v, i, n); 
}

void heapsort(int v[], int n) {
    int tmp, tam_heap; 
    construir_heap(v, n);
    tam_heap = n; 

    for(int i = n-1; i > 0; i--) {
        tmp = v[0]; 
        v[0] = v[i]; 
        v[i] = tmp; 
        tam_heap--; 
        rearranjar_heap(v, 0, tam_heap); 
    }
}

int main(void) {
    int v[] = {4, 2, 1, 8, 3, 9, 0, 1}; 

    heapsort(v, 8); 

    for(int i = 0; i < 8; i++)
        printf("%d ", v[i]); 

    return 0; 
}
