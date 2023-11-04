#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> g[100];

const int INF = 1e9 +10;
vector<int> dist(101, INF);

void dijkstra(int source)
{
    vector<int> vis(101, 0);

    set<pair<int,int>> st;

    st.insert({0, source});
    dist[source]=0;
    while(st.size()>0)
    {
        auto node = *st.begin();
        int v= node.second;
        int vdist = node.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v]=1;
        for(auto child: g[v])
        {
            int c= child.first;
            int wt= child.second;
            if(dist[v]+wt < dist[c])
            {
                dist[c]=dist[v]+wt;
                st.insert({dist[c], c});
            }

        }
    }


}


int main()

{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    dijkstra(1);

    for(int i=1; i <= n; i++)
        cout<<dist[i]<<" ";




}
