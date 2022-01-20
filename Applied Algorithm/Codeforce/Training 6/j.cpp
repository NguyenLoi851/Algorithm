#include<bits/stdc++.h>
using namespace std;

const int MAX = 15;
int n,m;
int matrix[MAX][MAX];
int res = 0;
int clique[MAX] = {0};
int sizeGraph = 0;

void input(){
    int u,v;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
}

bool isCompleteGraph(){
    for(int i=1;i<=sizeGraph;i++){
        for(int j=i+1;j<=sizeGraph;j++){
            if(matrix[clique[i]][clique[j]] == 0) return false;
        }
    }
    return true;
}

void TRY(int i){
    for(int j=clique[i-1]+1;j<=n;j++){
        clique[i]=j;
        sizeGraph++;
        if(isCompleteGraph()){
            res = max(sizeGraph, res);
            TRY(i+1);
        }
        sizeGraph--;
    }
}

int main(){
    input();
    TRY(1);
    cout << res;
    return 0;
}