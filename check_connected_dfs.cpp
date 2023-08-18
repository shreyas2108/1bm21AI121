#include <iostream>

using namespace std;
int a[10][10],n,vis[10];
int dfs(int);


int main()
{
 int i,j,src;
 cout<<"enter the number of nodes:";
 cin>>n;
 cout<<"enter the adjacency matrix\n";
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<n;j++)
     {
         cin>>a[i][j];
     }
 }
 cout<<"enter the source node:";
 cin>>src;
 int ans=dfs(src);
 ans=dfs(src);
if(ans==1)
{
cout<<"graph is connected";
}
else
{
cout<<"graph is disconnected";
}
    return 0;
}
int dfs(int src)
{
    int j;
    vis[src]=1;
    for(int j=1;j<=n;j++)
    {
        if(a[src][j]==1 && vis[j]!=1)
        {
            dfs(j);
        }
    }
    for(int j=1;j<=n;j++)
    {
        if(vis[j]!=1)
        {
            return 0;
        }
        if(vis[j]==1)
        {
            return 1;
        }
    }
}