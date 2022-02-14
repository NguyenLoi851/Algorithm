#include<bits/stdc++.h>
using namespace std;

const int MAX = 22;
vector<vector<int>> matrix;
int deg[MAX]={0};

void input(){
    int u,v;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        m[u][v] = 1; m[v][u] = 1;
        deg[u]++; deg[v]++;
    }
    for(int i=1;i<=n;i++){
        m[i][i] = deg[i];
    }
}

void solve(){
    int x=1,y=1;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j && m[i][j]==1){
                m[i][j]--;
            }
        }
    }
    solve();

    return 0;
}