#include<bits/stdc++.h>
using namespace std;

const int MAX = 35;

int n,b;
int a[MAX], c[MAX];

int x[MAX];
int ans;
int currentWeight, currentValue;

void input(){
    cin >> n >> b;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
    }
}

bool check(int v){
    return a[v]+currentWeight<=b;
}

void TRY(int k){
    for(int v=x[k-1]+1;v<=n;v++){
        if(check(v)){
            x[k]=v;
            currentWeight +=a[v];
            currentValue += c[v];
            if(currentValue > ans) 
                ans =  currentValue;
            TRY(k+1); 
            currentWeight -=a[v];
            currentValue -= c[v];
        }
    }
}

void solve(){
    ans =0;
    currentWeight = 0;
    currentValue = 0;
    x[0]=0;
    TRY(1);
    cout << ans;  
}

int main(){
    ios_base::sync_with_stdio(0);
    input();
    solve();
    return 0;
}