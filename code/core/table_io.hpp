#include<cstdlib>
#include<sstream>
#include"table.hpp"

namespace cyg{
	void print(const std::string& path,bool type,table::const_iterator _begin,table::const_iterator _end){}

	template<typename hT,typename...ArgsT>
	void print(const std::string& path,bool type,table::const_iterator _begin,table::const_iterator _end,hT harg,ArgsT...Args){
		std::stringstream buf;
		if(_begin!=_end){
			auto iter=_begin->begin();
			buf<<std::any_cast<std::string>(*(iter++))<<' ';
			for(;iter!=_begin->end();iter++)
				buf<<std::any_cast<hT>(*iter)<<' ';
		}
		if(type)std::system(("echo \""+buf.str()+"\" > "+path).c_str());
		else std::system(("echo \""+buf.str()+"\" >> "+path).c_str());
		print(path,type,_begin++,_end,Args...);
	}
}
