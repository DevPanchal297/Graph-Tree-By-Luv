// JAY SHIV SAKTI


// https://www.spoj.com/problems/NAKANJ/
#include<bits/stdc++.h>
using namespace std;
#define OM_NAMAH_SHIVAY ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define F first
#define S second
#define int long long int
#define pb push_back
int lev[8][8];
int vis[8][8];

int getx(string s){
    return s[0]-'a';
}
int gety(string s){
    return s[1]-'1';
}
bool isValid(int x,int y){
    if (x>=0 && x<8 && y>=0 && y<8)
    {
        return true;
    }
    return false;
}
std::vector<pair<int,int>> movements={
    {-1,2},{1,2},{2,-1},{2,1},{-1,-2},{1,-2},{-2,-1},{-2,1}
};
int bfs(string source,string dest){
    int scrx =getx(source);
    int scry =gety(source);
    int destx =getx(dest);
    int desty =gety(dest);
    queue<pair<int,int>> q;
    q.push({scrx,scry});
    vis[scrx][scry]=1;
    lev[scrx][scry]=0;
    while(!q.empty()){
        pair<int,int> v =q.front();
        int x =v.F;
        int y =v.S;
        q.pop();

        for(auto it:movements){
            int childx = it.F + x;
            int childy = it.S+y;

            if (!isValid(childx,childy)) 
            {
                continue;
            }
            if (!vis[childx][childy])
            {
                q.push({childx,childy});
                lev[childx][childy] = lev[x][y]+1;
                vis[childx][childy]=1;
            }
        }

        if (lev[destx][desty]!=-1)
        {
            return lev[destx][desty];
        }
    }
    return lev[destx][desty];
}
void solve(){
   string s1,s2;cin>>s1>>s2;
   for (int i = 0; i < 8; ++i)
    {
    for (int j = 0; j < 8; ++j)
        {
        lev[i][j]=-1;
        }
    }
    for (int i = 0; i < 8; ++i)
    {
    for (int j = 0; j < 8; ++j)
        {
            vis[i][j]=0;
        }
    }
    cout<<bfs(s1,s2)<<endl;
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