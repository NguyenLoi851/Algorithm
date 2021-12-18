#include<bits/stdc++.h>
using namespace std;

void cong1(int n, string str){
    if(str[n]=='0'){
        str[n]='1';
    }else{
        str[n]='0';
        cong1(n-1, str);
    }
    cout << str; 
    exit(0);
}

int main(){
    int n;
    string str;
    int cnt1=0;
    cin >> n >> str;
    for(int i=0;i<n;i++){
        if(str[i]=='1'){
            cnt1++; 
        } 
    }
    if(cnt1==n){
        cout << -1;
        return 0;
    }
    cong1(n,str);
    return 0;
}