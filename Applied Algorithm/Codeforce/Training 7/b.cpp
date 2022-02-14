#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int n;
int t[MAX];

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> t[i];
    }
}

int main(){
    input();
    sort(t+1, t+n+1, greater<int>());
    int res = 0;
    for(int i=1;i<=n;i++){
        if(res<i+t[i]-1){
            res = i+t[i]-1;
        }
    }
    res += 2;
    cout << res;
    return 0;
}