#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_function(const char *);

int main(int argc, char **argv)
{
  char buf[1000];

  printf("Enter a string: ");
  fgets(buf, 999, stdin);

  my_function(buf);

  printf("Exiting normally\n");
}

void my_function(const char *src)
{
  char copy[500];
  strcpy(copy, src);
}
