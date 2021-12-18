// #include<iostream>
// #include<string>
// #include<stack>
// using namespace std;

// int main(){
//     string A,B; cin >> A >> B;
//     stack<int> a,b,c;
//     for(int i=0;i<A.length();i++)
//         a.push(A[i]-'0');
//     for(int i=0;i<B.length();i++)
//         b.push(B[i]-'0');
//     while(!a.empty()||!b.empty()){
//         if(a.empty()){
//             int t = b.top();
//                 b.pop();
//                 if(t>9){
//                     t-=10;
//                     b.top()+=1;
//                 }
//                 c.push(t);
//         }
//         else{
//             if(b.empty()){
//                 int t = a.top();
//                 a.pop();
//                 if(t>9){
//                     t-=10;
//                     a.top()+=1;
//                 }
//                 c.push(t);
//             }
//             else{
//                 int t = a.top() + b.top();
//                 a.pop();
//                 b.pop();
//                 if(t>9){
//                     t-=10;
//                     if(b.empty()){
//                         b.push(1);
//                     }else{
//                         b.top()+=1;
//                     }
//                 }
//                 c.push(t);
//             }
//         }
//     }
//     while(!c.empty()){
//         cout << c.top();
//         c.pop();
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    unsigned long long a, b, c, d, res1, res2;
    cin >> a >> b;
    c = a % 10;
    d = b % 10;
    a = a / 10;
    b = b / 10;
    res1 = a+b;
    res2 = c+d;
    if(res2 >= 10){
        res2-=10;
        res1+=1;
    }
    if(res1==0){
        cout << res2;
    }else{
        cout << res1 << res2;
    }
    return 0;
}
