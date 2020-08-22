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

vll v;
int frequency(int start,int end,ll x)
{
    if(v[start]!=x)
        return 0;

    if(v[start]==x&&v[end]==x)
        return end-start+1;
    auto it=v.begin();
    it+=start;
    auto itr=v.begin();
    itr+=end;
    int index=UB(it,itr,x)-it;
    //index-=start;
    return index;
}
int main()
{
    IOS

    int h;
    cin>>h;
    int n=(h)*(h+1)/2;
    v.assign(n+1,-1);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    sort(all(v));

    int last=1;
    int freq_last=0;
    if(v[2]==v[1])
        freq_last=1;
    int flag=1;
    for(int len=2;;len++)
    {
        if(last==n)
            break;
        int start=last+1;
        int end=last+len;
        int f=frequency(start,end,v[last]);
        //cout<<f<<" "<<freq_last<<endl;

        if((len-freq_last-1)<f)
        {
            flag=0;
            break;
        }
        freq_last=frequency(start,end,v[end]);
        last=end;
    }
    if(flag)
        cout<<"YES"<<endl;
    else
    {
        cout<<"NO"<<endl;
    }
    

        
    return 0;  
}