#include<iostream>
using namespace std;
struct node
{
	int data;
	node*prev;
	node*next;
};
class doublink
{
	node*head;
	node*tail;
	public:
		doublink()
		{
			head=NULL;
			tail=NULL;
		}
		void addhead(int n)
		{
			node*temp=new node;
			temp->data=n;
			temp->next=head;
			temp->prev=NULL;
			head->prev=temp;
			head=temp;
		}
		void addnodepos(int pos,int n)
		{
			int i;
			node*temp=new node;
			temp->data=n;
			node*ref;
			ref=head;
			for(i=1;i<pos-1;i++)
			{
				ref=ref->next;
			}
			temp->next=ref->next;
			ref->next=temp;
			temp->prev=ref;
		}
		void insert(int n)
		{
			node*temp=new node;
			temp->data=n;
			temp->prev=NULL;
			temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
			temp->prev=NULL;
		}
		else
		{
			temp->prev=tail;
			tail->next=temp;
			tail=tail->next;
		}
        }
		void display()
		{
			node *temp=head;
            while(temp!=NULL)
            {
            cout<<temp->data;
            temp=temp->next;
            }
            cout<<"\n";
        }
		
		void rdisplay()
		{
			node*temp;
			temp=tail;
			while(temp!=NULL)
			{
				cout<<temp->data;
				temp=temp->prev;
			}
			cout<<"\n";
		}
		void deletehead()
		{
			node*temp;
			temp=head;
			head=head->next;
			head->prev=NULL;
			delete temp;
		}
		void deletetail()
		{
			node*temp;
			temp=tail;
			tail=tail->prev;
			tail->next=NULL;
			delete(temp);
		}
		void deletepos(int pos)
		{
			node*temp;
			node*ref,*refp;
			ref=head;
			refp=head;
			for(int a=1;a<pos;a++)
			{
				refp=ref;
				ref=ref->next;
			}
			temp=ref;
			ref=ref->next;
			refp->next=ref;
			ref->prev=refp;
			delete(temp);
		}
};
int main()
{
	int choice,choice2,size,num,n,posa;
	doublink a;
	cout<<"\t\tWELCOME TO THE PROGRAM OF DOUBLY LINKED LIST\n";
	cout<<"SINCE THE LIST IS EMPTY CREATE A LIST:\n";
	cout<<"ENTER THE NUMBER OF NODES YOU WANT TO ADD:\n";
	cin>>n;
    cout<<"ENTER NODES:\n";
	for(int d=0;d<n;d++)
	{
	cin>>num;
	a.insert(num);
	} 
		while(1)
	{
	cout<<"ENTER YOUR CHOICE FROM BELOW:\n\t1.ADD NODES\n\t2.DELETE HEAD NODE";
	cout<<"\n\t3.DELETE TAIL NODE\n\t4.DELETE A NODE FROM A SPECIFIC POSITION";
	cout<<"\n\t5.DISPLAY LIST \n\t6.REVERSE THE GIVEN LIST\n\t7.EXIT";
	cin>>choice;
	switch(choice)
	{
		case 1:		cout<<"WELCOME TO NODE ADDITION :\nSELECT WHERE DO YOU WANT TO ADD THE NODE:\n";
		            cout<<"1.HEAD NODE\t2.POSITION NODE\t3.TAIL NODE\n";
		            cin>>choice2;
		            switch(choice2)
		            {
		            	case 1:	cout<<"Enter node:";
	                            cin>>num;
                                a.addhead(num);
                                cout<<"\nNODE ADDED SUCCESFULLY!!\n";
                                break;
                        case 2: cout<<"Enter the position on which you want to enter the node:\n";
        	                    cin>>posa;
                            	cout<<"Enter node:\n";
                     	        cin>>num;
        	                    a.addnodepos(posa,num);
        	                    cout<<"NODE ADDED SUCCESSCULLY:\n";
								break;
						case 3: cout<<"NODE WILL BE ADDED ON THE LAST POSITION:\n";
			                    cout<<"Enter node:\n";
		                      	cin>>num;
	                      		a.insert(num);
	                      		cout<<"NODE ADDED SUCCESSFULLY!!\n";
								break;
						default:cout<<"INVALID CHOICE!!!!!";				        
					}
					break;
		case 2:     cout<<"\nDELETING HEAD NODE!!!!\n";
		            a.deletehead();
					break;
		case 3:     cout<<"DELETING TAIL NODE!!!!\n";
    	            a.deletetail();
					break;
		case 4:     cout<<"Enter the position from where you want to delete the node:\n";
		            cin>>posa;
		            a.deletepos(posa);
					break;
		case 5:		cout<<"\nTHE UNIQUE LIST IS :\n";
	                a.display();
					break;
		case 6:     cout<<"THE REVERSE IS:\n";
		            a.rdisplay();
		            break;
		default:	exit(0);															
	}
}
	return 0;
}
