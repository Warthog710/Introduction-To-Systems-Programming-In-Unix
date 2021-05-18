#include <stdio.h>

int main()
{
    float studentData[7][5] = { 
        {95.10, 80.00, 82.3, 94.2, 93.00},
        {97.80, 90.20, 72.7, 91.2, 83.00},
        {92.90, 83.90, 75.65, 83.2, 73.00},
        {82.10, 94.70, 79.91, 86.2, 88.00},
        {72.10, 44.40, 89.98, 96.2, 98.00},
        {92.10, 84.30, 79.92, 86.2, 88.00},
        {72.10, 86.60, 91.90, 89.2, 73.00}};

        float grade = 0;

        /*Casting to a float pointer*/
        float* ptr = (float*) studentData;

        /*Traversing using pointer arithmetic*/
        printf("Traversing using pointer arithmetic:\n\n");
        printf ( "------------------------------------- \n");  
        printf ( " HWs  Quiz  Mid-1 Mid-2 Final = Grade  \n");   
        printf ( "------------------------------------- \n");

        for (int count = 0; count < 7; count++)
        {    
            for (int index = 0; index < 5; index++)
            {          
                printf("%5.2f ", *ptr);
                switch (index)
                {
                    case 0:
                    case 2:
                    case 3:
                        grade = grade + (*ptr * .2);
                        break;

                    case 1:
                        grade = grade + (*ptr * .1);
                        break;

                    case 4:
                        grade = grade + (*ptr * .3);
                        break;
                
                }
                ptr++;
            }
            printf("= %5.2f\n", grade);
            grade = 0;           
        }

        /*Reset pointer*/
        ptr = (float*) studentData;

        /*Printer array using pointer offset*/
        printf("\n\nTraversing using pointer offset:\n\n");
        printf ( "------------------------------------- \n");  
        printf ( " HWs  Quiz  Mid-1 Mid-2 Final = Grade  \n");   
        printf ( "------------------------------------- \n");

        for (int count = 0; count < 7; count++)
        {
            for (int index = 0; index < 5; index++)
            {
                printf("%5.2f ", *((ptr + count * 5) + index));

                switch (index)
                {
                    case 0:
                    case 2:
                    case 3:
                        grade = grade + (*((ptr + count * 5) + index) * .2);
                        break;

                    case 1:
                        grade = grade + (*((ptr + count * 5) + index) * .1);
                        break;

                    case 4:
                        grade = grade + (*((ptr + count * 5) + index) * .3);
                        break;                
                } 
            }
            printf("= %5.2f\n", grade);
            grade = 0;             
        }    
}