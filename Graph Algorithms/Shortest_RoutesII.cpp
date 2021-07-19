//AUTHOR: stranger10
//FLOYD WARSHALL
//TIME COMPLEXITY : O(V^3)

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
 
int test,n,m,a,b,c,q;

//TIME COMPLEXITY : O(n^3)
//The idea is to one by one pick all vertices and updates all shortest paths which 
//include the picked vertex as an intermediate vertex in the shortest path. When we pick 
//vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} 
//as intermediate vertices.

void Floyd_Warshall(vector<vector<int>>&adj){
      frr(k,1,n){
          frr(i,1,n){
              frr(j,1,n){
                  if(adj[i][k]!=LLONG_MAX && adj[k][j]!=LLONG_MAX && adj[i][j]>(adj[i][k]+adj[k][j])){
                              adj[i][j]=(adj[i][k]+adj[k][j]);
                  }
              }
          }
      }
}
 
void solve(){ 
  cin>>n>>m>>q;
  vector<vector<int>>adj(n+1);

  frr(i,0,n){
      frr(j,0,n){
          if(i==j) adj[i].pb(0);
          else adj[i].pb(LLONG_MAX);
      }
  }

  fr(i,m){
      cin>>a>>b>>c;
      adj[a][b]=min(adj[a][b],c);
      adj[b][a]=min(adj[b][a],c);
  }
  Floyd_Warshall(adj);
  while(q--){
     cin>>a>>b; 
     if(adj[a][b]!=LLONG_MAX) cout<<adj[a][b]<<endl;
     else cout<<-1<<endl;
  }
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
