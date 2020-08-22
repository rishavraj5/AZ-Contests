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

ll n,k;
ll dp[100003];
ll minsum(ll curr,vll &pre)
{
    if(curr>n)
        return 0;

    if(dp[curr]!=-1)
        return dp[curr];

    ll res=0,ans=1e12,power=0;
    for(int i=curr;i<=n;)
    {
        res=pre[i]^pre[curr-1];
        res+=minsum(i+1,pre);
        ans=min(ans,res);
        //cout<<curr<<" "<<ans<<" "<<endl;
        power++;
        i=curr+binpow(2,power,1e18)-1;
    }
    return dp[curr]=ans;
}



int main()
{
    IOS
    
    for(int i=0;i<=100001;i++)
        dp[i]=-1;

    cin>>n;


    vll v(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    vll pre(n+1,0);
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]^v[i];
    }

    cout<<minsum(1,pre)<<endl;

    return 0;
}