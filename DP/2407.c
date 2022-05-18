#include<stdio.h>

// longlong이 오버플로우 발생함

unsigned long long num[101][101];
unsigned long long num2[101][101];

int main(){
    int n, m;
    scanf("%d %d",&n,&m);
    for (int i=0;i<101;i++){
        for(int j=0;j<101;j++)
        {
            num[i][j]=0;
            num2[i][j]=0;
            if (i==j||i==0||j==0){
                num[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if (i==0||i==j||j==0){
                num[i][j]=0;
                num2[i][j]=0;
            }
            num[i][j]=num[i-1][j-1]+num[i-1][j];
            num2[i][j]=num2[i-1][j-1]+num2[i-1][j];
            if(num[i][j]>10000000000000000){
                num2[i][j] += num[i][j]/10000000000000000;
                num[i][j]-=10000000000000000;
            }
        }
    }
    if (num2[n][m]!=0){
        printf("%lld%016lld",num2[n][m],num[n][m]);
    }
    else{
        printf("%lld",num[n][m]);
    }
}