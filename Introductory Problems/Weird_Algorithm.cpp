
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

int test, n;

void solve()
{
    cin >> n;
    while (n != 1)
    {
        cout << n << " ";
        if (n & 1)
        {
            n = (n * 3) + 1;
        }
        else
        {
            n = n / 2;
        }
    }
    cout << 1 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
