#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll         long long int
#define umap       unordered_map
#define mod        998244353ll
#define pb         push_back
#define all(x)     (x).begin(), (x).end()
#define rall(x)    (x).rbegin(), (x).rend()
#define MN(a,b,c)  min(a,min(b,c))
#define MX(a,b,c)  max(a,max(b,c))
#define pr1         pair<ll,ll>
#define F          first
#define S          second
#define mP         make_pair
#define f(i,n)     for(ll i=0;i<n;i++)
#define f1(i,x,y)  for(ll i=x;i<=y;i++)
#define f2(i,x,y)  for(ll i=x;i>=y;i--)
#define yes        cout<<"Yes"<<"\n"
#define no         cout<<"No"<<"\n"
#define modsum(a,b)  ((a%mod)+(b%mod))%mod
#define modpro(a,b)  ((a%mod)*(b%mod))%mod
#define moddif(a,b)  ((a%mod)-(b%mod)+mod)%mod
#define modsumt(a,b,c) modsum(a,modsum(b,c))
// Remove macro of endl in interactive task
// in case of no errors check macros and functions again
//__builtin_popcount(x)
//__builtin_parity(x)   =(number of set bits)%2
//__builtin_clz(x)      to count the number of leading  zeroes 
//__builtin_ctz(x)      to count the number of trailing zeroes 
//__gcd(a,b)
// Binary Search 
// TO AVOID GETTING INFINITE LOOP
// mid = (l+r)/2      l=mid+1   r=mid
// mid = (l+r+1)/2    l=mid     r=mid-1
//std::cout << std::fixed; std::cout << std::setprecision(12); std::cout << z ;
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // For getting input from input.txt file
    freopen("hps.in", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("hps.out", "w", stdout);
  ll N,K;cin>>N>>K;
  vector <char> v(N);
  f(i,N) cin>>v[i];
  ll dp[N][K+1][3];
  memset(dp,0,sizeof(dp));
  // 0 -> Hoof  1-> Paper  2-> Scissor
  // Base Case
  dp[0][0][0]= (v[0]=='S') ? 1 : 0;
  dp[0][0][1]= (v[0]=='H') ? 1 : 0;
  dp[0][0][2]= (v[0]=='P') ? 1 : 0;
  ll ans=0;
  f(i,N)
  {
    if(i==0) continue;
     f(k,K+1)
      {
          if(k>i) continue;
           dp[i][k][0]= (v[i]=='S') ? 1 : 0;
           dp[i][k][1]= (v[i]=='H') ? 1 : 0;
           dp[i][k][2]= (v[i]=='P') ? 1 : 0;  
           if(k==0) 
           {
              dp[i][k][0]+= dp[i-1][k][0];
              dp[i][k][1]+= dp[i-1][k][1];
              dp[i][k][2]+= dp[i-1][k][2];
           }
           else
           {
               dp[i][k][0]+= max(dp[i-1][k][0],max(dp[i-1][k-1][1],dp[i-1][k-1][2]));
               dp[i][k][1]+= max(dp[i-1][k][1],max(dp[i-1][k-1][2],dp[i-1][k-1][0]));
               dp[i][k][2]+= max(dp[i-1][k][2],max(dp[i-1][k-1][1],dp[i-1][k-1][0]));
           } 
           if(i==(N-1))
           {
              f(j,3) ans=max(ans,dp[i][k][j]);
           } 
      }
  }
  cout<<ans;
}