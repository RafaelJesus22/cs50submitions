#include <cs50.h>
#include <stdio.h>

int main(void) {
    
    int size;
    
    do{
        size = get_int("what's the pyramid size? ");
    } while (size < 1 || size > 8);
    
    int hash = 1;

    for (int i = size; i > 0; i--) {
        
        for (int j = i - 1; j > 0; j--) {
            printf(" ");
        }
        
        for (int j =  hash; j > 0; j--){
            printf("#");
        }

        printf("  ");

        for (int j =  hash; j > 0; j--){
            printf("#");
        }

        hash++;
        printf("\n");
    }
}
