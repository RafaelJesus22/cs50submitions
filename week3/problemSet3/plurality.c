#include <cs50.h>
#include <stdio.h>
#include <string.h>

// defines candidate max number
#define MAX 9

// defines type candidate
typedef struct
{
    string name;
    int votes;
}
candidate;


candidate candidates[9]; // declare candidates array
int candidate_count; // holds the number of candidates passed at CLI

// functions prototype
bool vote(string);
void print_winner();


int main(int argc, string argv[])
{

    // checks if there is command line arguments
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1; // gets the number of command line arguments
    
    // checks if there is more candidates than is allowed
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 1;
    }


    // inicializes candidates name and number of votes
    for (int i = 0; i < candidate_count; i ++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voters = get_int("Number of voters: "); // gets the number of voters
    int voted = 0; // holds the number of votes already voted
    
    // loops until there is no vote left to do
    while (voted < voters)
    {
        string Vote = get_string("Vote: "); // gets the vote

        // checks if its a valid name
        if (vote(Vote))
        {
            voted++;
        }
        else
        {
            puts("Invalid vote.");
        }
    }

    // prints the results 
    print_winner();
}


bool vote(string name)
{
    // loops through the array of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // checks if there's a candidate which name is equal the name passed
        if (strcmp(candidates[i].name, name) == 0)
        {
            //increment the number of votes of this candidate
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

void print_winner()
{
    int biggestNumber = 0; // holds the biggest number of votes

    // loops through all candidates
    for (int i = 0; i < MAX; i++)
    {
        // checks if the current number of votes is bigger than the last biggest number found
        if (candidates[i].votes > biggestNumber)
        {
            biggestNumber = candidates[i].votes; // update the biggest number
        }
    }

    // loops again through the candidates
    for (int i = 0; i < MAX; i++)
    {
        // checks if the current candidate number of votes is equals the biggest number of votes found
        if (candidates[i].votes == biggestNumber)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}