#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,x,y,k, map[20][20], dice[6]={0,}; // n e w s u d
    cin>>n>>m>>x>>y>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            cin>>map[j][i];
        }
    }
    int curx=y, cury=x, dx[4]={1,-1,0,0}, dy[4]={0,0,-1,1};
    for(int i=0;i<k;i++){
        int o;
        cin>>o;
        int temp[6];
        curx+=dx[o-1];
        cury+=dy[o-1];
        if(curx<0||m<=curx||cury<0||n<=cury){
            curx-=dx[o-1];
            cury-=dy[o-1];
            continue;
        }
        for(int j=0;j<6;j++){
            temp[j]=dice[j];
        }
        if(o==1){
            dice[1]=temp[4];
            dice[2]=temp[5];
            dice[4]=temp[2];
            dice[5]=temp[1];
        }
        else if(o==2){
            dice[1]=temp[5];
            dice[2]=temp[4];
            dice[4]=temp[1];
            dice[5]=temp[2];
        }
        else if(o==3){
            dice[0]=temp[4];
            dice[3]=temp[5];
            dice[4]=temp[3];
            dice[5]=temp[0];
        }
        else{
            dice[0]=temp[5];
            dice[3]=temp[4];
            dice[4]=temp[0];
            dice[5]=temp[3];
        }
        if(map[curx][cury]==0){
            map[curx][cury]=dice[5];
        }
        else{
            dice[5]=map[curx][cury];
            map[curx][cury]=0;
        }
        // for(int j=0;j<6;j++){
        //     cout<<dice[j]<<" ";
        // }
        // cout<<endl;
    cout<<dice[4]<<'\n';
    }
}


//     n e w s u d

//     0 1 2 3 4 5
// 1   n d u s e w     
// 2   n u d s w e
// 3   d e w u n s
// 4   u e w d s n
//         n
// w   0   2
//     0   4
//     0   6
//     0   0

//     7
// 0   5   8
//     3
//     0