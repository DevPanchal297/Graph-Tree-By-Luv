// JAY SHIV SAKTI
#include<bits/stdc++.h>
using namespace std;
#define OM_NAMAH_SHIVAY ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define F first
#define S second
// #define int long long int
#define pb push_back

const int N=1e5+10;
vector<int> g[N];
int par[N];
void dfs(int v,int p=-1){

    par[v]=p;
    for(int child:g[v]){
        if(child==p){
            continue;
        }
        dfs(child,v);
    }
} 

vector<int> path(int v){
    vector<int> ans;
    while(v!=-1){
        ans.pb(v);
        v=par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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
    int a,b;
    cin>>a>>b;
    vector<int> x1=path(a);
    vector<int> y1=path(b);
    int lca=-1;
    int mn_ln=min(x1.size(),y1.size());
    for (int i = 0; i <mn_ln; ++i)
    {
        if (x1[i]==y1[i])
        {
            lca=x1[i];
        }
        else{
            break;
        }
    }
    cout<<lca<<endl;return;
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