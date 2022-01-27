#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

//function to count letters
int count_letters(string text);
//function to count words
int count_words(string text);
//function to count sentences
int count_sentences(string text);
int main(void)
{
    //prompt for text
    string text = get_string("Text: ");
    //average number of letters will be the quotient of letters divided by words times 100
    //here and in all calculations requiring precision, I multiplied by a floating point constant
    //in the numerator and denominator, otherwise the division would yield an int quotient
    //which does not allow for decimals
    float avg_letters = (100.0000 * ((1.00000 * count_letters(text)) / ((1.00000 * count_words(text))))); 
    float avg_sentences = (100.0000 * ((1.00000 * count_sentences(text)) / ((1.00000 * count_words(text)))));
    //applying math of index
    int cl_index = round((.0588 * avg_letters) - (.296 * avg_sentences) - 15.8); 
    if (cl_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (cl_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", cl_index);

    }
}

int count_sentences(string text)
{
    //initialize a count for number of sentences at 0
    int sentence_count = 0;
    //iterate this loop for every character in the string
    for (int k = 0; k < strlen(text); k++)
    {
        //move all chars, adding one to sentence count if the value
        //equals the ascii value for . ? !
        if (text[k] == 46 || text[k] == 33 || text[k] == 63)
        {
            sentence_count++;
        }
    }
    //return the number of sentences
    return sentence_count;
}

int count_letters(string text)
{
    //initialize count for number of letters at 0
    int letter_count = 0;
    //repeat loop for the whole sentence
    for (int i = 0; i < strlen(text); i++)
    {
        //if a character is not whitespace and is in alphabet 
        //(so not apostrophes in contractions, for exammple,
        //then add 1 to letter count
        if (isspace(text[i]) == 0 && isalpha(text[i]) != 0)
        {
            letter_count++;
        }
    }
    // return letter count
    return letter_count;
}

int count_words(string text)
{
    //initialize count at 1 (because there's always one more word than spaces
    int word_count = 1;
    //iterate through whole sentence, if isspace yields a nonzero value (indincating
    //white space), then add to the word counter
    for (int j = 0; j < strlen(text); j++)
    {
        if (isspace(text[j]) != 0)
        {
            word_count++;
        }
    }
    //return word_count
    return word_count;
}
