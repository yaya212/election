#include <cs50.h>
#include <stdio.h>
#include<string.h>
// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
            preferences[i][j] = 0;
        }
    }
    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
            //testing the vote function which went well
            // else
            // {
            //     printf("Found!!!\npair_count = %d\n", pair_count);
            // }
        }

        record_preferences(ranks);

        printf("\n");
    }
    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    //printf("pair_count = %d\n", pair_count);
    //I will use the pair_count as a temporary counter here
    if(pair_count == candidate_count)
    {
        pair_count = 0;
        return false;
    }
    else
    {
        if(strcmp(name, candidates[pair_count]) == 0)
        {
            ranks[rank] = pair_count;
            pair_count = 0;
            return true;
        }
        else
        {
            pair_count++;
            return vote(rank, name, ranks);
        }
    }
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int index1 = -1;
    int index2 = -1;
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            pair_count = 0;
            if(i != j)
            {
                for(int k = 0; k < candidate_count; k++)
                {
                    if(ranks[k] == i)
                    {
                        index1 = k;
                    }
                    if(ranks[k] == j)
                    {
                        index2 = k;
                    }
                    if((index1 >= 0) && (index2 >= 0))
                    {
                        break;
                    }
                }
                if(index1 < index2)
                {
                    //printf("index1: %d\nindex2: %d\n", index1, index2);
                    pair_count++;
                    //printf("pair_count = %d\n", pair_count);
                    preferences[i][j] += pair_count;
                    //printf("preferences[%d][%d] = %d\n", i, j, preferences[i][j]);
                }
                index1 = -1;
                index2 = -1;
            }
        }
    }

//testing the preferences worked well
    // for(int i = 0; i < candidate_count; i++)
    // {
    //     for(int j = 0; j < candidate_count; j++)
    //     {
    //         printf("preferences[%d][%d] = %d\n", i, j, preferences[i][j]);
    //     }
    // }
    pair_count = 0;
    // TODO
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if(i != j)
            {
                if(preferences[i][j] > 0)
                {
                    if(preferences[i][j] > preferences[j][i])
                    {
                        printf("true 1\n");
                        pairs[pair_count].winner = i;
                        pairs[pair_count].loser = j;
                        pair_count++;
                    }
                }
            }
        }
    }

//Testing the creation of pairs worked
    // for(int i = 0; i < pair_count; i++)
    // {
    //     printf("Pair[%i]:\nWinner: %d\nLoser: %d\n", i, pairs[i].winner, pairs[i].loser);
    // }
    // TODO
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int sorted = 1;
    for(int i = 0; i < pair_count; i++)
    {
        for(int j = i+1; j < pair_count; j++)
        {
            if(preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[j].winner][pairs[j].loser])
            {
                sorted = 0;
                int temp = pairs[i].winner;
                pairs[i].winner = pairs[j].winner;
                pairs[j].winner = temp;
                temp = pairs[i].loser;
                pairs[i].loser = pairs[j].loser;
                pairs[j].loser = temp;
            }
        }
    }

//Testing the sorting of pair worked
    printf("The sorted pairs are:\n\n");

    for(int i = 0; i < pair_count; i++)
    {
        printf("Pair[%i]:\nWinner: %d\nLoser: %d\n", i, pairs[i].winner, pairs[i].loser);
    }
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int tmp = -1;
    int flag = 0;
    for(int i = 0; i < pair_count; i++)
    {
        if(flag == 0)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
        if(pairs[i].winner == pairs[i+1].loser)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }

//Testing the addition of edges worked well
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j< candidate_count; j++)
        {
            printf("locked[%d][%d] = %d\t", i, j, locked[i][j]);
        }
    }
    printf("\n");
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int winner = 0;
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            for(int k = 0; k < candidate_count; k++)
            {
                if(locked[j][k] == true)
                {
                    if(k == winner)
                    {
                        winner++;
                    }
                }
            }
        }
    }

    printf("%s\n", candidates[winner]);
    // TODO
    return;
}

