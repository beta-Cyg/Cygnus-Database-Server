#include<iostream>
#include"/home/beta-cyg/Cygnus-Database-Server/code/core/adder.hpp"
using namespace std;
using namespace cyg;

struct node{
	int a;
	double b;
	node(const int& aa=0,const double& bb=0.0):a(aa),b(bb){}
};

table test;
adder add("/home/beta-cyg/cygtest","hello.db");

void out(node x){
	cout<<x.a<<' '<<x.b;
}

int main(){
	test.push_back_row("test_row");
	test.insert_row("test_row","test_r2");
	test.push_back("test_row",node(520,13.14));
	for(int i=0;i<31;i++)test.push_back("test_row",node(i,i*0.5));
	for(int i=-5;i<0;i++)test.push_front("test_r2",node(i,i*0.5));
	add.output(test,{out,out});

	return 0;
}
