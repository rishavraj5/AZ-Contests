#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+9;
#define endl '\n'
#define SIGMA 128
const ld PI=3.14159265358979;
#define fr(i,n) for(ll i=1;i<=(n);i++)
#define rep(i,k,n) for(ll i=k;i<=(n);i++)
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
string getBase(ll x,ll b){
    // returns number in reversed form
    //getBase(6,2) gives 011 AND NOT 110
    // make the sizes of returned strings equal before processing
    string ans;
    while(x){
        ans+=('0'+x%b);
        x/=b;
    }
    return ans;
}

struct node
{
    ll ti,si,sum,diff;
    node(ll a=0,ll b=0,ll c=-1e18,ll d=-1e18)
    {
        ti=a;
        si=b;
        sum=c;
        diff=d;
    }
};
node t[400400];
vector<ppl> v;
ll n,m;

node merge(node aa,node bb)
{
    node temp;
    temp.sum=max(aa.sum,bb.sum);
    temp.diff=max(aa.diff,bb.diff);
    return temp;
}
void build(int idx,int l,int r)
{
    if(l>r)
        return;
    if(l==r)
    {
        t[idx].sum=v[l].S+v[l].F;
        t[idx].diff=v[l].S-v[l].F;
        //cout<<t[idx].sum<<" "<<t[idx].diff<<" "<<idx<<endl;
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);

    t[idx]=merge(t[idx<<1],t[idx<<1|1]);
}

node query(int idx,int l,int r,int ql,int qr)
{
    if(l>r)
        return node();
    if(l>qr or r<ql)
        return node();
    if(ql<=l and r<=qr)
        return t[idx];
    int mid=(l+r)>>1;
    return merge(query(idx<<1,l,mid,ql,qr),query(idx<<1|1,mid+1,r,ql,qr));
}
void solve()
{
    cin>>n>>m;
    fr(i,n)
    {
        ll x,y;
        cin>>x>>y;
        v.eb(x,y);
    }
    sort(all(v));
    build(1,0,n-1);
   

    ll ans=0;
    rep(i,0,n-1)
    {
        ppl pp1=mp(v[i].F+m,1e18);
        ppl pp2=mp(v[i].F-m,-1e18);
        ll val1=0,val2=0;

        ll idx=UB(all(v),pp1)-v.begin();
        idx--;
        node xx,yy;
        if(i<idx)
        {
            //deb2(i,idx);
            //xx=query(1,0,n-1,i+1,idx);
            //cout<<xx.sum<<endl;
            val1=max(val1,xx.sum+v[i].S-v[i].F);
        }
        idx=LB(all(v),pp2)-v.begin();

        if(i>idx)
        {
            //deb2(i,idx);
            yy=query(1,0,n-1,idx,i-1);
            //cout<<yy.diff<<endl;
            val2=max(val2,yy.diff+v[i].S+v[i].F);
        }
        ans=max({ans,val1,val2});
    }
    cout<<ans<<endl;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    IOS

    //w(_)
        solve();
    
    return 0;  
}

