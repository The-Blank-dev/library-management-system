#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstring>
#include "book.h"
#include <iostream>
using namespace std;

class node{
public:
	Book b; node *next;
	node(const char *);
	~node();
};
node* create_list();
void insert_node(node **,const char *);
void delete_node(node **,const char *);
void display_list(node *);
#endif