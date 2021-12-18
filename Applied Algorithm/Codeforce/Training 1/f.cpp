#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> res;
    for(int i=0;i<n;i++){
        string t;
        cin >> t;
        if(t.length()<=10){
            res.push_back(t);
        }
        else{
            string str = "";
            str += t[0];
            str += to_string(t.length()-2);
            str += t[t.length()-1];
            res.push_back(str);
        }
    }
    for(int i=0;i<n;i++){
        cout << res[i] << endl;
    }
    return 0;
}