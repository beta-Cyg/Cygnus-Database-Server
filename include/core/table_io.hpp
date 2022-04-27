#ifndef TABLE_IO_HPP
#define TABLE_IO_HPP

#include<cstdlib>
#include<sstream>
#include<iostream>
#include<fstream>
#include"table.cpp"

namespace cyg{
	void output(const std::string& path,table::const_iterator _begin,table::const_iterator _end){}

	template<typename hT,typename...ArgsT>
	void output(const std::string& path,table::const_iterator _begin,table::const_iterator _end,hT hArg,ArgsT...Args){
		std::stringstream buf;
		if(_begin!=_end){
			auto iter=_begin->begin();
			buf<<std::any_cast<std::string>(*(iter++))<<' ';
			for(;iter!=_begin->end();iter++)
				buf<<std::any_cast<hT>(*iter)<<' ';
		}
		table::const_iterator i=_begin;
		++i;
		std::fstream out(path,std::ios::app);
		//std::cout<<"buf: "<<buf.str()<<std::endl;
		out<<buf.str()<<std::endl;
		out.close();
		//std::system(("echo "+buf.str()+" >> "+path).c_str());
		output(path,i,_end,Args...);
	}

	void input(){}
}

#endif
