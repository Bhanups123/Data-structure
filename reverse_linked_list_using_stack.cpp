#include<iostream>
#include<stack>
using namespace std;
struct node{
	int data;
	node* next;
};
node* create_ll(node* head, int data){
	node* new_node= new node;
	new_node->data = data;
	new_node->next= NULL;
	if(head!=NULL)
		new_node->next= head;
	return new_node;	
}
node* reverse(node* head){
	if(head==NULL)
		return head;
	node* temp= head;
	stack<node *>S;
	
	while(temp!=NULL){
		S.push(temp);
		temp = temp->next;
	}
	temp = S.top();
	head = temp;
	S.pop();
	while(!S.empty()){
		temp->next = S.top();
		S.pop();
		temp= temp->next;
	}
	temp->next = NULL;
	return head;
}
void print_list(node* head){
	while(head!= NULL){
		cout<<head->data<<"\t";
		head= head->next;
	}
	cout<<endl;
}
int main(){
	node* head= NULL;
	head= create_ll(head, 1);
	head= create_ll(head, 2);
	head= create_ll(head, 3);
	head= create_ll(head, 4);
	head= create_ll(head, 5);
	print_list(head);
	head= reverse(head);
	print_list(head);
	
	return 0;
}
