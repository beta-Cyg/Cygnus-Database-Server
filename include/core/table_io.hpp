#ifndef TABLE_IO_HPP
#define TABLE_IO_HPP

#include<cstdlib>
#include<sstream>
#include<iostream>
#include<fstream>
#include"table.cpp"

namespace cyg{
	void output(const std::string& path,table::const_iterator _begin,table::const_iterator _end){
		std::stringstream buf;
		for(;_begin!=_end;_begin++){
			auto iter=_begin->begin();
			buf<<*(iter++)<<' ';
			for(;iter!=_begin->end();iter++)
				buf<<*iter<<' ';
            buf<<std::endl;
		}
		std::fstream out(path,std::ios::app);
		out<<buf.str();
		out.close();
	}

    void reset(const std::string& path){
        std::fstream out(path,std::ios::trunc|std::ios::out);
        out.close();
    }

	void input(const std::string& path){
        std::fstream in(path,std::ios::in);

        in.close();
    }
}

#endif
