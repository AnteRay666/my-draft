#include<bits/stdc++.h>
using namespace std;
int main(){
    bool f[300][300];
    string a[300];

    for(int i = 1; i <= 234; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= 234; i++)
    {
        for(int j = 1; j <= 234; j++){
            if(a[i] == a[j]) f[i][j] = 1;
            else f[i][j] = 0;
        }

        for(int j = 235; j <= 252; j++){
            f[i][j] = 1;
        }
    }

    for(int i = 235; i <= 252; i++){
        for(int j = 1; j <= 252; j++){
            f[i][j] = 1;
        }
    }
    int i = 1;
    int j = 1;
    cout << "[";
    cout << f[i][j];
    for(j = 2; j <= 252; j++){
        cout << "," << f[i][j];
    }
    cout << "]" << endl;
    for(i = 2; i <= 252; i++){
        int j = 1;
        cout << ",[";
        cout << f[i][j];
        for(j = 2; j <= 252; j++){
            cout << "," << f[i][j];
        }
        cout << "]" << endl;
    }
    system("pause");
    return 0;
}