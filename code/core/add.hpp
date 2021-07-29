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
	adder(std::string p,std::string n):path(p),name(n){
		//todo add data to the table
	}
};
