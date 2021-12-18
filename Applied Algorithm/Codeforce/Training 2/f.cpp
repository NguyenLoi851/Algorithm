#include<iostream>
#include<algorithm>
using namespace std;

const int NMAX = 200000+5;
int n,b;
int a[NMAX];
int ans;
void solve(){
    ans = -1;
    for(int i=2;i<=n-1;i++){
        int maxL = -1;
        int maxR = -1;
        for(int j=1;j<=i-1;j++){
            if(maxL<a[j]) maxL = a[j];
        }
        for(int j=i+1;j<=n;j++){
            if(maxR<a[j]) maxR = a[j];
        }
        if(maxL-a[i]>=b && maxR-a[i]>=b){
            ans = max(ans,maxL-a[i]+maxR-a[i]);
        }
    }
    cout << ans << endl;
}

int max_pre[NMAX];
int max_sub[NMAX];

void solve2(){
    max_pre[1] = a[1];
    max_sub[n] = a[n];
    for(int i=2;i<=n;i++){
        max_pre[i] = max(max_pre[i-1],a[i]);
    }
    for(int i=n-1;i>=1;i--){
        max_sub[i] = max(max_sub[i+1],a[i]);
    }
    ans = -1;
    for(int i=1;i<=n;i++){
        int temp = max_pre[i] - a[i];
        int temp2 = max_sub[i] - a[i];
        if(temp>=b && temp2>=b){
            ans = max(ans,temp+temp2);
        }
    }
    cout << ans << endl;
}

int main(){
    cin >> n >> b;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }    
    solve2();
    return 0;
}