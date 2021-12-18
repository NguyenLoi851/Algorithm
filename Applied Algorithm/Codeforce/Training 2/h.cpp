#include<iostream>
#include<stack>
using namespace std;

int n;
string str;
int flag;

void solve(){
    flag=1;
    stack<char> s;
    for(int i=0; i<str.length(); i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            s.push(str[i]);
        }else{
            if(s.empty()){
                flag=0;
                break;
            }else{
                if((str[i]==']'&&s.top()=='[')||
                   (str[i]==')'&&s.top()=='(')||
                   (str[i]=='}'&&s.top()=='{')){
                       s.pop();
                }
                else{
                    flag = 0;
                }
            }
        }
    }
    if(!s.empty()){
        flag =0 ;
    }
    cout << flag << endl;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        solve();
    }
    return 0;
}