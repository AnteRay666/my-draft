#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926
#define HS 100000

int main()
{
  double t[5];
  t[0] = 2.183;
  t[1] = 2.809;
  t[2] = 3.616;
  t[3] = 4.525;
  t[4] = 5.460;
  double a[5];
  double b[5];
  double A[5];
  double i3 = 40.9929;
  double cir = pi * pi * 4;
  double ij = 0.232;
  double k = 446.588;
  double ic;
  double m = 240.64;
  double d1 = 35.10, d2 = 6.28, h = 33.11;
  ic = (m * (d1 * d1 + d2 * d2) / 16 + m * h * h / 12) / HS;
  cout << "ic=  " << ic << endl;
  for (int i = 0; i < 5; i++)
  {
    a[i] = (k * pow(t[i], 2) / cir - i3 - ij) / 2;
    b[i] = ic + m * pow((i + 1) * 5, 2) / 1000;
    A[i] = abs(a[i] - b[i]) / b[i];
  }

  for (int i = 0; i < 5; i++)
  {
    cout << "x=" << (i + 1) * 5 << endl;
    cout << "Is= " << a[i] << endl;
    cout << "i'= " << b[i] << endl;
    cout << "error%= " << A[i] * 100 << "%" << endl;
    cout << endl;
  }
  system("pause");
}