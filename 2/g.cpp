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

ll n,m;
vll wt,val,pref;
vector< ppl > set1_,set2_,subset1_,subset2_;

// VERY IMPORTANT

void subsetcal(vector< ppl > &v,vector< ppl > &s)
{
    int sz=v.size();
    for(int i=1;i<(1<<sz);i++)
    {
        ll sum=0,totval=0;
        for(int j=0;j<sz;j++)
        {
            if((1<<j)&i)
            {
                sum+=v[j].F;
                totval+=v[j].S;
            }
        }
        s[i-1].F=sum;
        s[i-1].S=totval;
    }
}
void print(vector<ppl> v)
{
    for(auto pp: v)
    {
        cout<<pp.F<<" "<<pp.S<<endl;
    }
}

int main()
{
    IOS


    w(t)
    {
        subset1_.clear();subset2_.clear();set1_.clear();set2_.clear();pref.clear();

        cin>>n>>m;
        wt.assign(n,0);
        val.assign(n,0);
        for(int i=0;i<n;i++)
            cin>>wt[i];
        for(int i=0;i<n;i++)
            cin>>val[i];

        int size1_=n/2;
        int size2_=n-n/2;

        set1_.resize(size1_);
        set2_.resize(size2_);
        
        for(int i=0;i<size1_;i++)
        {
            set1_[i].F=wt[i];
            set1_[i].S=val[i];
        }
        for(int i=0;i<size2_;i++)
        {
            set2_[i].F=wt[i+size1_];
            set2_[i].S=val[i+size1_];
        }
    
        size1_=(1<<size1_)-1;
        size2_=(1<<size2_)-1;

        
        subset1_.resize(size1_);

        subset2_.resize(size2_);
        
        subsetcal(set1_,subset1_);
        subsetcal(set2_,subset2_);

        sort(all(subset1_));
        sort(all(subset2_));

        // print(subset1_);
        // cout<<endl;
        // print(subset2_);
        // cout<<endl;

        pref.resize(size2_);
        pref[0]=subset2_[0].S;
        for(int i=1;i<size2_;i++)
        {
            pref[i]=max(pref[i-1],subset2_[i].S);
        }
        ll ans=0;
        for(int i=0;i<size1_;i++)
        {
            if(subset1_[i].F<=m)
                ans=max(ans,subset1_[i].S);
        }
        for(int i=0;i<size2_;i++)
        {
            if(subset2_[i].F<=m)
                ans=max(ans,subset2_[i].S);
        }

        for(int i=0;i<size1_;i++)
        {
            if(subset1_[i].F>=m)
                continue;
            ppl p=mp(m-subset1_[i].F,1e18);
            int index=UB(all(subset2_),p)-subset2_.begin();
            index--;
            ll cal=subset1_[i].S;
            if(index>=0)
            {
                cal+=pref[index];
            }
            ans=max(cal,ans);
        }
        cout<<ans<<endl;
    }


        
    return 0;  
}