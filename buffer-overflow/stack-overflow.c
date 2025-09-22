#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_function(const char *);

void win()
{
  printf("You win!\n");
  exit(0);
}

int main(int argc, char **argv)
{
  char buf[101];

  printf("Enter a string: ");
  fgets(buf, 100, stdin);

  my_function(buf);

  printf("Exiting normally\n");
}

void my_function(const char *src)
{
  int var1 = 1;
  // int var2 = 2;
  // int var3 = 3;
  // int var4 = 4;
  char copy[4];
  strcpy(copy, src);
}
