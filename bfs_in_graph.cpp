// JAY SHIV SAKTI
#include<bits/stdc++.h>
using namespace std;
#define OM_NAMAH_SHIVAY ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define F first
#define S second
#define ll long long int
#define pb push_back

const int N =100000;
vector<ll> g[N];
ll vis[N];
ll level[N];

void dfs(int source){

    queue<ll> q;
    q.push(source);
    vis[source]=1;
    while(!q.empty()){
        ll cur_v = q.front();
        q.pop();
        cout<<cur_v<<" ";
        for(ll child:g[cur_v]){
            if (!vis[child])
            {
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_v]+1;
            }
        }
    }   
    cout<<endl;
}
void solve(){
    ll n;cin>>n;
    for (int i = 0; i < n; ++i)
    {
        ll x,y;cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
    {
        cout<<i<<": "<<level[i]<<endl;
    }
}
int32_t main()
{
    OM_NAMAH_SHIVAY;
    int t;
    t=1;
    // cin>>t;
    // cout<<"t not found"<<endl;
    
    while(t--){
        solve();
    }
    // #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    // #endif
    return 0;
}