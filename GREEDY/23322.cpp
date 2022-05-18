#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

// 단순하게 생각하기

int main(){
    int n,k;
    cin>>n>>k;
    int ch[2001];
    for(int i=0;i<n;i++){
        cin>>ch[i];
    }
    int eat=0;
    int day=0;
    for(int i=k;i<n;i++){
        while(1){
            if(ch[i]!=ch[i-k]){
                eat += ch[i]-ch[i-k];
                ch[i]=ch[i-k];
                day++;
                // cout<<i<<" "<<eat<<" "<<day<<endl;
                sort(ch,ch+n);
            }
            else
                break;
        }
    }
    // queue<int> q;
    // int max=0;
    // int maxidx=0;
    // for(int i=k;i<n;i++){
    //     if(i-k>=0&&ch[i]>ch[i-k]){
    //         if (max < ch[i]-ch[i-k]){
    //             max = ch[i]-ch[i-k];
    //             maxidx=i;
    //         }
    //     }
    // }
    // if (maxidx!=0)
    //     q.push(maxidx);
    // while(!q.empty()){
    //     max=0;
    //     maxidx=0;
    //     int cur=q.front();
    //     q.pop();
    //     if(cur-k>=0&&ch[cur]>ch[cur-k]){
            // eat += ch[cur]-ch[cur-k];
            // ch[cur]=ch[cur-k];
            // day++;
            // cout<<cur<<" "<<eat<<" "<<day<<endl;
            // sort(ch,ch+n);
    //     }
    //     cout<<ch[0]<<ch[1]<<ch[2]<<ch[3]<<endl<<endl;
    //     for(int i=k;i<n;i++){
    //         if(i-k>=0&&ch[i]>ch[i-k]){
    //             if (max < ch[i]-ch[i-k]){
    //                 max = ch[i]-ch[i-k];
    //                 maxidx=i;
    //                 // cout<<max<<" "<<maxidx<<endl;
    //             }
    //         }
    //     }
    //     if (maxidx!=0)
    //         q.push(maxidx);

    // }
    cout<<eat<<" "<<day<<endl;
}