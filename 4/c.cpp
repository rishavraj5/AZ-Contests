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

    w(t)
    {
        int n,m,i,j;
        cin>>n;
        string s[n+1];
        int maxlen=0;
        fr(i,n)
        {
            cin>>s[i];
            maxlen=max(maxlen,(int)s[i].length());
        }
        string target;
        cin>>target;
        m=(int)target.length();
        
        ll cnt[maxlen+1][SIGMA];
        rep(i,0,maxlen)
            rep(j,0,126)
                cnt[i][j]=0;
        fr(i,n)
        {
            for(int j=0;j<s[i].size();j++)
            {
                cnt[j+1][s[i][j]]++;
            }
        }
        
        ll dp[m+1][maxlen+1];

        rep(i,0,m)
            rep(j,0,maxlen)
                dp[i][j]=0;
        
        for(int i=0;i<=maxlen;i++)
            dp[0][i]=1;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=maxlen;j++)
            {
                dp[i][j]=dp[i][j-1];
                dp[i][j]+=(1LL*cnt[j][target[i-1]]*dp[i-1][j-1])%mod;
                dp[i][j]%=mod;
            }
        }
        cout<<dp[m][maxlen]<<endl;
    }

    return 0;  
}


