#include <stdio.h> 
#include <time.h>

unsigned long long comparacoes = 0;
unsigned long long movimentos = 0;

void rearranjar_heap(int v[], int i, int tam_heap) {
    int esq, dir, aux, maior; 
    esq = 2*i + 1; 
    dir = 2*i + 2; 

    comparacoes++; 
    if(esq < tam_heap && v[esq] > v[i]) 
        maior = esq; 
    else 
        maior = i; 
    
    comparacoes++; 
    if(dir < tam_heap && v[dir] > v[maior]) 
        maior = dir; 

    if(maior != i ) {
        aux = v[maior]; 
        v[maior] = v[i]; 
        v[i] = aux;
        movimentos++;
        rearranjar_heap(v, maior, tam_heap); 
    }

    comparacoes+=5;
}

void construir_heap(int v[], int n) {
    int i; 
    for(i = n/2 - 1; i >= 0; i--) {
        rearranjar_heap(v, i, n); 
    }
}

void heapsort(int v[], int n) {
    int tmp, tam_heap; 
    construir_heap(v, n);
    tam_heap = n; 

    for(int i = n-1; i > 0; i--) {
        movimentos++;
        tmp = v[0]; 
        v[0] = v[i]; 
        v[i] = tmp; 
        tam_heap--; 
        rearranjar_heap(v, 0, tam_heap); 
    }
}

int main(void) {

    int tam;
    scanf("%d", &tam);

    int v[tam];
    for(int i = 0; i<tam; i++)
        scanf("%d", &v[i]);

    clock_t start = clock();
    heapsort(v, tam);
    clock_t end = clock();

    for(int i = 0; i<tam; i++) 
        printf("%d ", v[i]); 

    printf("\nComparacoes: %llu\nMovimentos: %llu\n", comparacoes, movimentos);
    printf("Tempo: %fs\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0; 
}
