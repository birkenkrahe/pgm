#include <iostream>
#include <string>

int main()
{
  std::string str = "Hello";
  for (int i = str.length()-1; i == 0; i--)
    std::cout << str[i];

  return 0;
}
