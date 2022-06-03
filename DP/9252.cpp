#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    int num[1001][1001];
    cin>>a>>b;
    int alen = strlen(a.c_str()), blen=strlen(b.c_str());
    for(int i=0;i<=blen;i++){
        for(int j=0;j<=alen;j++){
            num[j][i]=0;
        }
    }
    for(int i=1;i<=blen;i++){
        for(int j=1;j<=alen;j++){
            if(a[j-1]==b[i-1])
                num[j][i]=num[j-1][i-1]+1;
            else
                num[j][i]=max(num[j-1][i],num[j][i-1]);
        }
    } 
    // for(int i=0;i<=blen;i++){
    //     for(int j=0;j<=alen;j++){
    //         cout<<num[j][i];
    //     }
    //     cout<<endl;
    // }
    cout<<num[alen][blen]<<'\n';
    int idx=1;
    int i=alen, j=blen;
    stack<char> s;
    while(1){
        if(num[i][j]==0)
            break;
        if(a[i-1]!=b[j-1]){
            if(num[i-1][j]>=num[i][j-1])
                i=i-1;
            else
                j=j-1;
            continue;
        }
        else{
            s.push(a[i-1]);
            // cout<<a[i]<<" "<<i<<" "<<j<<endl;
            i=i-1;
            j=j-1;
            continue;
        }
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}