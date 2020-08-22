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


int main()
{
    IOS

    w(t)
    {
        string s;
    cin>>s;
    map<ll,ll> freq;
    vll added(127,0);
    vll given(127,0);
    for(auto ch: s)
        freq[ch]++;
    string ans="";
    for(int i=97;i<=122;i++)
    {
        for(int j=1;j<=freq[i]/2;j++)
        {
            added[i]=1;
            ans+=(char)i;
            given[i]++;
        }
    }
    for(int i=97;i<=122;i++)    
    {
        if((2*given[i]+1)==freq[i])
        {
            ans+=(char)i;
            break;
        }
    }
    for(int i=122;i>=97;i--)
    {
        if(added[i])
        {
            for(int j=1;j<=given[i];j++)
            {
                ans+=(char)i;
            }
        }
    }
    cout<<ans<<endl;
    }
    
    return 0;  
}

