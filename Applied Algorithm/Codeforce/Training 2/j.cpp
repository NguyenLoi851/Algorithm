#include<bits/stdc++.h>
using namespace std;

int n;
string str;
vector<string> s;

void printPath(){
    cout << "/";
    for(int i=0;i<s.size();i++){
        cout << s[i] << "/";
    }
    cout << endl;
}

void convertToArray(){
    int x=3;
    if(str[3]=='/'){
        s={};
        x=4;
    }
    string temp = "";
    for(int i=x;i<str.length();i++){
        if(str[i]!='/'){
            temp += str[i];
            if(i==str.length()-1){
                if(temp.compare("..")==0) s.pop_back();
                else s.push_back(temp);
            }
        }else{
            if(temp.compare("..")==0){
                s.pop_back();
            }else{
                s.push_back(temp);
                //cout << "push: " << temp << endl;
            }
            temp="";
        }
    }
}

int main(){
    cin >> n;
    getline(cin,str);
    for(int i=0;i<n;i++){
        getline(cin,str);
        //cout << "string: " << str << endl;
        if(str.compare("pwd")==0){
            printPath();
        }
        else{
            convertToArray();
        }
    }
    return 0;
}
