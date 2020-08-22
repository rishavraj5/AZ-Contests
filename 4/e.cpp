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

ll dp[503][503];
ll mn[503][503];
ll mx[503][503];
vll v;
ll n;
ll calc(ll st,ll end)
{
    if(st>end)
        return 0;

    if(end>n or st<1)
        return 1e18;
   


    if(dp[st][end]!=-1)
        return dp[st][end];
   
    ll res=1e18;
    for(int i=st;i<=end;i++)
    {
        res=min(res,calc(st,i-1)+calc(i+1,end)+mn[st][i-1]+mx[st][i-1]+mn[i+1][end]+mx[i+1][end]);
    }
    return dp[st][end]=res;
}

int main()
{
    IOS
    
    cin>>n;
    v.assign(n+1,0);
    int i,j;
    fr(i,n) 
        cin>>v[i];
    fr(i,n)
    {
        ll xx=1e18,yy=-1;
        rep(j,i,n)
        {
            xx=min(xx,v[j]);
            yy=max(yy,v[j]);
            mn[i][j]=xx;
            mx[i][j]=yy;
        }
    }
    rep(i,0,n)
        rep(j,0,n) 
            dp[i][j]=-1;
    cout<<calc(1,n)<<endl;

    return 0;  
}

