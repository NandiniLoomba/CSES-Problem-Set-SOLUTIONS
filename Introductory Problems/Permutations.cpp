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
        cout << 1 << endl;
    else if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        int a = (n / 2) + 1;

        frr(i, 1, n / 2)
        {
            cout << a << " " << i << " ";
            a++;
        }
        if (n & 1)
        {
            cout << a << endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
