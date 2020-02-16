#include<iostream>
#include<queue>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};
node* create_node(int data){
	node* new_node = new node();			//new operator
		
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	
	return new_node;
}
node* search_binary_search_tree(node* root, int x){
	if(root==NULL)
		return root;
	else if(x==root->data)
		return root;
	else if(x<root->data)
		return search_binary_search_tree(root->left, x);
	else
		return search_binary_search_tree(root->right, x);
}
node* search_max(node* root){
	while(root->right!=NULL)
		root= root->right;
	return root;
}
//node* search_binary_search_tree_predecessor(node* root, int x){
//	if(root==NULL)
//		return root;
//	if(x==root->left->data || x==root->right->data)
//		return root;
//	else if(x<root->data){
//		return search_binary_search_tree_predecessor(root->left, x);
//	}
//	else
//		return search_binary_search_tree_predecessor(root->right, x);
//}

//void delete_element(node* root, int x){
//	if(root==NULL){
//		cout<<"empty tree"<<endl;
//		return;
//	}
//	else{
//		node* temp_deleted = search_binary_search_tree(root, x);
//		if(temp_deleted == NULL)
//			cout<<x<<"\tnot found"<<endl;
//			
//		node* temp_replacing = search_max(temp_deleted->left);
//		
//		temp_replacing->right = temp_deleted->right;
//		
//		temp_replacing->left = temp_deleted->left;
//		
//		node* predecessor = search_binary_search_tree_predecessor(root, x);
//		
//		if(x<predecessor->data)
//			predecessor->left = temp_replacing;
//		else if(x>predecessor->data)
//			predecessor->right = temp_replacing;
//		
//		node* replacing_predecessor = search_binary_search_tree_predecessor(root, temp_replacing->data);
//		
//		if(x<replacing_predecessor->data)
//			replacing_predecessor->left = NULL;
//		else if(x>replacing_predecessor->data)
//			replacing_predecessor->right = NULL;
//			
//		delete temp_deleted;
//	}
//}
void binary_search_tree(node* root, int data){
	
	if(data<= root->data){
		if(root->left==NULL){
			root->left = create_node(data);
			return;
		}
		binary_search_tree(root->left, data);
	}
	else{	
		if(root->right==NULL){
			root->right=create_node(data);
			return;
		}
		binary_search_tree(root->right, data);	
	}
}
void print_bst(node* root){
	if(root== NULL)
		return;
	print_bst(root->left);
	cout<<root->data<<"\t";
	print_bst(root->right);
}
int z;
int height_tree(node* root){
	if(root==NULL)
		return -1;
	if(height_tree(root->left)>= height_tree(root->right))
	return 1 + height_tree(root->left);
	else
	return 1+ height_tree(root->right);
	
//	return 1+ (height_tree(root->left)>=height_tree(root->right))?height_tree(root->left):height_tree(root->right);   ?WHY not working
	
}
void level_order_traversal(node* root){
	if(root==NULL)
		return;
	queue<node*> Q;
	
	Q.push(root);
	while(!Q.empty()){
		cout<<Q.front()->data<<"\t";
		if(Q.front()->left!=NULL)
			Q.push(Q.front()->left);
		if(Q.front()->right!=NULL)
			Q.push(Q.front()->right);
		Q.pop();		
	}	
}
int main(){
	node* root = create_node(12);
	
	binary_search_tree(root, 7);
	binary_search_tree(root, 15);
	binary_search_tree(root, 10);
	binary_search_tree(root, 11);
	binary_search_tree(root, 8);
	binary_search_tree(root, 6);
	binary_search_tree(root, 13);
	binary_search_tree(root, 16);
	
	cout<<"BST: ";
	print_bst(root);
	
	cout<<endl
		<<"height :"<<height_tree(root)<<endl
		<<"Level Order Traversal: ";
	
	level_order_traversal(root);
//	delete_element(root, 10);
	

}

