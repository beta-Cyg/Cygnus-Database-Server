#include"/home/beta-cyg/Cygnus-Database-Server/code/core/table_io.hpp"
using namespace std;
using namespace cyg;

table t;

int main(){
	t.push_back_row("test");
	for(int i=0;i<10;i++)t.push_back("test",i);
	print("test.db",false,t.begin(),t.end(),123);

	return 0;
}
