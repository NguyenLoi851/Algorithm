#include<iostream>
using namespace std;

const long long NMAX = 100000+5;
unsigned long long n;
unsigned long long a[NMAX];
unsigned long long q,p,c;
unsigned long long ans;   

int d(int u){
    if(u==1) return 1;
    return a[u]!=a[u-1];
}

void solve(){
    ans -= d(p);
    if(p!=n) ans-=d(p+1);
    a[p]=c;
    ans += d(p);
    if(p!=n) ans+=d(p+1);
    cout << ans << endl;
}

int main(){
    cin >> n;
    cin >> a[1];
    ans = 1;
    for(unsigned long long i=2; i<=n; i++){
        cin >> a[i];
        ans+=d(i);
    }
    
    cin >> q;
    for(unsigned long long i=1;i<=q;i++){
        cin >> p >> c;
        solve();
    }
    return 0;
}