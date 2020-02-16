#include<iostream>
using namespace std;
int top=-1;
#define MAX 10
int stack[MAX];
void push(int data){
	++top;
	if(top== MAX){
		cout<<"overflow"<<endl;
		return;
	}
	stack[top]= data;	
}
void pop(){
	top--;
	if(top== -1){
		cout<<"underflow"<<endl;
		return;
	}
}
void peek(){
	cout<<stack[top]<<endl;
}
bool is_empty(){
	if(top== -1)
		return true;
	return false;
}
void print_stack(){
	for(int i=0; i<=top; i++)
		cout<<stack[i]<<" ";
}
int main(){
	//	print_stack();
	push(1);
	
//	print_stack();
	push(2);
	push(3);
	push(4);
	print_stack();
	cout<<endl;
	pop();
	pop();
	pop();
	print_stack();
	cout<<endl;
	pop();
	pop();
	return 0;
	
}
