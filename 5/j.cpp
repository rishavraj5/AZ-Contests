#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+9;
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
ll binpow(ll x, ll y, ll p){ if(x<=0)return 0;  ll res = 1;x = x % p;if (x == 0)return 0;while (y > 0)  { if (y & 1) res = (res*x) % p; y = y>>1;x = (x*x) % p;}return res;}  
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a % b); } 
bool parity(ll x,ll y){ bool f = ((x ^ y) < 0);return !f;}

ll prod[3003000];
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    IOS
    prod[0]=1;
    for(int i=1;i<=3000000;i++)
    {
        prod[i]=prod[i-1]*i;
        prod[i]%=mod;
    }

    w(_)
    {
        ll A,a,b;
        cin>>A>>a>>b;
        if(a<b)
            swap(a,b);
        int ok=0;
        ll ways;
        if(a>A and (a-b)==2)
        {
            ok=1;
            ways=binpow(2,(b-A+1),mod);
            
            ll val=prod[2*(A-1)];
            ll inv=binpow(prod[A-1],mod-2,mod);
            val*=inv;
            val%=mod;
            val*=inv;
            val%=mod;
            ways*=val;
            ways%=mod;
        }

        if(a==A and (b<a-1))
        {
            ok=1;
            ways=prod[a+b-1];
            ways*=binpow(prod[a-1],mod-2,mod);
            ways%=mod;
            ways*=binpow(prod[b],mod-2,mod);
            ways%=mod;
        }

        if(ok)
        {
            cout<<ways<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
    } 
    
    return 0;  
}
 