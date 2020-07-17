#include <stdio.h>
#include <ctype.h>

// index = 0.0588  * L -0.296 * S - 15.8
// L is avarage number of letters per 100 words
// S is average number os seentences per 100 words

//  count number of letters, words and sentences to have enough information for solving the formula  OK

/**
 *  if output is less than 1, output "Before Grade 1"
 *  if output is 16 or higher, output "Grade 16+"
*/

int round( float );

int main(void) {
    
    int words = 0; int sentences = 0 ;int letters = 0; 
    float hundredsOfWords, L, S;

    char text[1000]; 
    gets(text);

    // loop to iterate through the text
    for (int i = 0; text[i] != '\0'; i++) {
        
        // condition to count the number of words
        if ( (isalnum(text[i]) || ispunct(text[i])) && (!isalnum(text[i + 1]) && !ispunct(text[i + 1])) ) {
            words++;
        }

        // condition to count the number of sentences
        if (text[i] == '.' ||text[i] == '!' || text[i] == '?' ) {
            sentences++;
        }
        // condition to count the number of letters
        if ( isalnum((text[i])) ) {
            letters++;
        }
    }
    
    hundredsOfWords = (float)words / 100.0;  // gets the number of hundreds
    L = (float)letters / hundredsOfWords;   //  gets the average number of letters per 100 words 
    S = (float)sentences / hundredsOfWords;//   gets the average number of sentences per 100 words

    float index = 0.0588  * L -0.296 * S - 15.8; 

    // printf("\n\nL: %f   \nS: %f  \nindex: %f \n\n", L, S, index);

    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index > 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", round(index));
    }

}


int round( float index ) {
    
    if( index - (int)index < 0.5 ) {
        return (int)index;
    }

    return (int)index + 1;
}