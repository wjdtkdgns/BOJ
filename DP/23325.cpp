#include<iostream>
#include<cstring>
#include<climits>
#include<queue>
#include<cmath>

using namespace std;

// a,b에 -INT_MAX를 넣을 경우 오버플로우 발생함.
// limit 값을 넣는 것을 조심해야함

string str;
int dp[200001];
int len;

int aaa(int cur){ 
    if(dp[cur]!=0){
        return dp[cur];
    }

    int a=-9999999,b=-9999999,temp;
    if(cur-2>=0){
        a=aaa(cur-2);
        if(a!=-9999999){
            if(str[cur]=='+')
                temp=10;
            else
                temp=1;
            if(str[cur-1]=='-')
                temp*=-1;
            a+=temp;
        }
    }
    if(cur-3>=0&&str[cur]=='-'&&str[cur-1]=='+'){
        b=aaa(cur-3);
        if(b!=-9999999){
            temp=11;
            if(str[cur-2]=='-')
                temp*=-1;
            b+=temp;
        }
    }
    dp[cur]=max(a,b);
    return dp[cur];
}

int main(){
    cin>>str;
    len=strlen(str.c_str());
    memset(dp,0,sizeof(dp));
    if(len==2){
        cout<<"11";
        return 0;
    }
    else if(len==1){
        if(str[0]=='+')
            cout<<"10";
        else
            cout<<"1";
        return 0;
    }
    if(len>1){
        if(str[0]=='+'&&str[1]=='-')
            dp[1]=11;
        else
            dp[1]=-9999999;
    }
    if(str[0]=='+')
    {
        dp[0]=10;
    }
    else{
        dp[0]=1;
    }
    



    int a=-9999999,b=-9999999;
    if(len>3&&str[len-1]=='-'&&str[len-2]=='+'){
        a=11;
        if(str[len-3]=='-'){
            a=-11;
        }
        a+=aaa(len-4);
    }
    if (len>2){
        b=1;
        if(str[len-1]=='+')
            b=10;
        if(str[len-2]=='-'){
            b*=-1;
        }
        b+=aaa(len-3);
    }
    dp[len-1]=max(a,b);
    // for(int i=0;i<len;i++)
    //     cout<<dp[i]<<" ";
    // cout<<endl;
    cout<<dp[len-1];
}