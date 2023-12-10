// 树结构基本操作的演示
// 22050612赵际磊
// 2023年11月

#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926
#define HS 100000
int main()
{
  double t0 = 0.6311; // T/s
  double t1 = 0.8882;
  double t2 = 1.333;
  double t3 = 1.909;

  double m1 = 357.20; // m/g
  double m2 = 671.98;
  double m3 = 134.77;

  double d = 99.48; // l/mm
  double d1 = 94.14;
  double d2 = 99.00;
  double L = 611.0;

  double i1, i0, i2, i3, i_1, i_2, i_3;

  i_1 = 0.125 * m1 * pow(d, 2) / HS;
  double k; // the first!

  double con = 4 * pi * pi;

  k = con * i_1 / (t1 * t1 - t0 * t0);
  cout << "k: " << k << endl;

  i0 = k * t0 * t0 / con;
  cout << i0 << endl;

  i1 = k * pow(t1, 2) / con - i0;
  cout << "i1'= " << i_1 << "   i1=  " << i1 << endl;
  cout << "error%= " << abs(i1 - i_1) / i_1 << endl;

  i_2 = 0.125 * m2 * (pow(d1, 2) + pow(d2, 2)) / HS;
  i2 = k * pow(t2, 2) / con - i0;
  cout << "i2'= " << i_2 << "   i2=  " << i2 << endl;
  cout << "error%= " << abs(i2 - i_2) / i_2 << endl;

  double ij = 0.232;
  i_3 = m3 * pow(L, 2) / HS / 12;
  i3 = k * pow(t3, 2) / con - ij;
  cout << "i3'= " << i_3 << "   i3=  " << i3 << endl;
  cout << "error%= " << abs(i3 - i_3) / i_3 << endl;
  cout << endl;

  system("pause");
}