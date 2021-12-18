#include<bits/stdc++.h>
using namespace std;

string str;

void solve2(){
    vector<int> index;
    index.push_back(-1);
    stack<char> s;
    int l = str.length();
    //cout << "length: " << l << endl;
    for(int i=0;i<l;i++){
        if(str[i]=='('||str[i]=='['){
            s.push(str[i]);
            index.push_back(i);
            //cout << s.top() << " ";
        }else{
            if(!s.empty()&&((str[i]==']'&&s.top()=='[')||
                (str[i]==')'&&s.top()=='('))){
                    s.pop();
                    index.pop_back();
                    //cout << s.top() << " ";
            }
            else{
                s.push(str[i]);
                index.push_back(i);
                //cout << s.top() << " ";
            }
        }
    }
    index.push_back(l);
    //cout << index.size() << endl;
    int cnt = 0;
    int max_lenght = 0;
    int max_sq = 0;
    int x=0;

    for(int i=0;i<index.size()-1;i++){
        cnt=0;
        for(int j=index[i]+1;j<index[i+1];j++){
            if(str[j]=='[') cnt++;
        }
        if((max_lenght<index[i+1]-index[i]-1&&max_sq==cnt) || max_sq<cnt){
            max_lenght = index[i+1]-index[i]-1;
            x=index[i];  
            max_sq=cnt;
        }
    }
    //cout << "max_lenght: " << max_lenght << endl;
    if(max_lenght>0){
        cnt=0;
        for(int i=x+1;i<x+1+max_lenght;i++){
            if(str[i]=='[') cnt++;
        }

    cout << cnt << endl;
        for(int i=x+1;i<x+1+max_lenght;i++){
            cout << str[i];  
        }
    }else{
        cout << 0 << endl;
    }
    
}

int main(){
    cin >> str;
    solve2();
    return  0;
}