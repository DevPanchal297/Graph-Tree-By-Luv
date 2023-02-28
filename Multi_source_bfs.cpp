// JAY SHIV SAKTI
// https://www.codechef.com/problems/SNSOCIAL

#include<bits/stdc++.h>
using namespace std;
#define OM_NAMAH_SHIVAY ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define F first
#define S second
#define ll long long int
#define pb push_back
#define INF 10000001
ll n,m;
const ll N=1000;
ll arr[N][N];
bool vis[N][N];
ll l[N][N];
std::vector<pair<ll,ll>> mov={{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
void reset(){
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            vis[i][j]=0;
            l[i][j]=INF;
        }
    }
}
ll bfs(){
    ll mx=0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
                mx=max(mx,arr[i][j]);
        }
    }
    queue<pair<ll,ll>> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (mx==arr[i][j])
            {
                q.push({i,j});
                l[i][j]=0;
                vis[i][j]=1;
            }
        }
    }
    ll ans=0;
    while(!q.empty()){
        pair<ll,ll> p = q.front();
        ll x =p.F;
        ll y =p.S;
        q.pop();

        for(auto it:mov){
            ll x1 =x+it.F;
            ll y1 =y+it.S;

            if (x1<0||y1<0||x1>=n||y1>=m||vis[x1][y1]==true)
            {
                continue;
            }
            else{
                q.push({x1,y1});
                l[x1][y1]=l[x][y]+1;
                ans=max(ans,l[x1][y1]);
                vis[x1][y1]=1;
            }
        }
    }

    return ans;
}
void solve(){
    cin>>n>>m;
    reset();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
        }
    }
    cout<<bfs()<<endl;return;
}
int32_t main()
{
    OM_NAMAH_SHIVAY;
    int t;
    t=1;
    cin>>t;
    // cout<<"t not found"<<endl;
    
    while(t--){
        solve();
    }
    // #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    // #endif
    return 0;
}