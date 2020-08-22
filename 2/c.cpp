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

ll n;
vll cnt,result;
int main()
{
    IOS

    w(t)
    {
        string s;
        cin>>n>>s;
        result.assign(28,0);
        for(int dis=1;dis<=26;dis++)
        {
            cnt.assign(127,0);
            ll distinct=0;
            ll ans=0;
            int i=0,j=0;
            while(j<n)
            {
                cnt[s[j]]++;
                if(cnt[s[j]]==1)
                    distinct++;
                while(distinct>dis)
                {
                    cnt[s[i]]--;
                    if(cnt[s[i]]==0)
                        distinct--;
                    i++;
                }
                ans+=j-i+1;
                j++;
            }
            result[dis]=ans;
        }
        for(int i=26;i>=1;i--)
            result[i]-=result[i-1];
        
        for(int i=25;i>=1;i--)
            result[i]+=result[i+1];
        
        for(int i=1;i<=26;i++)
            cout<<result[i]<<" ";
        cout<<endl;
    }
        
    return 0;  
}