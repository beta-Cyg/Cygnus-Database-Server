#include<iostream>
#include"/home/beta-cyg/Cygnus-Database-Server/code/core/table.hpp"
using namespace std;
using namespace cyg;

struct node{
	int a;
	double b;
	node(const int& aa=0,const double& bb=0.0):a(aa),b(bb){}
};

table test;

int main(){
	test.create_row("test_row");
	//test.insert_row("test_row","test_r2");
	test.push_back("test_row",node(520,13.14));
	for(int i=0;i<31;i++)test.push_back("test_row",node(i,i*0.5));
	for(auto i:test["test_row"])cout<<any_cast<node>(i).a<<' '<<any_cast<node>(i).b<<endl;

	return 0;
}
