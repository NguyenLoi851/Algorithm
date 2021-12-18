#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    //int n;
    cin >> n;
    int *h = new int[n];
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    if(next_permutation(h,h+n)==false){
        cout << -1;
        return 0;
    }
    for(int i=0;i<n;i++){
        cout << h[i] << " ";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int MAX = 10005;

int n;
int a[MAX];

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
}

void solve(){
    int i=n-1;
    while(i>=1 && a[i]>a[i+1]) i--;
    if(i<1){
        cout << "-1";
        return; 
    }
    int j=n;
    while(a[j] < a[i]) j--;

    swap(a[i],a[j]);

    int ii = i+1;
    int jj = n;
    while(ii < jj){
        swap(a[ii],a[jj]);
        ii++;
        jj--;
    }

    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}