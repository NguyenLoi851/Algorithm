#include<bits/stdc++.h>
using namespace std;

int n,kk;
int load;
int f,f_best;
int c[25][25];
bool visited[25];
int dmin;
int x[25];

void input(){
    cin >> n;
    kk=1;
    dmin = INT_MAX;
    for(int i=0;i<2*n+1;i++){
        for(int j=0;j<2*n+1;j++){
            cin >> c[i][j];
            if(c[i][j]>0&&dmin>c[i][j]) dmin = c[i][j];
        }
    }
}

bool check(int i, int k){
    if(visited[i]==true) return false;
    if(i<=n){
        if(load >= kk ) return false;
    }
    else{
        if(visited[i-n]==false) return false;
    }
    return true;
}

void updateBest(){
    if(f+c[x[2*n]][0]<f_best){
        f_best=f+c[x[2*n]][0];
    }
}

void TRY(int k){
    for(int i=1;i<=2*n;i++){
        if(check(i,k)){
            visited[i] = true;
            x[k] = i;
            load += (i<=n) ? 1 : -1;
            f=f+c[x[k-1]][i];
            if(k==2*n){
                updateBest();
            }
            else{
                if(f+dmin*(2*n+1-k)<f_best){
                    TRY(k+1);
                }
            }
            visited[i] = false;
            load -= (i<=n) ? 1 : -1;
            f-=c[x[k-1]][x[k]];
        }
    }
}

int main(){
    input();
    f_best = INT_MAX;
    f = 0;
    load = 0;
    x[0]=0;
    for(int i=0;i<2*n+1;i++){
        visited[i] = false;
    }
    TRY(1);
    cout << f_best;
    return 0;
}