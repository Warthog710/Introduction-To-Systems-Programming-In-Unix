#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> 
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
    char email[100];
    int number = 0, numCorrect = 0, index, status;
    pid_t pid;

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

        /*Ask the user if they want an email*/
        printf("\nWould you like to be sent an email with your answers and final score?\n");
        printf("(enter 1 for yes and 0 for no)\n");
        scanf("%d", &index);

        if (index != 1)
        {
            printf("\nGoodbye\n");
            exit(0);
        }

        pid = fork();

        /*Child process*/
        if (pid == 0)
        {
            FILE* ptr = fopen("scores.txt", "w");

            /*If the file is not created. Exit with status 1.*/
            if (ptr == NULL)
            {
                exit(1);
            }

            /*Print score to scores.txt*/
            for (index = 0; index < NUM_ASK; index++)
            {
                fprintf(ptr, "%s\n", questionList[index].q);
                fprintf(ptr, "%s\n", questionList[index].c1);
                fprintf(ptr, "%s\n", questionList[index].c2);
                fprintf(ptr, "%s\n", questionList[index].c3);
                fprintf(ptr, "%s\n", questionList[index].c4);
            

                if (strchr(questionList[index].answer, questionList[index].response))
                {
                    fprintf(ptr, "You answered %c. This was correct.\n\n", questionList[index].response);
                    numCorrect++;
                }
                else
                {
                    fprintf(ptr, "You answered %c. This was incorrect. The correct answer was %s\n", questionList[index].response, questionList[index].answer);
                }               
            }
            fprintf(ptr, "You scored %d/%d.\n", numCorrect, NUM_ASK);

	    fclose(ptr);

            printf("\nPlease enter your email adress:\n");
            scanf("%s", email);

            /*Use muttmail.sh to send the email*/
            execlp("muttmail.sh", "", email, "scores.txt", "See the attached file for your scores.", (char*) NULL);     
            exit(0);
        }       
        /*Parent process*/
        else
        {
            wait(&status);

            /*If status other than 0, an error occured.*/
            if (WEXITSTATUS(status))
            {
                printf("\nAn error occured... The email was not sent.\n");
            }
            else
            {
                printf("\nYour email has been sent. If you do not receive your email, please verify that you entered the correct email.\n");            
            }
        }      
    }
}
