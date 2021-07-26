#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

namespace cyg{
	class list_err:exception{
	private:
		string why;
	public:
		list_err(string str):why(str){}

		const char* what(){
			return why.c_str();
		}
	};

	class list{
	public:
		struct node{
			int num,ch,ma,en;
			node *ne,*la;
			node(int n=0,int c=0,int m=0,int e=0,node* nex=nullptr,node* las=nullptr):
			num(n),ch(c),ma(m),en(e),ne(nex),la(las){}
		};
	private:
		node *head,*tail;
		int size;
	public:
		list():head(new node()),tail(new node()),size(0){
			head->ne=tail;
			tail->la=head;
		}

		~list(){
			node* buf=tail;
			while(buf!=nullptr){
				node* temp=buf;
				buf=buf->la;
				delete temp;
			}
		}

		void push_back(int n,int c,int m,int e){
			node* test;
			try{test=find(n);}
			catch(...){
				node* buf=new node(n,c,m,e);
				buf->la=tail->la;
				buf->ne=tail;
				tail->la->ne=buf;
				tail->la=buf;
				return;
			}
			throw list_err("The student already has data.");
		}

		void push_back_nowait(int n,int c,int m,int e){
			node* buf=new node(n,c,m,e);
			buf->la=tail->la;
			buf->ne=tail;
			tail->la->ne=buf;
			tail->la=buf;
		}

		node* find(int n){
			node* buf=head->ne;
			while(buf!=nullptr){
				if(buf->num==n)break;
				buf=buf->ne;
			}
			if(buf==nullptr)
				throw list_err("Can not find the student.");
			return buf;
		}

		void erase(int n){
			node* buf=head->ne;
			bool flag=false;
			while(buf!=nullptr){
				if(buf->num==n){
					buf->ne->la=buf->la;
					buf->la->ne=buf->ne;
					delete buf;
					flag=true;
				}
				buf=buf->ne;
			}
			if(not flag)throw list_err("Can not find the student!");
		}

		node* begin(){
			return head->ne;
		}

		node* end(){
			return tail;
		}
	};
}

cyg::list stus;
string type;

int main(){
	cout<<"Type help to get tips\n";
	while(true){
		cout<<"main>> ";
		cin>>type;
		if(type=="help")
			cout<<"add: add students' data\n"
				<<"find: get the students' data\n"
				<<"delete: delete the students' data\n"
				<<"all: show all students' data\n"
				<<"clear: clear the screen\n"
				<<"exit: exit the system\n\n";
		else if(type=="add"){
			cyg::list::node N;
			cout<<"Student's number: ";
			cin>>N.num;
			cout<<"Chinese result: ";
			cin>>N.ch;
			cout<<"Math result: ";
			cin>>N.ma;
			cout<<"English result: ";
			cin>>N.en;
			try{
				stus.push_back(N.num,N.ch,N.ma,N.en);
			}
			catch(cyg::list_err le){
				cout<<le.what()<<"Do you still want to add it?(Y/n)";
				string t;
				cin>>t;
				if(t=="Y")stus.push_back_nowait(N.num,N.ch,N.ma,N.en);
				cout<<endl;
			}
			cout<<endl;
		}
		else if(type=="find"){
			int num;
			cin>>num;
			cyg::list::node* N;
			try{
				N=stus.find(num);
			}
			catch(cyg::list_err le){
				cout<<le.what()<<endl<<endl;
				continue;
			}
			cout<<"Student "<<N->num<<
			":\nChinese result: "<<
			N->ch<<"\nMath result: "<<
			N->ma<<"\nEnglish result: "<<
			N->en<<"\n\n";
		}
		else if(type=="delete"){
			int num;
			cin>>num;
			try{
				stus.erase(num);
			}
			catch(cyg::list_err le){
				cout<<le.what()<<endl;
			}
			cout<<endl;
		}
		else if(type=="all"){
			for(cyg::list::node* i=stus.begin();i!=stus.end();i=i->ne)
			cout<<"Student "<<i->num<<
			":\nChinese result: "<<
			i->ch<<"\nMath result: "<<
			i->ma<<"\nEnglish result: "<<
			i->en<<"\n\n";
		}
		else if(type=="clear")
			system("clear");
		else if(type=="exit")
			break;
		else cout<<"syntax error!\n\n";
	}

	return 0;
}
