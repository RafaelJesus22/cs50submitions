#include <cs50.h>
#include <stdio.h>
#include <string.h>

// declare max voters and max candidates
#define MAX_CANDIDATES 9
#define MAX_VOTERS 9


// defines type candidate
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// create array of candidates and array of preferences
candidate candidates[MAX_CANDIDATES];
int preferences[MAX_VOTERS][MAX_CANDIDATES];
int candidate_count;
int voter_count;


// function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);


int main(int argc, string argv[])
{
    // checks if any candidate was passed
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1; // define number of candidates
    
    // checks if number of candidates is bigger than allowed
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    voter_count = get_int("Number of voters: ");

    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }
    // initialize candidates array
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // gets the rank for each voter
    for (int i = 0; i < voter_count; i++)
    {
       for (int j = 0; j < candidate_count; j++)
       {
            while (true)
            {
                printf("Rank %i: ", j+1);
                string name = get_string("");

                if (vote(i, j, name))
                {
                    break;
                }
            }
        }

        printf("\n");
    }

    while (!print_winner())
    {
        if (!is_tie(find_min()))
        {
            eliminate(find_min());
        }
    }

}


bool vote(int voter, int rank, string name)
{
    // look for a candidate called name
    for (int i = 0; i < candidate_count; i++)
    {
        // if candidate found, update preferences so that they are the voter's rank preferences and return true
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }


    // if no candidate found, don't update any preferences at all and return false
    return false;
}


void tabulate(void)
{
    // for voter in preferences
    for (int i = 0; i < voter_count; i++)
    {
        // for rank of voter preferences
        for (int j = 0; j < candidate_count; j++)
        {
            int vote = preferences[i][j]; // handles the candidate position
            if (!candidates[vote].eliminated) // if candidate is not eliminated
            {
                candidates[vote].votes++;
                break;
            }
        }
    }
}


bool print_winner(void)
{
    tabulate();

    int min_votes = voter_count / 2 + 1;
    int winner_count = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min_votes && !candidates[i].eliminated)
        {
            printf("%s\n", candidates[i].name);
            winner_count++;
        }
    }

    if (winner_count > 0)
    {
        return true;
    }

    return false;
}


int find_min(void)
{
    int min = candidates[0].votes;

    for (int i = 0; i < candidate_count; i++)
    {
        if (min > candidates[i].votes)
        {
            min = candidates[i].votes;
        }
    }

    // return the minimun number of voter of anyone still in the election
    return min;
}


bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes != min && !candidates[i].eliminated)
        {
            return false;
        }
    }
    return true;
}


void eliminate(int min)
{
    // eliminate anyone still in the race who has the min number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            candidates[i].eliminated = true;
        }
    }
}
