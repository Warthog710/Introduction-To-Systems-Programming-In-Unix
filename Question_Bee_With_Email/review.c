#include <stdio.h>
#include <string.h>
#include "struct.h"

void review (Questions_T questionList[], int count)
{
    int index, numCorrect = 0;

    for (index = 0; index < count; index++)
    {
        printf("%s\n", questionList[index].q);
        printf("%s\n", questionList[index].c1);
        printf("%s\n", questionList[index].c2);
        printf("%s\n", questionList[index].c3);
        printf("%s\n", questionList[index].c4);

        if (strchr(questionList[index].answer, questionList[index].response))
        {
            printf("\nYou answered %c. This was correct.\n", questionList[index].response);
            numCorrect++;
        }
        else
        {
            printf("\nYou answered %c. This was incorrect. The correct answer was %s\n", questionList[index].response, questionList[index].answer);
        }   
    }
    printf("You scored %d/%d.\n", numCorrect, count);
}
