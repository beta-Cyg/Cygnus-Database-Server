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

#define Index(r) basic_index[r]

namespace cyg{
	class bad_table_activity:std::exception{
	private:
		std::string reason;
	public:
		bad_table_activity(std::string&& why):reason(why){}

		const char* what(){
			return reason.c_str();
		}
	};

	class table{
	public:
		typedef unsigned long long size_type;
	private:
		std::unordered_map<std::string,size_type>basic_index;
		std::vector<std::vector<std::any>>basic_table;
		size_type row_size;
	public:
		table():basic_index(),basic_table(),row_size(0){}

		~table(){row_size=0;}

		template<typename...ArgsT>
		void insert_row(std::string index,ArgsT&&...args){
			basic_table.push_back(std::vector<std::any>(std::forward<ArgsT>(args)...));
			basic_index[index]=row_size++;
		}

		std::vector<std::any>& operator[](std::string index){
			if(basic_index.count(index))return basic_table[Index(index)];
			else throw bad_table_activity("The row is not exist!");
		}

		void push_back(std::string row,const std::any& value){
			if(basic_index.count(row))basic_table[Index(row)].push_back(value);
			else throw bad_table_activity("The row is not exist!");
		}

		void push_back(std::string row,std::any&& value){
			if(basic_index.count(row))basic_table[Index(row)].push_back(value);
			else throw bad_table_activity("The row is not exist!");
		}
	};
}

#undef Index

#endif
