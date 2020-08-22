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

vll g[1000100];
set<ll> canreach;
vll vis,outdeg;
ll n,m,src,des;
void dfs(ll s)
{
    int cnt=0;
    vis[s]=1;
    for(auto child: g[s])
    {
        if(!vis[child])
        {
            cnt++;
            dfs(child);
        }
        else if(vis[child]==1)
        {
            cout<<"NO"<<endl;
            exit(0);
        }
    }

    if(outdeg[s]==0)
        canreach.insert(s);
    vis[s]=2;
}
int main()
{
    IOS
    int i,j;
    cin>>n>>m;
    outdeg.assign(n+1,0);
    fr(i,m)
    {
        ll x,y;
        cin>>x>>y;
        g[x].eb(y);
        //indeg[y]++;
        outdeg[x]++;
    }

    vis.assign(n+1,0);
    cin>>src>>des;

    dfs(src);
    
    int sz=canreach.size();
    // for(auto x: canreach)
    //     cout<<(x)<<endl;
    // cout<<sz<<endl;
    if(sz==1 and (*canreach.begin())==des)
        cout<<"YES"<<endl;
    else    
        cout<<"NO"<<endl;


    return 0;  
}

