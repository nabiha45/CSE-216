#include <bits/stdc++.h>

using namespace std;
int n;

void findsubset(int id, int sum, vector<int> sett, vector<int> sub)
{
    if(sum==0)
    {
        cout<<"[";
        for(int i=0; i < sub.size(); i++)
        {
            cout<<sub[i]<<" ";
        }
        cout<<"]";
        return;
    }
    if(id==n)
    {
        return;
    }
    findsubset(id+1, sum, sett, sub);

    if(sett[id] <= sum)
    {
        sub.push_back(sett[id]);
        findsubset(id+1, sum-sett[id], sett, sub);
        sub.pop_back();
    }

}
int main()
{
    cin>>n;
    vector<int> v;
    for(int i=0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> sub;
    findsubset(0, 30, v, sub);
}
