#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000005;

int N;
unsigned long long M;
unsigned long long h[MAX];
unsigned long long maxH=0;
unsigned long long L,R,mid,ans;

void input(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >> h[i];
        maxH = max(maxH,h[i]);
    }
}

bool check(unsigned long long mid){
    unsigned long long sum = 0;
    for(int i=1;i<=N;i++){
        if(h[i]>mid) sum+= (h[i]-mid);
    }
    return sum>=M;
}

void solve(){
    L=0;
    R=maxH;
    while(L<R-1){
        mid = (L+R)/2;
        if(check(mid)){
            ans = mid;
            L = mid; 
        }else R=mid;
    }
    cout << ans; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}