#include <stdio.h>
#include <string.h>

/*Task 1*/
typedef struct _user
{
    char name[14];
    int age;
} user;

int main()
{
    int count;

    /*Task 2*/
    printf("Task 2: Printing the size of the structure.\n\n");
    printf("The size of the structure is %ld.\n\n", sizeof(user));

    /*Task 3*/
    user data[3];

    /*Task 4*/
    for (count = 0; count < sizeof(data)/sizeof(data[0]); count++)
    {
        switch (count)
        {
        case 0:
            strcpy(data[count].name, "John");
            data[count].age = 20;
            break;
        case 1:
            strcpy(data[count].name, "Jack");
            data[count].age = 33;
            break;
        case 2:
            strcpy(data[count].name, "Sam");
            data[count].age = 25;
            break;
        default:
            break;  
        }           
    }

    /*Task 5*/
    user *ptr = data;

    /*Task 6*/
    printf("Task 6: Printing all cell values in data using the dot operator.\n\n");
    for (count = 0; count < sizeof(data)/sizeof(data[0]); count++)
    {
        printf("The name is %s, and the age is %d.\n", (*(ptr + count)).name, (*(ptr + count)).age);
    }
    printf("\n");

    /*Task 7*/
    ptr++;

    /*Task 8*/
    printf("Task 8: Print the name and age of the second cell.\n\n");
    printf("The name is %s, and the age is %d.\n\n", (*ptr).name, (*ptr).age);

    /*Task 9*/
    ptr--;

    printf("Task 9: Print all cell values in data using the -> operator.\n\n");
    for (count = 0; count < sizeof(data)/sizeof(data[0]); count++)
    {
        printf("The name is %s, and the age is %d.\n", (ptr + count)->name, (ptr + count)->age);
    }
    printf("\n");

    /*Task 10*/
    printf("Task 10: Print the size of the data array.\n\n");
    printf("The size of data is %ld.\n", sizeof(data));  
}