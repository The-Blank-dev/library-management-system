# include "features.h"

void display_library(node *head){
	display_list(head);
}
void display_book(node *head){
	char *bookname=new char[30];
	node *p=head;
	cout<<"\nChoose from-"<<endl;
	while(p!=NULL){
		p->b.get_name();
		p=p->next;
	}
	p=head;
	char *command=new char[35];
	strcpy(command,"gedit ");
	
	cout<< "\nEnter name of book u want to open- ";
	cin.getline(bookname, 30);
	while(p!=NULL){
		if(!strcmp(bookname,p->b.send_name()))
			strcat(command,p->b.send_filename());
		p=p->next;
	}
	system(command);
}
void search_book(node *head){
	char *ip=new char[30];
	char *temp=new char[30];
	cout<<"Enter book's name or author's name to be searched- ";
	cin.getline(ip, 30);
	int i,flag;
	cout<<"Matches shown below-"<<endl;
	cout<<"Using book's name-"<<endl;
	int c=0;
	node *p;
	p=head;
	while(p!=NULL){
		flag=0;
		strcpy(temp,p->b.send_name());
		for(i=0;i<strlen(ip) && i<strlen(temp);i++){
			if(temp[i]!=ip[i] && temp[i]-ip[i]!=32 && temp[i]-ip[i]!=-32){
				flag=0;
				break;
			}
			else
				flag=1;
		}
		if(flag){
			p->b.get_info();
			c++;
		}
		p=p->next;
	}
	if(c==0)
		cout <<"No results found"<<endl;
	
	c=0;
	p=head;
	cout<<"Using author's name-"<<endl;
	while(p!=NULL){
		flag=0;
		strcpy(temp,p->b.send_author());
		for(i=0;i<strlen(ip) && i<strlen(temp);i++){
			if(temp[i]!=ip[i] && temp[i]-ip[i]!=32 && temp[i]-ip[i]!=-32){
				flag=0;
				break;
			}
			else
				flag=1;
		}
		if(flag){
			p->b.get_info();
			c++;
		}
		p=p->next;
	}
	if(c==0)
		cout <<"No results found"<<endl;
		
}