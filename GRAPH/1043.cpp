#include<iostream>
#include<vector>

using namespace std;

int N, M, T_num;
bool l[50], T[50];
vector<int> v[50];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin>>N>>M;
    cin>>T_num;
    int a, b;
    for(int i=0; i<50; i++)
        T[i]=0;
    for(int i=0; i<T_num; i++){
        cin>>a;
        T[a - 1] = 1;
    }
    for(int i=0; i<M; i++){
        cin>>a;
        l[i]=0;
        for(int j=0; j<a; j++){
            cin>>b;
            v[i].push_back(b - 1);
        }
    }

    for(int i=0; i<M; i++){ // 파티 순서
        for(int j=0; j<v[i].size() && i!=-1 && l[i]==0; j++){ // 파티 참석자
            for(int z=0; z<50 && i!=-1 && l[i]==0; z++){ // true check
                if (T[v[i][j]] == 1)
                {
                    l[i] = 1;
                    for(int k=0; k<v[i].size(); k++)
                        T[v[i][k]] = 1;
                    i = -1;
                }
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<M; i++)
        if(l[i] == 0)
            cnt++;
    cout<<cnt;
}