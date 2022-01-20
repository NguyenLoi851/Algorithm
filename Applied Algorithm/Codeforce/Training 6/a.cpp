#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int n,m;
int num_comp;
vector<int> Adj[MAX];
vector<int> iComponent(MAX, -1);

void input(){
    int u,v;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
}

void Find_Component(int cur_comp, int u){
    if(iComponent[u] != -1) return;
    iComponent[u] = cur_comp;
    for(int i=0;i<Adj[u].size();++i){
        int v = Adj[u][i];
        Find_Component(cur_comp,v);
    }
}

void solve(){
    num_comp=0;
    for(int u=1;u<=n;++u){
        if(iComponent[u] == -1){
            Find_Component(num_comp, u);
            num_comp++;
        }
    }
}

int main(){
    input();
    solve();
    cout << num_comp;
    return 0;
}