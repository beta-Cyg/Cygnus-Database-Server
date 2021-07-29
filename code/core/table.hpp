#ifndef BASIC_TABLE_H
#define BASIC_TABLE_H

#ifndef DEBUG
#pragma once
#endif

#include<unordered_map>
#include<utility>
#include<vector>
#include<string>

namespace cyg{
	template<typename ValueT>
	class table{
	public:
		typedef ValueT value_type;
		typedef unsigned long long size_type;
		typedef ValueT& reference;
		typedef const ValueT& const_reference;
	private:
		std::unordered_map<std::string,std::vector<ValueT>>basic_table;
	public:
		table():basic_table(){}

		template<typename...ArgsT>
		void insert_row(std::string index,ArgsT...args){
			basic_table.insert(
				std::make_pair(index,
					std::vector<value_type>(
						std::forward(args...)
					)
				)
			);
		}

		std::vector<value_type>& operator[](std::string index){
			return basic_table[index];
		}

		void push_back(std::string row,const_reference value){
			basic_table[row].push_back(value);
		}

		void push_back(std::string row,reference&& value){
			basic_table[row].push_back(value);
		}

		template<typename...ArgsT>
		void emplace_back(std::string row,ArgsT&&...Args){
			basic_table[row].emplace_back(std::forward(Args...));
		}

		template<typename...ArgsT>
		void emplace_back(std::string row,const ArgsT&...Args){
			basic_table[row].emplace_back(std::forward(Args...));
		}
	};
}

#endif
