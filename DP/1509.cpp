#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

string str;
bool pal[2501][2501];
int len, split[2501];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    len = strlen(str.c_str());
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            pal[i][j]=0;
            if(i==j){
                pal[i][j]=1;
            }
            if(j==i+1 && str[i]==str[j]){
                pal[i][j]=1;
            }
        }
        split[i]=99999999;
    }
    for(int i=0;i<len;i++){
        int start = i-1;
        int end = i+1;
        while(0<=start&&end<len){
            if(pal[start+1][end-1]&&str[start]==str[end]){
                pal[start][end]=1;
            }
            start--;
            end++;
        }
    }
    for(int i=0;i<len;i++){
        int start = i-1;
        int end = i+2;
        while(0<=start&&end<len){
            if(pal[start+1][end-1]&&str[start]==str[end]){
                pal[start][end]=1;
            }
            start--;
            end++;
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<=i;j++){
            if(pal[j][i]){
                if(j==0){
                    split[i]=min(split[i],1);
                }
                else{
                    split[i]=min(split[i],split[j-1]+1);
                }
            }
        }
    }
    cout<<split[len-1];
}