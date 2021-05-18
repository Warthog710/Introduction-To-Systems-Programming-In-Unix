#include <stdlib.h>
#include <time.h>
#include "struct.h"

void shuffle (Questions_T questionList[], int count)
{
    srand(time(NULL));
    int random, index = 0;
    Questions_T temp[count];

    /*Intilize temp array.*/
    for (index = 0; index < count; index++)
    {
        temp[index].q[0] = '\0';
    }
    
    index = 0;

    /*Shuffle the questions*/
    while(1)
    {
        random = rand() % count;

        if(temp[random].q[0] != '\0')
        {
            continue;
        }
        else
        {
            temp[random] = questionList[index];
            index++;
        }

        if (index >= count)
        {
            break;
        }        
    }

    /*Copy shuffled temp array back into questionlist*/
    for (index = 0; index < count; index++)
    {
        questionList[index] = temp[index];
    }  
}
