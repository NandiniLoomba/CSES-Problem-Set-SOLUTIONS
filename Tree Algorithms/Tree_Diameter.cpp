//AUTHOR:stranger10
//DFS AND DIAMETER LOGIC

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
 
int test,n,a,b,ans=0;
void dfs(vector<int>&dist,vector<vector<int>>&adj,int a,int parent){

       for(auto i:adj[a]){
            if(i!=parent){
                dist[i]=dist[a]+1;
                dfs(dist,adj,i,a);
            }
       } 
}

void solve(){ 
   cin>>n; 
   vector<vector<int>>adj(n+1);
   fr(i,n-1){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
   }
   vector<int>dist(n+1,0);
   dfs(dist,adj,1,1);
   
   int max_dist=0;
   frr(i,1,n){
       if(max_dist<dist[i]) max_dist=dist[i],ans=i,dist[i]=0;
   }
   
   dfs(dist,adj,ans,ans);
  
   max_dist=0;
   frr(i,1,n){
       if(max_dist<dist[i]) max_dist=dist[i];
   }
   cout<<max_dist<<endl;
}
 
int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
     
    //cin>>test;
    test=1;
    while (test--)
    {
        solve();
    }
 
    return 0;
}
