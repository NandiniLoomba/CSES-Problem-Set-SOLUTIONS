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

int test, n;

int calc(vector<int> &dp, int ind){
   if(dp[ind] != -1) {
    return dp[ind];
   }
   if(ind == n) return dp[ind] = 1;
   int count = 0;
   frr(i, 1, 6){
       if((ind + i) <= n) count = (count + calc(dp, ind + i)) % mod;
       else break;
   }
   return dp[ind] = count;
}

void solve()
{
  cin>>n;
  vector<int> dp(n+1, -1);
  cout<< calc(dp, 0);
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
