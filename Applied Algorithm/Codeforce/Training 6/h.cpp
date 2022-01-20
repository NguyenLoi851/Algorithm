#include<bits/stdc++.h>
using namespace std;

const int MAX = 35;
int n,m,k;
vector<int> Adj[MAX];
bool bVisited[MAX];
int matrix[MAX][MAX];
int res = 0;
int idx[MAX];

void input(){
    int u,v;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
}

void TRY(int i, int start){
    for(int j=0;j<Adj[idx[i]].size();j++){
        int u = Adj[idx[i]][j];
        if(bVisited[u] == false){
            bVisited[u] = true;
            idx[i+1]=u;
            if(i==k-1 && matrix[u][start] == 1){
                res++;
            }else{
                TRY(i+1, start);
            }
            bVisited[u] = false;
        }
    }
}

void solve(){
    for(int i=1;i<=n-k+1;i++){
        idx[1]=i;
        bVisited[i] = true;
        TRY(1,i);
    }
}

int main(){
    input();
    solve();
    cout << res/2;
    return 0;
}