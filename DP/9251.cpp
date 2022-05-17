#include<iostream>
#include<cstring>

using namespace std;

// LCS

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    string str1, str2;
    cin>>str1>>str2;
    int len1 =strlen(str1.c_str()), len2= strlen(str2.c_str());
    int lcs[len1+1][len2+1];
    for(int i=0;i<len1+1;i++){
        for(int j=0;j<len2+1;j++){
            lcs[i][j]=0;
        }
    }
    for(int i=1;i<len2+1;i++){
        for(int j=1;j<len1+1;j++){
            if (str1[j-1]==str2[i-1])
                lcs[j][i]=lcs[j-1][i-1]+1;
            else
                lcs[j][i]=max(lcs[j-1][i],lcs[j][i-1]);
            // cout<<str1[j-1]<<" "<<str2[i-1]<<" "<<lcs[j][i]<<"  ";
        }
        // cout<<endl;
    }
    if (lcs[len1][len2]<min(len1,len2))
        cout<<lcs[len1][len2];
    else
        cout<<min(len1,len2);

}