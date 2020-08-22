#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+21;
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


ll hashing1[100100];
ll hashing2[100100];
ll revhashing1[100100];
ll revhashing2[100100];
int main()
{
    // #ifndef ONLINE_JUDGE
    //freopen("input-2.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // #endif

    IOS

    w(_)
    {
        string s,t;
        cin>>s>>t;
        ll n=(ll)s.length();
        ll m=(ll)t.length();
        if(n!=m)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(s==t)
        {
            cout<<"YES"<<endl;
            cout<<"0\n";
            continue;
        }
        
        ll p=47;
        for(int i=0;i<n;i++)
        {
            if(i)
                hashing1[i]=(hashing1[i-1]*p+s[i]);
            else
            {
                hashing1[i]=(s[i]);
            }
            hashing1[i]%=mod;
        }
        for(int i=0;i<n;i++)
        {
            if(i)
                hashing2[i]=(hashing2[i-1]*p+t[i]);
            else
            {
                hashing2[i]=(t[i]);
            }
            hashing2[i]%=mod;
        }

        reverse(all(s));
        for(int i=0;i<n;i++)
        {
            if(i)
                revhashing1[i]=(revhashing1[i-1]*p+s[i]);
            else
            {
                revhashing1[i]=(s[i]);
            }
            revhashing1[i]%=mod;
        }
        reverse(all(t));
        for(int i=0;i<n;i++)
        {
            if(i)
                revhashing2[i]=(revhashing2[i-1]*p+t[i]);
            else
            {
                revhashing2[i]=(t[i]);
            }
            revhashing2[i]%=mod;
        }
        reverse(all(s));
        reverse(all(t));

        int flag=0,ans;
        for(int i=0;i<n;i++)
        {
            if(hashing1[i]==revhashing2[i])
            {
                //deb(i);
                int l=i+1,r=n-1;
                ll val1=-1,val2=-2;
                //deb2(l,r);
                if(l<=r)
                {
                    val1=hashing1[r];
                    ll val=hashing1[l-1]*binpow(p,r-l+1,mod);
                    val%=mod;
                    val1-=val;
                    //deb(val1);
                    val1+=mod;
                    val1%=mod;
                }

                l=0;r=n-i-2;
                if(r>=l)
                {
                    val2=hashing2[r];
                }
                //deb2(val1,val2);
                if(val1==val2)
                {
                    int j;
                    for(j=0;j<r;j++)
                    {
                        if(s[j+i+1]!=t[j])
                        {
                            break;
                        }
                    }
                    if(j==r)
                    {
                        flag=1;
                        ans=i+1;
                        break;
                    }
                }
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;  
}
 