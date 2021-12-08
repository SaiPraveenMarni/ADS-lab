#include<stdio.h>
#include<stdlib.h>
struct node
{
  int key;
  struct node *left;
  struct node *right;
  int height;
};
typedef struct node *NODE;

int max(int a,int b);
int height(NODE n)
{
   if(n==NULL)
   return 0;
   return n->height;
}
int max(int a,int b)
{
   if(a>b)
   return a;
   else
   return b;
}


NODE newnode(int key)
{

   NODE newnode=(NODE)malloc(sizeof(struct node));

   newnode->key=key;
   newnode->left=NULL;
   newnode->right=NULL;
   newnode->height=1;

   return(newnode);
}
NODE rightrotate(NODE y)
{
     NODE x=y->left;
     NODE t2=x->right;

     x->right=y;
     y->left=t2;



     y->height=max(height(y->left),height(y->right)) + 1;
     x->height=max(height(x->left),height(x->right)) + 1;

     return x;

}
NODE leftrotate(NODE x)
{
    NODE y=x->right;
    NODE t2=y->left;

    y->left=x;
    x->right=t2;

	 x->height=max(height(x->left),height(x->right)) + 1;
     y->height=max(height(y->left),height(y->right)) + 1;

     return y;

}
int getbalance(NODE n)
{
    if(n==NULL)
    return 0;
    return height(n->left)-height(n->right);
}
NODE insert(NODE node,int key)
{
   if(node==NULL)
   {
      return(newnode(key));
   }
   if(key<node->key)
   {
       node->left=insert(node->left,key);
   }
   else if(key>node->key)
   {
       node->right=insert(node->right,key);
   }
   else
   return node;

   node->height=max(height(node->left),height(node->right)) + 1;

   int balance=getbalance(node);
   printf("BALANCE OF %d is %d\n",node->key,balance);

   if(balance>1 && key<node->left->key)
   return rightrotate(node);

   if(balance>1 && key>node->left->key)
   {
       node->left=leftrotate(node->left);
       return rightrotate(node);

   }
   if(balance<-1 && key>node->right->key)
   {
       return leftrotate(node);
   }
   if(balance<-1 && key<node->right->key)
   {
       node->right=rightrotate(node->right);
       return leftrotate(node);
   }
   return node;
}
NODE minvalenode(NODE root)
{
   NODE current=root;
   while(current->left!=NULL)
   {
      current=current->left;
   }
   return current;
}
void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->key);
        preorder(root->left);
        preorder(root->right);
    }

}
NODE deletenode(NODE root,int key)
