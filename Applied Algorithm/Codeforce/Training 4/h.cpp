#include<bits/stdc++.h>
using namespace std;

const int MAX = 1005;

int n,l;
int a[MAX];
int L,R,mid;
int dMax, indMax;
double ans;

void input(){
    cin >> n >> l;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
}

bool check(int val){
    for(int i=1;i<=n-1;i++){
        if(a[i]+val < a[i+1]-val) return false;
    }
    return true;
}

int main(){
    input();
    sort(a+1,a+n+1);
    a[0]=0;
    a[n+1]=l;
    dMax = 0;
    for(int i=0;i<=n;i++){
        dMax = max(dMax, a[i+1]-a[i]);
        if(dMax < a[i+1]-a[i]){
            dMax = a[i+1]-a[i];
            // indMax = i;
        }
    }
    // if(indMax = 0 && a[1] != 0) cout << setprecision(9) << fixed << (double)dMax; 
    // else{
    //     if(indMax = n && a[n] != l) cout << setprecision(9) << fixed << (double)dMax;
    //     else{
    //         cout << setprecision(9) << fixed <<(double)dMax/2;
    //     }
    // }
    ans = max((double)dMax/2,(double)(a[1]-a[0]));
    ans = max(ans,(double)(a[n+1]-a[n])); 
    cout << setprecision(9) << fixed << ans;
    
    // L=0;R=dMax;
    // double esilon = 1e-9;
    // while(R-L>esilon){
    //     mid = (L+R)/2;
    //     if(check(mid)){
    //         ans=mid;
    //         R=mid-esilon;
    //     }else{
    //         L=mid+esilon;
    //     }
    // }
    // cout << ans; 
    return 0;
}