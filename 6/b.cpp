#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+7;
#define endl '\n'
#define SIGMA 128
const ld PI=3.14159265358979;
#define fr(i,n) for(ll i=1;i<=(n);i++)
#define rep(i,k,n) for(ll i=k;i<=(n);i++)
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
string getBase(ll x,ll b){
    // returns number in reversed form
    //getBase(6,2) gives 011 AND NOT 110
    // make the sizes of returned strings equal before processing
    string ans;
    while(x){
        ans+=('0'+x%b);
        x/=b;
    }
    return ans;
}

ll n;
vll g[100101];
ll in[100100];
ll out[100100];

void dfs1(ll s,ll par)
{
    for(auto child: g[s])
    {
        if(par==child)
            continue;
        dfs1(child,s);
        in[s]=max(in[s],in[child]+1);
    }
}

void dfs2(ll s,ll par)
{
    ll max1=-1,max2=-1;
    for(auto child: g[s])
    {
        if(child==par)
            continue;
        
        if(in[child]>=max1)
        {
            max2=max1;
            max1=in[child];
        }
        else if(in[child]>max2)
        {
            max2=in[child];
        }
    }

    for(auto child: g[s])
    {
        if(child==par)
            continue;
        out[child]=out[s]+1;
        if(in[child]==max1)
        {
            out[child]=max(out[child],2+max2);    
        }
        else
        {
            out[child]=max(out[child],2+max1);
        }
        dfs2(child,s);
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    IOS

    cin>>n;
    fr(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        g[x].eb(y);
        g[y].eb(x);
    }

    dfs1(1,0);
    dfs2(1,0);

    ll ans=0;
    //cout<<endl;
    fr(i,n)
    {
        ans=max(ans,in[i]+out[i]);
        //cout<<in[i]<<" "<<out[i]<<endl;
    }

    rep(i,2,n)
    {
        if((in[i]+out[i])!=ans)
        {
            cout<<"YES"<<endl;
            exit(0);
        }
    }
    cout<<"NO"<<endl;
    return 0;  
}
 