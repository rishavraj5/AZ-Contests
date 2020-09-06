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
//  ./a.out < input.txt > output.txt 
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
void solve()
{
    ll n;
    cin>>n;
    vector<ppl> v(n);
    rep(i,0,n-1)
        cin>>v[i].F>>v[i].S;
    sort(all(v));
    int i=0;
    int day=0;
    int cnt=0;
    mset<int> s;

    while(i<n)
    {   
        while(!s.empty())
        {
            int val=(*s.begin());
            if(val<day)
                s.erase(s.begin());
            else
                break;
        }
        
        if(s.empty())
            day=v[i].F;

        while(i<n and v[i].F<=day)
        {
            s.insert(v[i].S);
            i++;
        }
        cnt++;
        day++;
        s.erase(s.begin());
    }
    
    for(auto it=s.begin();it!=s.end();it++)
    {
        if(day<=(*it))
        {
            day++;
            cnt++;
        }
    }

    cout<<cnt<<endl;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    IOS

    w(_)
        solve();
    
    return 0;  
}

