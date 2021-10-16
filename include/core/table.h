#ifndef TABLE_H
#define TABLE_H

#include<unordered_map>
#include<exception>
#include<utility>
#include<vector>
#include<string>
#include<list>
#include<any>

namespace cyg{
    class bad_table_activity:public std::exception{
    private:
        std::string reason;
    public:
        bad_table_activity();

        bad_table_activity(std::string&& why);

        const char* what();
    };

    extern bad_table_activity rne_err;

    class table{
    public:
        typedef unsigned long long size_type;
        typedef std::list<std::vector<std::any>>::iterator iterator;
        typedef std::list<std::vector<std::any>>::const_iterator const_iterator;
	typedef std::list<std::vector<std::any>>::reverse_iterator reverse_iterator;
	typedef std::list<std::vector<std::any>>::const_reverse_iterator const_reverse_iterator;
    private:
        std::unordered_map<std::string,iterator>basic_index;
        std::list<std::vector<std::any>>basic_table;
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

        void push_front_row(std::string index);

        void push_back_row(std::string index);

        void insert_row(const std::string& position,std::string index);

        void insert_row(const_iterator position,std::string index);

        void erase_row(const std::string& position);

        void erase_row(const_iterator position);

        std::vector<std::any>& operator[](const std::string& index);

        std::vector<std::any>& at(const std::string& index);

        std::any& front(const std::string& row);

        const std::any& front(const std::string& row)const;

        const std::any& back(const std::string& row);

        std::any& back(const std::string& row)const;

        void push_back(const std::string& row,const std::any& value);

        void push_back(const std::string& row,std::any&& value);

        void push_front(const std::string& row,std::any&& value);

        void push_front(const std::string& row,const std::any& value);

        void insert(const std::string& row,std::vector<std::any>::const_iterator position,const std::any& value);

        void insert(const std::string& row,std::vector<std::any>::const_iterator position,std::any&& value);

        void erase(const std::string& row,std::vector<std::any>::const_iterator position);
    };
}

#endif
