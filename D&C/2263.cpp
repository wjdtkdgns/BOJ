#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> in, post, pre;
int n;
bool visited[100002]={0, };

int L(int i){
    int idx=1;
    if (i==0)
        return 0;
    while(!visited[in[i-idx]] && i-idx>=0 && i-idx<n)
        idx++;
    return idx-1;
}

void DP(int start, int end){
    if(visited[post[end]]==1)
        return;
    int i=0;
    pre.push_back(post[end]);
    visited[post[end]]=1;
    if (start==end)
        return;
    while(in[i]!=post[end] && i<n)
        i++;
    int Lcnt=L(i);
    if (Lcnt-1>=0)
        DP(start, start+Lcnt-1);
    if(start+Lcnt<=end-1)
        DP(start+Lcnt, end-1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin>>n;
    int a;
    for (int i=0; i<n; i++){
        cin>>a;
        in.push_back(a-1);
    }
    for (int i=0; i<n; i++){
        cin>>a;
        post.push_back(a-1);
    }
    

    DP(0, n-1);
    for (int i=0; i<n; i++)
    {
        cout<<pre[i]+1;
        if(i!=n-1)
            cout<<" ";
    }   
}