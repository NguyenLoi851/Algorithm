#include<bits/stdc++.h>
using namespace std;

const int MAX = 25;
int n, K, Q;
int d[MAX]; // number of packages of each house
int x[MAX]; // x[i] services for house i 
int c[MAX]; // c[i]: number of houses which truck i services
int q[MAX]; // q[i]: remain packages of truck i 
unsigned long long res; 
int cnt; 

void input(){
    cin >> n >> K >> Q;
    for(int i=1;i<=n;i++){
        cin >> d[i];
    }
}

void setup(){
    for(int i=1;i<=n;i++){
        c[i]=0;
    }
    for(int i=1;i<=n;i++){
        q[i]=Q;
    }
    res = 0;
    cnt=0;
}

unsigned long long factorial(int k){
    unsigned long long ans=1;
    for(int i=2;i<=k;i++){
        ans*=i;
    }
    return ans;
}

void TRY(int k){

    if(k==n+1){
        unsigned long long temp=1;
        for(int j=1;j<=K;j++){
            if(c[j]>0) temp*=factorial(c[j]);
            else return;
        }
        res+=(temp%1000000007);
        return;
    }

    for(int i=1;i<=K;i++){
        if(q[i]>=d[k] && d[k]>0){
            x[k]=i;
            q[i]-=d[k];
            c[i]++;
            // if(k==n){
            //     unsigned long long temp=1;
            //     for(int j=1;j<=K;j++){
            //         if(c[j]>0) temp*=factorial(c[j]);
            //         else cnt++;
            //     }
            //     res+=(temp%1000000007);
            //     //return;
            // }
            // else TRY(k+1);
            TRY(k+1);
            q[i]+=d[k];
            c[i]--;
        }
    }
}

int main(){
    input();
    setup();
    TRY(1);
    res/=factorial(K);
    cout << (int)res%1000000007;
    return 0;
}

