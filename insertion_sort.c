#include <stdio.h> 

void insertion_sort(int v[], int tam) {
    int tmp, j;

    for (int i = 1; i < tam; i++) {
        tmp = v[i];
        j = i - 1;
        
        // Movendo os elementos maiores que tmp para frente
        while (j >= 0 && v[j] > tmp) {
            v[j + 1] = v[j];
            j--;
        }
        // Inserindo o elemento temporário na posição correta
        v[j + 1] = tmp;
    }
}

int main(void) {
    int v[] = {3, 4, 1, 8, 7}; 
    insertion_sort(v, 5); 

    for (int i = 0; i < 5; i++) {
        printf("%d ", v[i]); 
    }

    return 0; 
}
