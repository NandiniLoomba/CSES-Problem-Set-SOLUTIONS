//AUTHOR:stranger1O

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

int test, n;

void solve()
{
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    cout << 0 << endl
         << 6 << endl;
    int minus = 0, point = 1;
    frr(i, 3, n)
    {
        int ans = ((i * i) * ((i * i) - 1)) / 2;
        minus = minus + (8 * point);
        cout << ans - minus << endl;
        point++;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    test = 1;
    while (test--)
    {
        solve();
    }

    return 0;
}
