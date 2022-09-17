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
int calc(vector<vector<char>> &mat, vector<vector<int>> &dp, int r, int c){
  if(dp[r][c] != -1) return dp[r][c];
  if(r == (n - 1) && c == (n - 1)) return dp[r][c]=1;
  int count = 0;
  if((c + 1) < n && mat[r][c + 1] != '*') count = calc(mat, dp, r, c + 1);
  if((r + 1) < n && mat[r + 1][c] != '*') count = (count + calc(mat, dp, r + 1, c))%mod;
  return dp[r][c] = count;
}
void solve()
{
  cin >> n;
  vector<vector<char>> mat(n, vector<char>(n));
  vector<vector<int>> dp(n, vector<int>(n, -1));
  fr(i, n){
    fr(j, n){
      cin>>mat[i][j];
    }
  }
  if(mat[0][0] == '*') cout<<0<<endl;
  else cout<<calc(mat, dp, 0, 0);
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
