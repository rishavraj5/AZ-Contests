#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+7;
#define endl '\n'
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

ll dp[501][501];
ll cal(ll n,ll m)
{
    if(n==m)
        return dp[n][m]=0;
    
    if(dp[n][m]!=-1)
        return dp[n][m];
    
    ll ans=1e9;
    for(int i=1;i<=n/2;i++)
    {
        ans=min(1+cal(i,m)+cal(n-i,m),ans);
    }
    for(int j=1;j<=m/2;j++)
    {
        ans=min(1+cal(n,j)+cal(n,m-j),ans);
    }
    return dp[n][m]=ans;
}
int main()
{
    IOS
    int i,j;
    rep(i,0,500)
        rep(j,0,500)
            dp[i][j]=-1;
    for(int i=1;i<=500;i++)
    {
        ll x=cal(i,500);
    }
    w(t)
    {
        ll n,m;
        cin>>n>>m;
        if(dp[n][m]!=-1)
            cout<<dp[n][m]<<endl;
        else 
            cout<<dp[m][n]<<endl;
    }

    return 0;  
}

