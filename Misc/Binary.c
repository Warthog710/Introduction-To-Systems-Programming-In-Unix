#include <stdio.h>

int main (void)
{
  unsigned char ch, result;
  int num;

  /*Reading into an int*/
  printf("Please enter a number between 0 and 255\n");
  scanf("%d", &num);

  /*Assigning an usigned char to the int value*/
  ch = num;

  /*Converting number into binary*/
  result = ch % 128;
  printf("\n%d ", ch / 128);
  ch = result;

  result = ch % 64;
  printf("%d ", ch / 64);
  ch = result;

  result = ch % 32;
  printf("%d ", ch / 32);
  ch = result;

  result = ch % 16;
  printf("%d ", ch / 16);
  ch = result;

  result = ch % 8;
  printf("%d ", ch / 8);
  ch = result;

  result = ch % 4;
  printf("%d ", ch / 4);
  ch = result;

  result = ch % 2;
  printf("%d ", ch / 2);
  ch = result;

  result = ch % 1;
  printf("%d\n", ch / 1);
  ch = result;
}
