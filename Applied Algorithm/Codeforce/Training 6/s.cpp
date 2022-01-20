#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
vector<int> Adj[MAX];
vector<int> iSide(MAX, -1);
int T,n,m;
bool is_bipartite = true;

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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for(int t=1;t<=T;t++){
        int u, v;
        cin >> n >> m;
        for(int i=1;i<=m;i++){
            cin >> u >> v;
            Adj[u].push_back(v);
            Adj[v].push_back(u);          
        }
        for(int uu=1;uu<=n;uu++){
            if(iSide[uu]==-1){
                iSide[uu] = 0;
                Check_Bipartite(uu);
            }
        }
        cout << "Scenario #" << t << ":" << endl;
        if(is_bipartite==false) cout << "Suspicious bugs found!" << endl;
        else cout << "No suspicious bugs found!" << endl;

        is_bipartite = true;
        for(int i=1;i<=n;i++){
            Adj[i].clear();
        }
        iSide.assign(MAX, -1);
    }
    return 0;
}