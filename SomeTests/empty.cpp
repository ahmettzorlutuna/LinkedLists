#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
  int x = 4;

  int *pX = &x;
  cout << &x;
  cout << pX;
  return 0;
}
