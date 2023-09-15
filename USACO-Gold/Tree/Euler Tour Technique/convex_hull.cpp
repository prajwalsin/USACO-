#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F first 
#define S second
pair <long long,long long> mn;
long long crosspro(pair <long long,long long> piv,pair <long long,long long> a,pair <long long,long long> b)
{
    long long cp = piv.F*(a.S-b.S)+a.F*(b.S-piv.S)+b.F*(piv.S-a.S);
    if(cp > 0) return  1;
    if(cp < 0) return -1;
    return 0;
}
bool cmp(pair <long long,long long> a,pair <long long,long long> b)
{
    long long cp = crosspro(mn,a,b);
    if(cp == 0)
    {
        return (a.F-mn.F)*(a.F-mn.F) + (a.S-mn.S)*(a.S-mn.S) > (b.F-mn.F)*(b.F-mn.F) + (b.S-mn.S)*(b.S-mn.S);
    }
    else
    {
        if(cp>0) return true;
        else     return false;
    }
}
int main()
{
    while(true)
    {
        long long n;cin>>n;
        if(n==0) break;
        vector <pair<long long,long long>> a(n);
        mn.F=mn.S=100000;
        for(long long i=0;i<n;i++) 
        {
            long long x,y;cin>>x>>y;
            a[i]={x,y};
            if(y<mn.S)
            {
                mn.S=y;
                mn.F=x;
            }
            else if(y==mn.S)
            {
                mn.F=min(mn.F,x);
            }
        }
        sort(a.begin(),a.end(),cmp);
        // Graham Scan 
        stack <pair<long long,long long>> s;
        s.push(mn);
        for(long long i=0;i<(n-1);i++)
        {
            if(s.size()==1)
            {
                if(a[i].F==mn.F && a[i].S==mn.S) continue;
                else                             s.push(a[i]);
            }
            else
            {
                while(s.size()>=2)
                {
                // check where a[i] can be a possible vertex
                pair <long long,long long> p1=s.top();s.pop();
                pair <long long,long long> p2=s.top();
                // p2->p1 , p1->a
                ll cp=crosspro(p1,p2,a[i]);
                if(cp == 0) 
                {
                    if(p2==mn) s.push(p1);
                    else       s.push(a[i]);
                    break;
                }
                if(crosspro(p1,p2,a[i])<0)
                {
                    s.push(p1);
                    s.push(a[i]);
                    break;
                }
                }
                //if(s.size()==1) s.push(a[i]);
            }
        }
        if(s.size()>=3)
        {
            pair <ll,ll> p1=s.top();s.pop();
            pair <ll,ll> p2=s.top();
            if(crosspro(mn,p1,p2)!=0) s.push(p1); 
        }
        vector <pair<long long,long long>> ans;
        cout<<s.size()<<"\n";
        while(!s.empty())
        {
           ans.push_back(s.top());
           s.pop();
        }
        for(long long i=ans.size()-1;i>=0;i--) cout<<ans[i].F<<' '<<ans[i].S<<"\n";
    }
}
