#include<iostream>
#include<cstring>

using namespace std;

int main(){
    string str[5];
    int jump[10001]={0, };
    for(int i=0;i<5;i++){
        cin>>str[i];
    }
    int len=strlen(str[0].c_str());
    for(int i=0;i<5;i++){
        for(int j=0;j<len;j++){
            if(str[i][j]=='w')
                jump[j]=1;
            else if(str[i][j]=='L')
                jump[j]=2;
        }
    }
    char ch[3][5]={{'.','o','m','l','n'},{'o','w','l','n','.'},{'.','.','o','l','n'}};
    for(int i=0;i<5;i++){
        for(int j=0;j<len;j++){
            if(jump[j]==0){
                for(int k=0;k<5;k++){
                    if(str[i][j]==ch[0][k]){
                        cout<<ch[1][k];
                        break;
                    }
                }
            }
            else if(jump[j]==1){
                for(int k=0;k<5;k++){
                    if(str[i][j]==ch[1][k]){
                        cout<<ch[0][k];
                        break;
                    }
                }
            }
            else if(jump[j]==2)
                cout<<str[i][j];
        }
        cout<<endl;
    }

}