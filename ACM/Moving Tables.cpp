
#include <bits/stdc++.h>
using namespace std;
int a[205];
int main(){
    int T,begin,end;
     cin>>T;
     while(T--)
      {
         memset(a,0,sizeof(a)); 
         int n;
        cin>>n;
        for(int i=1;i<=n;i++){
             cin>>begin>>end;
             if(end<begin)
                 swap(begin,end);
             for(int j=(begin+1)/2;j<=(end+1)/2;j++)             
                 a[j]+=10;
        }
         int min_time=0;
        for(int i=1;i<=200;i++)
         min_time=max(min_time,a[i]);
        cout<<min_time<<endl;
      }
    return 0;
}