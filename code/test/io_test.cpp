#include"C:/msys64/home/wyfx/Cygnus-Database-Server/code/core/table_io.hpp"
#include<iostream>
using namespace std;
using namespace cyg;

table t;

int main(){
	t.push_back_row("stu");
	t.push_front_row("num");
	for(int i=0;i<10;i++)t.push_back("stu",to_string(i));
	for(int i=1;i<=10;i++)t.push_back("num",i);
	print("test.db",true,t.begin(),t.end(),int(1),string(""));

	return 0;
}
