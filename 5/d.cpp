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

    w(_)
    {
        ll n,i;
        cin>>n;
        vll v(n+1);
        map<ll,ll> freq;
        fr(i,n)
        {
            cin>>v[i];
            freq[v[i]]++;
        }
        
        map<ll,ppl> fir;
        
        fr(i,n)
        {
            if(fir.find(v[i])==fir.end())
            {
                fir[v[i]]={i,i};
            }
            else
            {
                fir[v[i]].F=min(fir[v[i]].F,i);
                fir[v[i]].S=max(fir[v[i]].S,i);
            }
        }
        
        vector<pair<ppl,ll>> rng;
        
        for(auto pp: fir)
        {
            //cout<<pp.F<<"-> "<<pp.S.F<<" "<<pp.S.S<<endl;
            rng.eb(mp(mp(pp.S.F,pp.S.S),freq[pp.F]));
        }
        sort(all(rng));



        vector<pair<ppl,ll>> newrng;
        
        ll x=rng[0].F.F;
        ll y=rng[0].F.S;
        ll mx=rng[0].S;
        //deb2(x,y);
        
        for(int i=1;i<rng.size();i++)
        {
            if(rng[i].F.F>y)
            {
                newrng.eb(mp(mp(x,y),mx));
                x=rng[i].F.F;
                y=rng[i].F.S;
                mx=rng[i].S;
            }
            else
            {
                y=max(y,rng[i].F.S);
                mx=max(mx,rng[i].S);
            }
        }        

        newrng.eb(mp(mp(x,y),mx));
        // for(int i=0;i<newrng.size();i++)
        // {
        //     cout<<newrng[i].F.F<<" "<<newrng[i].F.S<<" "<<newrng[i].S<<endl;
        // }

        ll ans=0;
        for(int i=0;i<newrng.size();i++)
        {
            ans+=(newrng[i].F.S-newrng[i].F.F-newrng[i].S+1);
        }
        cout<<ans<<endl;
    }

    return 0;  
}

