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

const int MAX=1e7+7;
bool v[MAX];
ll sp[MAX];

void Sieve(){                                   // Oprimised primefactorisation
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


ll number(string &s)
{
    int power=1;
    int len=s.length();
    ll num=0;
    for(int i=len-1;i>=0;i--)
    {
        num+=(s[i]-48)*power;
        power*=10;
    }
    return num;
}

void solve()
{
    string n;
    cin>>n;
    ll cntdig=n.length();
    
    string newstr=n;
    for(int i=1;i<=9;i++)
    {
        newstr[0]=i+48;
        ll xx=number(newstr);
        if(xx!=1 and sp[xx]==xx)
        {
            cout<<"yes"<<endl;
            return;
        }
    }
    for(int idx=1;idx<n.length();idx++)
    {
        newstr=n;
        for(int i=0;i<=9;i++)
        {
            newstr[idx]=i+48;
            ll xx=number(newstr);
            if(xx!=1 and sp[xx]==xx)
            {
                cout<<"yes"<<endl;
                return;
            }
        }   
    }
    cout<<"no"<<endl;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    IOS
    Sieve();

    w(_)
    {
        solve();
    }

    return 0;  
}

