#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
int n,m;
vector<int> Adj[MAX];
vector<int> Low(MAX), Num(MAX, -1);
vector<bool> bConnect(MAX, false);
int cur_num = 0;
int cnt = 0;

stack<int> iComp;

void input(){
    int u,v;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        Adj[u].push_back(v);
    }
}

void SCC(int u){
    iComp.push(u);
    bConnect[u] = true;
    Low[u] = cur_num+1;
    Num[u] = ++cur_num;
    for(int i=0;i<Adj[u].size();i++){
        int v = Adj[u][i];
        if(Num[v] == -1){
            SCC(v);
            Low[u] = min(Low[u], Low[v]);
        }else if(bConnect[v]==true){
            Low[u] = min(Low[u], Num[v]);
        }
    }
    if(Num[u]==Low[u]){
        cnt++;
        while(true){
            int cur = iComp.top();
            iComp.pop();
            bConnect[cur] = false;
            if(cur == u) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for(int i=1;i<=n;i++){
        if(Num[i] == -1){
            SCC(i);
        }
    }
    cout << cnt;
    return 0; 
}