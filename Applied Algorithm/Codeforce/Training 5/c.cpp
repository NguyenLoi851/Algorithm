#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6+5;
int n,l1,l2;
int a[MAX]; 
int F[MAX];
int best; 

deque<int> d;

void input(){
    cin >> n >> l1 >> l2;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
}

void solve(){
    for(int i=1;i<=n;i++){
        F[i] = a[i];

        // int tmp = 0; // max F[i-j] voi j=[l1,l2];
        // for(int j=l1;j<=l2;j++){
        //     if(i-j>0 && tmp<F[i-j]){
        //         tmp = F[i-j];
        //     }
        // }
        // F[i] += tmp;

        while(!d.empty() && d.front() < i-l2)
            d.pop_front();
        if(i-l1>0){
            while(!d.empty() && F[d.back()] < F[i-l1])
                d.pop_back();
            d.push_back(i-l1);
        }
        F[i] += (d.empty() ? 0: F[d.front()]);
        
        best = max(best, F[i]);
    }
}

int main(){
    input();
    solve(); 
    cout << best; 
    return 0;
}