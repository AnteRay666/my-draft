#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926
int main()
{
  double a, b, c, d;
  int con = 0;
  double B;
  double B0;
  double vh;
  double kh = 167;
  double N = 108.9;

  B0 = 4 * pi * 0.0000001 * N * 100 * 0.5;
  cout << "B0= " << B0 * 1000 << " (10-3T)" << endl;
  /*1.35 1.09 1.12 1.36
  1.84 1.59 1.62 1.86
  2.14 1.87 1.87 2.14
  2.27 1.99 2.01 2.25
  2.33 2.04 2.06 2.31
  2.44 2.16 2.17 2.42
  2.44 2.16 2.18 2.42
  2.41 2.12 2.14 2.38
  2.43 2.15 2.16 2.42
  2.47 2.19 2.20 2.46
  2.46 2.17 2.19 2.44
  2.43 2.16 2.17 2.42
  2.31 2.03 2.04 2.29
  2.23 1.95 1.96 2.22
  2.09 1.82 1.84 2.08
  1.80 1.52 1.51 1.79
  1.33 1.02 1.04 1.32*/
  while (cin >> a >> b >> c >> d)
  {
    if (a == 0)
      break;

    // cout << a << " " << b << " " << c << " " << d << endl;
    vh = (a + b + c + d) / 4;
    cout << "Vh= " << vh << endl;
    B = vh / kh / 2.00;
    cout << "B= " << B * 1000 << " (10-3T)" << endl;

    con++;
    if (con == 5)
    {
      cout << "Nest! " << endl;
      con = 0;
    }
  }
  system("pause");
}