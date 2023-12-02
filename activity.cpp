#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;

    for(int i=0; i < n; i++)
    {
        int s, e;
        cin>>s>>e;
        v.push_back({s,e});
    }

    sort(v.begin(), v.end(), cmp);
    vector<pair<int,int>> ans;
    //for(auto it: v) cout<<it.second<<" ";
    int take=1;
    int e= v[0].second;
    ans.push_back({v[0].first, v[0].second});
    for(int i=1; i < n; i++)
    {
        if(v[i].first >= e)
        {
            take++;
            e=v[i].second;
            ans.push_back({v[i].first, v[i].second});
        }
    }
    for(auto it: ans)
    {
        cout<<"("<<it.first<<","<<it.second<<")";
    }
    cout<<take<<endl;
}
