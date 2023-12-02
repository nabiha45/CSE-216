#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> adj;

map<string, int> degree;
set <string> nodes;
vector<string> ans;

int n;

bool topsort()
{
    queue<string> qu;
    for(string i: nodes)
    {
        if(degree[i]==0) qu.push(i);
    }
    while(!qu.empty())
    {
        string top= qu.front();
        qu.pop();
        ans.push_back(top);
        for(string i : adj[top])
        {
            degree[i]--;
            if(degree[i]==0)
            {
                qu.push(i);
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
        string u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        degree[v]++;
        nodes.insert(u);
        nodes.insert(v);
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
