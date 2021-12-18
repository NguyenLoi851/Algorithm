#include<bits/stdc++.h>
using namespace std;

string str;

void solve(){
    stack<char> s;  
    int len = str.length();
    for(int i=0;i<len;i++){
        if(s.empty()){
            s.push(str[i]);  
        }
        else{
            if((s.top() == '+' && str[i]=='+')||
                s.top() == '-' && str[i]=='-'){
                    s.pop();
            }
            else{
                s.push(str[i]);
            }
        }
    }
    if(!s.empty()){
        cout << "No";
    }
    else cout << "Yes";
}

int main(){
    cin >> str;
    solve();
    return 0;
}