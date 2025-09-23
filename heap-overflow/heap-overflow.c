#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct data
{
  char name[64];
  int role;
};

void enter_name(struct data *, const char *);

int main(int argc, char **argv)
{
  char buf[101];

  printf("Enter a string: ");
  fgets(buf, 100, stdin);
  buf[strcspn(buf, "\n")] = 0;

  struct data *d;
  d = (struct data *)malloc(sizeof(struct data));

  enter_name(d, buf);

  printf("Role is %d.\n", d->role);
  if (d->role == 0)
    {
      printf("Hello %s, you have been granted admin status.\n", d->name);
    }
  else
    {
      printf("Hello %s, you are an ordinary user.\n", d->name);
    }
}

void enter_name(struct data *d, const char *src)
{
  // use 1 for ordinary users, 0 for admin
  d->role = 1;
  memset(d->name, 0, 64);
  strcpy(d->name, src);
}
