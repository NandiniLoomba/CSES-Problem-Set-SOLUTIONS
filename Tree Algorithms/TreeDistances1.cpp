//AUTHOR:stranger10

#include <bits/stdc++.h>
using namespace std;
#define Input(v, n) fr(i, n) cin >> v[i];
#define sort(v) sort(v.begin(), v.end());
#define int long long int
#define double long double
#define fr(i, n) for (int i = 0; i < n; i++)
#define frr(i, s, e) for (int i = s; i <= e; i++)
#define rfr(i, s, e) for (int i = s; i >= e; i--)
#define fix(f, n) fixed << setprecision(n) << f
#define endl "\n"
#define pb push_back
#define mp make_pair
#define INF LLONG_MAX
#define mod 1000000007

int test,n,m1,m2,a,b;

int bfs(vector<vector<int>>&adj,int p){
  queue<int>q;
  vector<int>dist(n,0);
  vector<bool>visited(n,0);
  q.push(p);

  while(q.size()!=0){
    int t=q.front();
    q.pop();
    visited[t]=1;
    for(auto it:adj[t]){
      if(visited[it]==0){
        q.push(it);
        dist[it]=dist[t]+1;
      }
    }
  }
  int ans=-INF,k;
  fr(i,n){
    if(ans<dist[i]){
       ans=max(ans,dist[i]);
       k=i;
    }
    
  }
  return k;
}

void calc(vector<vector<int>>&adj,int p,vector<int>&dist){
  queue<int>q;
  vector<bool>visited(n,0);
  q.push(p);

  while(q.size()!=0){
    int t=q.front();
    q.pop();
    visited[t]=1;
    for(auto it:adj[t]){
      if(visited[it]==0){
        q.push(it);
        dist[it]=dist[t]+1;
      }
    }
  }
}

void solve()
{ 
  cin>>n;
  vector<vector<int>>adj(n);
  fr(i,n-1){
    cin>>a>>b;
    a--,b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  m1=bfs(adj,0);
  m2=bfs(adj,m1);
  vector<int>dist1(n,0),dist2(n,0);
  calc(adj,m1,dist1);
  calc(adj,m2,dist2);
  fr(i,n){
    cout<<max(dist1[i],dist2[i])<<" ";
  }cout<<endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  //cin>>test;
  test=1;
  while(test--){
    solve();
  }

  return 0;
}
