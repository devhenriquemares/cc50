#include <cs50.h>
#include <stdio.h>
#include <string.h>

// NUMERO MAXIMO DE VOTADORES E CANDIDATOS
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// PREFERENCIAS [i] [j], I PARA VOTADOR E J PARA PREFERENCIA
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;

} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

string winner_name;
int eliminated_candidates = 0;
int turn = 2;
bool turn_condition = false;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    secondTurn:
    if(turn_condition == true)
    {   
        do 
        {
            voter_count = get_int("Number of voters: ");
            
            if(voter_count % 2 == 0)
            {
                printf("In the second turn the number of voters have to be odd\n");
            }
        }
        while(voter_count % 2 == 0);
    }
    else 
    {
        voter_count = get_int("Number of voters: ");
    }
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < (candidate_count - eliminated_candidates); j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            for(int k = 0; k < candidate_count; k++)
            {
                if(strcmp(name, candidates[k].name) == 0 && candidates[k].eliminated == true)
                {
                    printf("Invalid vote. The candidate have been eliminated.\n");

                    return 4;
                }
            }
            
            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                
                return 5;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // break;

        // Check if election has been won
        bool won = print_winner();
        if(won)
        {  
            printf("The winner is: %s", winner_name);

            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if(tie)
        {
            printf("The election it's tied\n");

            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s, %i votos\n", candidates[i].name, candidates[i].votes);
                }
            }
            printf("\n");
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        for (int i = 0; i < candidate_count; i++)
            {
                candidates[i].votes = 0;
            }

        tabulate();

        won = print_winner();

        if(won)
        {   
            printf("\nThe winner is: %s\n\n", winner_name);
            break;
        }
        else
        {
            printf("Now we're going to the %i turn.\n", turn);

            // Reset vote counts back to zero
            for (int i = 0; i < candidate_count; i++)
            {
                candidates[i].votes = 0;
            }

            turn++;

            turn_condition = true;

            goto secondTurn;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;

            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for(int i = 0; i < voter_count; i++)
    {
        int x = 1;

        for(int j = 0; j < candidate_count; j++)
        {
            if(preferences[i][0] == j && candidates[j].eliminated != true)
            {
                candidates[j].votes++;
            }
            else if(preferences[i][0] == j && candidates[j].eliminated == true)
            {
                preferences[i][0] = preferences[i][x];
                
                j = -1;

                x++;
            }
        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int total_votes = 0;

    for(int i = 0; i < candidate_count; i++)
    {
        total_votes = total_votes + candidates[i].votes;
    }

    for(int j = 0; j < candidate_count; j++)
    {
        if(candidates[j].votes > (total_votes / 2))
        {
            winner_name = candidates[j].name;

            return true;
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int minimal_votes;
    int x = 1;

    if(candidates[0].eliminated == false)
    {
        minimal_votes = candidates[0].votes;
    }  

    for(int i = 0; i < candidate_count; i++)
    { 
        if(candidates[i].eliminated == false)
        {
            if(candidates[i].votes < minimal_votes)
            {
                minimal_votes = candidates[i].votes;
            }
        }
    }
    return minimal_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int equalVotes;

    for(int j = 0; j < candidate_count; j++)
    {
        if(candidates[j].eliminated == false)
        {
            if(candidates[j].votes == min)
            {
                break;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for(int j = 0; j < candidate_count; j++)
    {
        if(candidates[j].votes == min)
        {
            candidates[j].eliminated = true;

            printf("%s was eliminate...\n", candidates[j].name);
            
            eliminated_candidates++;
        }
    }

    return;
}
