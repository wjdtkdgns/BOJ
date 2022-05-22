#include<iostream>
#include<map>

using namespace std;

// 도가뉴 항등식
// Fm+n = Fm-1 * Fn + Fm * Fn+1

long long n;
map<long long,long long> m;

int fibo(long long n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(m.find(n)==m.end()){
        if(n%2==0){
            long long temp=fibo(n/2);
            long long temp2=fibo(n/2-1);
            m.insert(make_pair(n,temp*(temp+2*temp2)%1000000007));
        }
        else{
            long long temp=fibo(n/2+1);
            long long temp2=fibo(n/2);
            m.insert(make_pair(n,(temp*temp+temp2*temp2)%1000000007));
        }
    }
    return m[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cout<<fibo(n);
}