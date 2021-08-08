#ifndef TABLE_IO_HPP
#define TABLE_IO_HPP

#include<cstdlib>
#include<sstream>
#include<iostream>
#include"table.hpp"

namespace cyg{
	template<typename hT,typename...ArgsT>
	void output(const std::string& path,table::const_iterator _begin,table::const_iterator _end){
		std::cout<<typeid(hT).name()<<std::endl;
		if(typeid(hT).hash_code()==typeid(void*).hash_code())return;
		std::stringstream buf;
		if(_begin!=_end){
			auto iter=_begin->begin();
			buf<<std::any_cast<std::string>(*(iter++))<<' ';
			for(;iter!=_begin->end();iter++)
				buf<<std::any_cast<hT>(*iter)<<' ';
		}
		std::system(("echo "+buf.str()+" >> "+path).c_str());
		output<ArgsT...>(path,++_begin,_end);
	}

	void input();
}

#endif
