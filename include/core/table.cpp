#include"table.h"

#undef CDS_DEBUG

namespace cyg{
    bad_table_activity::bad_table_activity()=default;

    bad_table_activity::bad_table_activity(std::string&& why):reason(why){}

    const char* bad_table_activity::what()const noexcept{
        return reason.c_str();
    }

    bad_data_cast::bad_data_cast()=default;

    const char* bad_data_cast::what()const noexcept{
        return "the string cannot convert to the type";
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

    table::const_iterator table::cbegin()const noexcept{
	    return basic_table.cbegin();
    }

    table::const_iterator table::cend()const noexcept{
	    return basic_table.cend();
    }

    table::reverse_iterator table::rbegin()noexcept{
	    return basic_table.rbegin();
    }

    table::const_reverse_iterator table::rbegin()const noexcept{
	    return basic_table.rbegin();
    }

    table::const_reverse_iterator table::crbegin()const noexcept{
	    return basic_table.crbegin();
    }

    table::reverse_iterator table::rend()noexcept{
	    return basic_table.rend();
    }

    table::const_reverse_iterator table::rend()const noexcept{
	    return basic_table.rend();
    }

    table::const_reverse_iterator table::crend()const noexcept{
	    return basic_table.crend();
    }

    const table::size_type& table::size()const noexcept{
        return row_size;
    }

    bool table::empty()const noexcept{
        return row_size==0;
    }

    void table::push_front_row(const std::string& index){
        basic_table.push_front(std::vector<std::string>());
        basic_index[index]=basic_table.begin();
        basic_index.at(index)->push_back(index);
        row_size++;
    }

    void table::push_back_row(const std::string& index){
        basic_index[index]=basic_table.insert(basic_table.end(),std::vector<std::string>());
        basic_index.at(index)->push_back(index);
        row_size++;
    }

    void table::insert_row(const std::string& position,const std::string& index){
        basic_index[index]=basic_table.insert(basic_index[position],std::vector<std::string>());
        basic_index.at(index)->push_back(index);
        row_size++;
    }

    void table::insert_row(table::const_iterator position,const std::string& index){
        basic_index[index]=basic_table.insert(position,std::vector<std::string>());
        basic_index.at(index)->push_back(index);
        row_size++;
    }

    void table::erase_row(const std::string& position){
        if(basic_index.count(position)){
            basic_table.erase(basic_index[position]);
            basic_index.erase(position);
            row_size--;
#ifdef CDS_DEBUG
            std::cerr<<"debug:"<<std::endl;
            for(const auto& i:basic_table){
                for(const auto& j:i)
                    std::cerr<<j<<' ';
                std::cerr<<std::endl;
            }
#endif
        }
        else throw rne_err;
    }

    std::vector<std::string>& table::operator[](const std::string& index){
        if(basic_index.count(index))return *basic_index[index];
        else throw rne_err;
    }

    std::vector<std::string>& table::at(const std::string& index){
        if(basic_index.count(index))return *basic_index[index];
        else throw rne_err;
    }

    std::string& table::front(const std::string& row){
        if(basic_index.count(row))return basic_index.at(row)->at(1);
        throw rne_err;
    }

    const std::string& table::front(const std::string& row)const{
        if(basic_index.count(row))return basic_index.at(row)->at(1);
        throw rne_err;
    }

    const std::string& table::back(const std::string& row){
        if(basic_index.count(row))return basic_index.at(row)->back();
        throw rne_err;
    }

    std::string& table::back(const std::string& row)const{
        if(basic_index.count(row))return basic_index.at(row)->back();
        throw rne_err;
    }

    void table::push_back(const std::string& row,const std::string& value){
        if(basic_index.count(row))basic_index.at(row)->push_back(value);
        else throw rne_err;
    }

    void table::push_back(const std::string& row,std::string&& value){
        if(basic_index.count(row))basic_index.at(row)->push_back(value);
        else throw rne_err;
    }

    void table::push_front(const std::string& row,std::string&& value){
        if(basic_index.count(row))basic_index.at(row)->insert(basic_index[row]->begin()+1,value);
        else throw rne_err;
    }

    void table::push_front(const std::string& row,const std::string& value){
        if(basic_index.count(row))basic_index.at(row)->insert(basic_index[row]->begin()+1,value);
        else throw rne_err;
    }

    void table::insert(const std::string& row,std::vector<std::string>::const_iterator position,const std::string& value){
        if(basic_index.count(row))basic_index.at(row)->insert(position,value);
        else throw rne_err;
    }

    void table::insert(const std::string& row,std::vector<std::string>::const_iterator position,std::string&& value){
        if(basic_index.count(row))basic_index.at(row)->insert(position,value);
        else throw rne_err;
    }

    void table::erase(const std::string& row,std::vector<std::string>::const_iterator position){
        if(basic_index.count(row))basic_index.at(row)->erase(position);
        else throw rne_err;
    }

    Integer data_cast(const std::string& value){
        Integer result=0;
        bool flag=false;
        if(value[0]=='-')flag=true;
        for(Integer i=flag;i<value.size();i++)
            if(not std::isdigit(value[i]))
                throw bad_data_cast();
        auto temp=value;
        std::reverse(temp.begin(),temp.end());
        for(Integer i=flag;i<temp.size();i++){
            result*=10;
            result+=value[i]-'0';
        }
        return flag?-result:result;
    }
}
