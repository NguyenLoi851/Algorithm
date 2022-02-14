#include "iostream"
#include "algorithm"
using namespace std;

int main(){
    int n;
    cin >> n;
    int *a = new int[n];
    int e=INT_MIN>>2;
    int res=INT_MIN>>2;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++){
        e = max(e+a[i],a[i]);
        res = max(e,res);
    }
    cout << res;
    return 0;
}