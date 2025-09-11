#include <iostream>
#include <cstring>

int main()
{
  char str[1000];
  std::cin >> str;
  int size = strlen(str);
  for (int i = size-1; i >= 0; i--)
    std::cout << str[i];
  return 0;
}
