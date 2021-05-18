#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
char str1 [ 256 ] = "My Sweat Dream at 1600 Pennsylvania Ave Washington, DC 20500";
char str2 [] = "eat";

/*Question 1: How would you find if str2 is present in str1, useing the strstr() function?*/
{
    printf("Question 1: How would you find if str2 is present in str1, using the strstr() function?\n\n");

    printf("The strstr() works by accepting a search string and a search term. It then returns a pointer to the first");
    printf(" occurence of the search term in the search string. It returns a NULL pointer if it was not found.\n\n");

    char* ptr = strstr(str1, str2);

    if (ptr != NULL)
    {
        printf("The string was found at address: %p\n", ptr);
    }
    else
    {
        printf("The string was NOT found.\n");
    } 
}

/*Question 2: Count the letters only in str1 without using strlen function. 
Verify your value with the strlen function and print if it matches or not.*/
{
    int strSizeOne = 0, strSizeTwo = 0;

    printf("\nQuestion 2: Count the letters only in str1 without using strlen function.");
    printf("Verify your value with the strlen function and print if it matches or not.\n\n");

    for (int count = 0; count < 256; count++)
    {
        if(str1[count] != '\0')
        {
            strSizeOne++;
        }
        else
        {
            break;
        }        
    }

    strSizeTwo = strlen(str1);

    if(strSizeOne == strSizeTwo)
    {
        printf("Without strlen(): %d With strlen(): %d\n", strSizeOne, strSizeTwo);
        printf("They are equal.\n");
    }
    else
    {
        printf("Without strlen(): %d With strlen(): %d\n", strSizeOne, strSizeTwo);
        printf("They are NOT equal.\n");
    }  
}

/*Ask the user for a string and store it in str4. Use the pointer ptr4 only.
Write a program to check if str4 contains all the letters of the alphabet. 
The alphabet letters should appear at least once.*/
{
    printf("\nQuestion 3: Ask the user to enter a string. Verify that all the letters of the ");
    printf(" alphabet are contained in the string.\n\n");

    char str4[64];
    char* ptr4 = str4;

    printf("Please enter a string:\n");
    scanf("%s", str4);

    unsigned int temp = 0;

    for (int count = 0; count < 64; count++)
    {
        if(isalpha(*(ptr4 + count)))
        {
            /*printf("%c ", str4[count]);*/
            /*printf("%d\n", 90 - toupper(*(ptr4 + count)));*/
            temp = temp | (1 << 90 - toupper(*(ptr4 + count)));
        }
        else if(*(ptr4 + count) == '\0')
        {
            break;
        }    
        else
        {
            continue;
        }            
    }

    if(temp == 67108863)
    {
        printf("All letters in the alphabet were entered!!!\n");
    }
    else
    {
        printf("Missing letters from the alphabet.\n");
    } 
}

/*Question 4: Describe what this program is doing.*/
{
    printf("\nQuestion 4: Describe what this program is doing.\n\n");
    printf("This program is attempting to find if a string contained in address2 can be found in address1.");
    printf(" However, it will never print anything because j and i will never equal the strlen(). ");
    printf("If you put -1 in the if statements it would begin to work.\n\n");
}

/*Question 5: What is the problem with this program?*/
{
    printf("Question 5: What is the problem with this program? It is supposed to reverse a string.\n\n");
    printf("This program is reversing the string twice. Therefore, the string prints in its original form. "); 
    printf("If you were to divide len by 2 you would find that this algorithm now works.\n");
}
}
