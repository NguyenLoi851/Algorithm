#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
int n, m;
int x[MAX];
unsigned long long c[MAX][MAX];
bool visited[MAX];
unsigned long long f,f_best;
unsigned long long dmin;

void input(){
    int i,j;
    unsigned long long cc;
    dmin = INT_MAX;
    cin >> n >> m;
    for(int o=0;o<m;o++){
        cin >> i >> j >> cc;
        c[i][j] = cc;
        if(dmin>cc) dmin = cc;
    }
}

bool check(int i, int k){
    if(c[x[k-1]][i]==INT_MAX || visited[i]==true) return false;
    return true;
}

void updateBest(){
    if(f+c[x[n]][x[1]]<f_best && c[x[n]][x[1]] != INT_MAX) 
        f_best = f+c[x[n]][x[1]];
}

void TRY(int k){
    for(int i=2;i<=n;i++){
        if(check(i,k)){
            x[k]=i;
            visited[i]=true;
            f = f + c[x[k-1]][x[k]];
            if(k==n){
                updateBest();
            }else{
                if(f+dmin*(n-k+1)<f_best){
                    TRY(k+1);
                }
            }
            visited[i]=false;
            f = f - c[x[k-1]][x[k]];
        }
    }
}

int main(){
    for(int i=0;i<=MAX;i++){
        for(int j=0;j<=MAX;j++){
            c[i][j] = INT_MAX;
        }
    }
    input();
    f_best = INT_MAX;
    f=0;
    for(int i=0;i<=n;i++){
        visited[i]=false;
    }
    x[1] = 1;
    visited[1] = true;
    TRY(2);
    cout << f_best;
    return 0;
}