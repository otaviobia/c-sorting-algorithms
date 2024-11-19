#include <stdio.h> 
#include <time.h>

unsigned long long comparacoes = 0;
unsigned long long movimentos = 0;

void bubble_sort(int v[], int tam) {

    int tmp; 
    int trocou; 

    for(int i = 0; i<tam-1; i++) {
        trocou = 0; 
        for(int j = 0; j<tam-i-1; j++) {
            comparacoes++;
            if(v[j] > v[j+1]) {
                tmp = v[j]; 
                v[j] = v[j+1]; 
                v[j+1] = tmp; 
                trocou = 1;
                movimentos++;
            }
        }

        if (!trocou)
            break;
    }
}


int main(void) {
    
    int tam;
    scanf("%d", &tam);

    int v[tam];
    for(int i = 0; i<tam; i++)
        scanf("%d", &v[i]);

    clock_t start = clock();
    bubble_sort(v, tam); 
    clock_t end = clock();

    for(int i = 0; i<tam; i++) 
        printf("%d ", v[i]); 

    printf("\nComparacoes: %llu\nMovimentos: %llu\n", comparacoes, movimentos);
    printf("Tempo: %fs\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0; 
}