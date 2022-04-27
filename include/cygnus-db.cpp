#include<iostream>
#include<fstream>
#include"core/table_io.hpp"
#include<boost/json/src.hpp>
#include<cstdlib>
#include<string>
#include<cstring>
#include<unistd.h>
#include"version.h"
#define HELP_CONTEXT \
	"1)add--table [table name]"
using namespace std;

string type;
char path[256];
int result;

const char* get_path(){
	ifstream fin("log/path.json");
	string json_str;
	fin>>json_str;
	auto json_value=boost::json::parse(json_str);
	return json_value.get_object().begin()->value().get_string().c_str();
}

int main(int argc,char** args){
	strcpy(path,get_path());
	cout<<"Cygnus-Database-Server "<<CDS_VERSION<<endl;
	while(true){
		getcwd(path,sizeof path);
		cout<<"\ncygnus-db("+string(path)+")";
		if(result!=0)cout<<"["+to_string(result)+"]";
		cout<<">>";
		result=0;
		cin>>type;
		if(type=="add--table"){
			string table_name;
			cout<<"Please input table name:";
			cin>>table_name;
			result=system(("touch "+string(path)+"/"+table_name).c_str());
		}
		else if(type=="cd"){
			string cd_path;
			cin>>cd_path;
			result=chdir(cd_path.c_str());
		}
		else if(type=="help")cout<<HELP_CONTEXT;
		else if(type=="version")cout<<CDS_VERSION;
		else if(type=="exit")break;
		else cout<<"syntax error",result=1;
	}

	return 0;
}
