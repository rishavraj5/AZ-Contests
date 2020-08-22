
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+7;
#define endl '\n'
const ld PI=3.14159265358979;
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


const int maxN=1e5+100;
bool sieve[maxN];
ll dp[maxN];
ll cnt[maxN];
vll v;

int main()
{
    IOS
    ll n,x,r1,r2;
    cin>>n>>x>>r1>>r2;
    for(int i=2;i<maxN;i++)
        sieve[i]=true;
    for(int i=2;i*i<maxN;i++)
    {
        for(int j=i*i;j<maxN;j+=i)
        {
            sieve[j]=false;
        }
    }
    for(int i=2;i<maxN;i++)
    {
        cnt[i]=cnt[i-1]+sieve[i];
    }
    v.assign(n+1,0);
    for(ll i=1;i<=n;i++)
    {
        if((cnt[i]*r2)>=(r1*i))
            v[i]=1;
        else
        {
            v[i]=0;
        }
    }
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        dp[i]=1+dp[i-1];
        if((i-x)>=1)
        {
            if(v[i-x])
                dp[i]=min(dp[i-x]+1,dp[i]);
        }
    }
    cout<<dp[n]<<endl;

        
    return 0;  
}