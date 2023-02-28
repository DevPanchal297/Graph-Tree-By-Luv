#include<bits/stdc++.h>
using namespace std;
#define OM_NAMAH_SHIVAY ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define F first
#define S second
#define int long long
#define pb push_back
const int N=1e5+10;
vector<int> g[N];
int depth[N],height[N];
void dfs(int vertex,int par=0){

    for(int child:g[vertex]){

        if (child==par)
        {
            continue;
        }
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);

    }
}
void solve(){
    int n;cin>>n;
    for (int i = 0; i < n-1; ++i)
    {
        int x,y;cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1);
    for (int i = 1; i <=n; ++i)
    {
        cout<<depth[i]<<" "<<height[i]<<endl;
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