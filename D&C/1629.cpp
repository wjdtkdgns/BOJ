#include <iostream>

using namespace std;

// long long 범위 조심

long long A, B, C;
long long ans = 0;

long long DP(long long a, long long b){
    if (b==1){
        return a%C;
    }
    ans = DP(a*a % C, b/2);
    if (b%2 == 1)
    {
        ans *= a;
    }
    return ans % C;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    int c=1;
    cin>>A>>B>>C;
    cout<<DP(A,B)%C;
}

// 16 8 4 2 1
// 01011