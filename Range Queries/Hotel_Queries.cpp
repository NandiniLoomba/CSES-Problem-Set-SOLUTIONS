//AUTHOR:stranger10
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

int test,n,m;
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
       seg[index]=max(seg[(2*index)+1],seg[(2*index)+2]);
}

void update(int req,int val,int index,int low,int high){
    if(high<req || low>req) return;
    if(high==low){
        seg[index]=seg[index]-val;
        return;
    }
    int mid=(high+low)/2;
    update(req,val,(2*index)+1,low,mid);
    update(req,val,(2*index)+2,mid+1,high);
    seg[index]=max(seg[(2*index)+1],seg[(2*index)+2]);
}

int query(int index,int low,int high,int val){
    if(low==high && seg[index]>=val){
         return low+1;
    }
    int mid=(low+high)/2;
    if(seg[(2*index)+1]>=val){
         return query((2*index)+1,low,mid,val);
    }
    else if(seg[(2*index)+2]>=val){
         return query((2*index)+2,mid+1,high,val);
    }
    else{
        return 0;
    }
}

void solve(){ 
   cin>>n>>m;
   vector<int>v1(n),v2(m);
   Input(v1,n);Input(v2,m);
   build(v1,0,0,n-1);
   fr(i,m){
       int ans=query(0,0,n-1,v2[i]);
       cout<<ans<<" ";
       if(ans!=0) update(ans-1,v2[i],0,0,n-1);
   }cout<<endl;
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
