#include <iostream>
#include "ContactInfo.h"          // you will rename this later
using namespace std;

int main() {
  ContactInfo entry("Kristen Lee", "555-2021");
  cout << "Name: " << entry.getName() << "\n"
       << "Phone Number: " << entry.getPhoneNumber() << "\n";
  return 0;
}
