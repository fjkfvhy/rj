#include<iostream>
#include<cstring>
using namespace std;
struct airplane               //航班信息
{
	char num[50];             //航班号
	char start[50],end[50];   //航班起点站、航班终点站
	int start_time,end_time;  //航班起飞时间、航班到达时间
};
struct node                   //航班信息线性存储
{
	struct airplane plane;
	int n;
	struct node *next;
};
node *creat1(node *&head)     //建立链表存储航班信息
{
	node *pre=NULL,*p;
	head=new node();
	cout<<"请输入需要录入的航班数量"<<endl;
	cin>>head->n;
	for(int i=0;i<head->n;i++)
	{
		cout<<"请输入第"<<i+1<<"个航班的航班号、起点站、终点站、起飞时间、到达时间"<<endl;
		p=new node();
		cin>>p->plane.num>>p->plane.start>>p->plane.end>>p->plane.start_time>>p->plane.end_time;
		if(pre==NULL)
			head->next=p;
		else
			pre->next=p;
		pre=p;
	}
	return pre;
}
void creat2(node *&head,node *&pre)     //在链表中插入元素添加航班信息
{
	node *p;
	cout<<"请输入需要添加的航班数量"<<endl;
	int n;
	cin>>n;
	for(int i=head->n;i<head->n+n;i++)
	{
		cout<<"请输入第"<<i+1<<"个航班的航班号、起点站、终点站、起飞时间、到达时间"<<endl;
		p=new node();
		cin>>p->plane.num>>p->plane.start>>p->plane.end>>p->plane.start_time>>p->plane.end_time;
		pre->next=p;
		pre=p;
	}
	head->n+=n;
}
void sort(node *head,node *pre)     //按照航班号升序排序
{
	node *p=head,*q=NULL,*r=NULL,*f=pre;
	int i;
	for(i=0;i<head->n-1;i++)
	{
		p=head;
		q=p->next;
		while(r!=f)
		{
			r=q->next;
			if(strcmp(q->plane.num,r->plane.num)>0)
			{
				p->next=r;
				q->next=r->next;
				r->next=q;
			}
			p=p->next;
			q=p->next;
		}
		f=q;
	}
	cout<<"排序结果如下："<<endl;
	p=head->next;
	while(p!=NULL)
	{
		cout<<p->plane.num<<" "<<p->plane.start<<" "<<p->plane.end<<" "<<p->plane.start_time<<" "<<p->plane.end_time<<endl;
		p=p->next;
	}
}
void show(node *head)     //按照输入信息查询航班所有信息
{
	cout<<"请选择输入信息的类型：1.航班号 2.起点站 3.终点站 4.起飞时间 5.到达时间"<<endl;
	int n;
	cin>>n;
	int f;
	node *p;
	while(n<1||n>5)
	{
		cout<<"输入有误，请重新输入"<<endl;
		cin>>n;
	}
	if(n==1)   //按照航班号查询
	{
		f=0;
		p=head->next;
		cout<<"请输入需要查询的航班号"<<endl;
		char num[50];
		cin>>num;
		cout<<"查询结果如下"<<endl;
		while(p!=NULL)
		{
			if(strcmp(p->plane.num,num)==0)
			{
				f=1;
				cout<<p->plane.num<<" "<<p->plane.start<<" "<<p->plane.end<<" "<<p->plane.start_time<<" "<<p->plane.end_time<<endl;
				break;
			}
			p=p->next;
		}
		if(f==0)
			cout<<"未查询到该航班信息"<<endl;
	}
	if(n==2)
	{
		f=0;
		p=head->next;
		cout<<"请输入需要查询的起点站"<<endl;
		char c[50];
		cin>>c;
		cout<<"查询结果如下"<<endl;
		while(p!=NULL)
		{
			if(strcmp(p->plane.start,c)==0)
			{
				f=1;
				cout<<p->plane.num<<" "<<p->plane.start<<" "<<p->plane.end<<" "<<p->plane.start_time<<" "<<p->plane.end_time<<endl;
			}
			p=p->next;
		}
		if(f==0)
			cout<<"未查询到该航班信息"<<endl;
	}
	if(n==3)
	{
		f=0;
		p=head->next;
		cout<<"请输入需要查询的终点站"<<endl;
		char c[50];
		cin>>c;
		cout<<"查询结果如下"<<endl;
		while(p!=NULL)
		{
			if(strcmp(p->plane.end,c)==0)
			{
				f=1;
				cout<<p->plane.num<<" "<<p->plane.start<<" "<<p->plane.end<<" "<<p->plane.start_time<<" "<<p->plane.end_time<<endl;
			}
			p=p->next;
		}
		if(f==0)
			cout<<"未查询到该航班信息"<<endl;
	}
	if(n==4)
	{
		f=0;
		p=head->next;
		cout<<"请输入需要查询的起飞时间"<<endl;
		int time;
		cin>>time;
		cout<<"查询结果如下"<<endl;
		while(p!=NULL)
		{
			if(p->plane.start_time==time)
			{
				f=1;
				cout<<p->plane.num<<" "<<p->plane.start<<" "<<p->plane.end<<" "<<p->plane.start_time<<" "<<p->plane.end_time<<endl;
			}
			p=p->next;
		}
		if(f==0)
			cout<<"未查询到该航班信息"<<endl;
	}
	if(n==5)
	{
		f=0;
		p=head->next;
		cout<<"请输入需要查询的到达时间"<<endl;
		int time;
		cin>>time;
		cout<<"查询结果如下"<<endl;
		while(p!=NULL)
		{
			if(p->plane.end_time==time)
			{
				f=1;
				cout<<p->plane.num<<" "<<p->plane.start<<" "<<p->plane.end<<" "<<p->plane.start_time<<" "<<p->plane.end_time<<endl;
			}
			p=p->next;
		}
		if(f==0)
			cout<<"未查询到该航班信息"<<endl;
	}
}
int main()     //航班信息的查询与检索系统功能选择
{
	cout<<"欢迎使用航班信息的查询与检索系统"<<endl;
	cout<<"请选择功能：1.录入信息 2.添加信息 3.信息排序 4.查询信息 5.退出系统"<<endl;
	int n;
	cin>>n;
	node *head=NULL,*pre=NULL;
	while(1)
	{
		while(n<1||n>5)
		{
			cout<<"输入有误，请重新输入";
			cin>>n;
		}
		if(n==1)
		{
			pre=creat1(head);
			cout<<"信息录入成功"<<endl;
			cout<<"请选择下一步操作"<<endl;
			cin>>n;
		}
		if(n==2)
		{
			if(head==NULL)
			{
				cout<<"存储结构未建立，信息添加失败"<<endl;
				cout<<"请重新选择功能"<<endl;
				cin>>n;
			}
			else
			{
				creat2(head,pre);
				cout<<"信息添加成功"<<endl;
				cout<<"请选择下一步操作"<<endl;
				cin>>n;
			}
		}
		if(n==3)
		{
			if(head==NULL)
			{
				cout<<"存储结构未建立，排序失败"<<endl;
				cout<<"请重新选择功能"<<endl;
				cin>>n;
			}
			else if(head->next==NULL)
			{
				cout<<"未录入航班信息，排序失败"<<endl;
				cout<<"请重新选择功能"<<endl;
				cin>>n;
			}
			else
			{
				sort(head,pre);
				cout<<"请选择下一步操作"<<endl;
				cin>>n;
			}
		}
		if(n==4)
		{
			if(head==NULL)
			{
				cout<<"存储结构未建立，查询失败"<<endl;
				cout<<"请重新选择功能"<<endl;
				cin>>n;
			}
			else
			{
				while(1)
				{
					show(head);
					cout<<"是否继续查询：1.是 2.否"<<endl;
					int m;
					cin>>m;
					while(m!=1&&m!=2)
					{
						cout<<"输入有误，请重新输入"<<endl;
						cin>>m;
					}
					if(m==2)
						break;
				}
				cout<<"请选择下一步操作"<<endl;
				cin>>n;
			}
		}
		if(n==5)
		{
			cout<<"期待您的下次使用"<<endl;
			break;
		}
	}
	return 0;
}