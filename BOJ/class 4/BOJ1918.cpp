#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    stack<char> s;
    string str;
    cin >> str;
    
    for (int i = 0; i < str.length(); i++){
        if ('A' <= str[i] && str[i] <= 'Z'){
            cout << str[i];
        }
        else{
            if (str[i] == '('){
                s.push(str[i]);
            }
            else if (str[i] == ')'){
                while (!s.empty() && s.top() != '('){
                    cout << s.top();
                    s.pop();
                }
                s.pop();
            }
            else if (str[i] == '+' || str[i] == '-'){
                while (!s.empty() && s.top() != '('){
                    cout << s.top();
                    s.pop();
                }
                
                s.push(str[i]);
            }
            else{ //str[i] == '*' || str[i] == '/'
                while (!s.empty() && (s.top() == '*' || s.top() == '/')){
                    cout << s.top();
                    s.pop();
                }
                
                s.push(str[i]);
            }
        }
    }
    
    while (!s.empty()){
        cout << s.top();
        s.pop();
    }
    
    cout << "\n";
    
    return 0;
}
