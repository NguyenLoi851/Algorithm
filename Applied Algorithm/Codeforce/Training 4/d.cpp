#include<bits/stdc++.h>
using namespace std;

const int MAX = 505;

unsigned long long n;
unsigned long long L,R,mid;
unsigned long long m,k;
long long a[MAX];
long long ans[MAX];
long long b[MAX];

bool check(long long max_val){
    long long cnt=0, sum=0;
    memset(b,0,sizeof(b));
    for(int i=m;i>=1;i--){
        if(sum+a[i]<=max_val&&i>=k-cnt) sum+=a[i];
        else{
            cnt++;
            sum = a[i];
            b[i]=1;
        }
    }
    if(cnt==k-1){
        for(int i=1;i<=m;i++) ans[i]=b[i];
        return true;
    }
    return false;
}

void printSolution(){
    for(int i=1;i<=m;i++){
        cout << a[i] << " ";
        if(ans[i]==1) cout << " / ";
    }
    cout << endl;
}

int main(){
    long long t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(t=1;t<=n;t++){
        L=R=0;
        cin >> m >> k;
        for(int i=1;i<=m;i++){
            cin >> a[i];
            R+=a[i];
            if(a[i]>L) L=a[i];
        }
        memset(ans,0,sizeof(ans));
        while(L<=R){
            mid = (L+R)/2;
            if(check(mid)) R=mid-1;
            else L=mid+1;
        }
        printSolution();
    }
    return 0;
}