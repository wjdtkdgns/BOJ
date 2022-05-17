#include<iostream>
#include<queue>

using namespace std;

// 벽을 뚫은 것과 아직 뚫지않은 것의 visited만 나눈다면 쉬운 문제였음
// -> 두 경우에 대해 같은 visited를 사용한다면 서로의 길을 막는 경우가 발생함

int n,m;
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
int map[1001][1001];
bool visited[1001][1001][2];

int BFS(int x, int y, int b, int d){
    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(x,y),make_pair(b,d)));
    visited[x][y][0]=1;
    visited[x][y][1]=1;
    while(!q.empty()){
        int curx=q.front().first.first;
        int cury=q.front().first.second;
        int block=q.front().second.first;
        int depth=q.front().second.second;
        q.pop();
        if(curx==m-1&&cury==n-1)
            return depth;
        for(int i=0;i<4;i++){
            if(0<=curx+dx[i]&&curx+dx[i]<m){
                if(0<=cury+dy[i]&&cury+dy[i]<n){
                    if(!visited[curx+dx[i]][cury+dy[i]][block]){
                        if(block==0){
                            if(!map[curx+dx[i]][cury+dy[i]]){
                                visited[curx+dx[i]][cury+dy[i]][block]=1;
                                q.push(make_pair(make_pair(curx+dx[i],cury+dy[i]),make_pair(0,depth+1)));
                            }
                            else if (map[curx+dx[i]][cury+dy[i]]){
                                visited[curx+dx[i]][cury+dy[i]][block]=1;
                                q.push(make_pair(make_pair(curx+dx[i],cury+dy[i]),make_pair(1,depth+1)));
                            }
                        }
                        else{
                            if(!map[curx+dx[i]][cury+dy[i]]){
                                visited[curx+dx[i]][cury+dy[i]][1]=1;
                                q.push(make_pair(make_pair(curx+dx[i],cury+dy[i]),make_pair(1,depth+1)));
                            }
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;
            cin>>a;
            map[j][i]=a-'0';
            visited[j][i][0]=0;
            visited[j][i][1]=0;
        }
    }
    cout<<BFS(0,0,0,1);
}