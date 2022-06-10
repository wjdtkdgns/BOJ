#include <iostream>

using namespace std;

int dp[100001] = { 0, }, coin[101], n, k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> coin[i];
    }
    for(int i=0;i<=k;i++){
        dp[i]=99999999;
    }
    dp[0]=0;
	for (int i = 0; i < n; i++){

		for (int j = coin[i]; j <= k; j++){
            if(dp[j] > dp[j-coin[i]]+1)
			    dp[j] = dp[j - coin[i]] + 1;
		}
    }
    if(dp[k]==99999999){
        cout<<-1;
    }
    else{
	    cout << dp[k];
    }
}