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

int test, row, col;

void solve()
{
    cin >> row >> col;
    if (row > col)
    {
        int start = ((row - 1) * (row - 1)) + 1;
        if (row & 1)
        {
            cout << start + col - 1 << endl;
        }
        else
        {
            cout << start + row - 1 + row - col << endl;
        }
    }
    else
    {
        int start = ((col - 1) * (col - 1)) + 1;
        if (col & 1)
        {
            cout << start + col - 1 + col - row << endl;
        }
        else
        {
            cout << start + row - 1 << endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> test;
    while (test--)
    {
        solve();
    }

    return 0;
}
