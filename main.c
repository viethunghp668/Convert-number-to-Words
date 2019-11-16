#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_numbers.h"

int main()
{
  char s[100] = "\0";
  printf("Nhap vao so can doc:\n");
  fgets(s, 100, stdin);
  printf("%s", read(s));

  return 0;
}
