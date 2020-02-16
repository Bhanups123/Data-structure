#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool check_balanced_parenthesis(string str){
	stack<char> s;
	for(char &chr:str){
		if(chr=='('||chr=='{'||chr=='['){
			s.push(chr);
		}
		else if(chr==')'){
			if(!s.empty()&&s.top()=='(')
				s.pop();
			else
				return false;
		}
		else if(chr=='}'){
			if(!s.empty()&&s.top()=='{')
				s.pop();
			else
				return false;
		}
		else if(chr==']'){
			if(!s.empty()&&s.top()=='[')
				s.pop();
			else
				return false;
		}
	}
	return s.empty()?true:false;
}
int main(){
	string str;
	getline(cin, str);
	cout<<check_balanced_parenthesis(str);
	
	return 0;
}
