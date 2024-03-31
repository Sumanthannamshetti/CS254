#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int dp[N][N];
set<int>s;
vector<int>wt(N),val(N);
int func(int i,int w,int lim){
    if(i<0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    int ans=func(i-1,w,lim);
    if(wt[i]+w<=lim){
        ans=max(ans,func(i-1,w+wt[i],lim)+val[i]);
    }
    return dp[i][w]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,lim;
    cin>>n>>lim;
    for(int i=0;i<n;i++)cin>>val[i];
    for(int i=0;i<n;i++)cin>>wt[i];
    cout<<func(n-1,0,lim);
}