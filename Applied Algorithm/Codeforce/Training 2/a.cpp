#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
 
unsigned long long calculateMaxArea(int *a, int n){
    stack<int> s;
    unsigned long long i=0,temp,areaWithTop,maxArea = 0;
 
    while(i<n) {
        if(s.empty() || (a[s.top()]<=a[i])){
            s.push(i);
            i++;
        }
        else{
            temp = s.top();
            s.pop();
            if(s.empty()){
                areaWithTop = a[temp]*i;
            }
            else{
                areaWithTop = a[temp]*(i-1-s.top());
            }
            //cout << "Area with " << areaWithTop << endl;
            maxArea = max(areaWithTop,maxArea);
        }
    }
    while(!s.empty()){
        temp = s.top();
        s.pop();
        if(s.empty()){
            areaWithTop = a[temp]*i;
        }
        else{
            areaWithTop = a[temp]*(i-1-s.top());
        }
        //cout << "Area with " << areaWithTop << endl;
        maxArea = max(areaWithTop,maxArea);
    }
    return maxArea;
}
 
int main(){
    int n;
    
    do{
        cin >> n;
        if(n==0){
            break;
        }
        int *a = new int[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << calculateMaxArea(a,n) << endl;
    }while(n!=0);
    return 0;
}