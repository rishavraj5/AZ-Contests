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

vector<ppl> g[100100];
ll a[100100];
ll vis[100100];
void dfs(ll s,ll curr)
{
    vis[s]=1;
    for(auto ch: g[s])
    {
        if(!vis[ch.F])
        {
            a[ch.F]=curr^ch.S;
            dfs(ch.F,a[ch.F]);
        }
    }

}
struct node
{
    ll cnt;
    node* child[2];
    node()
    {
        cnt=0;
        child[0]=NULL;
        child[1]=NULL;
    }
};

struct trie
{
    node* root;
    trie()
    {
        root=new node;
    }
    void insert(ll x)
    {
        node* curr=root;
        for(ll i=31;i>=0;i--)
        {
            curr->cnt++;
            int ch=((x>>i)&1);
            if(curr->child[ch]==NULL)
            {
                curr->child[ch]=new node;
            }
            curr=curr->child[ch];
        }
        curr->cnt++;
    }
    ll maxxor(ll x)
    {
        node* curr=root;
        ll ans=0;
        for(int i=31;i>=0;i--)
        {
            int ch=((x>>i)&1);
            ch^=1;
            if(curr->child[ch]==NULL or curr->child[ch]->cnt==0)
            {
                ch^=1;
            }
            ans|=(ch<<i);
            curr=curr->child[ch];
        }
        return x^ans;
    }

};


int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    IOS

    ll n,i;
    cin>>n;
    fr(i,n-1)
    {
        ll x,y,c;
        cin>>x>>y>>c;
        g[x].eb(y,c);
        g[y].eb(x,c);
    }

    dfs(1,0);

    trie tt;
    ll ans=0;
    

    fr(i,n)
    {
        //deb(a[i]);
        tt.insert(a[i]);
    }
    fr(i,n)
    {
        ans=max(ans,tt.maxxor(a[i]));
    }
    cout<<ans<<endl;
    return 0;  
}

