#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int MAX = 1e9+7;
int k,n;
ull res;
ull c[1005];

void solve(){
    if(k>n) return;
    if(n-k<k) k=n-k;
    for(int i=0;i<=k;i++) c[i]=0;
    c[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=min(i,k);j>0;j--){
            c[j] = (c[j]+c[j-1])%MAX;
        }
    }
    res = c[k];
}

int main(){
    cin >> k >> n;
    // ull res = 1;
    // for(int i=1;i<=k;i++){
    //     res *= n--;
    //     res /= i;
    // }
    solve();
    cout << res; 
    return 0;
}