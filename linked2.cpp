#include<iostream>
using namespace std;
struct node 
{
	int data;
	node*next;
};
void insert(node*tail,int b);
void display(node*head);
void inserthead(node*head,node*tail,int a)
{
	node*temp = new node;
	temp->data = a;
	temp->next = NULL;
    head = temp;
    tail = temp; 
}
void insert(node*head,node*tail,int b)
{
	if(head==NULL)
	{
		inserthead(head,tail,b);
	}
	else
	{
	node*temp=new node;
	temp->data=b;
	temp->next=NULL;
	tail->next=temp;
	tail=tail->next;
    }
}
void display(node*head)
{
	node*temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\n";
		temp=temp->next;
	}
}
int main()
{
	node*head,*tail;
	head=NULL;
	tail=NULL;
	int choice,num2;
	cout<<"Enter choice:";
	cin>>choice;
	while(choice!=1)
	   {
		   cout<<"Enter number:";
	       insert(head,tail,num2);
       }
    display(head);
    return 0;
}
