#include<bits/stdc++.h>
using namespace std;
struct food{
    int cat;
    int java;
    double eff;
};
bool cmp(struct food p,struct food q)
{
    if(p.eff==q.eff)
        return p.cat<q.cat;
    return p.eff>q.eff;
}
 
int main()
{
    struct food food[1005];
    int i,p,j,x,f,q;
    double y;
    while(scanf("%d%d",&j,&f)!=EOF)
    {
        if(j==-1&&f==-1)
            break;
        for(i=0;i<=1004;i++)
        {
            food[i].cat=0;
            food[i].java=0;
            food[i].eff=0;
        }
        for(i=0;i<f;i++)
        {
            scanf("%d",&food[i].java);
            scanf("%d",&food[i].cat);
            food[i].eff=(double)food[i].java/food[i].cat;
        }
        sort(food,food+f,cmp);
        y=0;
        for(i=0;i<f;i++)
        {
            j-=food[i].cat;
            if(j>=0)
                y+=food[i].java;
            else
            {
                j+=food[i].cat;
                y+=food[i].eff*j;
                break;
            }
        }
        printf("%.3lf\n",y);
    }
    return 0;
}