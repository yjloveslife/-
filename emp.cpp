// emp.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
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
		cout<<"��������:";
		cin>>name;
		cout<<"���빤��:";
		cin>>num;
		cout<<"�����Ա�:";
		cin>>sex;
		cout<<"���뼮��:";
		cin>>jg;
		cout<<"���벿��:";
		cin>>bumeng;
		cout<<"���빤��:";
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
	}//ͷ��㽨��.
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
		cout<<"\n��������.\n"<<endl;
		for(;p!=NULL;p=p->next)
		{
			p->e1.input();
		}
		cout<<"���!"<<endl;
		
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
		cout<<"\n�����ѱ���\n"<<endl;
	}
	void load()
	{
		ifstream fin("1111.txt");
		if(!fin)
			{cout<<"ERROR!"<<endl;
		return;}
		node *first,*newnode,*tail;
		first=tail=head;
		while(fin.peek()!=EOF)//δָ���ļ�β  ִ��
		{
			newnode =new node;
		    newnode->next=NULL;
			tail->next=newnode;
		    tail=newnode;
			fin.read((char *)&(tail->e1),sizeof(tail->e1));
		}
		end=tail;
		fin.close();

		cout<<"\n�Ѷ�ȡ�ļ�����\n"<<endl;

	}
	void del()
	{
		int a;
		cout<<"��1.������2.���Ų��Ҳ�ɾ��";
		node *p=head;
		string pp;
		cin>>a;
		switch(a)
		{
		case 1:
			
				cout<<"����:";
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
			cout<<"����:";
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
		cout<<"��Ӽ�������";
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
		cout<<"���"<<endl;
	}
	void gai()
	{
		
	{
		int a;
		cout<<"��1.������2.���Ų����޸�";
		node *p=head->next;
		string pp;
		int num1;
		cin>>a;
		switch(a)
		{
		case 1:
				cout<<"����:";
				cin>>pp;
				for(;p!=NULL;p=p->next)
				{
					if(p->e1.getname()==pp)
					{
						int f;
						string AA;
						cout<<"\n1.����\t2.�Ա�\n3.����\t4.����\n5.����\n�����޸���:";
						cin>>f;
						switch(f)
						{
						case 1:
							cout<<"new����";
							cin>>num1;
							p->e1.c_num(num1);
							break;
						case 2:
							cout<<"new�Ա�";
							cin>>pp;
							p->e1.c_sex(pp);
							break;
						case 3:
							cout<<"new����";
							cin>>pp;
							p->e1.c_jg(pp);
							break;
						case 4:
							cout<<"new����";
							cin>>pp;
							p->e1.c_bumeng(pp);
							break;
						case 5:
							cout<<"new����";
							cin>>pp;
							p->e1.c_money(pp);
							break;
						}
						break;
					}
				}
			break;
		case 2:
			cout<<"����:";
				cin>>num1;
				for(;p!=NULL;p=p->next)
				{
					if(p->e1.getnum()==num1)
					{
						int f;
						string AA;
						cout<<"\n1.����\t2.�Ա�\n3.����\t4.����\n5.����\n�����޸���:";
						cin>>f;
						switch(f)
						{
						case 1:
							cout<<"new����";
							cin>>pp;
							p->e1.c_name(pp);
							break;
						case 2:
							cout<<"new�Ա�";
							cin>>pp;
							p->e1.c_sex(pp);
							break;
						case 3:
							cout<<"new����";
							cin>>pp;
							p->e1.c_jg(pp);
							break;
						case 4:
							cout<<"new����";
							cin>>pp;
							p->e1.c_bumeng(pp);
							break;
						case 5:
							cout<<"new����";
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
int _tmain(int argc, _TCHAR* argv[])
{
	int flag=0,A;
	list a;
	while(1)
	{
		cout<<"0.������������\n1.����򸲸�\t2.���\n3.���\t4.�޸�\n5.ɾ��\t6.�˳�\n7.����\t8.��ȡ(�Ḳ��ԭʼ����!)"<<endl;
		cout<<"�����������:";
		cin>>flag;
		switch(flag)
		{
		case 0:
			cout<<"����Ա����Ϣ:";
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

