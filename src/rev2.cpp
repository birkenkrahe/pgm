#include <iostream>

int main()
{
  char *str = nullptr;
  std::cin >> str;
  int size = sizeof(str);
  for (int i = size-2; i >= 0; i--)

    std::cout << str[i];

  return 0;
}
