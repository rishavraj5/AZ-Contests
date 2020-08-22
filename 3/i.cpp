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


void solve()
{
    ll n;
    cin>>n;
    vll v(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    ll k;
    cin>>k;
    vll dp(n+1,0);
    dp[1]=v[1];
    deque<ll> dq;
    dq.push_front(1);
    for(int i=2;i<=n;i++)
    {
        dp[i]=v[i]+dp[dq.front()];

        if(dq.empty())
        {
            dq.push_front(i);
            continue;
        }
        if(dq.front()<=(i-k))
            dq.pop_front();
        while(!dq.empty() and dp[i]>=dp[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<dp[n]<<endl;
}

int main()
{
    IOS
    
    w(t)
    {
        solve();
    }
    return 0;  
}

