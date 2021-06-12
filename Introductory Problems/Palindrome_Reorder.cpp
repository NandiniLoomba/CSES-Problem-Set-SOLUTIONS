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

int test, middle = 0;
char ch;
string s;

void solve()
{
    cin >> s;
    sort(s);
    vector<char> v1, v2;
    fr(i, s.size())
    {
        if (s[i] == s[i + 1])
        {
            v1.pb(s[i]);
            v2.pb(s[i]);
            i++;
        }
        else if (middle == 0 && s.size() & 1)
        {
            ch = s[i];
            middle = 1;
        }
        else
        {
            cout << "NO SOLUTION " << endl;
            return;
        }
    }
    fr(i, v1.size())
    {
        cout << v1[i];
    }
    if (middle == 1)
    {
        cout << ch;
    }
    rfr(i, v2.size() - 1, 0)
    {
        cout << v2[i];
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cin >> test;
    test = 1;
    while (test--)
    {
        solve();
    }

    return 0;
}
