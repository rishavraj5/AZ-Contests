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


int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    IOS

    ll n,i;
    cin>>n;
    vll v(n+1);
    fr(i,n)
        cin>>v[i];
    ll ans=0;
    for(ll i=1;i*i<=n;i++)
    {
        ll cnt0=0,cnt1=0;
        ll sz=i+(i*i);
        if(sz>n)
            break;
        for(ll j=1;j<sz;j++)
        {
            if(v[j]==0)
                cnt0++;
            else
                cnt1++;
        }
        for(ll j=sz;j<=n;j++)
        {
            if(v[j]==0)
                cnt0++;
            else
                cnt1++;

            if(cnt1==(cnt0*cnt0))
                ans++;

            if(v[j-sz+1]==0)
                cnt0--;
            else
                cnt1--;
        }
        
    }
    cout<<ans<<endl;
    return 0;  
}

