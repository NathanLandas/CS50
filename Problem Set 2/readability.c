#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calculate_letters(string s);
int calculate_words(string s);
int calculate_sentences(string s);
int calculate_grade(int letters, int words, int sentences);

int main(void)
{
    string input = get_string("Text: ");

    int letters = calculate_letters(input);
    int words = calculate_words(input);
    int sentences = calculate_sentences(input);
    int grade = calculate_grade(letters, words, sentences);

    if (grade >= 1 && grade <= 16)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int calculate_letters(string s)
{
    int letters = 0;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (s[i] <= 'z' && s[i] >= 'A')
        {
            letters++;
        }
    }
    return letters;
}

int calculate_words(string s)
{
    int words = 1;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (s[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int calculate_sentences(string s)
{
    int sentences = 0;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

int calculate_grade(int letters, int words, int sentences)
{
    float S = 100 * (float) sentences / (float) words;
    float L = 100 * (float) letters / (float) words;
    float grade = 0.0588 * L - 0.296 * S - 15.8;
    int gradeAdjusted;

    if (grade - (int) grade > 0.5)
    {
        gradeAdjusted = (int) grade + 1;
        // printf("Rounded Grade: %i\n", gradeAdjusted);
        return gradeAdjusted;
    }
    else
    {
        gradeAdjusted = (int) grade;
        return gradeAdjusted;
    }
}
