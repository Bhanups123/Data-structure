#include<iostream>
using namespace std;
#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

bool isempty(){
	if(front==-1 && rear==-1)
		return true;
	return false;
}
void enqueue(int data){
	if(isempty()){
		front = rear = 0;
	}
	else if((rear+1)%MAX == front){
		cout<<"overflow"<<endl;
		return;
	}
	else{
		rear = (rear+1)%MAX;
	}
	queue[rear]=data;
}
void dequeue(){
	if(isempty()){
		cout<<"underflow"<<endl;
		return;
	}
	else if(front==rear){
		queue[front]=0;
		front = rear = -1;
	}
	else{
		queue[front]=0;
		front = (front+1)%MAX;
	}
}
void front_show(){
	cout<<queue[front]<<endl;
}
void print(){
	for(int i=0;i<MAX;i++)
		cout<<queue[i]<<"\t";
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
	enqueue(7);
	print();
	for(int i=0;i<=MAX;i++)
	dequeue();
	print();
}

