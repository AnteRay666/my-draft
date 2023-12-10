#include<bits/stdc++.h>
using namespace std;
int main(){
    int c[300][50][10];
    memset(c,0x3f,sizeof(c));
    int i;
    while(cin >> i){
        string ch;
        cin >> ch;
        //硬卧
        if(ch == "硬卧"){
            string a;
            cin >> a;
            if(a == "上") {
                for(int j = 1; j <= 9; j++){
                    c[i][j][0] = min(c[i][j][0],2);
                    c[i][j][1] = min(c[i][j][1],INT_MAX);
                    c[i][j][2] = min(c[i][j][2],3);
                }
                for(int j = 10; j <= 42; j++){
                    c[i][j][0] = min(c[i][j][0],0);
                    c[i][j][1] = min(c[i][j][1],1);
                    c[i][j][2] = min(c[i][j][2],1);
                }
            }
            else if(a == "中"){
                for(int j = 1; j <= 9; j++){
                    c[i][j][0] = min(c[i][j][0],2);
                    c[i][j][1] = min(c[i][j][1],INT_MAX);
                    c[i][j][2] = min(c[i][j][2],3);
                }
                for(int j = 10; j <= 42; j++){
                    c[i][j][0] = min(c[i][j][0],1);
                    c[i][j][1] = min(c[i][j][1],0);
                    c[i][j][2] = min(c[i][j][2],1);
                }
            }
            else{
                for(int j = 1; j <= 9; j++){
                    c[i][j][0] = min(c[i][j][0],3);
                    c[i][j][1] = min(c[i][j][1],INT_MAX);
                    c[i][j][2] = min(c[i][j][2],2);
                }
                for(int j = 10; j <= 42; j++){
                    c[i][j][0] = min(c[i][j][0],1);
                    c[i][j][1] = min(c[i][j][1],1);
                    c[i][j][2] = min(c[i][j][2],0);
                } 
            }
        }
        //软卧
        else if(ch == "软卧"){
            string a;
            cin >> a;
            if(a == "上") {
                for(int j = 1; j <= 9; j++){
                    c[i][j][0] = min(c[i][j][0],0);
                    c[i][j][1] = min(c[i][j][1],INT_MAX);
                    c[i][j][2] = min(c[i][j][2],1);
                }
                for(int j = 10; j <= 42; j++){
                    c[i][j][0] = min(c[i][j][0],2);
                    c[i][j][1] = min(c[i][j][1],3);
                    c[i][j][2] = min(c[i][j][2],3);
                } 
            }else {
                for(int j = 1; j <= 9; j++){
                    c[i][j][0] = min(c[i][j][0],1);
                    c[i][j][1] = min(c[i][j][1],INT_MAX);
                    c[i][j][2] = min(c[i][j][2],0);
                }
                for(int j = 10; j <= 42; j++){
                    c[i][j][0] = min(c[i][j][0],3);
                    c[i][j][1] = min(c[i][j][1],3);
                    c[i][j][2] = min(c[i][j][2],2);
                } 
            }
        }else{
            for(int j = 1; j <= 9; j++){
                c[i][j][0] = min(c[i][j][0],0);
                c[i][j][1] = min(c[i][j][1],INT_MAX);
                c[i][j][2] = min(c[i][j][2],0);
            }
            for(int j = 10; j <= 42; j++){
                c[i][j][0] = min(c[i][j][0],0);
                c[i][j][1] = min(c[i][j][1],0);
                c[i][j][2] = min(c[i][j][2],0);
            }   
        }
        cin >> ch;
        if(ch=="是"){
            for(int j = 1; j <=42; j++){
                c[i][j][0] = 1061109567;
                c[i][j][1] = 1061109567;
            }
        }
        // cout << i << endl;
        // for(int j = 1; j <= 42; j++){
        //     for(int k = 0; k < 3; k++){
        //         cout << c[i][j][k] << " ";
        //     }
        //     cout << "|";
        // }
        // cout << endl;
    }
    for(int i = 235; i <= 252; i++){
        for(int j = 1; j <= 9; j++){
            c[i][j][1] = 0; 
        }
    }
    int ii = 1;
        cout << '[';
        int j = 1;
        cout << '[' ;
        int k = 0;
        cout << c[ii][j][k];
        for(k = 1; k < 3; k++){
            cout << "," << c[ii][j][k];
        }
        cout << "]";
        for(j = 2; j <= 42; j++){
            cout << ",[" ;
            int k = 0;
            cout << c[ii][j][k];
            for(k = 1; k < 3; k++){
                cout << "," << c[ii][j][k];
            }
            cout << "]";
        }
        cout << "]" << endl;
    for(int ii = 2; ii <= 252; ii++){
        cout << ",[";
        int j = 1;
        cout << '[' ;
        int k = 0;
        cout << c[ii][j][k];
        for(k = 1; k < 3; k++){
            cout << "," << c[ii][j][k];
        }
        cout << "]";
        for(j = 2; j <= 42; j++){
            cout << ",[" ;
            int k = 0;
            cout << c[ii][j][k];
            for(k = 1; k < 3; k++){
                cout << "," << c[ii][j][k];
            }
            cout << "]";
        }
        cout << "]" << endl;
    } 
    system("pause");
    return 0;
}
/*
*/