#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool priority_low(char c, char t){
	if(c=='*'&&t=='+')
		return true;
}
string infix_2_postfix(string str){
	stack<char> S;
	string post_str="";
	for(char& c:str){
		if(c<=57 && c>=48)
			post_str+=c-48;
		/*else if((c=='*'||c=='+')&&priority_low(S.top(),c)){
			while(priority_low(S.top(),c)){
				post_str+="S.top()";
				S.pop();
			}
		}*/
	}
	while(!S.empty()){
		post_str+="S.top()";
		S.pop();
	}
	return post_str;
}
int main(){
	string str="3+8*5";
	cout<<infix_2_postfix(str);
	
}
