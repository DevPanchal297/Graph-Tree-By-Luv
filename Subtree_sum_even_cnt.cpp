#include<bits/stdc++.h>
using namespace std;
#define OM_NAMAH_SHIVAY ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define F first
#define S second
#define int long long
#define pb push_back
const int N=1e5+10;
vector<int> g[N];
int subtree_sm[N],even_cnt[N];
void dfs(int vertex,int par=0){

    if (vertex%2==0)
    {
        even_cnt[vertex]++;
    }
    subtree_sm[vertex]+=vertex;
    for(int child:g[vertex]){

        if (child==par)
        {
            continue;
        }
        dfs(child,vertex);
        subtree_sm[vertex]+=subtree_sm[child];
        even_cnt[vertex]+=even_cnt[child];
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
        cout<<subtree_sm[i]<<" "<<even_cnt[i]<<endl;
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