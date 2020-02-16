#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
int main(){
	char str[50];
	int i=0;
	
	cout<<"enter string"<<endl;
	gets(str);
	
	stack<char> S;
	string s = str;
	for(const char &c: s){			//why not working?
		S.push(c);
	}

/*	for(i=0; i<strlen(str); i++){
		S.push(str[i]);
	}*/
	i=0;
	while(!S.empty()){
		str[i]= S.top();
		S.pop();
		i++;
	}
	cout<<str;
	
	return 0;
}
