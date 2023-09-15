// my_std_headers.h
#include <iostream>
#include <vector>
#include <algorithm>

#define F first
#define S second 
#define ll long long int
#define pb push_back
using namespace std;
 
ll n,q;
vector <ll>   a(200005);
vector <ll>   BIT(400005,0);
vector <ll>   v[200005];
vector <bool> vis(200005,false);
vector <ll>   strt(200005),en(200005);
vector <ll>   lev_nodes[200005];
vector <ll>   level;

int t=1;
void dfs(ll node)
{
  vis[node]=true;
  strt[node]=t++;
  for(auto z:v[node])
  {
     if(!vis[z]) 
     {
      level[z]=1+level[node];
      dfs(z);
     }
  }
  en[node]=t++;
  lev_nodes[level[node]].pb(node);
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
    
  cin>>n;
  for(ll i=2;i<=n;i++) 
  {
     int par;cin>>par;
     v[par].pb(i);
  }

  level.resize(n+1);
  level[1]=0;
  dfs(1);

  cin>>q;
  vector <int> ans(q);
  vector <pair<int,int> > levq[n];
  for(int i=0;i<q;i++)
  {
     int u,d;
     cin>>u>>d;
     levq[d].pb(make_pair(u,i));
  }

  for(int i=0;i<n;i++)
  {
      for(auto z:lev_nodes[i])
      {
         update(strt[z],1);
      }
      for(auto z:levq[i])
      {
         ans[z.S]=pref(en[z.F])-pref(strt[z.F]-1);
      }
      for(auto z:lev_nodes[i])
      {
         update(strt[z],-1);
      }
  }

  for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
  
}