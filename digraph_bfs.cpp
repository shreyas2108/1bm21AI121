#include <iostream>

using namespace std;
int a[10][10],n;
void bfs(int);
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
 bfs(src);
    return 0;
}

void bfs(int src)
{
    int q[10],vis [10],f=0,r=-1,i,j;
    for(int i=0;i<10;i++)
    {
        vis[i]=0;
    }
    r=r+1;
    q[r]=src;
    vis[src]=1;
    while(f<=r)
    {
        i=q[f];
        f=f+1;
        for(int j=0;j<=n;j++)
        {
            if(a[i][j]=1 && vis[j]!=1)
            {
                vis[j]=1;
                r=r+1;
                q[r]=j;

            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(vis[i]!=1)
        {
            cout<<"node"<<i<<" is not reachable\n";
        }
        else
        {
           cout<<"node"<<i<<" is reachable\n";

        }
    }
}
