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

ll n,m,k;
ll dis[404][404];
ll vis[404][404];
vector<ppl> g[404];

class prioritize{
public: bool operator() (pair<ll,ppl> &a,pair<ll,ppl> &b){
        return a.F > b.F;
    }
};
void dijkstra(ll sc)
{
    ll i,j;
    fr(i,n)
    {
        rep(j,0,n)
        {
            dis[i][j]=1e18;
            vis[i][j]=0;
        }
    }

    dis[sc][0]=0;
    priority_queue<pair<ll,ppl>,vector<pair<ll,ppl>>,prioritize>  q;
    q.push({0,{sc,0}});

    while(!q.empty())
    {
        pair<ll,ppl> curr=q.top();
        q.pop();
        if(vis[curr.S.F][curr.S.S])
            continue;
        vis[curr.S.F][curr.S.S]=1;

        for(auto child: g[curr.S.F])
        {
            ll node=child.F;
            ll wt=child.S;
            if(dis[node][curr.S.S+1]>dis[curr.S.F][curr.S.S]+wt)
            {
                dis[node][curr.S.S+1]=dis[curr.S.F][curr.S.S]+wt;
                q.push({dis[node][curr.S.S+1],{node,curr.S.S+1}});
            }
        }
    }



}
bool cmp(ll x,ll y)
{
    return x>y;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    IOS

    ll i,j;
    cin>>n>>m>>k;

    ll s,t;
    cin>>s>>t;

    vll discount(k);
    rep(i,0,k-1)
        cin>>discount[i];

    sort(all(discount),cmp);

    vll pref(k+1,0);
    fr(i,k)
        pref[i]=pref[i-1]+discount[i-1];

    fr(i,m)
    {
        ll x,y,c;
        cin>>x>>y>>c;
        g[x].eb(y,c);
    }

    dijkstra(s);

    ll ans=1e16;
    //cout<<dis[3][3]<<endl;
    for(ll i=0;i<=n;i++)
    {
        ll distance=dis[t][i];
        if(distance>=1e15)
            continue;
        distance-=pref[min(i,k)];
        ans=min(ans,distance);
    }

    if(ans>=1e16)
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;

    return 0;  
}
 