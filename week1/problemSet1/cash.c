#include <cs50.h>
#include <stdio.h>

int main(void) {
    
    int coins = 0; // number of coins 
    float change; // initializes variable

    do {
        change = get_float("change owed: ") * 100; // gets the change value in cents
    } while (change < 0 || change == 0);  

    //gets the number of quarters
    while(change >= 25) {
        change -= 25;
        coins++;
    }

    //gets the number of dimes
    while(change >= 10) {
        change -= 10;
        coins++;
    }

    //gets the number of nickels
    while(change >= 5) {
        change -= 5;
        coins++;
    }

    //gets the number of pennies
    while(change >= 1) {
        change -= 1;
        coins++;
    }
    
    // returns the number of coins 
    printf("%i \n", coins);
}
