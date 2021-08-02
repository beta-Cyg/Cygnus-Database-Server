#include<fstream>
#include"table.hpp"

namespace cyg{
	void print(const std::string& path){}

	template<typename hT,typename...ArgsT>
	void print(const std::string& path,table::const_iterator begin,table::const_iterator end){
		//table::iterator iter=begin;
		//iter++;
		std::ofstream fout(path.c_str());
		if(begin!=end)
			for(auto i:*begin)
				fout<<std::any_cast<hT>(i)<<' ';
		print<ArgsT...>(path,begin++,end);
	}
}
