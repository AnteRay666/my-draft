#include <bits/stdc++.h>
using namespace std;
int main()
{
  double a[10];
  double sum = 0, avg;
  // 922.315 898.476 904.866 893.225
  for (int i = 0; i < 4; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  avg = sum / 4;

  cout << sum << endl; // 3618.88
  cout << avg << endl; // 904.721
  double u[10];
  double ua = 0;

  for (int i = 0; i < 4; i++)
  {
    u[i] = pow((a[i] - avg), 2);
    ua += u[i];
  }
  double ans;
  ans = sqrt(ua / (4 * (4 - 1)));
  cout << ans << endl; // 6.32935

  double ud = 0.005;
  double ub, um, un;
  cin >> um >> un; // 6.750 5.890

  ub = (ud * sqrt(4 * um * um + 4 * un * un)) / (4 * 5 * 0.0005983);

  cout << ub << endl; // 7.48662

  double ur;
  ur = sqrt(ans * ans + ub * ub);
  cout << ur << endl; // 9.80358

  double er;
  er = ur / avg;
  cout << er << endl; // 0.010836

  system("pause");
}