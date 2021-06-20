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
     int visited[n][m];
     char arr[n][m];
     fr(i,n){
         fr(j,m){
             visited[i][j]=0;
         }
     }

     fr(i,n){
         fr(j,m){
             cin>>arr[i][j];
         }
     }

     int ans=0;
     fr(i,n){
         fr(j,m){
              if(arr[i][j]=='.' && visited[i][j]==0){
                  ans++;
                  queue<pair<int,int>>q;
                  q.push(mp(i,j));
                  visited[i][j]=1;
                  while(q.size()!=0){
                      int a=q.front().first;
                      int b=q.front().second;
                      q.pop();

                      if((a+1)<n && arr[a+1][b]=='.' && visited[a+1][b]==0) q.push(mp(a+1,b)),visited[a+1][b]=1;
                      if((a-1)>=0 && arr[a-1][b]=='.' && visited[a-1][b]==0) q.push(mp(a-1,b)),visited[a-1][b]=1;
                      if((b-1)>=0 && arr[a][b-1]=='.' && visited[a][b-1]==0) q.push(mp(a,b-1)),visited[a][b-1]=1;
                      if((b+1)<m && arr[a][b+1]=='.' && visited[a][b+1]==0) q.push(mp(a,b+1)),visited[a][b+1]=1;
                  }
              }
         }
     }
     cout<<ans<<endl;
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
