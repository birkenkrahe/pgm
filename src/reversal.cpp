#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;




int main() {
string str;
cin >> str;
reverse(str.begin(), str.end());
cout << str;
return 0;
}
