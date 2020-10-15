#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
/* Given a string and a set of delimiters, reverse the words
* in the string while maintaining the relative order of the delimiters.
* For example, given "hello/world:here", return "here/world:hello"
*
* Follow-up: Does your solution work for the following cases:
* "hello/world:here/", "hello//world:here"
*/

bool is_non_char(char ch){
    return ((ch > 'Z' && ch < 'A' )|| (ch > 'z' || ch < 'a'));
}
string reverse_word(string s){
    stack<string> st;
    queue<string> q;

    int i = 0;
    int j = 0;
    while( j < s.size()){
        if(is_non_char(s[j])){
            st.push(s.substr(i,j-i));
            i = j;
            j++;
            while(j < s.size() && is_non_char(s[j])){
                j++;
            }
            q.push(s.substr(i,j-i));
            i = j;
        }else{
            j++;
        }
    }
    if(i!=j){
        st.push(s.substr(i));
    }
    string res;
    if(is_non_char(s[0])){
        res += q.front();
        q.pop();
    }
    while(!st.empty() || !q.empty()){
        if(!st.empty()){
            //cout<<"st"<<st.top()<<endl;
            res += st.top();
            st.pop();
        }
        if(!q.empty()){
            //cout<<"q"<<q.front()<<endl;
            res += q.front();
            q.pop();
        }
    }
    return res;
}

int main(){
    //string s = "hello//world:here";
    //string s =  ":hello//world:here";
    string s = "hello/world:here/";
    cout<<s<<endl;
    cout<<reverse_word(s);
}
