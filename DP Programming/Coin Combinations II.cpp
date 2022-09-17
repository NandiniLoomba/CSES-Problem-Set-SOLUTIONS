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

int test, n, x;

void solve()
{
  cin >> n >> x;
  vector<int>coins(n);
  Input(coins,n);
  vector<int> curr(x + 1, 0), prev(x + 1, 0);
  curr[0] = prev[0] = 1;
  fr(i, n){
    frr(j, 1, x){
      int notTake = prev[j];
      int take = 0;
      if(coins[i] <= j) take = curr[j - coins[i]];
      curr[j] = (notTake + take)%mod;
    }
    prev = curr;
  }
  cout<<prev[x];
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
