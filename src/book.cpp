#include "book.h"

Book :: Book(const char* filepath):
filename(new char[100]),
name(new char[30]),
type(new char[20]),
author(new char[30]){
	
	set_filename(filepath);
	set_name();
	set_author();
	set_type();
	
}
Book :: ~Book(){
	cout << "Book-"<<name<<"has been deleted"<<endl;
	delete [] name;
	delete [] filename;
	delete [] author;
	delete [] type;
}
char* Book :: string_search(const char*str){
	fstream fio;
	fio.open(filename,ios::out | ios::in);
	//cout<<"test1";
	fio.seekg(0,ios::beg);
	//cout<<"test2";
	char *result=new char[30];
	char *line=new char[100];
	int flag=1,i;
	//cout<<"test3";
	while (fio) {
        fio.getline(line,100); 
        //cout<<line<<endl;
        //cout<<strlen(str)<<strlen(line);
        flag=0;
  		for(i=0;i<strlen(str) && i<strlen(line); i++){
  			
  			if(str[i]!=line[i]){
  				flag=0;
  				break;
  			}
  			else 
  				flag=1;
  		}
  		if(flag){
  			for(i=strlen(str)+2;i<strlen(line);i++){
  				if((line[i]>=65 && line[i]<=90) || (line[i]>=97 && line[i]<=122) || line[i]==' ' || line[i]==':' || line[i]==',' || line[i]=='.' || line[i]=='/' || line[i]=='?' || line[i]==';'){
  				result[i-strlen(str)-2]=line[i];
  				}
  				else break;
  			}
  			break;
  		}        
    } 
    //cout<<"test4";
    result[i-strlen(str)-2]='\0';
    //cout<<result<<endl;
    fio.close();
    return result;
}
void Book :: set_name(){
	strcpy(name,string_search("Title"));
}
void Book :: set_type(){
	cout <<"Enter the type of book-";
	get_name();
	cout<<"-  ";
	cin.getline(type, 20); 
}
void Book :: set_author(){
	strcpy(author,string_search("Author"));
}
void Book :: set_filename(const char* str){
	strcpy(this->filename,str);	
}

void Book :: get_name(){
	cout <<"\n"<<name;
}
void Book :: get_type(){
	cout <<"\n"<<type;
}
void Book :: get_author(){
	cout <<"\n"<<author;
}
void Book :: get_filename(){
	cout <<"\n"<<filename;
}
void Book :: get_info(){
	cout<<endl;
	cout<<"Book's name-";
	get_name();
	cout<<"\nBook's file-";
	get_filename();
	cout<<"\nBook's author-";
	get_author();
	cout<<"\nBook's type-";
	get_type();
	cout<<endl;
}
char* Book :: send_filename(){
	return filename;
}
char* Book :: send_name(){
	return name;
}
char* Book :: send_type(){
	return type;
}
char* Book :: send_author(){
	return author;
}