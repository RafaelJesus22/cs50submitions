#include <stdio.h>
#include <cs50.h>

int main(void){

    //prompts user for his name
    string user = get_string("Enter you name: ");

    //say hello to the user whatever his name is
    printf("Hello, %s\n", user);

}