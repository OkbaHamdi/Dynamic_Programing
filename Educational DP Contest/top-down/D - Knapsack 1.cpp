/**                         _       _______
                           | |     |____   /
                           | |          / /
                           | |         / /
                           | |____    / /
                           |______|  /_/
**/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef         long long ll;
typedef         long double ld;
typedef         vector<ll>vl;
typedef         deque<ll>dq;
typedef         pair<ll,ll>pl;
#define         ordered_set tree<int, null_type,less<int>, rb_tree_tag,tre
#define         yes {cout<<"YES"<<endl;return;}
#define         no {cout<<"NO"<<endl;return;}
#define         CR(_) {cout<<_<<endl;return;}
#define         F first
#define         S second
#define         pb push_back
#define         ppb pop_back
#define         pf push_front
#define         ppf pop_front
#define         aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define         all(v) v.begin(), v.end()
#define         rall(v) v.rbegin(), v.rend()
//const           ll MOD = LLONG_MAX;
//const           int MOD = 998244353;
const           int MOD=1000000007;
const           ld eps=1e-7;
const           double PI=acos(-1);
const           int N=2e5+5;
const           ll INF=1e18;
const           int L = log2(N)+1;
int n,w;
vector<vector<ll>>dp;
vector<ll>v,W;
ll rec(ll i,ll j){
    if(j<0)return -INF;
    if(i==0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll left=rec(i-1,j-W[i])+v[i];
    ll right=rec(i-1,j);
    return dp[i][j]=max(left,right);

}
void solve(){
    cin>>n>>w;
    v.resize(n+1);
    W.resize(n+1);
    dp.resize(n+1,vector<ll>(w+1,-1));
    for(int i=1;i<=n;i++)cin>>W[i]>>v[i];
    ll ans=0;
    for(int i=w;i>=0;i--)ans=max(ans,rec(n,i));
    cout<<ans<<endl;
}
int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        //freopen("input.txt", "r",stdin);
        //freopen("output.txt", "w",stdout);
        int _=1;
        //cin >>_;
        //cout<<fixed<<setprecision(6);
        while(_--)solve();
}
