#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
  char name[64];
};

struct fp
{
  void (*fp)(char*);
};

void win(char* name)
{
  printf("Hey, %s. You win!", name);
  exit(0);
}

void normal(char* name)
{
  printf("Hello, %s. This is a normal exit.", name);
  exit(0);
}

void enter_name(struct data *, const char *);

int main(int argc, char **argv)
{
  char buf[101];
  struct data *d;
  struct fp *f;


  printf("Enter a string: ");
  fgets(buf, 100, stdin);

  d = (struct data *)malloc(sizeof(struct data));
  f = (struct fp *)malloc(sizeof(struct fp));

  // setup the function pointer
  f->fp = normal;

  // get the name of the user
  enter_name(d, buf);

  // call the function
  f->fp(buf);
}

void enter_name(struct data *d, const char *src)
{
  strcpy(d->name, src);
}
