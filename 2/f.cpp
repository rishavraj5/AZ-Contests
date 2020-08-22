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

ll dp[2001][2001][2];
ll n,k;
int main()
{
    IOS

    cin>>n>>k;
    dp[0][0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {   
            if(j!=0)
                dp[i+1][j-1][0]+=dp[i][j][0];

            if(j+1==k)
                dp[i+1][j+1][1]+=dp[i][j][0];
            else if(j!=k)
                dp[i+1][j+1][0]+=dp[i][j][0];
            
            if(j!=0)
                dp[i+1][j-1][1]+=dp[i][j][1];
            if(j!=k)
                dp[i+1][j+1][1]+=dp[i][j][1];

            dp[i+1][j-1][0]%=mod;
            dp[i+1][j+1][1]%=mod;
            dp[i+1][j+1][0]%=mod;
            dp[i+1][j-1][1]%=mod;
        }
    }
    cout<<dp[n][0][1]<<endl;


        
    return 0;  
}