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

string s;

ll eval(int st,int end)
{
    ll res=0;
    for(int i=st;i<end;)
    {
        if(s[i]=='X')
        {
            i++;
            continue;
        }

        if(i==st)
        {
            if(s[i+1]=='X')
            {
                i+=2;
                continue;
            }
            
            if(s[i]=='+')
            {
                int j=i+1;
                for(;s[j]>=48 and s[j]<=57 and j<end;j++);
                ll val=0;
                ll power=1;
                for(int index=j-1;index>=i+1;index--)
                {
                    val+=(s[index]-48)*power;
                    power*=10;
                }
                res+=val;
                i=j;
            }
            else if(s[i]=='-')
            {
                int j=i+1;
                for(;s[j]>=48 and s[j]<=57 and j<end;j++);
                ll val=0;
                ll power=1;
                for(int index=j-1;index>=i+1;index--)
                {
                    val+=(s[index]-48)*power;
                    power*=10;
                }
                res-=val;
                i=j;
            }             
            else
            {
                int j=i;
                for(;s[j]>=48 and s[j]<=57 and j<end;j++);
                ll val=0;
                ll power=1;
                for(int index=j-1;index>=i;index--)
                {
                    val+=(s[index]-48)*power;
                    power*=10;
                }
                res+=val;
                i=j;
            }
        }
        if(s[i]=='+')
        {
            if(s[i+1]=='X')
            {
                i+=2;
                continue;
            }
            int j=i+1;
            for(;s[j]>=48 and s[j]<=57 and j<end;j++);
            ll val=0;
            ll power=1;
            for(int index=j-1;index>=i+1;index--)
            {
                val+=(s[index]-48)*power;
                power*=10;
            }
            res+=val;
            i=j;
        }
        else if(s[i]=='-')
        {
            if(s[i+1]=='X')
            {
                i+=2;
                continue;
            }
            int j=i+1;
            for(;s[j]>=48 and s[j]<=57 and j<end;j++);
            ll val=0;
            ll power=1;
            for(int index=j-1;index>=i+1;index--)
            {
                val+=(s[index]-48)*power;
                power*=10;
            }
            res-=val;
            i=j;
        }
    }
    return res;
}
int main()
{
    IOS
    
    cin>>s;
    int n=s.size();
    int mid;
    int idx;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='=')
        {
            mid=i;
        }
        if(s[i]=='X')
        {
            idx=i;
        }
    }    
    char sign;
    if(idx==0)
    {
        sign='+';
    }
    else if(idx==mid+1)
    {
        sign='+';
    }
    else
    {
        sign=s[idx-1];
    }
    
    if(idx<mid)
    {
        ll val2=eval(mid+1,n);
        ll val1=eval(0,mid);
        //cout<<val1<<" "<<val2<<endl;
        val2-=val1;
        if(sign=='-')
            val2*=-1;
        cout<<val2<<endl;
    }
    else
    {  
        ll val1=eval(mid+1,n);
        ll val2=eval(0,mid);
        //cout<<val1<<" "<<val2<<endl;
        val2-=val1;
        if(sign=='-')
            val2*=-1;
        cout<<val2<<endl;
    }
    

    return 0;  
}
 