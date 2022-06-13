#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool w[4][8];
    int k, past[4]={0, }, cur[4]={0, };
    for(int i=0;i<4;i++){
        int a;
        cin>>a;
        for(int j=7;j>=0;j--){
            w[i][j]=a%10;
            a/=10;
        }
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        queue<int> q;
        bool visited[4]={0, };
        int turn[4]={0,};
        q.push(a-1);
        cur[a-1]=(past[a-1]-b)%8 >= 0 ? (past[a-1]-b)%8 : (past[a-1]-b)%8 + 8;
        turn[a-1]=b;
        while(!q.empty()){
            int curpos = q.front();
            q.pop();
            // cout<<curpos<<" ";
            visited[curpos]=1;
            if(!visited[curpos-1] && curpos-1>=0 && w[curpos-1][(past[curpos-1]+2)%8]==!w[curpos][(past[curpos]+6)%8]){
                cur[curpos-1]=(past[curpos-1]+turn[curpos])%8>=0 ? (past[curpos-1]+turn[curpos])%8 : (past[curpos-1]+turn[curpos])%8 + 8;
                turn[curpos-1]=-turn[curpos];
                q.push(curpos-1);
            }
            if(!visited[curpos+1] && curpos+1<4 && w[curpos+1][(past[curpos+1]+6)%8]==!w[curpos][(past[curpos]+2)%8]){
                cur[curpos+1]=(past[curpos+1]+turn[curpos])%8>=0 ? (past[curpos+1]+turn[curpos])%8 : (past[curpos+1]+turn[curpos])%8 + 8;
                turn[curpos+1]=-turn[curpos];
                q.push(curpos+1);
            }
        }
        for(int j=0;j<4;j++){
            past[j]=cur[j];
            // cout<<past[j];
            // cout<<visited[j];
            // cout<<turn[j];
        }
        // cout<<endl;
    }
    int p[4]={1,2,4,8}, ans=0;
    for(int i=0;i<4;i++){
        ans += w[i][past[i]] ? p[i] : 0;
    }
    cout<<ans;
}