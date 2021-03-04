#ifndef BOOK_H
#define BOOK_H

#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
class Book{
private:
	char *filename,*name,*type,*author;
	char* string_search(const char* );
	void set_name();
	void set_author();
	void set_filename(const char* );
	void set_type();
public:
	Book(const char*);
	~Book();
	void get_name();
	void get_type();
	void get_author();
	void get_filename();
	void get_info();
	char* send_filename();
	char* send_name();
	char* send_type();
	char* send_author();
};
#endif