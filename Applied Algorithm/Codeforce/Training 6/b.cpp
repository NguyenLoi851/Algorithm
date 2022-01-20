#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int n,m;
vector<int> Adj[MAX];
vector<int> iSide(MAX, -1);

bool is_bipartite = true;

void input(){
    int u,v;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
}

void Check_Bipartite(int u){
    for(int i=0;i<Adj[u].size();i++){
        int v=Adj[u][i];
        if(iSide[v] == -1){
            iSide[v] = 1 - iSide[u];
            Check_Bipartite(v);
        }else if(iSide[u] == iSide[v]){
            is_bipartite = false;
        }
    }
}

void solve(){
    for(int u=1;u<=n;u++){
        if(iSide[u]==-1){
            iSide[u] = 0;
            Check_Bipartite(u);
        }
    }
}

int main(){
    input();
    solve();
    cout << (int)is_bipartite;
    return 0;
}