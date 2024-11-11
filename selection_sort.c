#include <stdio.h>

int *selectionSort(int v[], int tam) {
    int tmp, menor; 


    for(int i = 0; i<tam-1; i++) {
        menor = i; 
        for(int j =i+1; j<tam; j++) {
            if(v[j] < v[menor]) 
                menor = j;  
        
        }

        tmp = v[i]; 
        v[i] = v[menor]; 
        v[menor] = tmp;


    }

    return v; 
}



int main(void) {
    int v[] = {3,1, 8,4, 7}; 

    int *v_sorted = selectionSort(v, 5); 

    for(int i =0; i<5; i++) 
        printf("%d ", v[i]); 





    return 0; 
}