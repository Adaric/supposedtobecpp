/* Create a TBT and perform traversals */

#include <iostream>

#include <stdlib.h>
using namespace std;
struct tbtnode
{
int data;
tbtnode *left,*right;
int lbit,rbit,flag;
};


class TBT
{
tbtnode *root;
tbtnode *presuc(tbtnode *t);
tbtnode *insuc(tbtnode *t);
tbtnode *postsuc(tbtnode *t);
tbtnode * father(tbtnode *t);
void TBT::create1(tbtnode *fatherof,int leftorright);
public:
TBT()
{
root=new tbtnode;
root->lbit=0;
root->rbit=1;
root->left=root->right=root;
}
void preorder();
void inorder();
void postorder();
void create();
};

void main()
{
TBT tbt;
int choice;

cout<<”\n\n\t\t\t\t\t\t\t\t\t\t\t\t…. THREADED BINARY TREE ….”;
cout<<”\n\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ”;
do
{
cout<<”\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ”;
cout<<”\n\n MENU: “;
cout<<”\n\n\t1.Create\n\n\t2.Preorder Traversal\n\n\t3.Inorder Traversal\n\n\t4.Postorder Traversal\n\n\t5.Exit”;
cout<<”\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ”;
cout<<”\n\nEnter your choice: “;
cin>>choice;
switch(choice)
{
case 1: tbt.create();break;
case 2: tbt.preorder();break;
case 3: tbt.inorder();break;
case 4: tbt.postorder();break;
}

}while(choice!=5);
getch();
}

void TBT::create1(tbtnode *fatherof,int leftorright)//leftorright=0 for left child

{
tbtnode *p;
int x;
cout<<”\n\nEnter a data (-1 for no data): “;
cin >> x;
if(x==-1)
return ;
p=new tbtnode;
p->data=x;
if(leftorright==0)
{
p->flag=0;
p->lbit=fatherof->lbit;
p->left=fatherof->left;
fatherof->left=p;
fatherof->lbit=1;
p->rbit=0;
p->right=fatherof;
}
else
{
p->flag=1;
p->rbit=fatherof->rbit;
p->right=fatherof->right;
fatherof->right=p;
fatherof->rbit=1;
p->lbit=0;
p->left=fatherof;
}

cout<<”\n\n\tEnter left child of “<<x;
create1(p,0);
cout<<”\n\n\tEnter right child of “<<x;
create1(p,1);
}

void TBT:: create()
{
create1(root,0);
}

tbtnode * TBT::presuc(tbtnode *t)

{
if(t->lbit==1)
return(t->left);
if(t->rbit==1)
return(t->right);
while(t->rbit==0)
t=t->right;
return(t->right);
}

void TBT::preorder()

{
tbtnode *t;
t=root->left;
cout <<”\n\n”;
while(t!=root)
{
cout<<” “<<t->data;
t=presuc(t);
}
}

tbtnode * TBT::insuc(tbtnode *t)

{
if(t->rbit==1)
{
t=t->right;
while(t->lbit==1)
t=t->left;
return(t);
}
else
return(t->right);
}

void TBT::inorder()

{
tbtnode *t;
t=root->left;
cout<<”\n\n”;
while(t->lbit==1)
t=t->left;
while(t!=root)
{
cout<<” “<<t->data;
t=insuc(t);
}
}

tbtnode * TBT::postsuc(tbtnode *t)

{
if(t->flag==0)
{
t=father(t);
if(t->rbit==0)
return(t);
else
{
if(t==t->right)
return(t);
t=t->right;
while(t->lbit==1 || t->rbit==1)
if(t->lbit==1)
t=t->left;
else
t=t->right;
return(t);
}
}
else
return(father(t));

}

void TBT::postorder()

{
tbtnode *t;
t=root->left;
while(t->lbit==1 || t->rbit==1)
if(t->lbit==1)
t=t->left;
else
t=t->right;
while(t!=root)
{
cout<<” “<<t->data;
t=postsuc(t);
}
}

tbtnode * TBT::father(tbtnode *t)

{
if(t->flag==0)
{
while(t->rbit==1)
t=t->right;
return(t->right);
}
else
{
while(t->lbit==1)
t=t->left;
return(t->left);
}
}
