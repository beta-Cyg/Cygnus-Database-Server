#include<iostream>
#include<cstdlib>
#include<string>
#include"version.h"
using namespace std;

string name,path,type;

int main(int argc,char** args){
	if(argc<3){
		cout<<"Too few args.\n";
		return 0;
	}
	path=args[2];
	name=args[1];
	cout<<"Cygnus-Database-Server "<<CDS_VERSION<<endl;
	while(true){
		cout<<"\ncygnus-db("+name+")>> ";
		cin>>type;
		if(type=="add--table"){
			string table_name;
			cin>>table_name;
			system(("touch "+path+name+"/"+table_name+".db").c_str());
		}
		else if(type=="version")cout<<CDS_VERSION;
		else if(type=="exit")break;
		else cout<<"syntax error";
	}

	return 0;
}
