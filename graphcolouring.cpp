#include <bits/stdc++.h>

using namespace std;

bool graph[101][101];


bool issafe(int i, int j, int n, vector<int> c)
{
    for(int k=0; k < n; k++)
    {
        if(graph[i][k]==1 and c[k]== j) return false;
    }
    return true;
}
bool func(int m, int n, vector<int> c, int i){

    if(i== n) return true;

    for(int j=0; j< m; j++)
    {
        if(issafe(i,j, n, c))
        {
            c[i]=j;
            if(func(m,n,c,i+1)) return true;
            c[i]=-1;

        }
    }
    return false;

}

bool graphcolouring(int m, int n)
{
     vector<int> c(101, -1);

     return func(m,n,c,0);

}

int main()
{
    int n, m, e;
    cin>>n>>m>>e;
    for(int i=0; i < e; i++)
    {
        int x, y;
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }

    cout<<graphcolouring(m, n);


}
