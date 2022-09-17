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
  sort(coins);
  vector<int> prev(x + 1, INT_MAX), curr(x + 1, INT_MAX);
  prev[0] = curr[0] = 0;
  fr(i, n){
     frr(j, 1, x){
       if(coins[i] <= j){
         curr[j] = min(curr[j - coins[i]] + 1, prev[j]);
       }
     } 
     prev = curr;
  }
  if(prev[x] == INT_MAX) cout<< -1 <<endl;
  else cout<<prev[x]<<endl;
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
