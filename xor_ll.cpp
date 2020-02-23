#include<iostream>

using namespace std;
typedef uintptr_t ut;

struct node{
	int data;
	node *next;
};

void print(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"null"<<endl;
}
int main(){
	node *head = NULL, *cur = NULL, *temp;
	
	int x, n;
	
	cout<<"enter no. of nodes"<<endl;
	cin>>x;
	
	while(x-->0){
		cout<<"enter value"<<endl;
		cin>>n;
		if(head==NULL){
			node *temp = (node*)malloc(sizeof(node));
			temp->next = NULL;
			temp->data = n;
			head = cur = temp;
			
		}
		else{
			temp = (node*)malloc(sizeof(node));
			temp->next = NULL;
			temp->data = n;
			cur->next = temp;
			cur = temp;
		}
	}
	print(head);
	
	temp = (node *)((ut)(head->next)^(ut)(head)^(ut)(head));
	cout<<temp->data;
	
}
