#include <iostream>
#include <string>
#include <algorithm>

int main()
{
  std::string str;
  std::cin >> str;
  reverse(str.begin(), str.end());
  std::cout << str;

  return 0;
}
