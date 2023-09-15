// my_std_headers.h
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int
#define pb push_back
using namespace std;
 
ll n,q;
vector <ll>   a(200005);
vector <ll>   BIT(400005,0);
vector <ll>   v[200005];
vector <bool> vis(200005,false);
vector <ll>   strt(200005),en(200005);
vector <ll>   etour(400005);
vector <ll>   ans(200005,0);
 
int t=1;
void dfs(ll node)
{
  vis[node]=true;
  strt[node]=t++;
  ans[node]+=a[node];
  for(auto z:v[node])
  {
     if(!vis[z]) 
      {
        ans[z]+=ans[node];
        dfs(z);
      }
  }
  en[node]=t++;
}
 
void update(ll i,ll x)
{
   // increment ith index by x
   while(i<=(2*n+1))
   {
      BIT[i]+=x;
	    i+=(i & -i);
   }
}
 
ll pref(ll i)
{
	ll ans=0;
	while(i>0)
	{
		ans+=BIT[i];
		i-=(i & -i);
	}
	return ans;
}
 
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    
  cin>>n>>q;
  for(ll i=1;i<=n;i++) cin>>a[i];

  for(ll i=1;i<n;i++)
  {
    ll x,y;cin>>x>>y;
    v[x].pb(y);
    v[y].pb(x);
  }
  
  dfs(1);

  while(q--)
  {
     ll type;
     cin>>type;

     if(type == 1)
     {
        ll s,x;cin>>s>>x;
        ll upd=x-a[s];
        a[s]=x;
        update(strt[s],upd);
        update(en[s]+1,-1*upd);
     }
     else
     {
        ll s;cin>>s;
        cout<<pref(strt[s])+ans[s]<<"\n";
     }
  }
  
}