#include <iostream>

int main()
{
  char str[1000];
  int count=0;
  scanf("%s",str);
  std::cout << str;
  for (int i=0; i<1000;i++)
    {
      if (str[i] == '\0')
    {
      std::cout << "\n" << i;
      break;
    }
      count++;
    }
  std::cout << count << "\n";
  for (int i=count-1; i>=0; i--)
    std::cout << str[i];
  return 0;
}
