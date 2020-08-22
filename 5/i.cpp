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

ll dp[1010][1010];
ll cost(ll x1,ll y1,ll x2,ll y2)
{
    ll val=(x1-x2)*(x1-x2);
    val+=(y1-y2)*(y1-y2);
    //deb(val);
    return val;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    IOS

    string s,t;
    ll n,m;
    cin>>n>>m;
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    cin>>s>>t;

    dp[0][0]=0;

    ll newx=x1,newy=y1;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='N')
            newy++;
        else if(s[i-1]=='E')
            newx++;
        else if(s[i-1]=='W')
            newx--;
        else
            newy--; 

        dp[i][0]=cost(newx,newy,x2,y2);
        dp[i][0]+=dp[i-1][0];
    }

    newx=x2;
    newy=y2;
    for(int j=1;j<=m;j++)
    { 
    
        if(t[j-1]=='N')
            newy++;
        else if(t[j-1]=='E')
            newx++;
        else if(t[j-1]=='W')
            newx--;
        else
            newy--; 
        dp[0][j]=cost(x1,y1,newx,newy);
        dp[0][j]+=dp[0][j-1];
    }

    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='N')
            y1++;
        else if(s[i-1]=='E')
            x1++;
        else if(s[i-1]=='W')
            x1--;
        else
            y1--;
        
        newx=x2;
        newy=y2;
        for(int j=1;j<=m;j++)
        {    
            if(t[j-1]=='N')
                newy++;
            else if(t[j-1]=='E')
                newx++;
            else if(t[j-1]=='W')
                newx--;
            else
                newy--; 

            dp[i][j]=cost(x1,y1,newx,newy);

            dp[i][j]+=min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
        }
    }

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    cout<<dp[n][m]<<endl;

    return 0;  
}

