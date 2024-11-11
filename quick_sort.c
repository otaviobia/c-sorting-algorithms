
#include <stdio.h> 

void quick_sort(int v[], int inicio, int fim) {
    
    if(inicio < fim) {
        //TODO mudar a seleção do pivô 
        int pivo = v[(inicio+fim)/2]; 
        int i, j; 
        int tmp; 

        i = inicio; 
        j = fim; 


        do{
            while(v[i] < pivo) 
                i++; 
            while(v[j] > pivo) 
                j--; 
            
            if(j>=i) {
                tmp = v[i]; 
                v[i] = v[j]; 
                v[j] = tmp; 
                i++; 
                j--; 

            }

        }while(i<j); 

        quick_sort(v, inicio, j); 
        quick_sort(v, i, fim); 
    }


}




int main(void) {
    int v[] = {3,4,1,8,7}; 

    quick_sort(v, 0, 4); 

    for(int i = 0; i<4; i++) 
        printf("%d ", v[i]); 


    return 0; 
}