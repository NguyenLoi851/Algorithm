#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int main(){
    cin >> n;
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        a.push_back(temp);
    }
    cout << 1 <<" ";  
    for(int i=0; i<n; i++){
        if(a[i]<0){
            cout << a[i] << endl;
            a.erase(a.begin()+i);
            break;
        }
    }
    int flag=0;
    for(int i=0;i<n-1;i++){
        if(a[i]>0){
            cout << 1 << " " << a[i] << endl;    
            a.erase(a.begin()+i);
            flag = 1;
            break;
        }
    }
    if(flag==0){
        cout << 2 << " ";
        int cnt=0;
        int i = 0;
        while(cnt<2){
            if(a[i]<0){
                cout << a[i] << " ";
                a.erase(a.begin()+i);
                cnt++;
            }
            else i++;   
        }
        flag=2;
        cout << endl;
    }
    cout << n-1-flag << " ";
    for(int i=0;i<n-1-flag;i++){
        cout << a[i] <<" ";  
    }
    return 0;
}