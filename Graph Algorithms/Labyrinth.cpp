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

int test,n,m;


void solve()
{
     cin>>n>>m;
     vector<vector<char>>arr(n); 
     int w,r,s=-1,t=-1;

     fr(i,n){
         fr(j,m){
             char ch;cin>>ch;
             if(ch=='B') w=i,r=j;
             arr[i].pb(ch);
         }
     }

     bool visited[n][m];
     int dist[n][m];
     pair<int,int> parent[n][m];
     fr(i,n) fr(j,m) visited[i][j]=0,dist[i][j]=INT_MAX;

     visited[w][r]=1;
     dist[w][r]=0;
     parent[w][r]=mp(-1,-1);

     queue<pair<int,int>>q;
     q.push(mp(w,r));

     while(q.size()!=0){
         int a=q.front().first;
         int b=q.front().second;
         q.pop();
         
         if((a+1)<n && arr[a+1][b]!='#' && visited[a+1][b]==0){
              q.push(mp(a+1,b)),visited[a+1][b]=1,dist[a+1][b]=dist[a][b]+1,parent[a+1][b]=mp(a,b);
              if(arr[a+1][b]=='A')  {s=a+1,t=b;break;}
         }
         if((a-1)>=0 && arr[a-1][b]!='#' && visited[a-1][b]==0){
              q.push(mp(a-1,b)),visited[a-1][b]=1,dist[a-1][b]=dist[a][b]+1,parent[a-1][b]=mp(a,b);
              if(arr[a-1][b]=='A')  {s=a-1,t=b;break;}
         }
         if((b-1)>=0 && arr[a][b-1]!='#' && visited[a][b-1]==0){
              q.push(mp(a,b-1)),visited[a][b-1]=1,dist[a][b-1]=dist[a][b]+1,parent[a][b-1]=mp(a,b);
              if(arr[a][b-1]=='A')  {s=a,t=b-1;break;}
         }
         if((b+1)<m && arr[a][b+1]!='#' && visited[a][b+1]==0){
              q.push(mp(a,b+1)),visited[a][b+1]=1,dist[a][b+1]=dist[a][b]+1,parent[a][b+1]=mp(a,b);
              if(arr[a][b+1]=='A')  {s=a,t=b+1;break;} 
         }
         
     }
     
     if(s==-1) cout<<"NO"<<endl;
     else{
         cout<<"YES"<<endl;
         cout<<dist[s][t]<<endl;
         while(parent[s][t].first!=-1){
              if(parent[s][t].first>s) cout<<'D';
              else if(parent[s][t].first<s) cout<<'U';
              else if(parent[s][t].second>t) cout<<'R';
              else if(parent[s][t].second<t) cout<<'L';
              int n=s;
              s=parent[s][t].first;
              t=parent[n][t].second;
         }cout<<endl;
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
