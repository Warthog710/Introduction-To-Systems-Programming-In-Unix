#include <stdio.h>
#include "struct.h"

int readQuestions(Questions_T questionList[], int count)
{
    int index, number;

    FILE* ptr = fopen("/gaia/class/student/srivatss/IPC/ngbee/questionbank.txt", "r");

    /*If the file could not be opened.*/
    if(ptr == NULL)
    {
        printf("The file could not be opened...\n");
        return -1;
    }    
    else
    {
        for (index = 0; index < count; index++)
        {
            for (number = 0; number < 6; number++)
            {
                switch (number)
                {
                    case 0:
                        fgets(questionList[index].q, sizeof(questionList[index].q), ptr );
                        break;

                    case 1:
                        fgets(questionList[index].c1, sizeof(questionList[index].c1), ptr );
                        break;

                    case 2:
                        fgets(questionList[index].c2, sizeof(questionList[index].c2), ptr );
                        break;

                    case 3:
                        fgets(questionList[index].c3, sizeof(questionList[index].c3), ptr );
                        break;

                    case 4:
                        fgets(questionList[index].c4, sizeof(questionList[index].c4), ptr );
                        break;

                    case 5:
                        fgets(questionList[index].answer, sizeof(questionList[index].answer), ptr );
                        break;

                    default:
                        break;
                }
                questionList[index].questionNumber = index + 1;
                
                /*If at EOF, not enough questions in the file.*/
                if(feof(ptr))
                {
                    printf("The file does not contain enough questions...\n");
                    return -1;
                }
            }
        } 
        fclose(ptr);       
        return index;
    } 
}
