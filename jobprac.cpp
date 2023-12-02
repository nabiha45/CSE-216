#include <bits/stdc++.h>

using namespace std;


class Job
{
public:
    int id, profit, deadline;
};

int n, p;

bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

void jobsequence(Job arr[])
{
    sort(arr,arr+n, cmp);
    int result[n];
    bool slot[n];
    for(int i=0; i < n; i++) slot[i]=false;
    for(int i=0; i < n; i++)
    {
        for(int j= arr[i].deadline - 1; j >= 0; j--)
        {
            if(slot[j]==false )
            {
                slot[j]=true;
                result[j]=arr[i].id;
                p+= arr[i].profit;
                break;
            }
        }
    }
    for(int i=0; i < n; i++)
    {
        if(slot[i]) cout<<result[i]<<" ";
    }
    cout<<endl;
    cout<<p<<endl;

}
int main()
{

    cin>>n;
    Job arr[n];
    for(int i=0; i < n; i++)
    {
        cin>>arr[i].id>>arr[i].profit>>arr[i].deadline;
    }
    jobsequence(arr);
}
