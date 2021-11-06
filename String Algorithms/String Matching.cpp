//TIME COMPLEXITY : 0(n+m)
//SPACE COMPLEXITY : 0(m)
//KMP ALGO

#include <bits/stdc++.h>
using namespace std;
#define Input(v, n) fr(i, n) cin >> v[i];
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
 
int test,n,m;
string s1,s2;

void KMP(vector<int>&kmp,string s){
     int i=0;
     frr(j,1,s.size()-1){
         if(s[i]==s[j]) i++,kmp[j]=i;
         else{
           if(i!=0) i=kmp[i-1],j--;
         }
     }
}

void Search(vector<int>&kmp,int &count){
     int i=0;
     fr(j,s1.size()){
         if(s1[j]==s2[i]) i++;
         else{
           if(i!=0){
             i=kmp[i-1];
             j--;
           }
         }
         if(i==s2.size()) {
           count++;
           i=kmp[i-1];
         }
     }
}

void solve(){
   cin>>s1>>s2;
   vector<int>kmp(s2.size(),0);
   KMP(kmp,s2);
   int count=0;
   Search(kmp,count);
   cout<<count<<endl;
}

int32_t main()
{ 
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  
  test=1;
  while(test--){
    solve();
  }

  return 0;
}
