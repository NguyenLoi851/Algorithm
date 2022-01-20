#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int n;
vector<int> Adj[MAX];
int res = 0;
bool bVisited[MAX];

void input(){
    int u,v;
    cin >> n;
    for(int i=1;i<=n-1;i++){
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
}

int BFS(int start){
    queue<int> Q;
    Q.push(start);
    bVisited[start] = true;
    while(!Q.empty()){
        int v=Q.front();
        Q.pop();
        bool flagLeaf=true;
        for(int i=0;i<Adj[v].size();i++){
            int u=Adj[v][i];
            if(bVisited[u]==false){
                flagLeaf=false;
                bVisited[u]=true;
                Q.push(u);
            }
        }
        if(flagLeaf==true) res++;
    }
    return res;
}

int main(){
    input();
    res = BFS(1);
    cout << res;
    return 0;
}
