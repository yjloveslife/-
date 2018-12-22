#include"iostream"
#include"fstream"
#include"string"
using namespace std;

class em
{
	int num;
	string name,sex,jg,bumeng,money;
public:
	em(){}
	em(int num,string name,string sex,string jg,string bumeng,string money):num(num),name(name),sex(sex),jg(jg),bumeng(bumeng),money(money){}
	void c_num(int a)
	{num=a;}
	void c_name(string a)
	{name=a;}
	void c_sex(string a)
	{sex=a;}
	void c_jg(string a)
	{jg=a;}
	void c_bumeng(string a)
	{bumeng=a;}
	void c_money(string a)
	{money=a;}
	int getnum()
	{
		return num;
	}
	void input()
	{
		cout<<"输入姓名:";
		cin>>name;
		cout<<"输入工号:";
		cin>>num;
		cout<<"输入性别:";
		cin>>sex;
		cout<<"输入籍贯:";
		cin>>jg;
		cout<<"输入部门:";
		cin>>bumeng;
		cout<<"输入工资:";
		cin>>money;
	}
	string getname()
	{
		return name;
	}
	void show()
	{
		cout<<"num:"<<num<<"\tname:"<<name<<"\tsex:"<<sex<<"\tjg:"<<jg<<"\tbumeng:"<<bumeng<<"\tmoney:"<<money<<endl;
	}
};
class node
{
public:
	em e1;
	em e2;
	node *next;
};
class list
{
	node *head,*end;
public:
	list(){
		head=end=new node;
		head->next=NULL;
	}//头结点建立.
	void creat(int a)
	{
		
		node *first,*newnode,*tail;
		first=head;
		tail=end;
		for(int i=0;i<a;i++)
		{
			newnode =new node;
		    newnode->next=NULL;
			tail->next=newnode;
		    tail=newnode;
		}
		end=tail;
	}
	void input()
	{
		node *p;
		p=(head->next);
		cout<<"\n输入数据.\n"<<endl;
		for(;p!=NULL;p=p->next)
		{
			p->e1.input();
		}
		cout<<"完成!"<<endl;
		
	}
	void output()
	{
			for(node *p=head->next;p!=NULL;p=p->next)
			{
				p->e1.show();
			}
		
	}
	void save()
	{
		ofstream fout("1111.txt");
		if(!fout)
			{cout<<"ERROR!"<<endl;
		return;}
		node *p=head->next;
		for(;p!=NULL;p=p->next)
			fout.write((char *)&(p->e1),sizeof(p->e1));
		fout.close();
		cout<<"\n数据已保存\n"<<endl;
	}
	void load()
	{
		ifstream fin("1111.txt");
		if(!fin)
			{cout<<"ERROR!"<<endl;
		return;}
		node *first,*newnode,*tail;
		first=tail=head;
		while(fin.peek()!=EOF)//未指到文件尾  执行
		{
			newnode =new node;
		    newnode->next=NULL;
			tail->next=newnode;
		    tail=newnode;
			fin.read((char *)&(tail->e1),sizeof(tail->e1));
		}
		end=tail;
		fin.close();

		cout<<"\n已读取文件数据\n"<<endl;

	}
	void del()
	{
		int a;
		cout<<"按1.姓名或2.工号查找并删除";
		node *p=head;
		string pp;
		cin>>a;
		switch(a)
		{
		case 1:
			
				cout<<"姓名:";
				cin>>pp;
				for(;p->next!=NULL;p=p->next)
				{
					if(p->next->e1.getname()==pp)
					{
						p->next=p->next->next;
						break;
					}
				}
			break;
		case 2:
			cout<<"工号:";
			int num1;
				cin>>num1;
				for(;p->next!=NULL;p=p->next)
				{
					if(p->next->e1.getnum()==num1)
					{
						p->next=p->next->next;
						break;
					}
				}
			break;
		}
	}
	void add()
	{
		int a;
		cout<<"添加几个数据";
		cin>>a;
		node *p=head->next,*newnode,*tail=end;
		for(int i=0;i<a;i++)
		{
			newnode=new node;
			newnode->next=NULL;
			tail->next=newnode;
			tail=newnode;
			tail->e1.input();
		}
		end=tail;
		cout<<"完成"<<endl;
	}
	void gai()
	{
		
	{
		int a;
		cout<<"按1.姓名或2.工号查找修改";
		node *p=head->next;
		string pp;
		int num1;
		cin>>a;
		switch(a)
		{
		case 1:
				cout<<"姓名:";
				cin>>pp;
				for(;p!=NULL;p=p->next)
				{
					if(p->e1.getname()==pp)
					{
						int f;
						string AA;
						cout<<"\n1.工号\t2.性别\n3.籍贯\t4.部门\n5.工资\n输入修改项:";
						cin>>f;
						switch(f)
						{
						case 1:
							cout<<"new工号";
							cin>>num1;
							p->e1.c_num(num1);
							break;
						case 2:
							cout<<"new性别";
							cin>>pp;
							p->e1.c_sex(pp);
							break;
						case 3:
							cout<<"new籍贯";
							cin>>pp;
							p->e1.c_jg(pp);
							break;
						case 4:
							cout<<"new部门";
							cin>>pp;
							p->e1.c_bumeng(pp);
							break;
						case 5:
							cout<<"new工资";
							cin>>pp;
							p->e1.c_money(pp);
							break;
						}
						break;
					}
				}
			break;
		case 2:
			cout<<"工号:";
				cin>>num1;
				for(;p!=NULL;p=p->next)
				{
					if(p->e1.getnum()==num1)
					{
						int f;
						string AA;
						cout<<"\n1.姓名\t2.性别\n3.籍贯\t4.部门\n5.工资\n输入修改项:";
						cin>>f;
						switch(f)
						{
						case 1:
							cout<<"new姓名";
							cin>>pp;
							p->e1.c_name(pp);
							break;
						case 2:
							cout<<"new性别";
							cin>>pp;
							p->e1.c_sex(pp);
							break;
						case 3:
							cout<<"new籍贯";
							cin>>pp;
							p->e1.c_jg(pp);
							break;
						case 4:
							cout<<"new部门";
							cin>>pp;
							p->e1.c_bumeng(pp);
							break;
						case 5:
							cout<<"new工资";
							cin>>pp;
							p->e1.c_money(pp);
							break;
						}
						break;
					}
				}
			break;
		}
	}
	}
};
int main()
{
	int flag=0,A;
	list a;
	while(1)
	{
		cout<<"0.创建链表并输入\n1.输入或覆盖\t2.输出\n3.添加\t4.修改\n5.删除\t6.退出\n7.保存\t8.读取(会覆盖原始数据!)"<<endl;
		cout<<"输入操作功能:";
		cin>>flag;
		switch(flag)
		{
		case 0:
			cout<<"几个员工信息:";
			cin>>A;
			a.creat(A);
			a.input();
			break;
		case 1:
			a.input();
			break;
		case 2:
			a.output();
			break;
		case 3:
			a.add();
			break;
		case 4:
			a.gai();
			break;
		case 5:
			a.del();
			break;
		case 6:
			exit(0);
		case 7:
			a.save();
			break;
		case 8:
			a.load();
			break;


		}
	}
	return 0;
}

