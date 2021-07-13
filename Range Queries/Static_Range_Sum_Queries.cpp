//AUTHOR: stranger10
//PREFIX SUM

#include <bits/stdc++.h>
using namespace std;
#define Input(v, n) fr(i, n) cin >> v[i];
#define checkk(v, n) fr(i, n) cout << v[i] << " " << endl;
#define sort(v) sort(v.begin(), v.end());
#define int long long int
#define double long double
#define fr(i, n) for (int i = 0; i < n; i++)
#define frr(i, s, e) for (int i = s; i <= e; i++)
#define rfr(i, s, e) for (int i = s; i >= e; i--)
#define fix(f,n) fixed<<setprecision(n)<<f
#define endl "\n"
#define pb push_back
#define mp make_pair
#define mod 1000000007

int test,n,q,a,b;

void solve()
{   
    cin>>n>>q;
    vector<int>v(n),prefix_sum(n);
    Input(v,n);

    prefix_sum[0]=v[0];
    frr(i,1,n-1) prefix_sum[i]=prefix_sum[i-1]+v[i];

    while(q--){
        cin>>a>>b;
        a--,b--;
        if(a==0) cout<<prefix_sum[b]<<endl;
        else cout<<prefix_sum[b]-prefix_sum[a-1]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     
    //cin>>test;
    test=1;
    while (test--)
    {
        solve();
    }

    return 0;
}
