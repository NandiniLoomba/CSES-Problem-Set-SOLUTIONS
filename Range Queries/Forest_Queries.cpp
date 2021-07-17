//AUTHOR: stranger10
//Used DP 
//TIME COMPLEXITY : FOR MAKING THE TABLE : O(n^2)
//                : FOR EACH QUERY : O(1)


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

int test,n,q,a,b,c,d;
char ch;

void solve(){ 
    cin>>n>>q;
    int arr[n+1][n+1];
    fr(i,n+1) arr[0][i]=0,arr[i][0]=0;
    frr(i,1,n) frr(j,1,n){
        cin>>ch;
        if(ch=='.') arr[i][j]=0;
        else arr[i][j]=1;
    }
    
    frr(i,1,n){
        frr(j,1,n){
            arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+arr[i][j];
        }
    }

    fr(i,q){
        cin>>a>>b>>c>>d;
        cout<<(arr[c][d]-arr[a-1][d]-arr[c][b-1]+arr[a-1][b-1])<<endl;
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
