#ifndef ADD_HPP
#define ADD_HPP

#include<initializer_list>
#include<iostream>
#include<cstdio>
#include<string>
#include"table.hpp"

#ifndef DEBUG
#pragma once
#endif

namespace cyg{
	class adder{
	private:
		std::string path,name;
	public:
		adder(std::string p,std::string n):path(p),name(n){}

		void output(const cyg::table& t,std::initializer_list<void(std::any)>outs){
			freopen((path+"/"+name).c_str(),"w",stdout);
			auto iter=outs.begin();
			for(auto i:t){
				for(auto j:i)
					(*iter)(j);
				iter++;
				std::cout<<std::endl;
			}
			fclose(stdout);
		}

		void input(cyg::table& t){
			freopen((path+"/"+name).c_str(),"r",stdin);
			//todo input the data of the database file to the table.
			fclose(stdin);
		}
	};
}

#endif

