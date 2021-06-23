//AUTHOR: stranger1O

#include <bits/stdc++.h>
using namespace std;
#define Input(v, n) fr(i, n) cin >> v[i];
#define checkk(v, n) fr(i, n) cout << v[i] << " " << endl;
#define sort(v) sort(v.begin(), v.end());
#define int long long int
#define fr(i, n) for (int i = 0; i < n; i++)
#define frr(i, s, e) for (int i = s; i <= e; i++)
#define rfr(i, s, e) for (int i = s; i >= 0; i--)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define mod 1000000007

int test,n,m,a,b;

vector<int> dfs_helper(int a,vector<vector<int>>&adj,vector<int>&dist,vector<int>&visited,int &t){
    vector<int>ans;
    fr(i,adj[a].size()){
        if(visited[adj[a][i]]==1 && (dist[a]-dist[adj[a][i]])>=2){
               t=adj[a][i],ans.pb(adj[a][i]),ans.pb(a);
               return ans;
        }
        else if(visited[adj[a][i]]==0){
             visited[adj[a][i]]=1,dist[adj[a][i]]=dist[a]+1;
             ans=dfs_helper(adj[a][i],adj,dist,visited,t);
             if(t!=-1 && ans.size()>0){
                 if(a==t) t=-1;
                 ans.pb(a);
                 return ans;
             }
             else if(ans.size()>0) return ans;
        }
    }
    return ans;
}
vector<int> dfs(vector<vector<int>>&adj){
    vector<int>visited(n+1,0),dist(n+1,-1),ans;
    int t=-1;
    frr(i,1,n){
        if(visited[i]==0){
            visited[i]=1,dist[i]=0;
            ans=dfs_helper(i,adj,dist,visited,t);
            if(ans.size()>0) return ans;
        }
    }
    return ans;
}
void solve()
{
     cin>>n>>m;
     vector<vector<int>>adj(n+1);
     fr(i,m){
         cin>>a>>b;
         adj[a].pb(b),adj[b].pb(a);
     }
     vector<int>ans;
     ans=dfs(adj);
     if(ans.size()==0) cout<<"IMPOSSIBLE"<<endl;
     else{
         cout<<ans.size()<<endl;
         fr(i,ans.size()) cout<<ans[i]<<" ";
         cout<<endl;
     }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    test=1;
    while (test--)
    {
        solve();
    }

    return 0;
}
