#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<basic_table.h>

class adder{
private:
	string path,name;
	ifstream fin("");
	ofstream fout("");
public:
	adder(string p,string n):path(p),name(n){
		fin=ifstream(p);
		//todo add data to the table
	}
};
