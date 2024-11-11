#include <stdio.h> 

void bubble_sort(int v[], int tam) {

    int tmp; 
    int trocou; 

    for(int i =0; i<tam; i++) {
        trocou = 0; 
        for(int j = 0; j<tam-i; j++) {
            if(v[j] > v[j+1]) {
                tmp = v[j]; 
                v[j] = v[j+1]; 
                v[j+1] = tmp; 
                trocou = 1 ; 

            }

        }
    }
}


int main(void) {
    
    int v[] = {3,2,1,7,6,4,8}; 
    bubble_sort(v, 7); 

    for(int i = 0; i<7; i++) 
        printf("%d ", v[i]); 

    return 0; 
}