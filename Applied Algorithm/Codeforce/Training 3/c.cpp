#include<bits/stdc++.h>
using namespace std;

const int MAX = 35;

int m; // so luong giao vien
int n; // so mon hoc
vector<int> t[MAX]; // t[i]: la ds giao vien co the day mon i
int x[MAX]; // x[i]: la giao vien dc phan cong mon i
int load[MAX]; // load[i]: so mon duoc phan cong cho giao vien i  
bool C[MAX][MAX]; // C[i][j] = true neu i va j trung thoi khoa bieu
int best; // ki luc 
bool found; // found = true: tim thay ket qua

void input(){
    int temp, temp1, temp2;
    cin >> m >> n;
    for(int i=0;i<m;i++){
        cin >> temp;
        for(int j=0;j<temp;j++){
            cin >> temp2;
            t[temp2].push_back(i+1);
        }
    }
    cin >> temp;
    for(int i=0;i<temp;i++){
        cin >> temp1 >> temp2;
        C[temp1][temp2] = true;
        C[temp2][temp1] = true;
    }
}

bool check(int g, int k){
    for(int i=1;i<=k-1;i++){
        if(C[i][k] && x[i]==g) return false;
    }
    return true;
}

void solution(){
    found = true;
    int max_load = 0;
    for(int i=1;i<=m;i++) max_load = max(max_load,load[i]);
    best = min(best, max_load);
}

void TRY(int k){ // thu tung mon hoc
    for(int i=0;i<t[k].size();i++){
        int g = t[k][i];
        if(check(g,k)){
            x[k] = g;
            load[g]++;
            if(k==n) solution();
            else{
                if(load[g]<best) TRY(k+1);
            }
            load[g]--; 
        }
    }
}

int main(){
    memset(load, 0, MAX); 
    for(int i=1;i<=MAX;i++){
        for(int j=1;j<=MAX;j++){
            C[i][j]=false;
        }
    }
    input();
    best = 1000000;
    found = false;
    TRY(1);
    if (found == true) cout << best;
    else cout << -1; 
    return 0;
}