#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define all(a) a.begin(), a.end()
using namespace std;

vector<ll> a;
vector<ll> seg;
vector<ll> lazy;
vector<ll> lazy_partial;
vector<bool> mark;

// mark[node] = true ->  all elements represented present in this node's range have same value
void unset(ll node)
{
   if (mark[node])
   {
      mark[node] = false;
      mark[2 * node] = mark[2 * node + 1] = true;
      lazy[2 * node] = lazy[2 * node + 1] = lazy[node];
      lazy_partial[2*node] = lazy_partial[2*node+1]=0;
   }
}

void build(ll node, ll l, ll r)
{
   if (l == r)
      seg[node] = a[l];
   else
   {
      ll mid = (l + r) / 2;
      build(2 * node, l, mid);
      build(2 * node, mid + 1, r);
      seg[node] = seg[2 * node] + seg[2 * node + 1];
   }
}

void update_inc(ll val, ll l, ll r, ll node, ll nodel, ll noder)
{
   // no intersection
   if (l > noder || r < nodel)
      return;
   if (l <= nodel && r >= noder)
   {
      lazy[node] += val;
      return;
   }
   else
   {
      ll mid = (nodel + noder) / 2;
      ll l1 = max(nodel, l);
      ll r1 = min(noder, r);
      lazy_partial[node] += (r1 - l1 + 1) * val;
      update_inc(val, l, r, 2 * node, nodel, mid);
      update_inc(val, l, r, 2 * node + 1, mid + 1, noder);
   }
}

void update_same(ll val, ll l, ll r, ll node, ll nodel, ll noder)
{
   // no intersection
   if (l > noder || r < nodel)
      return;
   if (l <= nodel && r >= noder)
   {
      mark[node] = true;
      lazy[node] = val;
      lazy_partial[node] = 0;
      return;
   }
   else
   {
      unset(node);
      ll mid = (nodel + noder) / 2;
      ll l1 = max(nodel, l);
      ll r1 = min(noder, r);
      lazy_partial[node] += (r1 - l1 + 1) * val;
      update_inc(val, l, r, 2 * node, nodel, mid);
      update_inc(val, l, r, 2 * node + 1, mid + 1, noder);
   }
}

ll query(ll l, ll r, ll node, ll nodel, ll noder)
{
   // no intersection
   if (l > noder || r < nodel)
      return 0;
   if (l == nodel && r == noder)
   {
      return seg[node] + (noder - nodel + 1) * lazy[node] + lazy_partial[node];
   }
   else
   {
      ll mid = (nodel + noder) / 2;
      ll inc1 = 0, inc2 = 0;
      if (l <= mid)
      {
         ll R = min(r, mid);
         inc1 = query(l, R, 2 * node, nodel, mid);
      }
      if (r > mid)
      {
         ll L = max(l, mid + 1);
         inc2 = query(L, r, 2 * node + 1, mid + 1, noder);
      }
      ll l1 = max(nodel, l);
      ll r1 = min(noder, r);
      return (r1 - l1 + 1) * lazy[node] + inc1 + inc2;
   }
}
int main()
{
   ll t, n;
   cin >> t;
   while (t--)
   {
      cin >> n;
      a.resize(n);
      seg.resize(4 * n + 5);
      lazy.resize(4 * n + 5);
      lazy_partial.resize(4 * n + 5);
      mark.resize(4 * n + 5);
      fill(all(seg), 0);
      fill(all(lazy), 0);
      fill(all(lazy_partial), 0);
      fill(all(mark), false);

      for (ll i = 0; i < n; i++)
         a[i] = 0;

      ll q;
      cin >> q;
      while (q--)
      {
         int type;
         cin >> type;
         if (type == 0)
         {
            // Update query
            ll l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            update_inc(x, l, r, 1, 0, n - 1);
         }
         else
         {
            // range sum query
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << query(l, r, 1, 0, n - 1) << "\n";
         }
      }
   }
}
