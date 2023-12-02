#include <bits/stdc++.h>

using namespace std;

map<int,vector<int>> adj;
map<int,int> degree;
vector<int> ans;
int n;

bool topsort()
{
    queue<int> q;
    for(int i=1; i <=n; i++)
    {
        if(degree[i]==0) q.push(i);
    }

    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        ans.push_back(top);
        for(auto it: adj[top])
        {
            degree[it]--;
            if(degree[it]==0)
            {
                q.push(it);
            }
        }
    }
     if(ans.size()==n) return true;
    else return false;
}
int main()
{
        int e;
        cin>>n>>e;
        for(int i=0; i < e; i++)
        {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            degree[v]++;
        }
         if(topsort())
    {
        for(int i=0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
    }
    else cout<<"no\n";

}
