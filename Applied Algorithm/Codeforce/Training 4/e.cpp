#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int MAX = 100005;

int T, n, c;
ull x[MAX];
ull L,R,mid,res=0;

bool check(ull dis){
    int cnt=1;
    ull temp = x[1];
    for(ull i=2;i<=n;i++){
        if(x[i]-temp>=dis){
            temp=x[i];
            cnt++;
            if(cnt == c) return true;
        }
    }
    return false;
}

void solve(){
    cin >> T;
    for(int t=0;t<T;t++){
        cin >> n >> c;
        for(int i=1;i<=n;i++){
            cin >> x[i];
        }
        sort(x+1,x+n+1);
        L=1;R=1000000001;
        while(L<=R){
            mid = (L+R)/2;
            if(check(mid)){
                res = mid;
                L=mid+1;
            }else{
                R=mid-1;
            }
        }
        cout << res << endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}