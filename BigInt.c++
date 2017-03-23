#include <iostream>

#include "BigInt.h"

using namespace std;


int main()
{

  BigInt a = BigInt("1234",10);
  BigInt b;
  b.setStringValue((char*)"12345",10);
  BigInt c;

  c = a + b;

  cout << c.getStringValue(10) << endl;

  return 0;
}











