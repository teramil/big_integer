#include <iostream>

#include "BigInt.h"

using namespace std;


int main()
{

	BigInt a = BigInt("abcd1234",16);   // base = 16
  BigInt b = "12345";                 // base = 10
  BigInt c;

  c = a + b;

  //cout << c << endl;

	return 0;
}











