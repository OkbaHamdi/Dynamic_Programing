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
int n;
vector<vector<ll>>v,dp;
ll rec(ll i,ll j){
    if(j<0)return 0;
    if(i==0)return dp[i][j]=v[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    ll left,right;
    if(j==0){
        left=rec(i-1,j+1);
        right=rec(i-1,j+2);
    }else if(j==1){
        left=rec(i-1,j-1);
        right=rec(i-1,j+1);
    }else{
        left=rec(i-1,j-2);
        right=rec(i-1,j-1);
    }
    return dp[i][j]=max(left,right)+v[i][j];
}
void solve(){
    cin>>n;
    v.resize(n,vector<ll>(3));
    dp.resize(n,vector<ll>(3,-1));
    for(int i=0;i<n;i++)cin>>v[i][0]>>v[i][1]>>v[i][2];
    ll ans=max({rec(n-1,0),rec(n-1,1),rec(n-1,2)});
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
