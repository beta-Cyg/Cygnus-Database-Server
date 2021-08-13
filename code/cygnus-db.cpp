#include<iostream>
#include"core/table_io.hpp"
#include<cstdlib>
#include<string>
#include"version.h"
using namespace std;

string path,type;

int main(int argc,char** args){
	if(argc==1){
		cout<<"Too few args.\n";
		return 0;
	}
	path=args[1];
	cout<<"Cygnus-Database-Server "<<CDS_VERSION<<endl;
	while(true){
		cout<<"\ncygnus-db("+path+")>> ";
		cin>>type;
		if(type=="add--table"){
			string table_name;
			cin>>table_name;
			system(("touch "+path+"/"+table_name).c_str());
		}
		else if(type=="version")cout<<CDS_VERSION;
		else if(type=="exit")break;
		else cout<<"syntax error";
	}

	return 0;
}
