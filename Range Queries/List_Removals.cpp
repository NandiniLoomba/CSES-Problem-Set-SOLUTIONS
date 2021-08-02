//AUTHOR: stranger10
//SEGMENT TREE AND BINARY SEARCH

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
#define fix(f, n) fixed << setprecision(n) << f
#define endl "\n"
#define pb push_back
#define mp make_pair
#define INF LLONG_MAX
#define mod 1000000007

int test,n,d,k=0;
const int N=8e5+5;
int seg[N];

int query(int index,int low,int high,int l,int r){
  if(high<l || low>r) return 0;
  if(low>=l && high<=r) return seg[index];
  int mid=(low+high)/2;
  return (query((2*index)+1,low,mid,l,r)+query((2*index)+2,mid+1,high,l,r));
}


void update(int index,int low,int high,int k,int val){
    if(low>k || high<k) return;
    if(low==high) {
      seg[index]=val;
      return;
    }
    int mid=(low+high)/2;
    update((2*index)+1,low,mid,k,val);
    update((2*index)+2,mid+1,high,k,val);
    seg[index]=seg[(2*index)+1]+seg[(2*index)+2];
}

int BinarySearch(int low,int high,int d){
  int ans=INF;
  while(low<=high){
    int mid=(low+high)/2;
    int t=query(0,0,n-1,0,mid);
    if(t>=d) high=mid-1,ans=min(ans,mid);
    else low=mid+1;
  }
  return ans;
}
void solve()
{
  cin>>n;
  vector<int>v(n);
  fr(i,n){
    cin>>v[i];
    update(0,0,n-1,i,1);
  }
  
  fr(i,n){
    cin>>d;
    int ans=BinarySearch(0,n-1,d);
    cout<<v[ans]<<" ";
    update(0,0,n-1,ans,0);
  }
  cout<<endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  test=1;
  while (test--)
  {
    solve();
  }

  return 0;
}
