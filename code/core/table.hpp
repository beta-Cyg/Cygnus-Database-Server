#ifndef TABLE_HPP
#define TABLE_HPP

#include<unordered_map>
#include<exception>
#include<utility>
#include<vector>
#include<string>
#include<list>
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

	bad_table_activity rne_err("The row is not exist!");

	class table{
	public:
		typedef unsigned long long size_type;
		typedef std::list<std::vector<std::any>>::iterator iterator;
		typedef std::list<std::vector<std::any>>::const_iterator const_iterator;
	private:
		std::unordered_map<std::string,iterator>basic_index;
		std::list<std::vector<std::any>>basic_table;
		size_type row_size;
	public:
		table():basic_index(),basic_table(),row_size(0){}

		~table(){row_size=0;}

		iterator begin()noexcept{
			return basic_table.begin();
		}

		const_iterator begin()const noexcept{
			return basic_table.begin();
		}

		iterator end()noexcept{
			return basic_table.end();
		}

		const_iterator end()const noexcept{
			return basic_table.end();
		}

		const size_type& size()const noexcept{
			return row_size;
		}

		bool empty()const noexcept{
			return row_size==0;
		}

		void push_front_row(std::string index){
			basic_table.push_front(std::vector<std::any>());
			basic_index[index]=basic_table.begin();
			basic_index.at(index)->push_back(index);
			row_size++;
		}

		void push_back_row(std::string index){
			basic_index[index]=basic_table.insert(basic_table.end(),std::vector<std::any>());
			basic_index.at(index)->push_back(index);
			row_size++;
		}

		void insert_row(std::string position,std::string index){
			basic_index[index]=basic_table.insert(basic_index[position],std::vector<std::any>());
			basic_index.at(index)->push_back(index);
			row_size++;
		}

		void insert_row(const_iterator position,std::string index){
			basic_index[index]=basic_table.insert(position,std::vector<std::any>());
			basic_index.at(index)->push_back(index);
			row_size++;
		}

		void erase_row(std::string position){
			if(basic_index.count(position))basic_table.erase(basic_index[position]),row_size--;
			else throw rne_err;
		}

		void erase_row(const_iterator position){
			basic_table.erase(position);
			row_size--;
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
			if(basic_index.count(row))return basic_index.at(row)->at(1);
			throw rne_err;
		}

		const std::any& front(std::string row)const{
			if(basic_index.count(row))return basic_index.at(row)->at(1);
			throw rne_err;
		}

		const std::any& back(std::string row){
			if(basic_index.count(row))return basic_index.at(row)->back();
			throw rne_err;
		}

		std::any& back(std::string row)const{
			if(basic_index.count(row))return basic_index.at(row)->back();
			throw rne_err;
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
			if(basic_index.count(row))basic_index.at(row)->insert(basic_index[row]->begin()+1,value);
			else throw rne_err;
		}

		void push_front(std::string row,const std::any& value){
			if(basic_index.count(row))basic_index.at(row)->insert(basic_index[row]->begin()+1,value);
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

		void erase(std::string row,std::vector<std::any>::const_iterator position){
			if(basic_index.count(row))basic_index.at(row)->erase(position);
			else throw rne_err;
		}
	};
}

#endif
