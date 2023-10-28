#include <bits/stdc++.h>
using namespace  std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<int>a(n);
  vector<int>b(n);
  for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
 for(int i=0;i<n;i++)
    {
    cin>>b[i];
    }
// vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

// for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= m; j++) {
//         if (a[i-1] <= j) {
//             dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i-1]] + b[i-1]);
//         } else {
//             dp[i][j] = dp[i-1][j];
//         }
//     }
// }

// cout << dp[n][m] << endl;

return 0;


}