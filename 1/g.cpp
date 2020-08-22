#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+7;
#define endl '\n'
#define w(x) int x;cin>>x;while(x--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vll vector<ll>
#define ppi pair<Sint,int>
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

ll n;


int main()
{
    IOS

    cin>>n;
    vll v(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    
    vll product(n+1);
    product[0]=1;
    for(int i=1;i<=n;i++)
    {
        product[i]=(1LL*product[i-1]*i);
        product[i]%=mod;
    } 

    vll  d(n+1);
    d[1]=0;
    d[2]=1;
    for(int i=3;i<=n;i++)
    {
        d[i]=1LL*(i-1)*(d[i-1]+d[i-2]);
        d[i]%=mod;
    }

    vll ans(n+1);
    ans[0]=1;
    ans[1]=0;
    for(int i=2;i<=n;i++)
    {
        ll fir=product[n];
        fir%=mod;
        fir*=d[i];
        fir%=mod;
        ll div=1LL*product[i]*product[n-i];
        div=binpow(div,mod-2,mod);
        fir=1LL*fir*div;
        fir%=mod;
        ans[i]=fir;
    }
    
    vll pre(n+1,0);
    pre[0]=1;
    for(int i=1;i<=n;i++)
    {
        pre[i]=ans[i]+pre[i-1];
        pre[i]%=mod;
    }
    w(q)
    {
        ll k;
        cin>>k;
        cout<<pre[k]<<endl;
    }

    return 0;
}