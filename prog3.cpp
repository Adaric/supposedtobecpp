#include<iostream>
#include<cstdlib>
#include<ctype.h>
using namespace std;

struct node
{char data;
node *left,*right,*next;};

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

int main()
{
node *a,*b,*c;
a=(node*)malloc(sizeof(struct node));
b=(node*)malloc(sizeof(struct node));
c=(node*)malloc(sizeof(struct node));
a->data='a';
b->data='b';
c->data='c';
enqueue(a);
enqueue(b);
enqueue(c);
enqueue(a);

cout<<dequeue()->data;

cout<<dequeue()->data;

cout<<dequeue()->data;
return 0;}
