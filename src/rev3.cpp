#include <iostream>

int main()
{
  char str[1000];
  for (int i=0; i<1000; i++)
    {
      scanf("%c",&str[i]);
      printf("%c ", str[i]);
    }
  return 0;
}
