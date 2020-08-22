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

bool possible(ll x,vll &v)
{
    ll sum=0,count=0,mx=0;
    for(int i=1;i<=n;i++)
    {
        if((sum+v[i])>x)
        {   
            mx=max(sum,mx);
            sum=v[i];
            count++;
            if(count==k)
                return false;
        }
        else
        {
            sum+=v[i];
        }
        
    }
    mx=max(sum,mx);
    return mx<=x;
}

int main()
{
    cin>>n>>k;

    vll v(n+1);
    ll sum=0;
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    ll lo=0,hi=sum,ans=0;
    while(lo<=hi)
    {
        ll mid=(lo+hi)/2;
        if(possible(mid,v))
        {
            ans=mid;
            hi=mid-1;
            //cout<<ans<<" ";
        }
        else
        {
            lo=mid+1;
        }
        
    }
    cout<<ans<<endl;
    
    return 0;
}