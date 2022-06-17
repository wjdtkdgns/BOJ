#include<iostream>

using namespace std;

int map[9][9];

bool ver(int x, int i){
    for(int j=0;j<9;j++){
        if(i==map[x][j]){
            return 0;
        }
    }
    return 1;
}

bool hor(int y, int i){
    for(int j=0;j<9;j++){
        if(i==map[j][y]){
            return 0;
        }
    }
    return 1;
}

bool sqr(int x, int y, int i){
    int xx=x/3*3;
    int yy=y/3*3;
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            if(map[xx+j][yy+k]==i)
                return 0;
        }
    }
    return 1;
}

bool aaa(int x, int y){
    if(y==9){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<map[j][i];
            }
            cout<<'\n'; 
        }

        return 1;
    }
    int rtn=0;
    if(map[x][y]){
        rtn=aaa((x+1)%9,y+(x+1)/9);
    }else{
        for(int i=1;i<=9 && !rtn;i++){
            if(ver(x,i)){
                if(hor(y,i)){
                    if(sqr(x,y,i)){
                        map[x][y]=i;
                        rtn=aaa((x+1)%9,y+(x+1)/9);
                        map[x][y]=0;
                    }
                }
            }
        }
    }
    return rtn;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<9;i++){
        string a;
        cin>>a;
        for(int j=0;j<9;j++){
            map[j][i]=a[j]-'0';
        }
    }
    aaa(0,0);
}