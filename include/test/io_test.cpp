#include"core/table_io.hpp"
#include<iostream>
using namespace std;
using namespace cyg;

table t;

int main(){
	t.push_back_row("stu");
	t.push_front_row("num");
	for(int i=0;i<10;i++)t.push_back("stu",string("Bob"));
	for(int i=1;i<=10;i++)t.push_back("num",i);
	t.erase_row("num");
	output("test.cygdb",t.begin(),t.end(),string());

	return 0;
}
