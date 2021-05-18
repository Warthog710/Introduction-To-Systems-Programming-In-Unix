#include <stdio.h>
#include <string.h>
#include "struct.h"

void display (Questions_T questionList[], int count)
{
    int index;

    for (index = 0; index < count; index++)
    {
        printf("%s\n", questionList[index].q);
        printf("%s\n", questionList[index].c1);
        printf("%s\n", questionList[index].c2);
        printf("%s\n", questionList[index].c3);
        printf("%s\n", questionList[index].c4);
        printf("Your answer: ");
        scanf(" %c", &questionList[index].response);
        
        if (strchr(questionList[index].answer, questionList[index].response))
        {
            printf("\nYou answered correctly!\n\n");
        }
        else
        {
            printf("\nWrong answer.\n\n");
        }         
    }
}
