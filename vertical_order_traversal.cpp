#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};
node* create_tree(int data){
	node * temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
void print(node* root){
	if(root==NULL)
		return;
	print(root->left);
	cout<<root->data<<" ";
	print(root->right);
}
int min_hd, max_hd;
void min_max_horiz_dist(node* root, int hd){
	if(root==NULL)
		return;
		
	else if(hd<min_hd)
		min_hd = hd;
		
	else if(max_hd<hd)
		max_hd = hd;
		
	min_max_horiz_dist(root->left, hd-1);
	min_max_horiz_dist(root->right, hd+1);
	
}
void print_vertical_lines(node* root, int line_no, int hd){
	if(root==NULL)
		return;
	if(line_no == hd)
		cout<<root->data<<" ";
	print_vertical_lines(root->left, line_no, hd-1);
	print_vertical_lines(root->right, line_no, hd+1);	
}
void vertical_level_order_traversal(node* root){
	if(root== NULL)
		return;
	int hd= 0;
	min_max_horiz_dist(root, hd);
	for(int i =min_hd; i<=max_hd; i++){
		print_vertical_lines(root, i, hd);
		cout<<endl;
	}
}
int main(){
	node* root = create_tree(1);
	root->left = create_tree(2);
	root->right = create_tree(3);
	root->left->left = create_tree(4);
	root->left->right= create_tree(5);
	root->left->right->left= create_tree(8);
	root->right->left = create_tree(6);
	root->right->right = create_tree(7);	
	
	vertical_level_order_traversal(root);
//	print(root);
}

