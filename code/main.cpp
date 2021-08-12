#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

vector<string>Args;

void init_db(){
	string name,passwd,path;
	cout<<"Please type the path of the database"
		"(use '/' to part the directory): ";
	cin>>path;
	reverse(path.begin(),path.end());
	name=path.substr(0,path.find("/"));
	reverse(name.begin(),name.end());
	reverse(path.begin(),path.end());
	cout<<"Please type the passwd of the database: ";
	cin>>passwd;
	system(("mkdir "+path).c_str());
	system(("echo "+passwd+" >> "+path+"/.passwdlists").c_str());
	system(("touch "+path+"/database.db").c_str());
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
	}

	return 0;
}
