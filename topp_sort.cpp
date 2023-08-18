#include<iostream>
void source_removal(int n, int a[10][10])
{
inti,j,k,u,v,top,s[10],t[10],indeg[10],sum;
for(i=0;i<n;i++)
{
sum=0;
for(j=0;j<n;j++)
{
sum+=a[j][i];
}
indeg[i]=sum;
}
top=-1;
for(i=0;i<n;i++)
{
if(indeg[i]==0)
{
s[++top]=i;
}
}
k=0;
while(top!=-1)
{
u=s[top--];
t[k++]=u;
for(v=0;v<n;v++)
{
if(a[u][v]==1)
{
indeg[v]=indeg[v]-1;
if(indeg[v]==0)
s[++top]=v;

}
}
}
for(i=0;i<n;i++)
{
cout<<t[i];
}
}
void main()
{
inti,j,a[10][10],n;
cout<<"enter the number of nodes";
cin>>n;
cout<<"enter the adjacency matrix";
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
cin>>a[i][j];
}
}
source_removal(n,a);
getch();
}