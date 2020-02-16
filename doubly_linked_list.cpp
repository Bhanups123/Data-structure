#include<iostream>
using namespace std;
struct node{
	int data;
	node *prev, *next;
};
node * insert_begin_dlist(node* head, int data){
	node* new_node = new node;
	new_node->data = data;
	new_node->next = new_node->prev = NULL;
	
	if(head==NULL)
		return new_node;
	new_node->next = head;
	head->prev = new_node;
	
	return new_node;
}
node *delete_begin_dlist(node* head){
	if(head == NULL)
		return head;
	node* cur_node = head;
	head = head->next;
	head->prev = NULL;
	delete cur_node;
	return head;
}
void print_dlist(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head= head->next;
	}
}
void print_reverse_dlist_iterative(node* head){
	while(head->next!= NULL){
		head= head->next;
	}
	while(head!= NULL){
		cout<<head->data<<" ";
		head= head->prev;
	}
}
void print_reverse_dlist_recursion(node* head){
	if(head== NULL)
		return;
	print_reverse_dlist_recursion(head->next);
	cout<<head->data<<" ";
}
/*node* insert_begin_stack_memory(node* head, int data){
	node temp;
	temp.data = data;
	temp.next = NULL;
	temp.prev = NULL;
	if(head== NULL)
		return &temp;
	temp.next = head;
	head->prev = &temp;
	return &temp;
}*/
int main(){
	node* head= NULL;
	head = insert_begin_dlist(head,5);
	head = insert_begin_dlist(head,4);
	head = insert_begin_dlist(head,3);
	head = insert_begin_dlist(head,2);
	head = insert_begin_dlist(head,1);
	head = insert_begin_dlist(head,0);
	
	print_dlist(head);
	cout<<endl;
	print_reverse_dlist_iterative(head);
	cout<<endl;
	print_reverse_dlist_recursion(head);
	cout<<endl;
	head = delete_begin_dlist(head);
	print_dlist(head);
	
	/*node * temp=NULL;
	temp = insert_begin_stack_memory(temp, 10);
	temp = insert_begin_stack_memory(temp, 0);
	temp = insert_begin_stack_memory(temp, 10);
	print_dlist(temp);*/
	
	return 0;
}
