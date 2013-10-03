#include<iostream>
#include<cstdlib>
#include<ctype.h>
#include<math.h>
using namespace std;

struct node
{char data;
node *left,*right,*next;};

node *root,*temp,*m,*n,*start,*front,*end,*blank;
char stack[30],postfix[60];
int index=0;
void push(char t)
{
stack[index]=t;
index++;
}


char pop()
{
index--;
return stack[index];
}


void dopostfix()
{int j=0;
for(int i=0;postfix[i]!='\0';i++)
{


if(isalpha(postfix[i]) || isdigit(postfix[i]))
{stack[j]=postfix[i];
j++;}
else
	{
	m=(node*)malloc(sizeof(struct node));
	n=(node*)malloc(sizeof(struct node));
	
	j--;
	n->data=stack[j];

	j--;
	m->data=stack[j];

	if(root==NULL)
		{
		root=(node*)malloc(sizeof(struct node));
		root->data=postfix[i];
		root->left=m;
		root->right=n;
		m->left=NULL;
		m->right=NULL;
		n->left=NULL;
		n->right=NULL;}
	else
	{
		if(m->data=='#')
			{m->data=root->data;
			 m->left=root->left;
			 m->right=root->right;}
		else
			{m->left=NULL;
			m->right=NULL;}

		if(n->data=='#')
			{if(temp!=NULL)
			 {n->data=temp->data;
			 n->left=temp->left;
			 n->right=temp->right;
			 temp=NULL;}
			else
			{n->data=root->data;
			 n->left=root->left;
			 n->right=root->right;}
			 }
		else
			{n->left=NULL;
			n->right=NULL;}


		



		if(j!=0 && stack[0]=='#')
			{temp=(node*)malloc(sizeof(struct node));
			cout<<postfix[i]<<i<<endl;
 			temp->data=postfix[i]; 			
			temp->left=m;
 			temp->right=n;
 			
			}
		else
			{
 			root->left=m;
 			root->right=n;
			
 			root->data=postfix[i];
			}

		
	}	
	stack[j]='#';
	j++;
//SHIT ZOO
/*
cout<<m->data;
cout<<n->data;	       
cout<<root->data;
//cout<<stack[j-1]<<stack[j-2];*/
		
	
//SHIT ZOO ENDS
}	
}}



node *queue[30];
int f=0,l=-1;

void enqueue(node *t)
{l++;

queue[l]=t;}

struct node *dequeue()
{if(f<=l)
{node *t;

t=queue[f];
++f;

return t;}
}



int level,level1=0;



//Some fcking finding height of tree

void height(node *temp1)
{

if(temp==temp1)
{//cout<<"\n"<<index<<"here"<<temp1->data<<"\n";
level=index;}

if(temp1->left!=NULL && temp1->right!=NULL)
{index++;
height(temp1->left);
}

if(temp1->right!=NULL)
{index++;
height(temp1->right);
}

							//if(temp->left==NULL && temp->right==NULL)
index--;

return;

}

//IT WORKsBABE ok it worked but i swear it









//HERE"S THE FRIGGING LEVEL OREDER THAT FINALLY WORKS

void output()
{do
{


for(int i=0;i<30/(level1+1);i++)
{cout<<" ";}

if(level1%2!=0)
{cout<<"\t   ";}

cout<<temp->data;
index++;

for(int i=0;i<30/(level1+2);i++)
{cout<<" ";}

if(index==pow(2,level1))
{cout<<endl;
level1++;
index=0;}


if(temp->left!=NULL)
enqueue(temp->left);
else
enqueue(blank);

if(temp->right!=NULL)
enqueue(temp->right);
else
enqueue(blank);



if(temp==blank)
{enqueue(blank);
enqueue(blank);
}


temp=dequeue();



/*
//MY ADDITION FOR PRINTING IN LINES
if(temp!=blank)
{height(root);}
//cout<<level1<<" # "<<level<<endl;
if(level!=level1)
{cout<<endl<<level<<endl;
level1++;}
index=0;
//MY ADDITION FOR PRINTING IN LINES
*/
}
while(f<=l);
}

//AND THAT LEVEL ORDER ENDS HERE










int main()
{
root=NULL;
temp=NULL;

cin>>postfix;
dopostfix();
blank=(node*)malloc(sizeof(struct node));
blank->data=' ';
front=NULL;
end=NULL;
temp=root;
output();


cout<<endl;
//height(root);

return 0;}
