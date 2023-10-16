#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[2005][2005];
int c, n;
int p[2005], w[2005];

int knapsack(int i, int j)
{
    if(i < 0 or j <= 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int v1= knapsack(i-1, j);
    int v2=-1;
    if(w[i]<=j) v2 = p[i]+knapsack(i-1, j-w[i]);
    dp[i][j]= max(v1, v2);
    return dp[i][j];

}
int32_t main()
{
    cin>>n>>c;
    for(int i=0; i < n; i++)
    {
        cin>>w[i]>>p[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<knapsack(n-1, c)<<endl;
}
