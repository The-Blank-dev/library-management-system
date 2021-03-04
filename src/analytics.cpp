#include "analytics.h"

void analytics(node *head){
	cout <<"\nbooks list-";
	node *p=head;
	while(p!=NULL){
		p->b.get_name();
		p=p->next;
	}
	cout<<"\nSelect book- ";
	char *book=new char[30];
	cin.getline(book,30);
	p=head;
	while(p!=NULL){
		if(!strcmp(book,p->b.send_name())){
			if(!strcmp(p->b.send_type(),"novel"))
				novel(p->b.send_filename());
			else 
				play(p->b.send_filename());
			break;
		}

		p=p->next;
	}
	if(p==NULL)
		cout<<"BOOK NOT FOUND"<<endl;
}
void novel(const char *filepath){
	fstream fio;
	fio.open(filepath,ios::out | ios::in);
	fio.seekg(0,ios::beg);

	char *line=new char[1000];
	char *ipword=new char[20];
	cout<<"\nEnter a word- ";
	cin.getline(ipword,20);

	int i,j,l;
	s_array *top_para=new s_array[5];
	int *freq_arr=new int[5];
	for(i=0;i<5;i++){
		freq_arr[i]=0;
		top_para[i].string=new char [10000];
		strcpy(top_para[i].string,"");
	}
	int freq=0;
	char *temp_para=new char[10000];
	strcpy(temp_para,"");
	char *temp_word=new char[20];
	strcpy(temp_word,"");
	l=0;
	j=0;

	while (fio) {
		/*
		if(j==500)
			break;
		j++;
		*/
        fio.getline(line,1000);
        //cout<<line;
        //cout<<"\n freq="<<freq<<endl;
        l=0;
        
        while(line[l]==' ')
        	l++;
        //if(line[l]=='\n' || line[l]==' ')
        	//cout<<"new line"<<endl;
        
        if(line[l]!='\n' && l!=strlen(line)){
        	
        	for(i=0;i<strlen(line);i++){
        		if((line[i]>=65 && line[i]<=90) || (line[i]>=97 && line[i]<=122) )
        			strncat(temp_word,&line[i],1);
        		else{
        			strcat(temp_word,"\0");
        			if(!strcmp(temp_word,ipword)){
        				freq++;
        			}
        			strcpy(temp_word,"");
        		}
        		
        	}
        	strcat(temp_para,line);	
        }
        else{
        	//cout<<"else part ,freq="<<freq<<endl;

        	if(strlen(temp_para)>1){
        		//cout<<"greater than 1";
        	for(i=4;i>=0;i--){
        		if(freq>freq_arr[i])
        		{
        			if(i==4){
        				freq_arr[i]=freq;
        				strcpy(top_para[i].string,temp_para);
        			}
        			else
        			{
        				freq_arr[i+1]=freq_arr[i];
        				strcpy(top_para[i+1].string,top_para[i].string);
        				freq_arr[i]=freq;
        				strcpy(top_para[i].string,temp_para);
        			}
        		}
        		else
        			break;
        	}
        	
        	}
        	else
        		continue;
        	freq=0;
        	strcpy(temp_para,"");
        }
        
    }
    cout<<endl;
    for(i=0;i<5;i++){
    	cout<<top_para[i].string<<"\n FREQUENCY="<<freq_arr[i]<<"\n"<<endl;
    }
    /*
    delete []top_para;
    delete []temp_para;
    delete []temp_word;
    */
    fio.close();
}
void play(const char *filepath){
	fstream fio;
	fio.open(filepath,ios::out | ios::in);
	fio.seekg(0,ios::beg);

	char *line=new char[1000];
	char *character=new char[20];
	cout<<"\nEnter character's name- ";
	cin.getline(character,20);

	int sflag=0,eflag=0,fflag=0;
	int i,j,l;
	i=j=l=0;
	char *char_list=new char[10000];
	strcpy(char_list,"");

	char *scene=new char[10];
	char *enter=new char[10];
	strcpy(scene,"SCENE");
	strcpy(enter,"Enter");
	char *temp_word=new char[20];
	strcpy(temp_word,"");

	while (fio) {
		/*
		if(j==550)
			break;
		j++;
		*/
		//cout<<line<<endl;
        fio.getline(line,100);
        l=0;
        while(line[l]==' '|| line[l]=='\t')
        	l++;

        sflag=0;
        for(i=0;i<strlen(line)-l && i<strlen(scene);i++){
        	if(line[i+l]==scene[i])
        		sflag=1;
        	else{
        		sflag=0;
        		break;
        	}
        }
        if(sflag){
        	//cout<<j<<" detected scene fflag"<<fflag<<endl;
        	if(fflag)
        		cout<<"\nNew SCENE"<<char_list<<endl;
        	strcpy(char_list,"");
        	fflag=0;
        }

        eflag=0;
        for(i=0;i<strlen(line)-l && i<strlen(enter);i++){
        	if(line[i+l]==enter[i])
        		eflag=1;
        	else{
        		eflag=0;
        		break;
        	}
        }
        if(eflag){
        	//cout<<j<<" detected enter"<<endl;
        	for(i=0;i<strlen(line)-l;i++){
        		if((line[i+l]>=65 && line[i]<=90) || (line[i+l]>=97 && line[i]<=122) )
        			strncat(temp_word,&line[i+l],1);
        		else{
        			strcat(temp_word,"\0");
        			//cout<<temp_word<<endl;
        			if(!strcmp(temp_word,character))
        				fflag=1;
        			strcpy(temp_word,"");
        		}
        		
        	}
        	strcat(char_list,"\n");
        	strcat(char_list,line);
        }
        else continue;
    }
    if(fflag)
        cout<<"\nNew SCENE"<<char_list<<endl;
    fio.close();
}