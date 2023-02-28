// JAY SHIV SAKTI
// https://www.codechef.com/problems/REVERSE

#include<bits/stdc++.h>
using namespace std;
#define OM_NAMAH_SHIVAY ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define F first
#define S second
#define ll long long int
#define pb push_back
const ll N=1000000;
#define INF 1000000000
std::vector<pair<ll,ll>> g[N];
vector<ll> lev(N,INF);
ll n,m;
ll bfs(){
    deque<ll> q;
    q.push_back(1);
    lev[1]=0;
    while(!q.empty()){
        ll cur_v = q.front();
        q.pop_front();
        for (auto child:g[cur_v])
        {
            ll child_v = child.F;
            ll wt = child.S;
            if (lev[cur_v]+wt < lev[child_v])
            {
                lev[child_v] =lev[cur_v]+wt;
                if (wt==1)
                {
                    q.push_back(child_v);
                }
                else{
                    q.push_front(child_v);
                }
            }

        }
    }
    return lev[n]==INF ? -1:lev[n];
}
void solve(){
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        ll x,y;cin>>x>>y;
        if (x==y)
        {
            continue;
        }
        g[x].pb({y,0});
        g[y].pb({x,1});
    }
    cout<<bfs()<<endl;
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