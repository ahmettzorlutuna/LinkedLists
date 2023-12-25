#include <iostream>
using namespace std;

int sayi = 10;

int *adresi = &sayi;

int deger = *adresi;

int dizi[] = {1, 2, 3, 4, 5};
int *pDizi = dizi;


int main() {
  cout << dizi;
  return 0;
}