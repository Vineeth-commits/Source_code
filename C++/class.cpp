#include <iostream>
#include <string>
using namespace std;

class test1 {       // The class
  public:             // Access specifier
    float a;        // Attribute (int variable)
    int k;  // Attribute (string variable)
};

int main() {
  test1 ob1;  // Create an object of test1

  // Access attributes and set values
  ob1.a = 15.4;
  ob1.k = 7;

  // Print values
  cout << ob1.a << "\n"; 
  cout << ob1.k; 
  return 0;
}
