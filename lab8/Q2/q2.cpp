#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int dp[N][N];
vector<pair<int,int>>a(N);
int func(int n,int i,int t){
    if(i>=n)return 0;
    if(dp[i][t]!=-1)return dp[i][t];
    int ans=func(n,i+1,t);
    if(t<a[i].first){
        ans=max(ans,func(n,i+1,t+1)+a[i].second);
    }
    return dp[i][t]=ans;
}
bool compareFirst(const pair<int, int> &c, const pair<int, int> &b) {
    return c.first < b.first;
}
int main(){
    memset(dp, -1, sizeof(dp));
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){cin>>a[i].first;}
    for(int i=0;i<n;i++){cin>>a[i].second;}
    sort(a.begin(),a.begin()+n,compareFirst);
    cout<<"The max value : "<<func(n,0,0)<<endl<<"The id's of the jobs are : ";
    vector<int>sel;int j=0;
    for(int i=0;i<n;i++){
        if(dp[i][j]!=dp[i+1][j]){
            j++;
            sel.push_back(i+1);
        }}
    for(auto &a:sel)cout<<a<<" ";
}