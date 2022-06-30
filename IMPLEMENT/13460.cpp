#include<iostream>
#include<queue>

using namespace std;

int n,m;
char board[10][10];
int rx,ry,bx,by,dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
        board[j][i]=str[j];
            if(str[j]=='R'){
                rx=j;
                ry=i;
            }
            else if(str[j]=='B'){
                bx=j;
                by=i;
            }
        }
    }
    queue<pair<int, pair<pair<int,int>, pair<int,int> > > > q;
    q.push(make_pair(0,make_pair(make_pair(rx,ry),make_pair(bx,by))));
    while(!q.empty()){
        int curdepth=q.front().first;
        int currx=q.front().second.first.first;
        int curry=q.front().second.first.second;
        int curbx=q.front().second.second.first;
        int curby=q.front().second.second.second;
        int ans;
        // cout<<curdepth<<" "<<currx<<" "<<curry<<" "<<curbx<<" "<<curby<<endl;
        q.pop();
        for(int i=0;i<4;i++){
            int nextrx=currx;
            int nextry=curry;
            int nextbx=curbx;
            int nextby=curby;
            int cnt=0;
            int flag=1;
            int ansflag=0;
            int fall=0;
            while(flag){
                flag=0;
                if(!fall){
                    if(board[nextrx+dx[i]][nextry+dy[i]]!='#'&&!(nextrx+dx[i]==nextbx&&nextry+dy[i]==nextby)){
                        if(board[nextrx+dx[i]][nextry+dy[i]]=='O'){
                            fall=1;
                            nextrx=99;
                            nextry=99;
                        }
                        nextrx+=dx[i];
                        nextry+=dy[i];
                        flag=1;
                        cnt++;
                    }
                }
                if(board[nextbx+dx[i]][nextby+dy[i]]!='#'&&!(nextbx+dx[i]==nextrx&&nextby+dy[i]==nextry)){
                    if(board[nextbx+dx[i]][nextby+dy[i]]=='O'){
                        ansflag=1;
                        break;
                    }
                    nextbx+=dx[i];
                    nextby+=dy[i];
                    flag=1;
                    cnt++;
                }
            }
            if(ansflag==0&&fall==1){
                if(curdepth+1>=11){
                    cout<<-1;
                }
                else{
                    cout<<curdepth+1;
                }
                return 0;
            }
            if(ansflag==0&&cnt!=0){
                if(curdepth<10){
                    q.push(make_pair(curdepth+1,make_pair(make_pair(nextrx,nextry),make_pair(nextbx,nextby))));
                }
            }
        }
    }
    cout<<-1;
}