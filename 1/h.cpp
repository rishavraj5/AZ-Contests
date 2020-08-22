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
    w(t)
    {
        cin>>n;
        vll a(n+1);
        vll cnt(100002,0);

        ll mx=1e-5;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mx=max(mx,a[i]);
            cnt[a[i]]++;
        }
        vll pre(mx+1);
        pre[0]=0;
        for(int i=1;i<=mx;i++)
            pre[i]=pre[i-1]+cnt[i];

        ll ans=0;
        for(ll i=1;i<=mx;i++)
        {
            if(cnt[i]>0)
            {
                for(ll j=i;j<=mx;j+=i)
                {
                    ll end=min(j+i-1,mx);
                    ans+=1LL*cnt[i]*(pre[end]-pre[j-1])*(j/i);
                }
            }
        }
        cout<<ans<<endl;
    }
}