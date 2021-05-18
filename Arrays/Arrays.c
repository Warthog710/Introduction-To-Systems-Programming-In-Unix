/*Program written by Quinn Roemer on 10/3/2019 for CSC 60 at Sacramento State University*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    /*Problem 1 - Shuffle an existing array*/
    {
        printf("Problem 1 - Shuffle an Array Using rand()\n\n");

        unsigned char data[] = {4, 2, 9, 1, 3, 8, 5, 7, 6};

        unsigned char temp[sizeof(data)/sizeof(data[0])];

        int random, counter = 0;

        /*Set temp array to NULL (ASCII 0)*/
        for(int count = 0; count < (sizeof(temp)/sizeof(temp[0])); count++)
        {
            temp[count] = 0;
        }

        /*Continue to execute until broken out*/
        while(1)
        {
            random = rand() % (sizeof(data)/sizeof(data[0]));

            if(temp[random] != 0)
            {
                continue;
            }
            else
            {
                temp[random] = data[counter];
                counter++;
            }

            if(counter >= (sizeof(data)/sizeof(data[0])))
            {
                break;
            }                    
         }

         /*Copy temp into data and print*/
        for(int count = 0; count < (sizeof(data)/sizeof(data[0])); count++)
        {
            data[count] = temp[count];
            printf("%d ", data[count]);
        }
        printf("\n");
    }

    /*Problem 2 - Print if the values in an array are prime or not*/
    {
        printf("\nProblem 2- Print if the value in an array are prime or not\n\n");

        unsigned char data[] = {2, 11, 18, 23, 39, 32, 37, 47 };

        for(int count = 0; count < (sizeof(data)/sizeof(data[0])); count++)
        {
            if(data[count] == 1)
            {
                printf("%d is not prime!\n", data[count]);
                continue;
            }
            if(data[count] == 2)
            {
                printf("%d is prime!!!\n", data[count]);
                continue;
            }

            for(int index = data[count] - 1; index > 1; index--)
            {
                if(data[count] % index == 0)
                {
                    printf("%d is not prime.\n", data[count]);
                    break;
                }
                if(index == 2)
                {
                    printf("%d is prime!!!\n", data[count]);
                }
            }
        }
    }

    /*Problem 3 - Calculate the final grades of several students*/
    {
        printf("\nProblem 3 - Calculate the Final Grades of Several Students\n\n");

        float studentData[7][5] = { 
        {95.10, 80.00, 82.3, 94.2, 93.00},
        {97.80, 90.20, 72.7, 91.2, 83.00},
        {92.90, 83.90, 75.65, 83.2, 73.00},
        {82.10, 94.70, 79.91, 86.2, 88.00},
        {72.10, 44.40, 89.98, 96.2, 98.00},
        {92.10, 84.30, 79.92, 86.2, 88.00},
        {72.10, 86.60, 91.90, 89.2, 73.00}};

        float grade = 0;

        printf ( "------------------------------------- \n");  
        printf ( " HWs  Quiz  Mid-1 Mid-2 Final = Grade  \n");   
        printf ( "------------------------------------- \n");

        for(int count = 0; count < 7; count++)
        {
            for(int index = 0; index < 5; index++)
            {
                printf("%.2f ", studentData[count][index]);

                switch(index)
                {
                    case 0:
                    case 2:
                    case 3:
                        grade = grade + (studentData[count][index] * .2);
                        break;

                    case 1:
                        grade = grade + (studentData[count][index] * .1);
                        break;

                    case 4:
                        grade = grade + (studentData[count][index] * .3);
                        break;
                }             

            }
            printf("= %.2f\n", grade); 
            grade = 0;
        }
    }
}