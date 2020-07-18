#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/*
* invalid keys
* no key at all "usage"
* key with length less  than 26 characters "key must be..."
* key with no alphabetic characters "key must only contain alphabetic characters"
* key with repeted characters
*/

/*
TODO
[X] - get the key
[X] - validate the key
    [X] - no key
    [X] - key with length different than 26
    [X] - key with no alphabetic characters
    [X] - key with repeted characters
[X] - get plaintext
[X] - encipher
    [X] - change letters and keep non alphabetic characters
    [X] - keep plaintext case
[X] - print ciphertext
*/

void EncipherAndShow(string key);

const int SIZE = 26;

int main(int argc, string argv[])
{
    string key = argv[1];

    // in case user input no key
    if (!key)
    {
        puts("Usage: ./substitution key");
        return 1;
    }
    else
    {
        // validates key size
        if (strlen(key) < SIZE || strlen(key) > SIZE)
        {
            puts("Key must contain 26 characters.");
            return 1;
        }

        // validates if the key is only alphabetic
        for (int i = 0; i < SIZE; i++)
        {
            if (!isalpha(key[i]))
            {
                puts("key must only contain alphabetic characters.");
                return 1;
            }
        }

        // validades repeted characters
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (key[j] == key[i] && i != j)
                {
                    puts("Key must not contain repeted characters.");
                    return 1;
                }
            }
        }
    }

    EncipherAndShow(key);

}

void EncipherAndShow(string key)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string plaintext = get_string("plaintext: ");
    string cipheredText = plaintext;

    // loops through the plaintext
    for (int i = 0; i < SIZE; i++)
    {
        // validates non alphabetic caracters
        if (isalpha(plaintext[i]))
        {
            // for every character in alpha
            for (int j = 0; j < SIZE; j++)
            {
                // if current plaintext letter is equal to alpha[current j]
                if (alpha[j] == toupper(plaintext[i]))
                {
                    if (isupper(plaintext[i]))
                    {
                        cipheredText[i] = toupper(key[j]);
                        break;
                    }

                    if (islower(plaintext[i]))
                    {
                        cipheredText[i] = tolower(key[j]);
                        break;
                    }
                }
            }
        }
    }


    //print cipheredtext
    printf("ciphertext: %s\n", cipheredText);

}