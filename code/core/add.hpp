#ifndef ADD_HPP
#define ADD_HPP

#include<iostream>
#include<cstdio>
#include<string>
#include"table.hpp"

#ifndef DEBUG
#pragma once
#endif

class adder{
private:
	std::string path,name;
public:
	adder(std::string p,std::string n):path(p),name(n){}

	void output(const cyg::table& t){
		freopen((path+"/"+name).c_str(),"w",stdout);
		//todo output the table to the database file.
		fclose(stdout);
	}

	void input(cyg::table& t){
		freopen((path+"/"+name).c_str(),"r",stdin);
		//todo input the data of the database file to the table.
		fclose(stdin);
	}
};

#endif
