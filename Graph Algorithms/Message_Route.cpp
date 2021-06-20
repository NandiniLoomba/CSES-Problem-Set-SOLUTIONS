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


void solve()
{
     cin>>n>>m;
     vector<vector<int>>adj(n+1);
     vector<bool>visited(n+1,0);
     vector<int>dist(n+1,-1),parent(n+1),ans;
     fr(i,m){
         cin>>a>>b;
         adj[a].pb(b);
         adj[b].pb(a);
     }

     queue<int>q;
     q.push(n);
     visited[n]=1,parent[n]=-1,dist[n]=0;
     while(q.size()!=0){
         int t=q.front();
         q.pop();
         fr(i,adj[t].size()){
            if(visited[adj[t][i]]==0){
                q.push(adj[t][i]),visited[adj[t][i]]=1,parent[adj[t][i]]=t,dist[adj[t][i]]=dist[t]+1;
            }
         }
     }
     
     if(dist[1]==-1) cout<<"IMPOSSIBLE"<<endl;
     else{
         cout<<dist[1]+1<<endl;
         int a=1;cout<<1<<" ";
         while(parent[a]!=n){
            cout<<parent[a]<<" ";
            a=parent[a];
         }
         cout<<n<<endl;
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
