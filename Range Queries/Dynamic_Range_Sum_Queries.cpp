//AUTHOR: stranger10
//SEGMENT TREE

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

int test,n,q,a,b,k;
const int N=8*1e5+5;
int seg[N];

void build(vector<int>&v,int index,int low,int high){
    if(low==high){
        seg[index]=v[low];
        return;
    }
    int mid=(low+high)/2;
    build(v,(2*index)+1,low,mid);
    build(v,(2*index)+2,mid+1,high);
    seg[index]=seg[(2*index)+1]+seg[(2*index)+2];
}

void update(int index,int low,int high,int new_index,int val){
    if(low>new_index || high<new_index) return;
    if(low==high) {
        seg[index]=val;
        return;
    }
    int mid=(low+high)/2;
    if(new_index<=mid) update((2*index)+1,low,mid,new_index,val);
    else update((2*index)+2,mid+1,high,new_index,val);
    seg[index]=seg[(2*index)+1]+seg[(2*index)+2];
}

int query(int index,int low,int high,int l,int r){
       if(high<l || low>r) return 0;
       if(low>=l && high<=r) return seg[index];
       int mid=(low+high)/2;
       return (query((2*index)+1,low,mid,l,r)+query((2*index)+2,mid+1,high,l,r));
}

void solve()
{   
    cin>>n>>q;
    vector<int>v(n);
    Input(v,n);
    build(v,0,0,n-1);

    while(q--){
        cin>>k>>a>>b;
        a--,b--;
        if(k==1) update(0,0,n-1,a,b+1);
        else cout<<query(0,0,n-1,a,b)<<endl;
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
