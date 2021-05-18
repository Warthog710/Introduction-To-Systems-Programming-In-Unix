#include "struct.h"

void sort (Questions_T questionList[], int count)
{
    Questions_T temp;
    int index, element;

    for (index = 0; index < count; index++)
    {
        for (element = 0; element < (count - index); element++)
        {
            if (questionList[element].questionNumber > questionList[element + 1].questionNumber)
            {
                /*Swap*/
                temp = questionList[element];
                questionList[element] = questionList[element + 1];
                questionList[element + 1] = temp;
            }
        }
    }   
}