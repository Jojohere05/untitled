#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left;
	struct node* right;
};
struct node* postorder(struct node*root){
	if(root!=NULL){
	postorder(root->left);
	postorder(root->right);
	printf("%d",root->data);
	}
}
struct node* inorder(struct node*root){
	if(root!=NULL){
	inorder(root->left);
	printf("%d",root->data);
	inorder(root->right);
	}
}
struct node* preorder(struct node*root){
	if(root!=NULL){
	printf("%d",root->data);
	preorder(root->left);
	preorder(root->right);
		}
}
struct node* findmin(struct node*root){
	struct node*curr=root;
	while(curr!=NULL &&curr->left!=NULL){
		curr=curr->left;
	}
	return curr;
}
struct node* deletenode(struct node*root,int key){
	if (root == NULL) {
        return NULL;
    }
	else if(key<root->data){
		root->left=deletenode(root->left,key);
	}
	else if(key>root->data){
		root->right=deletenode(root->right,key);
	}
	else{
		
		if (root->left==NULL&& root->right==NULL){
			struct node* temp=root;
			free(root);
			return NULL;
		}
		else if(root->left==NULL){
			struct node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			struct node* temp=root->left;
			free(root);
			return temp;
		}
			struct node* temp=findmin(root->right);
			root->data=temp->data;
			root->right=deletenode(root->right,temp->data);

	}return root;
}
struct node*search(struct node*root,int key){
	struct node* result=root;
	if (root!=NULL && root->data==key){
		return root;
	}
	else if(key<root->data){
		return search(result->left,key);
	}
	else {
		return search(result->right,key);
	}
	
}
struct node*createnode(int data){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("memory allocation failed");
	}
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
struct node* insertnode(struct node*root,int data){
	if (root==NULL){
		root=createnode(data);
	}
	else if(data<root->data){
		root->left=insertnode(root->left,data);
	}
	else if(data>root->data){
		root->right=insertnode(root->right,data);
	}
	return root;
}
int main(){
	int n,i;
	printf("enter no of nodes in tree\n");
	scanf("%d",&n);
	struct node*root=NULL;
	int arr[n];
	for (i=0;i<n;i++){
		scanf("%d",&arr[i]);
		root=insertnode(root,arr[i]);
	}
/*	printf("preorder traversal\n");
	preorder(root);
	printf("inorder traversal");
	inorder(root);*/
	printf("postorder traversal\n");
	postorder(root);
	int key;
	printf("enter element to be searched\n");
	scanf("%d",&key);
	struct node*found=search(root,key);
	if (found!=NULL){
		printf("%d found in bst",key);
		root=deletenode(root,key);
		printf("postorder after traversal\n");
		postorder(root);
	}
	else{printf("element not found in bst");
	}
	return 0;
}
