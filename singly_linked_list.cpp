#include<malloc.h>
#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
node* insert_begin(node * head, int data){
	node* new_node = (node *)malloc(sizeof(node));
	new_node->data= data;
	new_node->next= head;
	return new_node;
}
node* insert_n(node* head, int data, int n){
	node* cur = head;
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data = data;
	if(n==0){
		head = insert_begin(head, data);
	}
	else if(n>0){
		while(n-1!=0){
			cur=cur->next;
			n--;
		}
		new_node->next=cur->next;
		cur->next = new_node;
	}
	return head;
}
void print_list(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head-> next;
	}
	cout<<"NULL"<<endl;
}
node * reverse_list(node* head){
	node *cur, *prev, *cur_next;
	prev = NULL;
	cur = head;
	cur_next = head->next;
	while(cur!=NULL){
		cur_next = cur->next;
		cur->next=  prev;
		prev = cur;
		cur = cur_next;
	//instead of line 45	if(cur!=NULL)
	//						cur_next = cur->next;
	}
	return prev;
}
void forward_print(node* head){
	cout<<head->data<<"  ";
	if(head->next!=NULL)
		forward_print(head->next);
	else
		cout<<endl;
}
void reverse_print(node* head){
	if(head==NULL){
		return;
	}
	reverse_print(head->next);
	cout<<head->data<<"  ";
}
node* reverse_list_rec(node* prev, node* head){
	if(head == NULL){
		return prev;
	}
	node* pointer;
	pointer = reverse_list_rec(head, head->next);
	head->next = prev;
	return pointer;
}
int main(){
	node* head= NULL;
	head = insert_begin(head, 4);
	head = insert_begin(head, 3);
	head = insert_begin(head, 2);
	head = insert_begin(head, 1);
	head = insert_n(head, 5, 4);
	print_list(head);
	head = reverse_list(head);
	print_list(head);
	forward_print(head);
	reverse_print(head);
	cout<<endl;
	head = reverse_list_rec(NULL, head);
	print_list(head);
	return 0;
}
