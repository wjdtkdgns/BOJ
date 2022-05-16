#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> v[26];

void prefix(int idx){
    if (idx == -1)
        return;
    cout<<(char)(idx+'A');
    prefix(v[idx][0]);
    prefix(v[idx][1]);
}

void infix(int idx){
    if (idx == -1)
        return;
    infix(v[idx][0]);
    cout<<(char)(idx+'A');
    infix(v[idx][1]);
}

void postfix(int idx){
    if (idx == -1)
        return;
    postfix(v[idx][0]);
    postfix(v[idx][1]);
    cout<<(char)(idx+'A');
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin>>n;
    for (int i=0;i<n;i++){
        char a,b,c;
        cin>>a>>b>>c;
        if (b!='.')
            v[a-'A'].push_back(b-'A');
        else
            v[a-'A'].push_back(-1);
        if (c!='.')
            v[a-'A'].push_back(c-'A');
        else
            v[a-'A'].push_back(-1);
    }
    prefix(0);
    cout<<endl;
    infix(0);
    cout<<endl;
    postfix(0);
}