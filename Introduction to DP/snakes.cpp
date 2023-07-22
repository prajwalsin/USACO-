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
    freopen("snakes.in", "r", stdin);
 
  // Printing the Output to output.txt file
    freopen("snakes.out", "w", stdout);

   ll n,k;cin>>n>>k;
   k++;
   vector <ll> a(n);
   f(i,n) cin>>a[i];
   ll dp[n][k+1];
   memset(dp,-1,sizeof(dp));
   // base case 
   dp[0][1]=0;
   for(ll i=1;i<n;i++)
   {
       for(ll l=1;l<=k;l++)
       {
           ll mx=a[i];
           ll sum=0;
           for(ll j=i;j>=0;j--)
           {
                // all from i to j will be in the same group 
                mx=max(mx,a[j]);
                sum+=a[j];
                    // total number of groups 
                    if(j==0)
                    {
                        if(l==1) dp[i][l]=(i-j+1)*mx - sum;
                    }
                    else
                    {
                        // only possible of j >= l-1
                        if(dp[j-1][l-1]!=-1) 
                        {
                            ll val= (i-j+1)*mx - sum + dp[j-1][l-1];
                            dp[i][l] = (dp[i][l]==-1)  ? val : min(dp[i][l],val);
                        }
                    }
           }
       }
   }
   ll ans=1e9;
   for(ll l=1;l<=k;l++) 
   {
      if(dp[n-1][l]!=-1) ans=min(ans,dp[n-1][l]);
   }
   cout<<ans;
}