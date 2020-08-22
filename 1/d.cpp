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
#define MAX 1000001
bool v[MAX];
ll sp[MAX];
void Sieve()
{                                   // Oprimised primefactorisation
	for (int i = 2; i < MAX; i += 2)	        //by storing minimum prime factors
        sp[i] = 2;
	for (ll i = 3; i < MAX; i += 2)
    {
		if (!v[i])
        {
			sp[i] = i;
			for (ll j = i; (j*i) < MAX; j += 2)
            {
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
		}
	}
}

ll factorize(ll x)
{
    ll ans=1;
    while(x!=1)
    {
        ll p=sp[x];
        ll count=0;
        while(x%p==0)
        {
            x/=p;
            count++;
        }
        ans=(1LL*ans*(count+1));
    }
    return ans;
}



int main()
{
    IOS
    Sieve();
    vll count(1000002);
    vll pre(1000002,0);
    
    for(int i=1;i<=1000000;i++)
    {
        count[i]=factorize(i);
        pre[i]=pre[i-1]+count[i];
    }

    w(t)
    {
        ll l,r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<endl;
    }
    
    return 0;
}