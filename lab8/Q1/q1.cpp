#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int dp[N][N];
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
    cout<<"The max value is : "<<func(n-1,0,lim)<<endl<<"The items included in the collection are : ";
    int j=0;
    vector<int>sel;
    for(int i=n-1;i>0;i--){
        if(dp[i][j]!=dp[i-1][j]){
            j+=wt[i];
            sel.push_back(i+1);
        }}
    if(dp[0][j]!=0)sel.push_back(1);reverse(sel.rbegin(),sel.rend());
    for(auto &a:sel)cout<<a<<" ";
}