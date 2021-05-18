#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

/*Function Prototypes*/
int newLines(FILE*);
void genRandomQuestions(int, int*);

int main()
{ 
    int randomQuestions[SIZE], numCorrect = 0, count, line, numLines;
    char correctAnswer, userAnswer;
    char buffer[200];

    /*Open file*/
    FILE* questionBank = fopen("/gaia/class/student/srivatss/IPC/ngbee/questionbank.txt", "r");

    /*Verifying file opened correctly*/
    if (questionBank != NULL)
    {
        numLines = newLines(questionBank);
    }
    else
    {
        printf("Invalid file location, Exiting program.\n");
        exit(0);
    }

    /*Verifying the number of questions is >= #questions in the bank*/
    if ((numLines / 6) < SIZE)
    {
       printf("The question bank does not contain enough questions. Exiting program.\n"); 
       exit(0);
    }

    /*Generate random questions to be asked*/
    genRandomQuestions(numLines, randomQuestions);

    /*Ask the user the question*/
    for (count = 0; count < SIZE; count++)
    {
        rewind(questionBank);

        /*Move pointer to question location*/
        for (line = 0; line < randomQuestions[count]; line++)
        {
            fgets(buffer, sizeof(buffer), questionBank);
        }

        /*Print question and choices*/
        for (line = 0; line < 5; line++)
        {
            fgets(buffer, sizeof(buffer), questionBank);
            printf("%s\n", buffer);
        }

        /*Record the correct answer*/
        fgets(buffer, sizeof(buffer), questionBank);
        correctAnswer = buffer[0];

        /*Ask user to enter their answer*/
        printf("Your answer: ");
        scanf(" %c", &userAnswer);

        /*Tell user if they were correct*/
        if (userAnswer == correctAnswer)
        {
            printf("You answered correctly!\n\n");
            numCorrect++;
        }    
        else
        {
            printf("You answered incorrectly.\n\n");
        }          
    }

    /*Give user final score*/
    printf("You answered %d out of %d correctly.\n", numCorrect, SIZE);

    /*Close file*/
    fclose(questionBank);
}

/*Count the number of lines in the file*/
int newLines(FILE* questionBank)
{
    char buffer[200];
    int numLines = 0;

    while (!feof(questionBank))
    {
        fgets(buffer, sizeof(buffer), questionBank);
        numLines++;
    } 

    /*Number of lines/questions will always be divisible by 6*/
    return numLines - (numLines % 6);
}

/*Generate the line locations of 5 distinct questions*/
void genRandomQuestions(int numLines, int* randomQuestions)
{
    srand(time(NULL));

    int pQuestion = numLines / 6, random, location = 0, count, index;

    char isDupe = 0;

    /*Iterate until randomQuestion is full*/
    for (count = 0; count < SIZE; count++)
    {
        /*Check for duplicates*/
        while(1)
        {
            isDupe = 0;
            random = (rand() % pQuestion) * 6;

            for (index = 0; index < count; index++)
            {
                if(*(randomQuestions + index) == random)
                {
                    isDupe = 1;
                    break;
                }            
            }

            if (isDupe == 1)
            {
                continue;
            }
            else
            {
                break;
            }            
        }
        /*Set the line number*/        
        *(randomQuestions + count) = random;
    }    
}
