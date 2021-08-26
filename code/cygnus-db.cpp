#include<iostream>
#include<fstream>
#include"core/table_io.hpp"
#include<boost/json/src.hpp>
#include<cstdlib>
#include<string>
#include"version.h"
using namespace std;

string path,type;

void get_path(string& _p){
	ifstream fin("log/path.json");
	string json_str;
	fin>>json_str;
	auto json_value=boost::json::parse(json_str);
	_p=json_value.get_object().begin()->value().get_string().c_str();
}

int main(int argc,char** args){
	get_path(path);
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
