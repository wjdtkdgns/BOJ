#include <iostream>
#include <stack>
#include <string>

using namespace std;

// stack.top은 stack이 비었을 경우 널을 반환하지않고, 오류를 띄움

char str[101];

int is_op(char a){
    if (a=='+'||a=='-')
        return 1;
    else if (a=='*'||a=='/')
        return 2;
    return 0;
}

int idx=0, keep=1;
void postfix(){
    stack<char> temp_o;
    while(str[idx]){
        if (str[idx]=='('){
            idx++;
            postfix();
        }
        else if (str[idx]==')'){
            while(!temp_o.empty()){
                cout<<temp_o.top();
                temp_o.pop();
            }
            return;
        }
        else if ('A'<=str[idx] && str[idx]<='Z'){
            cout<<str[idx];
        }
        else if (is_op(str[idx])!=0){
            if (is_op(str[idx])==1){
                while(!temp_o.empty()){
                    cout<<temp_o.top();
                    temp_o.pop();
                }
            }
            else if (!temp_o.empty())
                if(is_op(str[idx])==2&&is_op(temp_o.top())==2){
                    while(!temp_o.empty()&&is_op(temp_o.top())==2){
                        cout<<temp_o.top();
                        temp_o.pop();
                    }
                }
            temp_o.push(str[idx]);
        }
        idx++;
    }
    while(!temp_o.empty()){
        cout<<temp_o.top();
        temp_o.pop();
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>str;
    postfix();
}