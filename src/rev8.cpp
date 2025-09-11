#include <iostream>
#include <ranges>

int main()
{
  std::string str;
  std::cin >> str;

  for (char c : str | std::views::reverse)
    std::cout << c;
    
  return 0;
}
