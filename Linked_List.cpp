#include<iostream>
using namespace std;

struct node{
	int info;
	node *temp;
	node *next;
};

class list
{
	private:
		node *head, *temp, *ptr;
	public:
		list()
		{
			head = NULL;
			temp = NULL;
		}
		/*........................Insertion ..................................*/
		
		int insert_front(int x)
		{
			if(head == NULL)
			{
				head= new node();
				head->info = x;
				head->next = NULL;
				return 0;
			}
			else
			{
				temp=head;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				
				ptr = new node();
				ptr->info = x;
				ptr->next=NULL;
				temp->next=ptr;
				
			}
		}
		
		void insert_center(int x, int key)
		{
			temp=head;
			while(temp != NULL)
			{
				if(temp->info == key)
				{
					ptr= new node();
					ptr->info=x;
					ptr->next = temp->next;
					temp->next = ptr;
					return ;
				}
				temp = temp->next;
			}
		}
		/*......................  Searching ..............................*/
		
		void search(int x)
		{
			temp = head;
			
			while(temp != NULL)
			{
				if(temp->info == x)
				{
					cout<<"Value found  = "<<x<<endl;
				}
				temp = temp->next;
			}
		}
		
		/*.................. Deleting.......................*/
		int delete_middle(int x)
		{
			temp=head;
			while(temp  != NULL)
			{
				if(temp->next->info == x)
				{
					ptr= temp->next;
					temp->next = temp->next->next;
					delete ptr;
					ptr = NULL;
					return 0;
				}
				temp = temp->next;
			}
		}
		int delete_front(int x)
		{
			temp=head;
			if(head->info == x)
			{
				head = head->next;
				delete temp;
				temp = NULL;
				return 0;
			}
		}
		
		/*......................Printing............*/
		void print()
		{
			temp=head;
			while(temp != NULL)
			{
				cout<< temp->info <<"  ";
				temp = temp->next;
			}
		}
		
};

int main(){
	
	cout<<"..............Insertion of values........"<<endl;
	list l;
	l.insert_front(3);
	l.insert_front(4);
	l.insert_front(6);
	l.insert_front(7);
	
	l.insert_center(5,4);	// 1st value is for set value and 2nd is for after that
	cout<<"............Print the values.........."<<endl;
	l.print();
	cout<<" "<<endl;
	cout<<".............search the given value..........."<<endl;
	l.search(5);
	
	cout<<"........... delete the middle values..........."<<endl;
	l.delete_middle(5);
	cout<<"............print the remainning values............."<<endl;
	l.print();
	
	
	
	cout<<"........... delete the first values..........."<<endl;
	l.delete_front(3);
	cout<<"..........print the remainning values........."<<endl;
	l.print();
	
	
	return 0;
}
