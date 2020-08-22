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
bool possible(ll x,vector<ppl> &v)
{
    ll last=mod*mod,more=0,count=0;
    last=(-1)*last;
    for(int i=1;i<=k;i++)
    {
        if((last+x>v[i].S))
            continue;

        if(last+x<v[i].F)
        {
            last=v[i].F;
            count++;
        }
        else
        {
            last=last+x;
            count++;
        }
        
        more=(v[i].S-last)/x;
        last+=(more*x);
        count+=more;
        if(count>=n)
            return true;
    }
    return false;
}



int main()
{
    IOS
    
    cin>>n>>k;
    vector<ppl> v(k+1);
    v[0].F=-1;
    v[0].S=-1;
    for(int i=1;i<=k;i++)
        cin>>v[i].F>>v[i].S;

    sort(all(v));

    ll lo=0,hi=1e18,ans=0;

    while(lo<=hi)
    {
        ll mid=lo+(hi-lo)/2;
        if(possible(mid,v))
        {
            ans=mid;
            lo=mid+1;
            //cout<<ans<<" ";
        }
        else
        {
            hi=mid-1;
        }
        
    }
    cout<<ans<<endl;

    return 0;
}