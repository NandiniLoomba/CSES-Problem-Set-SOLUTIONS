//AUTHOR : stranger10
//LAZY PROPAGATION IN SEGMENT TREE

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

int test,n,q,a,b,k,u;
const int N=8*1e5+5;
int seg[N],lazy[N];

void build(vector<int>&v,int index,int low,int high){
    if(low==high){
        seg[index]=v[low];
        return;
    }
    int mid=(low+high)/2;
    build(v,(2*index)+1,low,mid);
    build(v,(2*index)+2,mid+1,high);
    seg[index]=(seg[(2*index)+1]+seg[(2*index)+2]);
}


int query(int index,int low,int high,int k){
       if(lazy[index]!=0){
          seg[index]+=(high-low+1)*lazy[index];
          if(high!=low){
              lazy[(2*index)+1]+=lazy[index];
              lazy[(2*index)+2]+=lazy[index];
          }
          lazy[index]=0;
       }
       if(high<k || low>k) return -1;
       if(low==high) return seg[index];
       int mid=(low+high)/2;

       int q1=-1,q2=-1;
       if(k<=mid) q1=query((2*index)+1,low,mid,k);
       else q2=query((2*index)+2,mid+1,high,k);
       return max(q1,q2);
}

void range_update(int index,int low,int high,int l,int r,int val){
      if(lazy[index]!=0){
          seg[index]+=(high-low+1)*lazy[index];
          if(high!=low){
              lazy[(2*index)+1]+=lazy[index];
              lazy[(2*index)+2]+=lazy[index];
          }
          lazy[index]=0;
      }
      if(high<l || low>r) return;
      if(high<=r && low>=l) {
          seg[index]+=((high-low+1)*val);
          if(high!=low){
              lazy[(2*index)+1]+=val;
              lazy[(2*index)+2]+=val;
          }
          return;
      }

      int mid=(low+high)/2;
      range_update((2*index)+1,low,mid,l,r,val);
      range_update((2*index)+2,mid+1,high,l,r,val); 
      seg[index]=seg[(2*index)+1]+seg[(2*index)+2];
}

void solve()
{   
    cin>>n>>q;
    memset(lazy,0,sizeof(lazy));

    vector<int>v(n);
    Input(v,n);
    build(v,0,0,n-1);

    while(q--){
        cin>>k;
        if(k==1){
            cin>>a>>b>>u;
            a--,b--;
            range_update(0,0,n-1,a,b,u);
        }
        else{
            cin>>u;
            u--;
            cout<<query(0,0,n-1,u)<<endl;
        }
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
