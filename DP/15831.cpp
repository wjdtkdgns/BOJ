#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// 구간을 구할 때는 반복문 중첩보단 앞 뒤 따로 생각하는게 더 좋을 듯

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int N, B, W;
    char stone[300001];
    int wcnt=0, bcnt=0, ans = 0, start=0, end=0;

	cin >> N >> B >> W;
	cin >> stone;
    while (start < N && end < N)
    {
        if (end < N && stone[end] == 'W')
            wcnt++;
        else
            bcnt++;
        end++;
        if (wcnt >= W && bcnt <= B)
            ans = max(ans, end - start);
        else if (bcnt > B){
            if (stone[start] == 'W')
                wcnt--;
            else
                bcnt--;
            start++;
        }
    }
    cout << ans;
}