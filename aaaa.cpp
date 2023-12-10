#include <bits/stdc++.h>
using namespace std;
double cal(string &a, string &b, double &cost)
{
  double fee;
  int sum;
  if (stoi(a.substr(0, 2)) > stoi(b.substr(0, 2)))
  {
    sum = 60 * (stoi(b.substr(0, 2)) + 24 - stoi(a.substr(0, 2))) + stoi(b.substr(3, 2)) - stoi(a.substr(3, 2));
    // cout << sum << endl;
    fee = sum * cost;
  }
  else if (stoi(a.substr(0, 2)) == stoi(b.substr(0, 2)))
  {
    if (stoi(a.substr(3, 2)) < stoi(b.substr(3, 2)))
      sum = stoi(b.substr(3, 2)) - stoi(a.substr(3, 2));
    else if (stoi(b.substr(3, 2)) == stoi(a.substr(3, 2)))
      sum = 24 * 60;
    else
      sum = 24 * 60 - (stoi(a.substr(3, 2)) - stoi(b.substr(3, 2)));
    fee = sum * cost;
  }
  else
  {
    sum = 60 * (stoi(b.substr(0, 2)) - stoi(a.substr(0, 2))) + stoi(b.substr(3, 2)) - stoi(a.substr(3, 2));
    // cout << sum << endl;
    fee = sum * cost;
  }
  return fee;
}
bool checktime(string &time)
{
  int hh = stoi(time.substr(0, 2));
  int mm = stoi(time.substr(3, 2));
  int flag = 0;
  if (hh >= 0 && hh <= 23 && mm >= 0 && mm <= 59)
    flag = 1;
  if (!flag)
  {

    return 1;
  }
  return 0;
}
int main()
{
  string a;
  string b;
  double cost = 1;
  double c;
  while (cin >> a)
  {
    while (checktime(a))
    {
      cout << "Error! Please enter the time again." << endl;
      cin >> a;
    }
    cin >> b;
    while (checktime(b))
    {
      cout << "Error! Please enter the time again." << endl;
      cin >> b;
    }
    cout << "test data" << endl;
    cout << a.substr(0, 2) << endl;
    cout << stoi(a.substr(0, 2)) << endl;
    cout << stoi(b.substr(0, 2)) << endl;
    cout << stoi(a.substr(3, 2)) << endl;
    cout << stoi(b.substr(3, 2)) << endl;
    cout << "sum ="
         << "60 *"
         << "(" << stoi(b.substr(0, 2)) << " - " << stoi(a.substr(0, 2)) << ")"
         << "+" << stoi(b.substr(3, 2)) << "-" << stoi(a.substr(3, 2)) << endl;

    c = cal(a, b, cost);
    cout << c << endl;
  }
  system("pause");
}