#include<iostream>
#include<string>
using namespace std;

namespace cyg{
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
			node* buf=new node(n,c,m,e);
			buf->la=tail->la;
			buf->ne=tail;
			tail->la->ne=buf;
			tail->la=buf;
		}
		
		node find(int n){
			node* buf=head->ne;
			while(buf!=nullptr){
				if(buf->num==n)break;
				buf=buf->ne;
			}
			return buf==nullptr?node():*buf;
		}
		
		void erase(int n){
			node* buf=N;
			N.buf
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
				<<"exit: exit the system\n\n";
		else if(type=="add"){
			cyg::list::node N;
			cin>>N.num>>N.ch>>N.ma>>N.en;
			stus.push_back(N.num,N.ch,N.ma,N.en);
			cout<<endl;
		}
		else if(type=="find"){
			int num;
			cin>>num;
			cyg::list::node N=stus.find(num);
			cout<<"Student "<<N.num<<
			":\nChinese result: "<<
			N.ch<<"\nMath result: "<<
			N.ma<<"\nEnglish result: "<<
			N.en<<"\n\n";
		}
		else if(type=="exit")
			break;
		else cout<<"syntax error!\n\n";
	}

	return 0;
}
