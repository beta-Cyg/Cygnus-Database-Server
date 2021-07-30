#ifndef BASIC_TABLE_H
#define BASIC_TABLE_H

#ifndef DEBUG
#pragma once
#endif

#include<unordered_map>
#include<exception>
#include<utility>
#include<vector>
#include<string>
#include<any>

namespace cyg{
	class bad_table_activity:std::exception{
	private:
		std::string reason;
	public:
		bad_table_activity():reason(""){}

		bad_table_activity(std::string&& why):reason(why){}

		const char* what(){
			return reason.c_str();
		}
	};

	static bad_table_activity rne_err("The row is not exist!");

	class table{
	public:
		typedef unsigned long long size_type;
		typedef std::vector<std::vector<std::any>>::iterator iterator;
		typedef std::vector<std::vector<std::any>>::const_iterator const_iterator;
	private:
		std::unordered_map<std::string,iterator>basic_index;
		std::vector<std::vector<std::any>>basic_table;
		size_type row_size;
	public:
		table():basic_index(),basic_table(),row_size(0){}

		~table(){row_size=0;}

		void create_row(std::string index){
			basic_index[index]=basic_table.insert(basic_table.begin(),std::vector<std::any>());
		}

		void insert_row(std::string position,std::string index){
			basic_index[index]=basic_table.insert(basic_index[position],std::vector<std::any>());
		}

		std::vector<std::any>& operator[](std::string index){
			if(basic_index.count(index))return *basic_index[index];
			else throw rne_err;
		}

		std::vector<std::any>& at(std::string index){
			if(basic_index.count(index))return *basic_index[index];
			else throw rne_err;
		}

		std::any& front(std::string row){
			if(basic_index.count(row))basic_index.at(row)->front();
			else throw rne_err;
		}

		const std::any& front(std::string row)const{
			if(basic_index.count(row))basic_index.at(row)->front();
			else throw rne_err;
		}

		const std::any& back(std::string row){
			if(basic_index.count(row))basic_index.at(row)->back();
			else throw rne_err;
		}

		std::any& back(std::string row)const{
			if(basic_index.count(row))basic_index.at(row)->back();
			else throw rne_err;
		}

		void push_back(std::string row,const std::any& value){
			if(basic_index.count(row))basic_index.at(row)->push_back(value);
			else throw rne_err;
		}

		void push_back(std::string row,std::any&& value){
			if(basic_index.count(row))basic_index.at(row)->push_back(value);
			else throw rne_err;
		}

		void push_front(std::string row,std::any&& value){
			if(basic_index.count(row))basic_index.at(row)->insert(basic_index[row]->begin(),value);
			else throw rne_err;
		}

		void push_front(std::string row,const std::any& value){
			if(basic_index.count(row))basic_index.at(row)->insert(basic_index[row]->begin(),value);
			else throw rne_err;
		}

		void insert(std::string row,std::vector<std::any>::const_iterator position,const std::any& value){
			if(basic_index.count(row))basic_index.at(row)->insert(position,value);
			else throw rne_err;
		}

		void insert(std::string row,std::vector<std::any>::const_iterator position,std::any&& value){
			if(basic_index.count(row))basic_index.at(row)->insert(position,value);
			else throw rne_err;
		}
	};
}

#endif
