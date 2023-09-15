#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
 
ll n;
vector <ll>   a(200005);
vector <ll>   BIT(400005.0);
vector <ll>   v[200005];
vector <bool> vis(200005,false);
vector <ll>   strt(200005),en(200005);
vector <ll>   etour(400005);
 
int t=1;
void dfs(ll node)
{
  vis[node]=true;
  strt[node]=t++;
  for(auto z:v[node])
  {
     if(!vis[z]) dfs(z);
  }
  en[node]=t++;
}
 
void update(ll i,ll x)
{
   // increment ith index by x
   while(i<=(2*n))
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
  vector <ll> temp(n);
  for(ll i=1;i<=n;i++) {cin>>a[i];temp[i-1]=a[i];}
  
  sort(temp.begin(),temp.end());
  map <ll,ll> mp;
  ll z=1;
  for(ll i=0;i<n;i++)
  {
    if(!(i>0 && temp[i]==temp[i-1])) mp[temp[i]]=z++;
  }
  
  for(ll i=1;i<=n;i++) a[i]=mp[a[i]];
  
  for(ll i=1;i<n;i++)
  {
    ll x,y;cin>>x>>y;
	v[x].pb(y);
	v[y].pb(x);
  }
  
  dfs(1);
  
  vector <ll> last(n+1,-1);
  vector <ll> is_end(2*n+1,-1);
  for(ll i=1;i<=n;i++) {etour[strt[i]]=etour[en[i]]=a[i];is_end[en[i]]=i;}
  
  vector <int> ans(n+1);
  for(int i=1;i<=2*n;i++) 
  {
      if(last[etour[i]]==-1)
	  {
		  update(i,1);
		  last[etour[i]]=i;
	  }
	  else
	  {
		  update(last[etour[i]],-1);
		  update(i,1);
		  last[etour[i]]=i;
	  }
	  if(is_end[i]!=-1)
		  
	  {
		  ll node=is_end[i];
		  ll j=strt[node];
		  ans[node]=pref(i)-pref(j-1);
	  }
  }
  for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
}