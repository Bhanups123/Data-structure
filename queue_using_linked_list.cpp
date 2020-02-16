#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
node* front= NULL;
node* rear= NULL;
void enqueue(int data){
	node* new_node = new node;
	new_node->data = data;
	new_node->next = NULL;
	
	if(front == NULL && rear== NULL){
		front = new_node;
		rear = new_node;
	}
	else{
		rear->next = new_node;
		rear = new_node;
	}
}
void dequeue(){
	node* temp = front;
	if(front == NULL && rear == NULL){
		cout<<"underflow"<<endl;
		return;
	}
	else if(front == rear){
		front = NULL;
		rear = NULL;
	}
	else{
		front = front->next;
	}
	free(temp);
}
void print(){
	node* temp = front;
	if(temp==NULL){
		cout<<"empty queue"<<endl;
		return;
	}
	while(temp!= NULL){
		cout<<temp->data<<"  ";
		temp = temp->next;
	}
	cout<<endl;
}
int main(){
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	
	print();
	
	dequeue();
	print();
	
	enqueue(6);
	print();
	
	while(front!=NULL)
		dequeue();
		
	dequeue();
	print();
	
}
