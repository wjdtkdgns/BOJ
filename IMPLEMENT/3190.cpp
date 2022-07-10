#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// 음수일때 나눗셈 조심

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k,map[101][101]={0,},l;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        map[b][a]=1;
    }
    cin>>l;
    pair<int,char> move[100];
    for(int i=0;i<l;i++){
        int a;
        char b;
        cin>>a>>b;
        move[i]=make_pair(a,b);
    }
    int curx=1,cury=1,curd=0,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},time=0,len=1;
    queue<pair<int,int> > snake;
    snake.push(make_pair(1,1));
    int mvcnt=0;
    while(1){
        curx+=dx[curd];
        cury+=dy[curd];
        time++;
        if(move[mvcnt].first==time&&mvcnt<l){
            if(move[mvcnt].second=='D'){
                curd=(curd+1)%4;
            }
            else{
                if(curd==0){
                    curd=3;
                }
                else{
                    curd-=1;
                }
            }
            mvcnt++;
        }

        if(curx<1||n<curx||cury<1||n<cury){
            cout<<time;
            return 0;
        }
        // cout<<curx<<" "<<cury<<"\t";
        for(int i=0;i<len;i++){
            int tempx=snake.front().first, tempy=snake.front().second;
            // cout<<tempx<<" "<<tempy<<"  ";
            if(tempx==curx&&tempy==cury){
                cout<<time;
                return 0;
            }
            snake.pop();
            snake.push(make_pair(tempx,tempy));
        }
        // cout<<endl;

        if(map[curx][cury]==1){
            // cout<<len<<endl;
            snake.push(make_pair(curx,cury));
            len++;
            map[curx][cury]=0;
        }
        else{
            snake.pop();
            snake.push(make_pair(curx,cury));
        }
    }
}