#include<bits/stdc++.h>
using namespace std;
map<char, vector<char>> graph;
map<char, int> indegree;
vector<char> topological_order;
int n, m;
bool topologicalSort()
{
    queue<char> q;
    for(int i=0;i<n;i++)
    {
        char c = 'A' + i;
        if(indegree[c]==0)
        {
            q.push(c);
        }
    }
    while(!q.empty())
    {
        char v = q.front();
        q.pop();
        topological_order.push_back(v);
        for(auto u: graph[v])
        {
            indegree[u]--;
            if(indegree[u]==0)
            {
                q.push(u);
            }
        }
    }
    if(topological_order.size()==n)
    {
        return true;
    }
    return false;
}
int count_cycle()
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        char c = 'A' + i;
        if(indegree[c]!=0)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>m;
    cout<<"Enter the edges: \n";
    for(int i=0;i<m;i++)
    {
        char u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    if(topologicalSort())
    {
        cout<<"Topological order: ";
        for(auto i: topological_order)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    else
    {
        cout<<"Topological order doesn't exist or there is a cycle\n";
    }
}
/*
6 7
A D
B C
B D
C E
C F
D E
D F
*/
