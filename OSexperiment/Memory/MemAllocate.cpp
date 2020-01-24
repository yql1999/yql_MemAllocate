// MemAllocate.cpp: implementation of the CMemAllocate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Memory.h"
#include "MemAllocate.h"
#include<iostream>
using namespace std;

#include "..\OSgraphics\Rectangle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMemAllocate::CMemAllocate()
{	
	//设置初始状态
	m_MemList = 0;
	InitMemoryBlock();
	InitJobs();
}

CMemAllocate::~CMemAllocate()
{
	for (MemoryBlock * p = m_MemList; p!=0; p = m_MemList)
	{
		m_MemList = p->nextPointer;
		delete p;
	}
}
void CMemAllocate::DrawMemory(CDC*pDC)//通过给内存块填充颜色显示内存的分配情况
{
	CPoint ptMemLeftTop = CPoint(100,50);
	CRectangle myRect(RGB(255,111,0),4,0,RGB(100,100,100),0,1,ptMemLeftTop,ptMemLeftTop);
	for (MemoryBlock * p = m_MemList; p!=0; p = p->nextPointer)
	{
		CPoint tmpLeftTop;
		tmpLeftTop.x = ptMemLeftTop.x ;
		tmpLeftTop.y = ptMemLeftTop.y + p ->StartAddr;
		CPoint tmpRightBottom;
		tmpRightBottom.x = ptMemLeftTop.x + 200;
		tmpRightBottom.y = tmpLeftTop.y + p->BlockLength;
		myRect.SetRectPeak(tmpLeftTop,tmpRightBottom);
		if (p->JobIndex  == 0 ) //如果内存块空， 填充浅色
			myRect.SetColorFill(RGB(200,200,200));
		else if(p->JobIndex==9)
			myRect.SetColorFill(RGB(256,256,256));
		else
			myRect.SetColorFill(RGB(100,100,100));
		
		myRect.Draw(pDC);
	}
}

void CMemAllocate::InitMemoryBlock()//初始化内存块，大小为1KB
{
	for (MemoryBlock * p = m_MemList; p!=0; p = m_MemList)
	{
		m_MemList = p->nextPointer;
		delete p;
	}	

	MemoryBlock * tmpMemBlock = new MemoryBlock;
	tmpMemBlock->BlockLength = 384;/*千字节KB*/
	tmpMemBlock->JobIndex = 0;
	tmpMemBlock->StartAddr = 0;

	MemoryBlock * tmpMemBlock2 = new MemoryBlock;
	tmpMemBlock2->BlockLength = 128;/*千字节KB*/
	tmpMemBlock2->JobIndex = 9;
	tmpMemBlock2->StartAddr = 384;

	
	MemoryBlock * tmpMemBlock3 = new MemoryBlock;
	tmpMemBlock3->BlockLength = 512;/*千字节KB*/
	tmpMemBlock3->JobIndex = 0;
	tmpMemBlock3->StartAddr = 512;

	tmpMemBlock->prePointer=0;
	tmpMemBlock->nextPointer=tmpMemBlock2;
	tmpMemBlock2->prePointer=tmpMemBlock;
	tmpMemBlock2->nextPointer=tmpMemBlock3;
	tmpMemBlock3->prePointer=tmpMemBlock2;
	tmpMemBlock3->nextPointer=0;


	m_MemList = tmpMemBlock;

	//MemoryBlock* tmpMemBlock4 = new MemoryBlock;		//初始化lastFind指针
	lastFind=tmpMemBlock2;
	lastFind->nextPointer = tmpMemBlock3;
}
void CMemAllocate::AddAJobInEnd(char * JobName,int JobIndex,int JobLength,int* JobPageTable)//添加进程
{
	JCBInfo * tmpJob = new JCBInfo;
	tmpJob ->JobName = JobName;
	tmpJob ->JobIndex =JobIndex;
	tmpJob ->JobLength = JobLength;
	tmpJob ->JobPageTable = JobPageTable;

	tmpJob ->nextPointer = 0;
	tmpJob ->prePointer = m_JobsEnd;

	m_JobsEnd = tmpJob;
	if (m_JobsEnd ->prePointer != 0)
		m_JobsEnd ->prePointer ->nextPointer = tmpJob;
	else
		m_JobsHead = tmpJob;
}

void CMemAllocate::InitJobs()//初始化进程列表，其中Joblength是指该作业所需的内存大小，如180表示180字节
{
	m_JobsHead = m_JobsEnd = 0;
	AddAJobInEnd("Job1",1,180,NULL);
	AddAJobInEnd("Job2",2,360,NULL);
	AddAJobInEnd("Job3",3,180,NULL);
	AddAJobInEnd("Job4",4,60,NULL);
	AddAJobInEnd("Job5",5,20,NULL);
	//AddAJobInEnd("Job6",6,100,NULL);
}

void CMemAllocate::AllocateMem_FirstAdapt(CMemAllocate::JCBInfo& job)//实现了首次适配算法
{
	for (MemoryBlock * p = m_MemList; p != 0; p=p->nextPointer)
	{
		if (job.JobLength < p->BlockLength && p->JobIndex == 0)			//如果作业需要空间小于内存块空间，分配
		{
			MemoryBlock * tmpMemBlock = new MemoryBlock;
			tmpMemBlock ->BlockLength = job.JobLength;
			tmpMemBlock ->JobIndex = job.JobIndex;
			tmpMemBlock ->StartAddr = p->StartAddr;
			tmpMemBlock ->nextPointer = p;
			tmpMemBlock ->prePointer = p ->prePointer;
			
			p->StartAddr = p->StartAddr + job.JobLength;
			p->BlockLength = p->BlockLength -job.JobLength;
			if (p->prePointer == 0 )
			{
				m_MemList = tmpMemBlock;
			}
			else
			{
				p->prePointer->nextPointer = tmpMemBlock;
			}
			p ->prePointer = tmpMemBlock;
			break;
		}
		else if(job.JobLength == p->BlockLength && p->JobIndex == 0)
		{
			p->JobIndex=job.JobIndex;
			break;
		}
		else
		{
			continue;
			
		}
	}
}

void CMemAllocate::AllocateMem_BestAdapt(CMemAllocate::JCBInfo& job)//实现了最佳适配算法
{
	MemoryBlock* bestMemBlock=0;		//指针指向最佳内存块
	for (MemoryBlock* q = m_MemList;q != 0;q = q->nextPointer)
	{
		if (job.JobLength < q->BlockLength && q->JobIndex == 0)		//找到第一个空闲块
		{
			bestMemBlock = q;
			break;
		}
	}
	if (bestMemBlock != 0) {
		for (MemoryBlock* p = bestMemBlock;p != 0;p = p->nextPointer)			//遍历内存链表
		{

			if (p->BlockLength == job.JobLength && p->JobIndex == 0)		//若空闲内存块大小与作业大小相同，找到
			{
				bestMemBlock = p;
				break;
			}
			//否则若找到比当前最佳更合适的内存块则赋值给bestMemBlock
			if (job.JobLength < p->BlockLength && p->BlockLength < bestMemBlock->BlockLength && p->JobIndex == 0) {
				bestMemBlock = p;
			}
		}
		//到此，bestMemBlock中保存了最佳内存块
		MemoryBlock* tmpMemBlock = new MemoryBlock;
		tmpMemBlock->BlockLength = job.JobLength;
		tmpMemBlock->JobIndex = job.JobIndex;
		tmpMemBlock->StartAddr = bestMemBlock->StartAddr;
		tmpMemBlock->nextPointer = bestMemBlock;
		tmpMemBlock->prePointer = bestMemBlock->prePointer;

		bestMemBlock->StartAddr = bestMemBlock->StartAddr + job.JobLength;
		bestMemBlock->BlockLength = bestMemBlock->BlockLength - job.JobLength;
		if (bestMemBlock->prePointer == 0)
		{
			m_MemList = tmpMemBlock;
		}
		else
		{
			bestMemBlock->prePointer->nextPointer = tmpMemBlock;
		}
		bestMemBlock->prePointer = tmpMemBlock;
	}
}


void CMemAllocate::AllocateMem_NextAdapt(CMemAllocate::JCBInfo& job)//实现了邻近适配算法
{
	for (MemoryBlock* p = lastFind->nextPointer; p != lastFind;)
	{
		if (job.JobLength < p->BlockLength && p->JobIndex == 0)			//如果作业需要空间小于内存块空间，分配
		{
			MemoryBlock* tmpMemBlock = new MemoryBlock;
			tmpMemBlock->BlockLength = job.JobLength;
			tmpMemBlock->JobIndex = job.JobIndex;
			tmpMemBlock->StartAddr = p->StartAddr;
			tmpMemBlock->nextPointer = p;
			tmpMemBlock->prePointer = p->prePointer;

			p->StartAddr = p->StartAddr + job.JobLength;
			p->BlockLength = p->BlockLength - job.JobLength;
			if (p->prePointer == 0)
			{
				m_MemList = tmpMemBlock;
			}
			else
			{
				p->prePointer->nextPointer = tmpMemBlock;
			}
			p->prePointer = tmpMemBlock;
			lastFind = tmpMemBlock;
			break;
		}
		else if (job.JobLength == p->BlockLength && p->JobIndex == 0)
		{
			p->JobIndex = job.JobIndex;
			lastFind = p;
			break;
		}
		if (p->nextPointer == 0)
			p = m_MemList;
		else
			p = p->nextPointer;
	}
}


void CMemAllocate::test()
{
	for (JCBInfo * p = m_JobsHead; p!= 0 ; p = p->nextPointer)
	{
	//	AllocateMem_FirstAdapt(*p);
	//	AllocateMem_BestAdapt(*p);
	//	AllocateMem_NextAdapt(*p);
	}
	
}