#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string key[12]={"","abc","def",
                "ghi","jkl","mno",
                "pqrs","tuv","wxyz",
                "", " ",""};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string str;
    getline(cin,str);
    for(int g=0;g<n;g++){
        getline(cin,str); 
        int res = 0;
        for(int i=0;i<str.size();i++){
            int count;
            for(int j=0;j<12;j++){
                for(int k=0;k<key[j].size();k++){
                    if(str[i]==key[j][k]){
                        count = k+1;
                    }
                }
            }
        res += count;
        }
        cout<<"Case #"<<g+1<<": "<<res<<endl;
    }
    return 0;
}