#include "update.h"

void update(const char* folder,node **head){
      struct dirent *entry;
      char *f_name=new char[30];
     
      node *p;
      int f;

      char *f_path=new char[100];
   	DIR *repo = opendir(folder);
   	if (repo == NULL) {
   		cout << "Invalid directory";
      return;
   	}


      int i=0;
   	while ((entry = readdir(repo)) != NULL) {
         //cerr<<"2"<<endl;

   		strcpy(f_name,entry->d_name);
         if(f_name[0]=='.'){
            continue;
            //cout<<f_name<<endl;//continue;
         }
         else
         {
            //out<<entry->d_name<<endl;
            //i++;
            //cout<<i<<endl;
            
            strcpy(f_path,folder);
            strcat(f_path,"/");
            strcat(f_path,f_name);
            
            //cout<<f_path<<endl;
            
            p=*head;

            //display_library(p);
            f=0;
            //cerr<<f_name<<endl;
            
            while(p!=NULL){
               //cerr<<"1"<<endl;
               if(!strcmp(f_path,p->b.send_filename())){
                  f=1;
                  break;
               }
               p=p->next;
            }
            
            //cout<<f<<endl;
            if(f==0)
              insert_node(head,f_path);
            //cerr<<f_name<<endl;
            
            
         } 
   	}
      //cerr<<"outside"<<endl;
      closedir(repo);


      
      
      p=*head;
      while(p!=NULL){
         repo = opendir(folder);
         while ((entry = readdir(repo)) != NULL) {
         f=0;
         strcpy(f_name,entry->d_name);
         if(f_name[0]=='.')
            continue;
         else
         {
            strcpy(f_path,folder);
            strcat(f_path,"/");
            strcat(f_path,f_name);
            if(!strcmp(f_path,p->b.send_filename())){
               f=1;break;
            }
         }
         }
         
         if(f==0){
            delete_node(head,p->b.send_filename());
            p=*head;
         }
         else
            p=p->next;
         closedir(repo);
      }
      
   




   fstream fio;
   fio.open("index.txt",ios::trunc | ios::out | ios::in);
   p=*head;
   while(p!=NULL){
      fio<<p->b.send_filename()<<"\t"<<p->b.send_name()<<"\t"<<p->b.send_author()<<"\t"<<p->b.send_type()<<"\t"<<endl;
      p=p->next;
   }
   fio.close();
   
   return ;
}