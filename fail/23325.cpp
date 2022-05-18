#include<iostream>
#include<cstring>
#include<climits>

using namespace std;

string str;
long long num = -INT_MAX;

void dp(int idx, int len, int ac, char op){
    if(idx==len&&op==-1){
        if(ac>num)
            num=ac;    
        return;
    }
    else if(idx==len&&op!=-1)
        return;
    if(idx==0){ // 처음
        if(len>1&&str[0]=='+'&&str[1]=='-'){
            dp(2,len,11,-1);
        }
        if(str[0]=='+'){
            dp(1,len,10,-1);
        }
        if(str[0]=='-'){
            dp(1,len,1,-1);
        }
    }
    else{
        if(op==-1){ // 연산자
            dp(idx+1,len,ac,str[idx]);
        }
        else{ // 숫자
            int nextac;
            cout<<str[idx]<<" "<<idx<<endl; 
            if (len>idx+1&&str[idx]=='+'&&str[idx+1]=='-'){
                // cout<<"1   ";
                if(op=='-')
                    nextac=ac-11;
                else
                    nextac=ac+11;
                dp(idx+2,len,nextac,-1);
            }
            if(str[idx]=='+'){
                if(op=='-')
                    nextac=ac-10;
                else
                    nextac=ac+10;
                dp(idx+1,len,nextac,-1);
            }
            else if(str[idx]=='-'){
                if(op=='-')
                    nextac=ac-1;
                else
                    nextac=ac+1;
                dp(idx+1,len,nextac,-1);
            }
        }
    }
    return ;
}

int main(){
    cin>>str;
    int len=strlen(str.c_str());
    dp(0,len,-INT_MAX,-1);
    cout<<num;
}