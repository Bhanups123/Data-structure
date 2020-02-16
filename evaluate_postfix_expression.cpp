#include<iostream>
#include<stack>
#include<string>
using namespace std;
int evaluate_expression(int x, char op, int y){
	switch(op){
		case '*':
			return x*y;
		case '/':
			return x/y;
		case '+':
			return x+y;
		case '-':
			return x-y;
	}
}
//Assuming expression is postfix
int evaluate_postfix_expression(string exp){
	stack<int> S;
	int z;
	int x,y;
	for(char& chr:exp){
		if(chr>=48 && chr<=57)
			S.push(chr-48);
		else if(chr=='*'||chr=='/'||chr=='+'||chr=='-'){
			y=S.top();S.pop();
			x=S.top();S.pop();
			S.push(evaluate_expression(x,chr,y));
		}
	}
	return S.top();
}
int main(){
	string str;
	cout<<"enter a postfix expression"<<endl;
	cin>>str;
	cout<<"Value after evaluation:"<<'\n'<<evaluate_postfix_expression(str)<<endl;
	return 0;
}
