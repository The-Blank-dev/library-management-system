
#include <cstring>
#include <dirent.h>
#include <fstream>
#include "update.h"
#include <sys/types.h>
#include "book.h"
#include "features.h"
# include "linked_list.h"
#include "analytics.h"
#include <iostream>
using namespace std;
void print_menu()
{
	cout << endl<<"\t***\tMENU\t***" <<endl;
	cout << "1.To update changes in library type 'update'" <<endl;
	cout << "2.To print list of books type 'list'" <<endl;
	cout << "3.To search books type 'search" <<endl;
	cout << "4.To open a book type 'open" <<endl;
	cout << "5.To perform analytics type 'analytics'" <<endl;
	cout << "6.To EXIT type 'exit'" <<endl;
	cout << "\t***\t****\t***" <<endl;
	cout << endl<<"Enter choice-" ;
}
void clear_screen(){
	system("clear");
}
int main()
{
	char *folder=new char[100];
	cout << "Enter folder path containing the books-" <<endl;
	cin.getline(folder, 100); 
	cout <<"Opened folder-"<< folder<<endl;
	char *ch=new char[20];
	strcpy(ch,"update");
	node* head;
	head=create_list();
	update(folder,&head);
	do
	{
		print_menu();
		cin.getline(ch,20);

		if(!strcmp(ch,"update")){
			update(folder,&head);
		}
		else if(!strcmp(ch,"list")){
			
			display_library(head);
		}
		else if(!strcmp(ch,"search")){
			search_book(head);
		}
		else if(!strcmp(ch,"open")){
			display_book(head);
		}
		else if(!strcmp(ch,"analytics")){
			analytics(head);
		}
		else if(!strcmp(ch,"exit"))
			break;
		else{
			cout<<"Invalid command"<<endl;
		}
		
	}while(strcmp(ch,"exit"));
	clear_screen();
	delete[] folder;
	delete[] ch;
	return 0;
}