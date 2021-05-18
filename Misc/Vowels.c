#include <stdio.h>

int main (void)
{
  char temp;
  int a = 0, e = 0, i = 0, o = 0 , u = 0;

  printf("Please enter a sentence and hit <enter>\n");

  /*Breaks on \n character*/
  while(1)
  {
    temp = getchar();

    /*Checking for all vowels. Both upper and lower case*/
    switch(temp)
    {
      case 'A':
      case 'a':
          a++;
          break;
      case 'E':
      case 'e':
          e++;
          break;
      case 'I':
      case 'i':
          i++;
          break;
      case 'O':
      case 'o':
          o++;
          break;
      case 'U':
      case 'u':
          u++;
          break;
      default:
          break;
    }

    /*If \n, break*/
    if (temp == '\n')
    {
          break;
    }
  }

  /*If all vowels are greater than 0*/
  if ( a != 0 && e != 0 && i != 0 && o != 0 && u != 0 && u != 0)
  {
    printf("Good string\n");
  }
  else
  {
    printf("Bad string\n");
  }
}