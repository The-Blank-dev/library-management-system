# include "linked_list.h"

node :: node(const char *path):	
	b(path),
	next(NULL){
		/*
		if(next==NULL)
			cout<<"null"<<endl;
		else
			cout<<"not null"<< endl;
		*/
	}
node :: ~node(){
	//b.Book::~Book();
}
node* create_list(){
	node *head;
	head=NULL;
	return head;
}
void insert_node(node **head,const char *path){
	node *p;
	p=*head;
	node *new_node=new node(path);
	new_node->next=NULL;
	if(*head==NULL){
		*head=new_node;
	}
	else {
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=new_node;
	}
}
void delete_node(node ** head,const char *path){
	node *p,*q;
	p=*head;
	if(!strcmp(p->b.send_filename(),path)){
		*head=p->next;
		delete p;
	}
	else{
		while(p!=NULL && strcmp(p->b.send_filename(),path)){
			q=p;
			p=p->next;
		}
		if(p==NULL){
			cout<<"DELETION FAILED"<<endl;
		}
		else if(!strcmp(p->b.send_filename(),path)){
			q->next=p->next;
			delete p;
		}
	}
}
void display_list(node *head){
	
	node *p;
	p=head;
	system("clear");
	cout<<"List of books present in Library-"<<endl;
	while(p!=NULL){
		p->b.get_info();
		p=p->next;
	}
}
