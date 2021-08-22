#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<boost/json.hpp>
using namespace std;

vector<string>Args;

void get_flag(bool& _f){
	string json_str;
	ifstream fin("log/flag.json");
	fin>>json_str;
	fin.close();
	auto json_val=boost::json::parse(json_str.c_str());
	//todo
}

string init_db(){
//	string path;
//	cout<<"Please type the path of databases"
//		"(use '/' to part the directory):";
//	cin>>path;
//	system((
//		"mkdir "+path
//	       ).c_str());
//	system((
//		"echo "+path+" > log/path.json"
//	       ).c_str());
	system(
		"echo \"{\\\"flag\\\": 1}\" > log/flag.json"
		);
//	return path;
}

void create_db(){
//	bool flag;
//	string path;
//	ifstream fin("log/path.json");
//	get_flag(flag);
//	if(not flag)
//		path=init_db();
//	else fin>>path;
//	string name,passwd;
//	cout<<"Please type the name of the database: ";
//	cin>>name;
//	cout<<"Please type the passwd of the database: ";
//	cin>>passwd;
//	system(("./bin/encrypt.c "+passwd+" "+path+"/.passwdlists").c_str());
//	system(("touch "+path+"/"+name).c_str());
}

void add_user(){
//    string passwd;
//    bool flag;
//    string path;
//    ifstream fin("log/path.json");
//    get_flag(flag);
//    if(not flag)
//        path=init_db();
//    else fin>>path;
//    cout<<"Please type the passwd of the user: ";
//    cin>>passwd;
//    system(("./bin/encrypt "+passwd+" "+path+"/.passwdlists").c_str());
}

int main(int argc,char** args){
	for(int i=0;i<argc;i++)
		Args.emplace_back(args[i]);
	switch(argc){
	case 1:
		cout<<"Too few args\n";
		break;
	case 2:
		if(Args[1]=="--init"){
			init_db();
		}
		else if(Args[1]=="--create"){
			create_db();
		}
		else if(Args[1]=="--adduser"){
		    add_user();
		}
		else{
			system(("cygnus-db "+Args[1]).c_str());
		}
		break;
	default:
	    break;
	}

	return 0;
}
