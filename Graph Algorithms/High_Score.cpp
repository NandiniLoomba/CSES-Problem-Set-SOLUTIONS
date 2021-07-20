//AUTHOR: stranger10
//BELLMAN FORD AND A VERY NICE TRICK
//TIME COMPLEXITY : O(VE)

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
void BellmanFord(vector<pair<pair<int,int>,int>>&v){
     vector<int>dist(n+1,LLONG_MIN);
     dist[1]=0;

     fr(i,n-1){
         fr(j,m){
             a=v[j].first.first;
             b=v[j].first.second;
             c=v[j].second;
             if(dist[a]!=LLONG_MIN && dist[b]<(dist[a]+c)){
                  dist[b]=dist[a]+c;
             }
         } 
     }
     //IF WE WOULD HAVE CHECKED THAT IF ANY NODE WEIGHT IS UPDATING OR NOT ONLY ONCE ie Vth TIME THEN WE 
     //ARE ONLY CHECKING FOR A POSITIVE WEIGHT CYCLE IN THE GRAPH BUT WE NEED TO CHECK FOR THE 
     //POSITIVE WEIGHT CYCLE WHICH IS AFFECTING THE NTH NODE.
     //EVEN IF THERE IS A POSTIVE WEIGHT CYCLE IN THE GRAPH BUT IT IS NOT AFFECTING THE NTH NODE
     //THEN WE DONT HAVE ANY PROBLEM WITH IT
     //ie. IF THERE IS A POSITIVE WEIGHT CYCLE WHICH AFFECTS THE NTH NODE THEN ANS SHOULD
     //BE -1 ELSE dist[n]

     fr(i,n-1){
         fr(j,m){
             a=v[j].first.first;
             b=v[j].first.second;
             c=v[j].second;
             if(dist[a]==LLONG_MAX){
                 dist[b]=LLONG_MAX;
             }
             else if(dist[a]!=LLONG_MIN && dist[b]<(dist[a]+c)){
                  dist[b]=LLONG_MAX;
             }
         } 
     }
     if(dist[n]==LLONG_MAX) cout<<-1<<endl;
     else cout<<dist[n]<<endl;
}
void solve(){ 
   cin>>n>>m;
   vector<pair<pair<int,int>,int>>v;
   fr(i,m){
       cin>>a>>b>>c;
       v.pb(mp(mp(a,b),c));
   }
   BellmanFord(v);
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
