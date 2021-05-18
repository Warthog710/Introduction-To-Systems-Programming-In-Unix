#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/*To change the number of questions read, modify this value.*/
#define NUM_QUESTIONS 50

/*To change the number of questions asked, modify this value.*/
#define NUM_ASK 5

int readQuestions(Questions_T[], int);
void shuffle(Questions_T[], int);
void sort(Questions_T[], int);
void display(Questions_T[], int);
void review(Questions_T[], int);

int main()
{
    Questions_T questionList[NUM_QUESTIONS];
    int number = 0;

    number = readQuestions(questionList, NUM_QUESTIONS);

    /*Check if there was an error*/
    if (number == -1)
    {
        printf("Aborting program execution...\n");
        exit(0);
    }
    else if (NUM_ASK > NUM_QUESTIONS)
    {
        printf("The number of questions to be asked is greater than the number of questions read...\n");
        printf("Aborting program execution...\n");
        exit(0); 
    }
    else
    {  
        shuffle(questionList, NUM_QUESTIONS);
        sort(questionList, NUM_ASK);
        display(questionList, NUM_ASK);
        review(questionList, NUM_ASK);
    }
}