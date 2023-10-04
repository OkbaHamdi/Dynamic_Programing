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
void solve(){
    cin>>n>>w;
    v.resize(n+1);
    W.resize(n+1);
    dp.resize(n+1,vector<ll>(w+1,0));
    for(int i=1;i<=n;i++)cin>>W[i]>>v[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++)dp[i][j]=dp[i-1][j];
        for(int j=0;j<=w;j++){
            if(j+W[i]>w)break;
            if(dp[i-1][j]||j==0)dp[i][j+W[i]]=max(dp[i-1][j+W[i]],dp[i-1][j]+v[i]);
        }
    }
    ll ans=0;
    for(int j=0;j<=w;j++)ans=max(ans,dp[n][j]);
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
