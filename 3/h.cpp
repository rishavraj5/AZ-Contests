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

ll n,m,q;
ll cnt[1001][1001];
ll mat[1001][1001];

bool valid(ll x,ll y)
{
    return (x>=1 and y>=1 and x<=n and y<=m);
}
bool possible(ll step,ll x,ll y,ll k)
{
    ll startx=x-step;
    ll starty=y-step;
    ll endx=x+step;
    ll endy=y+step;
    if(valid(startx,starty) and valid(endx,endy))
    {
        ll val=cnt[endx][endy]+cnt[startx-1][starty-1]-cnt[startx-1][endy]-cnt[endx][starty-1];
        return val<=k;
    }
    return false;
}

int main()
{
    IOS
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cnt[i][j]=(mat[i][j]==1);
            cnt[i][j]+=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
        }
    }
    
    cin>>q;
    while(q--)
    {
        ll x,y,k;
        cin>>x>>y>>k;
        x++;y++;
        ll lo=0,hi=2000,ans=0;
        while(lo<=hi)
        {
            ll mid=(lo+hi)/2;
            if(possible(mid,x,y,k))
            {
                ans=2*mid+1;
                ans*=ans;
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;  
}

