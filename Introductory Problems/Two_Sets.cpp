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
    int ans = (n * (n + 1)) / 2;
    if (ans & 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        int single = -1, start, total = ans / 2, count = 0;
        rfr(i, n, 1)
        {
            if (total >= i)
            {
                total -= i;
                start = i;
                count++;
            }
            else
            {
                single = total;
                count++;
                break;
            }
            if (total == 0)
            {
                break;
            }
        }
        cout << count << endl;
        if (single > 0)
        {
            cout << single << " ";
        }
        frr(i, start, n)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << n - count << endl;
        frr(i, 1, start - 1)
        {
            if (i != single)
            {
                cout << i << " ";
            }
        }
        cout << endl;
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
