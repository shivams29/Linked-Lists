//CIRCULAR LINKED LIST


#include<iostream>
using namespace std;

//STRUCTURE FOR NODE
struct node
{
	int data;
	node*next;
};

//CLASS WITH ALL OPERATIONS
class cirlink
{
	node *head,*tail;
	public:

//THIS CONSTRUCTOR INITIALIZES THE HEAD NODE AND TAIL NODE.
	cirlink()
	{
		head=NULL;
		tail=NULL;
	}
	
//FUNCTION FOR ADDING NODE AT THE STARTING POSITION.
	void inserthead(int n)
	{
		node*temp=new node;
		temp->data=n;
		temp->next=head;
		head=temp;
		tail->next=head;
	}
	
//THIS FUNCTION ADDS THE NODE AT LAST POSTITION. IT AUTOMATICALLY MAKES THE NEW NODE,HEAD NODE,IF THE LIST IN EMPTY.
	void insert(int n)
	{
		node*temp=new node;
		temp->data=n;
		temp->next=head;
		
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
	
//FUNCTION TO ADD THE NODE AT A CERTAIN POSITION.
	void insertpos(int pos,int n)
	{
		node*prev=new node;
		node*curr=new node;
		node*temp=new node;
		curr=head;
		for(int i=1;i<pos;i++)
		{
			prev=curr;
			curr=curr->next;
		}
		temp->data=n;
		prev->next=temp;
		temp->next=curr;
	}
	
	
//FUNCTION TO DELETE HEAD NODE.
	void deletehead()
	{
		node*temp;
		temp=head;
		head=temp->next;
		tail->next=head;
		delete temp;
	}
	

//FUNCTION TO DELETE THE NODE PRESENT AT A SPECIFIC POSITION.
	void deletepos(int pos)
	{
		node*temp,*prev;
		temp=head;
		for(int i=1;i<pos;i++)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=temp->next;
	}
	
	
//FUNCTION TO DELETE THE NODE PRESENT AT LAST OF THE LIST.
	void deletetail()
	{
		node*prev,*temp;
		temp=tail;
		prev=head;
		while(prev->next!=tail)
		{
			prev=prev->next;
		}
		prev->next=head;
		delete temp;
	}
	
//FUNCTION TO DISPLAY THE LIST.
	void display()
	{
		if(head==NULL)
		{
			cout<<"THe LIST IS EMPTY";
		}
		else{
		node*mark;
		mark=head;
		do
		{
			cout<<mark->data<<"\t";
			mark=mark->next;
		}while(mark!=head);
		}
	}
	

//FUNCTION TO DISPLAY THE REVERSE OF THE LIST.
	void reverse()
	{
		node*last,*curr,*prev,*forw;
		last=head;
		prev=head;
		curr=head->next;
		head=head->next;
		while(head!=last)
		{
			head=head->next;
			curr->next=prev;
			prev=curr;
			curr=head;
		}
		curr->next=prev;
		head=prev;
	}
};
int main()
{
	cirlink a;
	int pos,i,b,num,n,choice,choice2;
	cout<<"\n\tWELCOME TO THE LINKED LIST PROGRAM\n";
	cout<<"\nSINCE THE LIST IS EMPTY CREATE A LIST:\n";
	cout<<"\nENTER THE NUMBER OF NODES YOU WANT TO ADD:\n";
	cin>>n;
    cout<<"\nENTER NODES:\n";
	for(int d=0;d<n;d++)
	{
	cin>>num;
	a.insert(num);
	} 
	while(1)
	{
	cout<<"\nENTER YOUR CHOICE FROM BELOW:\n\t1.ADD NODES\n\t2.DELETE HEAD NODE";
	cout<<"\n\t3.DELETE TAIL NODE\n\t4.DELETE A NODE FROM A SPECIFIC POSITION";
	cout<<"\n\t5.DISPLAY LIST \n\t6.REVERSE THE GIVEN LIST\n\t7.EXIT";
	cin>>choice;
	if(choice==1)
	{
		cout<<"\nWELCOME TO NODE ADDITION :\nSELECT WHERE DO YOU WANT TO ADD THE NODE:\n";
		cout<<"\n1.HEAD NODE\t2.POSITION NODE\t3.TAIL NODE\n";
		cin>>choice2;
		if(choice2==1)
		{
		
	cout<<"\nEnter node:";
	cin>>num;
    a.inserthead(num);
    cout<<"\nNODE ADDED SUCCESFULLY!!\n";
        }
        else if(choice2==2)
        {
        	cout<<"\nEnter the position on which you want to enter the node:\n";
        	cin>>pos;
        	cout<<"\nEnter node:\n";
        	cin>>num;
        	a.insertpos(pos,num);
        	cout<<"\nNODE ADDED SUCCESSCULLY:\n";
		}
		else if(choice2==3)
		{
			cout<<"\nNODE WILL BE ADDED ON THE LAST POSITION:\n";
			cout<<"\nEnter node:\n";
			cin>>num;
			a.insert(num);
			cout<<"\nNODE ADDED SUCCESSFULLY!!\n";
		}
		else{
			cout<<"\nINVALID CHOICE";
		}
	}
    else if(choice==2)
    {
	cout<<"\nDELETING HEAD NODE!!!!\n";
		    a.deletehead();
    }
    else if(choice==3)
    {
    	cout<<"\nDELETING TAIL NODE!!!!\n";
    	a.deletetail();
	}
	else if(choice==4)
	{
		cout<<"\nEnter the position from where you want to delete the node:\n";
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
    	cout<<"\nAFTER REVERSAL THE LIST WILL BE:\n";
    	a.display();
    }
    else 
    {
    	exit(0);
	}
}
		return 0;
}
