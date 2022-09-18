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

int test, n, m;

int calc(vector<int> &arr, vector<bool> &visited, vector<vector<int>> &dp, int prev, int ind){
   visited[ind] = 1;
   if(ind == n) return 1;
   if(dp[ind][prev] != -1) return dp[ind][prev];
   if(arr[ind] != 0){
    if(abs(arr[ind] - prev) <= 1) return 1;
    return 0;
   } 
   int count = 0;
   if(prev >= 1 && prev <= m) count = (count + calc(arr, visited, dp, prev, ind + 1))%mod;
   if(prev >= 2) count = (count + calc(arr, visited, dp, prev - 1, ind + 1))%mod;
   if(prev < m) count = (count + calc(arr, visited, dp, prev + 1, ind + 1))%mod;
   return dp[ind][prev] = count;
}
void solve()
{
  cin>>n>>m;
  vector<int>arr(n);
  vector<vector<int>>dp(n, vector<int>(m + 1, -1));
  vector<bool> visited(n, 0);
  Input(arr,n);
  int ans = 1;
  
  fr(i, n){
    if(arr[i] == 0 && !visited[i]){
      int count = 0;
      if(i == 0){
         frr(j, 1, m){
            count = (count + calc(arr, visited, dp, j, i+1))%mod;
         }
      }
      else count = calc(arr, visited, dp, arr[i - 1], i);
      if(count == 0){
        cout<<0<<endl;
        return;
      }
      ans = (ans * count)%mod;
     
    }
    else if(i != 0 && arr[i-1] != 0 && abs(arr[i-1] - arr[i]) >= 2) {
        cout<<0<<endl;
        return;
    }
  }
  cout<<ans<<endl;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  test = 1;
  while (test--)
  {
    solve();
  }

  return 0;
}
