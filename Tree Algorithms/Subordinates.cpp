//AUTHOR:stranger10
//DFS


#include <bits/stdc++.h>
using namespace std;
#define Input(v, n) fr(i, n) cin >> v[i];
#define checkk(v, n) fr(i, n) cout << v[i] << " " << endl;
#define sort(v) sort(v.begin(), v.end());
#define int long long int
#define double long double
#define fr(i, n) for (int i = 0; i < n; i++)
#define frr(i, s, e) for (int i = s; i <= e; i++)
#define rfr(i, s, e) for (int i = s; i >= e; i--)
#define fix(f,n) fixed<<setprecision(n)<<f
#define endl "\n"
#define pb push_back
#define mp make_pair
#define mod 1000000007
 
int test,n,d;
void dfs(vector<int>&ans,vector<vector<int>>&adj,int a){
       
       for(auto i:adj[a]){
             dfs(ans,adj,i);
             ans[a]+=ans[i]+1;
       } 

}

void solve(){ 
   cin>>n; 
   vector<vector<int>>adj(n+1);
   fr(i,n-1){
        cin>>d; 
        adj[d].pb(i+2); 
   }
   vector<int>ans(n+1,0);
   dfs(ans,adj,1);

   frr(i,1,n) cout<<ans[i]<<" ";
   cout<<endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     
    //cin>>test;
    test=1;
    while (test--)
    {
        solve();
    }
 
    return 0;
}
