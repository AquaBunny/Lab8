/*******************************************************************************
* author          Daniel Bachler
* filename        histogram.c
* class          CS120
* date            2/18/16
*	Provides information about a phrase with several functions                       
*******************************************************************************/
 
#include <stdio.h>     /* printf      */
#include <ctype.h>     /* toupper     */
#include <string.h>    /* strlen      */
#include "histogram.h" /* lab defines */
 
int GetCounts(const char *sentence, int letters[], int *spaces, int *other)
{
    int i, total = 0;
   
    *spaces = 0;
    *other = 0;
   
   /*Sets amount of all letters to 0*/
    for(i = 0; i < NUM_LETTERS; i++)
        letters[i] = 0;
   
   
   
    for(i = 0; sentence[i]; i++){
        char character = toupper(sentence[i] + 0);
        /* If it's a letter, increment the corresponding index
            otherwise, increment the space/other value*/
        if(character >= 'A' && character <= 'Z'){
            letters[character - 'A']++;
            total++;
        }
        else if(character == ' ')
            ++*spaces;
        else
            ++*other;
    }
   
    return total;
}
 
void PrintHistogram(const int letters[])
{
    int i, j;
    for(i = 0; i < NUM_LETTERS; i++){
		/*Prints header for each letter*/
        printf("%c:", 'A' + i);
		/*Printing an asterisk for each apperance of the letter*/
        for(j = 0; j < letters[i]; j++)
            printf("*");
       
        printf("\n");
    }
}
 
void GetStatistics(const int letters[], double *average, char *max_letter, int *max_count)
{
    int i;
    *max_letter = 'A';
    for(i = 0; i < NUM_LETTERS; i++){
        *average += (i + 1) * letters[i];
       
        if(letters[i] > letters[*max_letter - 'A'])
            *max_letter = 'A' + i;
    }
   
    *average /= NUM_LETTERS;
    *max_count = letters[*max_letter - 'A'];
}