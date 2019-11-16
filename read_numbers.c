#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_numbers.h"

char *read_per_unit(char c)
{
  char *read_unit = malloc(7 * sizeof(char));
  char string[10][7] = {"Khong ", "Mot ", "Hai ", "Ba ", "Bon ", "Nam ", "Sau ", "Bay ", "Tam ", "Chin "};

  switch(c)
  {
    case '1':
    {
      strcpy(read_unit, string[1]);
      break;
    }
    case '2':
    {
      strcpy(read_unit, string[2]);
      break;
    }
    case '3':
    {
      strcpy(read_unit, string[3]);
      break;
    }
    case '4':
    {
      strcpy(read_unit, string[4]);
      break;
    }
    case '5':
    {
      strcpy(read_unit, string[5]);
      break;
    }
    case '6':
    {
      strcpy(read_unit, string[6]);
      break;
    }
    case '7':
    {
      strcpy(read_unit, string[7]);
      break;
    }
    case '8':
    {
      strcpy(read_unit, string[8]);
      break;
    }
    case '9':
    {
      strcpy(read_unit, string[9]);
      break;
    }
    case '0':
    {
      strcpy(read_unit, string[0]);
      break;
    }
  }

  return read_unit;
}

char *read_hundreds(char a[], int mod)
{
  char *str = malloc(50 * sizeof(char));
  char read_tram[] = "Tram ";

  if(mod == 0)
  {
    if(a[0] != '0')
    {
      strcat(str, read_per_unit(a[0]));
      strcat(str, read_tram);
    }
  }
  else if(mod == 1)
  {
    if(a[2] != '0' || a[1] != '0' || a[0] != '0')
    {
      strcat(str, read_per_unit(a[0]));
      strcat(str, read_tram);
    }
  }

  if(a[1] == '0')
  {
    if(a[2] != '0' && a[0] != '0' || a[2] != '0' && mod == 1)
    {
      char read_le[] = "Le ";
      strcat(str, read_le);
    }
  }
  else if(a[1] == '1')
  {
    char read_1[] = "Muoi ";
    strcat(str, read_1);
  }
  else
  {
    char read_muoi[] = "Muoi ";
    strcat(str, read_per_unit(a[1]));
    strcat(str, read_muoi);
  }

  if(a[2] == '5')
  {
    char read_lam[] = "Lam ";
    if(a[1] != '0')
    {
      strcat(str, read_lam);
    }
    else
    {
      strcat(str, read_per_unit(a[2]));
    }
  }
  else if(a[2] != '0')
  {
    strcat(str, read_per_unit(a[2]));
  }

  return str;
}

void split_string(char s[], char k[], int a, int b)
{
  int count = 0;

  for(int i = a; i <= b; i++)
  {
    k[count] = s[i];
    count++;
  }

  k[count] = '\0';
}

char *read(char s[])
{
  int n = strlen(s) - 1;
  char *str = malloc(300 * sizeof(char));
  char temp[300] = "\0", blank[300] = "\0";

  padding_0(s, temp, n);

  int m = strlen(temp);
  int loop = (m / 3);
  int a = 0, b = 2, k = loop;

  for(int i = 0; i < loop; i++)
  {
    if(i == 0)
    {
      split_string(temp, blank, a, b);
      strcat(str, read_hundreds(blank, 0));
    }
    else
    {
      split_string(temp, blank, a, b);
      strcat(str, read_hundreds(blank, 1));
    }

    if(i == loop - 1)
    {
      char read_dong[] = "Dong\n";
      strcat(str, read_dong);
    }
    else if(blank[0] != '0' || blank[1] != '0' || blank[2] != '0')
    {
      switch(k % 4)
      {
        case 0:
        {
          char read_ty[] = "Ty ";
          strcat(str, read_ty);
          break;
        }
        case 2:
        {
          char read_nghin[] = "Nghin ";
          strcat(str, read_nghin);
          break;
        }
        case 3:
        {
          char read_trieu[] = "Trieu ";
          strcat(str, read_trieu);
          break;
        }
      }
    }

    a += 3;
    b += 3;
    k--;
  }

  return str;
}

void padding_0(char s[], char temp[], int n)
{
  if (n % 3 == 0)
  {
    strcpy(temp, s);
  }
  else
  {
    for (int i = 0; i < (3 - (n % 3)); i++)
    {
      temp[i] = '0';
    }
    for (int k = 0; k < n; k++)
    {
      temp[k + (3 - (n % 3))] = s[k];
    }

    temp[n + (3 - (n % 3))] = '\0';
  }
}
