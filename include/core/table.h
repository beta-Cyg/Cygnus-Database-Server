#ifndef TABLE_H
#define TABLE_H

#include<unordered_map>
#include<algorithm>
#include<exception>
#include<utility>
#include<vector>
#include<string>
#include<cctype>
#include<list>

#include"../version.h"

#ifdef CDS_DEBUG
#include<iostream>
#endif

namespace cyg{
    typedef long long Integer;

    class bad_table_activity:public std::exception{
    private:
        std::string reason;
    public:
        bad_table_activity();

        explicit bad_table_activity(std::string&& why);

        const char* what()const noexcept;
    };

    class bad_data_cast:public std::exception{
    public:
        bad_data_cast();

        const char* what()const noexcept;
    };

    extern bad_table_activity rne_err;

    class table{
    public:
        typedef unsigned long long size_type;
        typedef std::list<std::vector<std::string>>::iterator iterator;
        typedef std::list<std::vector<std::string>>::const_iterator const_iterator;
	    typedef std::list<std::vector<std::string>>::reverse_iterator reverse_iterator;
	    typedef std::list<std::vector<std::string>>::const_reverse_iterator const_reverse_iterator;
    private:
        std::unordered_map<std::string,iterator>basic_index;
        std::list<std::vector<std::string>>basic_table;
        size_type row_size;
    public:
        table();

        ~table();

        iterator begin()noexcept;

        const_iterator begin()const noexcept;

        iterator end()noexcept;

        const_iterator end()const noexcept;

	    const_iterator cbegin()const noexcept;

    	const_iterator cend()const noexcept;

	    reverse_iterator rbegin()noexcept;

	    const_reverse_iterator rbegin()const noexcept;

	    reverse_iterator rend()noexcept;

    	const_reverse_iterator rend()const noexcept;

    	const_reverse_iterator crbegin()const noexcept;

    	const_reverse_iterator crend()const noexcept;

        const size_type& size()const noexcept;

        bool empty()const noexcept;

        void push_front_row(const std::string& index);

        void push_back_row(const std::string& index);

        void insert_row(const std::string& position,const std::string& index);

        void insert_row(const_iterator position,const std::string& index);

        void erase_row(const std::string& position);

        std::vector<std::string>& operator[](const std::string& index);

        std::vector<std::string>& at(const std::string& index);

        std::string& front(const std::string& row);

        const std::string& front(const std::string& row)const;

        const std::string& back(const std::string& row);

        std::string& back(const std::string& row)const;

        void push_back(const std::string& row,const std::string& value);

        void push_back(const std::string& row,std::string&& value);

        void push_front(const std::string& row,std::string&& value);

        void push_front(const std::string& row,const std::string& value);

        void insert(const std::string& row,std::vector<std::string>::const_iterator position,const std::string& value);

        void insert(const std::string& row,std::vector<std::string>::const_iterator position,std::string&& value);

        void erase(const std::string& row,std::vector<std::string>::const_iterator position);
    };

    Integer data_cast(const std::string& value);
}

#endif
