#include<bits/stdc++.h>
using namespace std;

const int NMAX = 100005;
int n;
int a[NMAX];
int b[NMAX];

int solve(int i){
    int j=n-1;
    while(j>i){
        if(a[j]<a[i]) return j-i-1;
        j--;
    }
    return -1;
}

int main(){
    cin >> n;
    // for(int i=0; i<n; i++){
    //     cin >> a[i];
    // }
    // for(int i=0;i<n;i++){
    //     b[i] = solve(i);
    // }
    // for(int i=0;i<n;i++){
    //     cout << b[i] << " ";
    // }
    pair<int,int> p[NMAX];
    for(int i=0;i<n;i++){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p,p+n);
    int maxx = -1;
    for(int i=0;i<n;i++){
        b[p[i].second] = max(0,maxx-p[i].second);
        maxx = max(maxx,p[i].second);
    }
    for(int i=0;i<n;i++){
        cout << b[i]-1 << " ";
    }
    return 0;
}