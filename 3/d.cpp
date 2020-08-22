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

bitset<101> dis[100100];
vi color;

struct UnionFind{
    int n,set_size, *parent, *rank;
    UnionFind(){}
    UnionFind(int a)
    {
        n=set_size=a;
        parent=new int[n+1];
        rank=new int[n+1];
        for(int i=1;i<=n;i++)
        {
            rank[i]=1;
            parent[i]=i;
            dis[i].set(color[i]);
        }
    }
    int find(int x)
    {
        if(parent[x]!=x)
            return parent[x]=find(parent[x]);
        return x;
    }
    void merge(int x,int y)
    {
        int xroot=find(x),yroot=find(y);
        if(xroot!=yroot)
        {
            if(rank[xroot]<rank[yroot])
            {
                dis[yroot]|=dis[xroot];
                parent[xroot]=yroot;
                rank[yroot]+=rank[xroot];

            }
            else
            {
                dis[xroot]|=dis[yroot];
                parent[yroot]=xroot;
                rank[xroot]+=rank[yroot];
            }
            set_size-=1;
        }
    }
    void reset()
    {
        set_size=n;
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
    }
    int size()
    {
        return set_size;
    }
    void print()
    {
        for(int i=1;i<=n;i++)
            cout<<i<<" --> "<<parent[i]<<endl;
    }

};
int main()
{
    IOS
    
    ll n,m,q;
    cin>>n>>m>>q;
    color.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>color[i];

    vector<ppi> edge(m+1);
    vector<ppi> query(q+1);
    vi remove(m+1,0);

    for(int i=1;i<=m;i++)
    {
        cin>>edge[i].F>>edge[i].S;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>query[i].F>>query[i].S;
        if(query[i].F==1)
        {
            remove[query[i].S]=1;
        }
    }

    UnionFind uf(n);
    for(int i=1;i<=m;i++)
    {
        if(!remove[i])
        {
            uf.merge(edge[i].F,edge[i].S);
        }
    }
    vi ans;
    for(int i=q;i>=1;i--)
    {
        if(query[i].F==1)
        {
            uf.merge(edge[query[i].S].F,edge[query[i].S].S);
        }
        else 
        {
            int par=uf.find(query[i].S);
            ans.eb(dis[par].count());
        }
    }
    reverse(all(ans));
    for(int i=0;i<(int)ans.size();i++)
        cout<<ans[i]<<endl;


    return 0;  
}

