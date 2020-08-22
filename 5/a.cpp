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



struct UnionFind{
    int n,set_size, *parent, *rank;
    UnionFind(){}
    UnionFind(int a)
    {
        n=set_size=a;
        parent=new int[n+1];
        rank=new int[n+1];
        for(int i=0;i<=n;i++)
        {
            rank[i]=1;
            parent[i]=i;
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
                parent[xroot]=yroot;
                rank[yroot]+=rank[xroot];
            }
            else
            {
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
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    IOS

    w(_)
    {
        ll n,c,i,m,r;
        cin>>n>>m>>c>>r;
        UnionFind uf(n+1);
        vector<pair<ll,ppl>> edge;
        fr(i,m)
        {
            ll x,y;
            cin>>x>>y;
            edge.eb(r,mp(x,y));
        }
        fr(i,n)
        {
            edge.eb(c,mp(0,i));
        }
        sort(all(edge));
        ll cost=0;
        for(auto pp: edge)
        {
            if(uf.find(pp.S.F)!=uf.find(pp.S.S))
            {
                uf.merge(pp.S.F,pp.S.S);
                cost+=pp.F;
            }
        }
        cout<<cost<<endl;
    }




    return 0;  
}

