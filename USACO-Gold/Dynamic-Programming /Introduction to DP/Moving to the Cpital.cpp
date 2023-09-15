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
  ll t,n,m;
  cin>>t;
  while(t--)
  {
     cin>>n>>m;
     vector <ll> v[n+1];
     f(i,m)
     {
        ll x,y;cin>>x>>y;
        v[x].pb(y);
     }
     vector <ll> dp(n+1,-1);
     queue  <ll> q;
     dp[1]=0;
     q.push(1);
     while(!q.empty())
     {
        ll node=q.front();q.pop();
        for(auto z:v[node])
        {
           if(dp[z]==-1) 
           {
               dp[z]=1+dp[node];
               q.push(z);
           }
        }
     }
     vector <ll> ans(n+1);
     vector <pair<ll,ll>> vr(n);
     f(i,n)
     {
        ans[i+1]=dp[i+1];
        vr[i]={dp[i+1],i+1};
     }
     sort(rall(vr));
     for(auto node : vr)
     {
         for(auto k : v[node.second])
         {
              if(dp[k]!=dp[node.second]) ans[node.second]=min(ans[k],ans[node.second]);
         }
     }
     f(i,n) cout<<ans[i+1]<<' ';
     cout<<"\n";
  }
}