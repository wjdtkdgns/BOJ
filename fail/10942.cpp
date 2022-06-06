#include<iostream>
#include<vector>

using namespace std;

int n,m,b[100001];
vector<bool> v[100001];

bool aaa(int s1,int d1, int s2, int d2){
    for(int i=0;i<=d2-s2;i++){
        if(b[s1+i]!=b[s2+i]){
            return 0;
        }
    }
    v[s2][d2-s2]=1;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            v[i].push_back(false);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(v[i][j-i]==1){
                continue;
            }
            if(i==j){
                v[i][0]=1;
                continue;
            }
            if(i+(j-i)/2!=i&&v[i][(j-i)/2]==1){
                if(!aaa(i,i-1+(j-i+1)/2 , i+(j-i+1)/2,j)){
                    v[i][j-i]=0;
                    continue;
                }
            }
            v[i][j-i]=1;
            for(int k=0;k<=(j-i)/2;k++){
                if(b[i+k]!=b[j-k]){
                    v[i][j-i]=0;
                    break;
                }
            }
        }
    }
    cin>>m;
    for(int q=0;q<m;q++){
        int a,b;
        cin>>a>>b;
        cout<<v[a][b-a]<<'\n';
    }
}