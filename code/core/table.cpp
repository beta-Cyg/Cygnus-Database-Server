#ifndef TABLE_HPP
#define TABLE_HPP

#include"table.h"

namespace cyg{
    bad_table_activity::bad_table_activity()=default;

	bad_table_activity::bad_table_activity(std::string&& why):reason(why){}

	const char* bad_table_activity::what(){
		return reason.c_str();
	}

	bad_table_activity rne_err("The row is not exist!");

    table::table():basic_index(),basic_table(),row_size(0){}

    table::~table(){row_size=0;}

    table::iterator table::begin()noexcept{
        return basic_table.begin();
    }

    table::const_iterator table::begin()const noexcept{
        return basic_table.begin();
    }

    table::iterator table::end()noexcept{
        return basic_table.end();
    }

    table::const_iterator table::end()const noexcept{
        return basic_table.end();
    }

    const table::size_type& table::size()const noexcept{
        return row_size;
    }

    bool table::empty()const noexcept{
        return row_size==0;
    }

    void table::push_front_row(std::string index){
        basic_table.push_front(std::vector<std::any>());
        basic_index[index]=basic_table.begin();
        basic_index.at(index)->push_back(index);
        row_size++;
    }

    void table::push_back_row(std::string index){
        basic_index[index]=basic_table.insert(basic_table.end(),std::vector<std::any>());
        basic_index.at(index)->push_back(index);
        row_size++;
    }

    void table::insert_row(const std::string& position,std::string index){
        basic_index[index]=basic_table.insert(basic_index[position],std::vector<std::any>());
        basic_index.at(index)->push_back(index);
        row_size++;
    }

    void table::insert_row(table::const_iterator position,std::string index){
        basic_index[index]=basic_table.insert(position,std::vector<std::any>());
        basic_index.at(index)->push_back(index);
        row_size++;
    }

    void table::erase_row(const std::string& position){
        if(basic_index.count(position))basic_table.erase(basic_index[position]),row_size--;
        else throw rne_err;
    }

    void table::erase_row(table::const_iterator position){
        basic_table.erase(position);
        row_size--;
    }

    std::vector<std::any>& table::operator[](const std::string& index){
        if(basic_index.count(index))return *basic_index[index];
        else throw rne_err;
    }

    std::vector<std::any>& table::at(const std::string& index){
        if(basic_index.count(index))return *basic_index[index];
        else throw rne_err;
    }

    std::any& table::front(const std::string& row){
        if(basic_index.count(row))return basic_index.at(row)->at(1);
        throw rne_err;
    }

    const std::any& table::front(const std::string& row)const{
        if(basic_index.count(row))return basic_index.at(row)->at(1);
        throw rne_err;
    }

    const std::any& table::back(const std::string& row){
        if(basic_index.count(row))return basic_index.at(row)->back();
        throw rne_err;
    }

    std::any& table::back(const std::string& row)const{
        if(basic_index.count(row))return basic_index.at(row)->back();
        throw rne_err;
    }

    void table::push_back(const std::string& row,const std::any& value){
        if(basic_index.count(row))basic_index.at(row)->push_back(value);
        else throw rne_err;
    }

    void table::push_back(const std::string& row,std::any&& value){
        if(basic_index.count(row))basic_index.at(row)->push_back(value);
        else throw rne_err;
    }

    void table::push_front(const std::string& row,std::any&& value){
        if(basic_index.count(row))basic_index.at(row)->insert(basic_index[row]->begin()+1,value);
        else throw rne_err;
    }

    void table::push_front(const std::string& row,const std::any& value){
        if(basic_index.count(row))basic_index.at(row)->insert(basic_index[row]->begin()+1,value);
        else throw rne_err;
    }

    void table::insert(const std::string& row,std::vector<std::any>::const_iterator position,const std::any& value){
        if(basic_index.count(row))basic_index.at(row)->insert(position,value);
        else throw rne_err;
    }

    void table::insert(const std::string& row,std::vector<std::any>::const_iterator position,std::any&& value){
        if(basic_index.count(row))basic_index.at(row)->insert(position,value);
        else throw rne_err;
    }

    void table::erase(const std::string& row,std::vector<std::any>::const_iterator position){
        if(basic_index.count(row))basic_index.at(row)->erase(position);
        else throw rne_err;
    }
}

#endif
