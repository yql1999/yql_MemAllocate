//内存分区适配算法
//#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 1024	//初始大小1KB
enum status { FREE, BUSY };

typedef struct freespace{
	int num;         //分区号
	int size;        //分区大小
	int address;     //分区首地址
	status state;    //分区状态，FREE和BUSY
};

typedef struct node{
	freespace data;
	node *head;
	node *next;
}*Linklist;

Linklist first,last;
node *latest;//指针记录最新一次的地址分配 

void initial(){
	first = new node;
	last = new node;
	first->head = NULL;
	first->next = last;
	last->head = first;
	last->next = NULL;
	last->data.address = 0;
	last->data.size = MAXSIZE;
	last->data.num = 0;
	last->data.state = FREE;
	latest = first->next;
} 

void menu(){
	cout << "--------------------内存分配系统--------------------" << endl;
	cout << "               1.首次适配算法                       " << endl;
	cout << "               2.最佳适配算法                       " << endl;
	cout << "               3.邻近适配算法                       " << endl;
	cout << "               4.查看主存分配情况                   " << endl;
	cout << "               5.回收主存                           " << endl;
	cout << "               6.exit                               " << endl;
	cout << endl << "Please input the number you choose:";
}

void display(){
	cout << "--------------------主存分配情况--------------------" << endl;
	node *p = first->next;
	while (p){
		cout << "分区号：";
		if (p->data.num == 0){
			cout << "空闲区  start address：" << p->data.address << "	end address：" << 
				p->data.address+p->data.size <<"	Partition size：" << p->data.size << "KB" << "	state:FREE" << endl;
		}
		else{
			cout << p->data.num << "	start address：" << p->data.address << "	end address：" << 
				p->data.address + p->data.size << "	Partition size：" << p->data.size << "KB" << "	state:";
			if (p->data.state == FREE)
				cout << "FREE" << endl;
			else if (p->data.state == BUSY)
				cout << "BUSY" << endl;
		}
		p = p->next;
	}
	cout << endl;
}

//首次适配 
int firstAlloc(){
	int num, size;
	cout << "Please input a process number and allocated main memory size（KB）：" << endl;;
	cin >> num >> size;
	Linklist list = new node;
	list->data.num = num;
	list->data.size = size;
	list->data.state = BUSY;
	node *p = first->next;
	while (p){
		//若空闲区大小>=申请空间大小，则分配更新 
		if (p->data.state == FREE&&p->data.size == size){
			p->data.state = BUSY;
			p->data.num = num;
			display();
			return 1;
		}
		if (p->data.state == FREE&&p->data.size > size){
			list->head = p->head;
			list->next = p;
			list->data.address = p->data.address;
			p->head->next = list;
			p->head = list;
			p->data.address = list->data.address + list->data.size;
			p->data.size -= size;
			display();
			return 1;
		}
		latest = p;
		p = p->next;
	}
	display();
	return 0;
}

//最佳适配 
int bestAlloc(){
	int num, size;
	cout << "Please input a process number and allocated main memory size（KB）：" << endl;;
	cin >> num >> size;
	int min_space=MAXSIZE;	//找出最佳位置
	Linklist list = new node;
	list->data.num = num;
	list->data.size = size;
	list->data.state = BUSY;
	node *p = first->next;
	node *q = NULL;
	while (p){
		if ((p->data.size > size || p->data.size == size)&&p->data.state==FREE){
			if (p->data.size - size < min_space){
				q = p;
				min_space = p->data.size - size;
			}
		}
		latest = p;
		p = p->next;
	}
	if (q == NULL)
		return 0;
	else{
		if (min_space == 0){
			q->data.num = num;
			q->data.state = BUSY;
			display();
			return 1;
		}
		else{
			list->head = q -> head;
			list->next = q;
			list->data.address = q->data.address;
			q->head->next = list;
			q->head = list;
			q->data.address += size;
			q->data.size -= size;
			display();
			return 1;
		}
	}
}

//邻近适配
int nearAlloc(){
	int num, size;
	cout << "Please input a process number and allocated main memory size（KB）：" << endl;;
	cin >> num >> size;
	Linklist list = new node;
	list->data.num = num;
	list->data.size = size;
	list->data.state = BUSY;
	node *p = latest->next;	//不同 
	while (p){
		//若空闲区大小>=申请空间大小，则分配更新 
		if (p->data.state == FREE&&p->data.size == size){
			p->data.state = BUSY;
			p->data.num = num;
			display();
			return 1;
		}
		if (p->data.state == FREE&&p->data.size > size){
			list->head = p->head;
			list->next = p;
			list->data.address = p->data.address;
			p->head->next = list;
			p->head = list;
			p->data.address = list->data.address + list->data.size;
			p->data.size -= size;
			display();
			return 1;
		}
		latest = p;
		p = p->next;
	}
	display();
	return 0;
}

//回收碎片
int recycle()
{
	int num;
	cout << "Please input the process number you want to reclaim memory：" << endl;
	cin >> num;
	node *p = first;
	while (p){
		if (p->data.num == num){
			p->data.state = FREE;
			p->data.num = 0;
			//根据与前后空闲区update内存分布情况 
			if (p->head->data.state == FREE){
				p->head->data.size += p->data.size;
				p->head->next = p->next;
				p->next->head = p->head;
				latest = p->head;	//要对latest指针进行更新
			}
			if (p->next->data.state == FREE){
				p->data.size += p->next->data.size;
				p->next->next->head = p;
				p->next = p->next->next;
			}
			break;
		}
		p = p->next;
	}
	display();
	return 1;
}


int main(){
	initial();
	int c;
	while (1){
		menu();
		cin >> c;
		switch (c){
		case 1:
			firstAlloc();
			break;
		case 2:
			bestAlloc();
			break;
		case 3:
			nearAlloc();
			break;
		case 4:
			display();
			break;
		case 5:
			recycle();
			break;
		case 6:
			exit(1);
			break;
		default :
			cout << "Error:input is wrong！" << endl;
			break;
		}
	}
	return 0;
}
