#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int n;
vector<int> Adj[MAX];
bool bVisited[MAX];
int parent[MAX];

void input(){
    int u,v;
    cin >> n;
    for(int i=1;i<=n-1;i++){
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
}

void DFS(int start){
    queue<int> Q;
    Q.push(start);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i=0;i<Adj[u].size();i++){
            int v=Adj[u][i];
            if(bVisited[v]==false){
                bVisited[v]=true;
                parent[v]=u;
                Q.push(v);
            }
        }
    }
}

int main(){
    input();
    DFS(1);
    for(int i=2;i<=n;i++) cout << parent[i] << " ";
    return 0;
}