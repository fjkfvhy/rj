#include<iostream>
#include<cstring>
using namespace std;
struct airplane               //������Ϣ
{
	char num[50];             //�����
	char start[50],end[50];   //�������վ�������յ�վ
	int start_time,end_time;  //�������ʱ�䡢���ൽ��ʱ��
};
struct node                   //������Ϣ���Դ洢
{
	struct airplane plane;
	int n;
	struct node *next;
};
node *creat1(node *&head)     //��������洢������Ϣ
{
	node *pre=NULL,*p;
	head=new node();
	cout<<"��������Ҫ¼��ĺ�������"<<endl;
	cin>>head->n;
	for(int i=0;i<head->n;i++)
	{
		cout<<"�������"<<i+1<<"������ĺ���š����վ���յ�վ�����ʱ�䡢����ʱ��"<<endl;
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
void creat2(node *&head,node *&pre)     //�������в���Ԫ����Ӻ�����Ϣ
{
	node *p;
	cout<<"��������Ҫ��ӵĺ�������"<<endl;
	int n;
	cin>>n;
	for(int i=head->n;i<head->n+n;i++)
	{
		cout<<"�������"<<i+1<<"������ĺ���š����վ���յ�վ�����ʱ�䡢����ʱ��"<<endl;
		p=new node();
		cin>>p->plane.num>>p->plane.start>>p->plane.end>>p->plane.start_time>>p->plane.end_time;
		pre->next=p;
		pre=p;
	}
	head->n+=n;
}
void sort(node *head,node *pre)     //���պ������������
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
	cout<<"���������£�"<<endl;
	p=head->next;
	while(p!=NULL)
	{
		cout<<p->plane.num<<" "<<p->plane.start<<" "<<p->plane.end<<" "<<p->plane.start_time<<" "<<p->plane.end_time<<endl;
		p=p->next;
	}
}
void show(node *head)     //����������Ϣ��ѯ����������Ϣ
{
	cout<<"��ѡ��������Ϣ�����ͣ�1.����� 2.���վ 3.�յ�վ 4.���ʱ�� 5.����ʱ��"<<endl;
	int n;
	cin>>n;
	int f;
	node *p;
	while(n<1||n>5)
	{
		cout<<"������������������"<<endl;
		cin>>n;
	}
	if(n==1)   //���պ���Ų�ѯ
	{
		f=0;
		p=head->next;
		cout<<"��������Ҫ��ѯ�ĺ����"<<endl;
		char num[50];
		cin>>num;
		cout<<"��ѯ�������"<<endl;
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
			cout<<"δ��ѯ���ú�����Ϣ"<<endl;
	}
	if(n==2)
	{
		f=0;
		p=head->next;
		cout<<"��������Ҫ��ѯ�����վ"<<endl;
		char c[50];
		cin>>c;
		cout<<"��ѯ�������"<<endl;
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
			cout<<"δ��ѯ���ú�����Ϣ"<<endl;
	}
	if(n==3)
	{
		f=0;
		p=head->next;
		cout<<"��������Ҫ��ѯ���յ�վ"<<endl;
		char c[50];
		cin>>c;
		cout<<"��ѯ�������"<<endl;
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
			cout<<"δ��ѯ���ú�����Ϣ"<<endl;
	}
	if(n==4)
	{
		f=0;
		p=head->next;
		cout<<"��������Ҫ��ѯ�����ʱ��"<<endl;
		int time;
		cin>>time;
		cout<<"��ѯ�������"<<endl;
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
			cout<<"δ��ѯ���ú�����Ϣ"<<endl;
	}
	if(n==5)
	{
		f=0;
		p=head->next;
		cout<<"��������Ҫ��ѯ�ĵ���ʱ��"<<endl;
		int time;
		cin>>time;
		cout<<"��ѯ�������"<<endl;
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
			cout<<"δ��ѯ���ú�����Ϣ"<<endl;
	}
}
int main()     //������Ϣ�Ĳ�ѯ�����ϵͳ����ѡ��
{
	cout<<"��ӭʹ�ú�����Ϣ�Ĳ�ѯ�����ϵͳ"<<endl;
	cout<<"��ѡ���ܣ�1.¼����Ϣ 2.�����Ϣ 3.��Ϣ���� 4.��ѯ��Ϣ 5.�˳�ϵͳ"<<endl;
	int n;
	cin>>n;
	node *head=NULL,*pre=NULL;
	while(1)
	{
		while(n<1||n>5)
		{
			cout<<"������������������";
			cin>>n;
		}
		if(n==1)
		{
			pre=creat1(head);
			cout<<"��Ϣ¼��ɹ�"<<endl;
			cout<<"��ѡ����һ������"<<endl;
			cin>>n;
		}
		if(n==2)
		{
			if(head==NULL)
			{
				cout<<"�洢�ṹδ��������Ϣ���ʧ��"<<endl;
				cout<<"������ѡ����"<<endl;
				cin>>n;
			}
			else
			{
				creat2(head,pre);
				cout<<"��Ϣ��ӳɹ�"<<endl;
				cout<<"��ѡ����һ������"<<endl;
				cin>>n;
			}
		}
		if(n==3)
		{
			if(head==NULL)
			{
				cout<<"�洢�ṹδ����������ʧ��"<<endl;
				cout<<"������ѡ����"<<endl;
				cin>>n;
			}
			else if(head->next==NULL)
			{
				cout<<"δ¼�뺽����Ϣ������ʧ��"<<endl;
				cout<<"������ѡ����"<<endl;
				cin>>n;
			}
			else
			{
				sort(head,pre);
				cout<<"��ѡ����һ������"<<endl;
				cin>>n;
			}
		}
		if(n==4)
		{
			if(head==NULL)
			{
				cout<<"�洢�ṹδ��������ѯʧ��"<<endl;
				cout<<"������ѡ����"<<endl;
				cin>>n;
			}
			else
			{
				while(1)
				{
					show(head);
					cout<<"�Ƿ������ѯ��1.�� 2.��"<<endl;
					int m;
					cin>>m;
					while(m!=1&&m!=2)
					{
						cout<<"������������������"<<endl;
						cin>>m;
					}
					if(m==2)
						break;
				}
				cout<<"��ѡ����һ������"<<endl;
				cin>>n;
			}
		}
		if(n==5)
		{
			cout<<"�ڴ������´�ʹ��"<<endl;
			break;
		}
	}
	return 0;
}