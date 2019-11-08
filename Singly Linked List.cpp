//Single Linked List

#include<iostream>
#include<stdlib.h>
using namespace std;

//Creation of node

struct node
{
	int data;
	node *next;
};


class linked
{
	node *head,*tail;
	public:
		linked()
		{
			head=NULL;
			tail=NULL;
		}
		void addhead(int n)
		{
			node*temp=new node;
			temp->data=n;
			temp->next=head;
			head=temp;
		}
		void addnodetail(int n)
		{
			node*temp=new node;
			temp->data=n;
			temp->next=NULL;
			
			if(head==NULL)
			{
				head=temp;
				tail=temp;
			}
			else
			{
				tail->next=temp;
				tail=tail->next;
			}
		}
		void addnodepos(int a,int b)
		{
			int i;
			node*temp=new node;
			node*prev=new node;
			node*curr=new node;
			curr=head;
			for(i=1;i<a;i++)
			{
				prev=curr;
				curr=curr->next;
			}
			temp->data=b;
			prev->next=temp;
			temp->next=curr;
			
		}
		void display()
		{
			if(head==NULL)
			{
				cout<<"THE LIST IS EMPTY !!!!\n";
			}
			else{
			node *temp2;
			temp2=head;
			while(temp2!=NULL)
			{
				cout<<temp2->data<<"\t";
				temp2=temp2->next;
			}
			cout<<"\n\n";
		}
		}
		void deletehead()
		{
			node*temp;
			temp=head;
			head=head->next;
			delete temp;
		}
		void deletetail()
		{
			node*temp,*prev;
		    temp=head;
		    prev=head;
		    while(temp->next!=NULL)
		    {
		    	prev=temp;
		    	temp=temp->next;
			}
			tail=prev;
			tail->next=NULL;
			delete temp;
		}
		void deletepos(int pos)
		{
			node*temp,*prev;
			temp=head;
			prev=head;
			int i;
			for(i=1;i<pos;i++)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next=temp->next;
		}
		void reverse()
		{
			node*curr,*prev,*forw;
			curr=head;
			prev=NULL;
			forw=NULL;
			while(curr!=NULL)
			{
				forw=curr->next;
				curr->next=prev;
				prev=curr;
				curr=forw;
			}
			head=prev;
		}
		
		
	
};

//Starting Of main 

int main()
{
	linked a;
	int pos,i,b,num,n,choice,choice2;
	cout<<"\n\tWELCOME TO THE LINKED LIST PROGRAM\n";
	cout<<"SINCE THE LIST IS EMPTY CREATE A LIST:\n";
	cout<<"ENTER THE NUMBER OF NODES YOU WANT TO ADD:\n";
	cin>>n;
    cout<<"ENTER NODES:\n";
	for(int d=0;d<n;d++)
	{
	cin>>num;
	a.addnodetail(num);
	} 
	while(1)
	{
	cout<<"ENTER YOUR CHOICE FROM BELOW:\n\t1.ADD NODES\n\t2.DELETE HEAD NODE";
	cout<<"\n\t3.DELETE TAIL NODE\n\t4.DELETE A NODE FROM A SPECIFIC POSITION";
	cout<<"\n\t5.DISPLAY LIST \n\t6.REVERSE THE GIVEN LIST\n\t7.EXIT";
	cin>>choice;
	if(choice==1)
	{
		cout<<"WELCOME TO NODE ADDITION :\nSELECT WHERE DO YOU WANT TO ADD THE NODE:\n";
		cout<<"1.HEAD NODE\t2.POSITION NODE\t3.TAIL NODE\n";
		cin>>choice2;
		if(choice2==1)
		{
		
	cout<<"Enter node:";
	cin>>num;
    a.addhead(num);
    cout<<"\nNODE ADDED SUCCESFULLY!!\n";
        }
        else if(choice2==2)
        {
        	cout<<"Enter the position on which you want to enter the node:\n";
        	cin>>pos;
        	cout<<"Enter node:\n";
        	cin>>num;
        	a.addnodepos(pos,num);
        	cout<<"NODE ADDED SUCCESSCULLY:\n";
		}
		else if(choice2==3)
		{
			cout<<"NODE WILL BE ADDED ON THE LAST POSITION:\n";
			cout<<"Enter node:\n";
			cin>>num;
			a.addnodetail(num);
			cout<<"NODE ADDED SUCCESSFULLY!!\n";
		}
		else{
			cout<<"INVALID CHOICE";
		}
	}
    else if(choice==2)
    {
	cout<<"\nDELETING HEAD NODE!!!!\n";
		    a.deletehead();
    }
    else if(choice==3)
    {
    	cout<<"DELETING TAIL NODE!!!!\n";
    	a.deletetail();
	}
	else if(choice==4)
	{
		cout<<"Enter the position from where you want to delete the node:\n";
		cin>>pos;
		a.deletepos(pos);
	}
	else if(choice==5)
	{
		cout<<"\nTHE UNIQUE LIST IS :\n";
	a.display();	
    }
    else if(choice==6)
    {
    	a.reverse();
    	cout<<"AFTER REVERSAL THE STRING WILL BE:\n";
    	a.display();
    }
    else 
    {
    	exit(0);
	}
}
		return 0;
}
