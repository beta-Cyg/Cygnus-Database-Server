#ifndef BASIC_TABLE_H
#define BASIC_TABLE_H

#include<unordered_map>
#include<initializer_list>
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
		std::unordered_map<std::string,vector<ValueT>>data;
	public:
		table():data(){}

		void insert_row(std::string index){
			data.insert(std::make_pair(index,std::vector<value_type>()));
		}

		std::vector<value_type>& operator[](std::string index){
			return data[index];
		}

		void push_back(std::string row,const_reference value){
			data[row].push_back(value);
		}

		template<typename...ArgsT>
		void emplace_back(std::string row,ArgsT...Args){
			data[row].emplace_back(Args...);
		}
	};
}

#endif
