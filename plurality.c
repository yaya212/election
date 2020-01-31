#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name, int s);
void print_winner(int max);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    printf("Candidate count is %d\n", candidate_count);
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        int s = 0;
        // Check for invalid vote
        if (vote(name, s) == false)
        {
            printf("Invalid vote when i = %d\n", i);
        }
        //printf("Candidate %s at index %d\n", candidates[i].name, i);
    }
    int max = 0;
    // Display winner of election
    print_winner(max);
}

// Update vote totals given a new vote
bool vote(string name, int s)
{
    if(s == candidate_count)
    {
        return false;
        //printf("Candidate %s is not found!!!\n",name);
    }
    else
    {
        if(!(strcmp(candidates[s].name, name)))
        {
            ++(candidates[s].votes);
            //printf("Candidate %s has %d votes\n",candidates[s].name,candidates[s].votes);
            return true;
        }
        else
        {
            //printf("Candidate %s is not found!!!\n",name);
            s++;
            return vote(name, s);
        }
    }
    //return true;
}
int j = 0;
// Print the winner (or winners) of the election
void print_winner(int max)
{
    if(j == candidate_count)
    {
        printf("%s\n", candidates[max].name);
        return;
    }
    else
    {
        if(candidates[j].votes > candidates[max].votes)
        {
            max = j;
            j++;
            print_winner(max);
        }
        else if((candidates[j].votes == candidates[max].votes) && (j != max))
        {
            printf("%s\n", candidates[j].name);
            j++;
            print_winner(max);
        }
        else
        {
            j++;
            print_winner(max);
        }
    }
}

