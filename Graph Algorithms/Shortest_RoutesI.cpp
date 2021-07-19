//AUTHOR: stranger10
//TIME COMPLEXITY : O(ElogV)
//DIJKSTRA SHORTEST PATH ALGORITHM

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

int test,n,m,a,b,c;

//TIME COMPLEXITY : Set in C++ are typically implemented using Self-balancing binary search trees.
//Therefore, time complexity of set operations like insert, delete is logarithmic 
//and time complexity of above solution is O(ELogV)).

void Dijkstras(vector<vector<pair<int,int>>>&adj){
      //set is defined to keep track of all the vertices which are being processed
      set<pair<int,int>>s;
      vector<int>dist(n+1,LLONG_MAX);
      dist[1]=0;
      //source vertex is assigned 0 distance. In this case source is 1
      s.insert(mp(0,1));
      
      while(s.size()!=0){
          //choose vertex with least dist and yet to be included in Dijkstra
          pair<int,int> t=*(s.begin());
          //remove it from set
          s.erase(s.begin());
          
          //traverse all the adjacent vertices of the chosen vertex
          for(auto i:adj[t.second]){
              int v=i.first;
              int weight=i.second;

              if(dist[v]>(t.first+weight)){
                  //if any of the choosen vertex is already processed once then remove it from the set
                  if(dist[v]!=LLONG_MAX){
                       s.erase(s.find(mp(dist[v],v)));
                  }
                  dist[v]=(t.first+weight);
                  s.insert(mp(dist[v],v));
              }
           
          }
      }
      frr(i,1,n){
          cout<<dist[i]<<" ";
      }cout<<endl;
}

void solve(){ 
  cin>>n>>m;
  //if a->b weight c
  // then adj[a].pb(mp(b,c));
  vector<vector<pair<int,int>>>adj(n+1);
  fr(i,m){
      cin>>a>>b>>c;
      adj[a].pb(mp(b,c));
  }
  Dijkstras(adj);
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
