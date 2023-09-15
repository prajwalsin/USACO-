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
  // // For getting input from input.txt file
  //   freopen("time.in", "r", stdin);
 
  // // Printing the Output to output.txt file
  //   freopen("time.out", "w", stdout);

   ll n,m,c;
   cin>>n>>m>>c;
   vector <ll> M(n+1);
   f(i,n) cin>>M[i+1];
   vector <ll> v[n+1];
   f(i,m)
   {
      ll x,y;
      cin>>x>>y;
      v[x].pb(y);
   }
   ll dp[n+1][1000];
   memset(dp,-1,sizeof(dp));
   dp[1][0]=0;
   vector <ll> poss;
   poss.pb(1);
   for(ll i=0;i<999;i++)
   {
       vector <ll> temp;
       for(ll j=0;j<poss.size();j++)
       {
              for(auto z:v[poss[j]]) 
              {
                  if(dp[z][i+1]==-1)
                  {
                       temp.pb(z);
                       dp[z][i+1]=M[z]+dp[poss[j]][i];
                  }
                  else
                  {
                       dp[z][i+1]=max(M[z]+dp[poss[j]][i],dp[z][i+1]);
                  }
              }
       }
       poss=temp;
   }
   ll ans=0;
   for(ll i=0;i<1000;i++) ans=max(ans,dp[1][i]-c*i*i);
   cout<<ans;
}