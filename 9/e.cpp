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
    ll val,maxi;
    node(ll a=1e9,ll b=1e9)
    {
        val=a;
        maxi=b;
    }   
};
node t[800800];
vll v;
node merge(node aa,node bb)
{
    node temp;
    temp.maxi=max(aa.maxi,bb.maxi);
    return temp;
}
void build(int idx,int l,int r)
{
    if(l>r)
        return;
    if(l==r)
    {
        t[idx]=node(v[l],v[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    t[idx]=merge(t[idx<<1],t[idx<<1|1]);
}
void update(int idx,int l,int r,int pos,ll key)
{
    if(l>r)
        return;
    if(l>pos or r<pos)
        return;
    if(pos==l and pos==r)
    {
        t[idx]=node(v[pos]-key,v[pos]-key);
        v[pos]-=key;
        return;
    }
    int mid=(l+r)>>1;
    update(idx<<1,l,mid,pos,key);
    update(idx<<1|1,mid+1,r,pos,key);
    t[idx]=merge(t[idx<<1],t[idx<<1|1]);
}
ll query(int idx,int l,int r,ll val)
{
    if(l>r)
        return 1e9;
    if(l==r)
    {
        if(t[idx].maxi>=val)
            return l;
        return 1e9;
    }
    
    int mid=(l+r)>>1;
    
    if(val<=t[idx<<1].maxi)
        return query(idx<<1,l,mid,val);
    else if(val<=t[idx<<1|1].maxi)
        return query(idx<<1|1,mid+1,r,val);

    return 1e9;
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    rep(i,0,n-1)
    {
        ll x;
        cin>>x;
        v.eb(x);
    }
    build(1,0,n-1);
    while(m--)
    {
        ll x;
        cin>>x;
        ll res=query(1,0,n-1,x);
        //deb(res);
        if(res>=1e9)
        {
            cout<<"0 ";
            continue;
        }
        cout<<res+1<<" ";
        update(1,0,n-1,res,x);
    }
    cout<<endl;
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
 