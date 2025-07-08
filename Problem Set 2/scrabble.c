#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int LETTERPOINT[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                     1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculateScore(string s);

int main(void)
{
    // get user input
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // calculate score
    int player1Score = calculateScore(player1);
    int player2Score = calculateScore(player2);

    // determine which score is larger and print out the winner
    if (player1Score > player2Score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2Score > player1Score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// function used to return the score from a given string
int calculateScore(string s)
{
    int score = 0;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        char character = toupper(s[i]);
        if (character >= 'A' && character <= 'Z')
        {
            score += LETTERPOINT[character - 'A'];
        }
    }
    return score;
}
