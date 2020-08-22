#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+7;
#define endl '\n'
#define SIGMA 128
const ld PI=3.14159265358979;
#define fr(i,n) for(i=1;i<=n;i++)
#define rep(i,k,n) for(i=k;i<=n;i++)
#define w(x) int x;cin>>x;while(x--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ps(x,y) cout<<fixed<<setprecision(y)<<x<<endl
#define pb push_back
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vll vector<ll>
#define vvl vector<vll>
#define ppi pair<int,int>
#define ppl pair<ll,ll>
#define F first
#define S second 
#define LB lower_bound
#define UB upper_bound
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll binpow(ll x, ll y, ll p){  ll res = 1;x = x % p;if (x == 0)return 0;while (y > 0)  { if (y & 1) res = (res*x) % p; y = y>>1;x = (x*x) % p;}return res;}  
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a % b); } 
bool parity(ll x,ll y){ bool f = ((x ^ y) < 0);return !f;}


ll t[400400];

void update(ll idx,ll l,ll r,ll pos,ll val)
{
    if(l>r)
        return;
    if(l>pos or r<pos)
        return;
    if(pos==l and pos==r)
    {
        t[idx]=val;
        return;
    }
    ll mid=(l+r)>>1;
    update(idx<<1,l,mid,pos,val);
    update(idx<<1|1,mid+1,r,pos,val);
    t[idx]=min(t[idx<<1],t[idx<<1|1]);

}

ll query(ll idx,ll l,ll r,ll ql,ll qr)
{
    if(l>r)
        return 1e16;
    if(l>qr or r<ql)
        return 1e16;

    if(ql<=l and r<=qr)
        return t[idx];
    
    ll mid=(l+r)>>1;

    return min(query(idx<<1,l,mid,ql,qr),query(idx<<1|1,mid+1,r,ql,qr));
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    IOS

    ll n,c,d,i;
    cin>>n>>c>>d;
    vector<pair<ll,ppl>> v(n);
    
    rep(i,0,n-1)
        cin>>v[i].F>>v[i].S.F>>v[i].S.S;
    sort(all(v));


    rep(i,0,400100)
        t[i]=1e16;

    update(1,0,d,d,0);

    for(ll i=n-1;i>=0;i--)
    {
        if(v[i].F==d)
            continue;
        ll val=query(1,0,d,v[i].F,min(d,v[i].F+v[i].S.S));
        if(val<1e16)
        {
            update(1,0,d,v[i].F,val+v[i].S.F);
        }
    }

    ll val=query(1,0,d,0,min(c,d));
    
    if(val>=1e16)
        cout<<"-1"<<endl;
    else
        cout<<val<<endl;        

    return 0;  
}
 