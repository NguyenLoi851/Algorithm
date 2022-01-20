#include<bits/stdc++.h>
using namespace std;

const int MAX = 10005;
int n,m;
int d[MAX];
int deg_out[MAX], deg_in[MAX];
vector<int> Adj[MAX];
int idx[MAX];
int dist[MAX] = {-1};

void input(){
    int u,v;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> d[i];
    }
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        deg_out[u]++;
        deg_in[v]++;
        Adj[u].push_back(v);
    }
}

void setup(){
    for(int i=1;i<=n;i++){
        if(deg_in[i]==0){
            Adj[0].push_back(i);
            deg_out[0]++;
        }
        if(deg_out[i]==0){
            Adj[i].push_back(n+1);
            deg_in[n+1]++;
        }
    }
}

void BFS(){
    queue<int> Q;
    for(int i=0;i<=n+1;i++){
        if(deg_in[i]==0) Q.push(i);
    }
    int cnt = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        idx[cnt]=u;
        cnt++;
        for(int i=0;i<Adj[u].size();i++){
            int v = Adj[u][i];
            deg_in[v]--;
            if(deg_in[v]==0) Q.push(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    setup();
    BFS();
    dist[0]=0;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<Adj[idx[i]].size();j++){
            int v=Adj[idx[i]][j];
            if(dist[idx[i]]+d[idx[i]]>dist[v]){
                dist[v] = dist[idx[i]]+d[idx[i]];
            }
        }
    }
    cout << dist[n+1];
    return 0;
}