// MemAllocate.h: interface for the CMemAllocate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEMALLOCATE_H__B3EE818A_71BA_4271_A81D_03613CC7ECF9__INCLUDED_)
#define AFX_MEMALLOCATE_H__B3EE818A_71BA_4271_A81D_03613CC7ECF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMemAllocate  
{	
	/*�ڴ��ṹ�����Ա�ʾ����ռ�ռ�������������ʽ��*/
	typedef struct MemoryBlock {			
		long StartAddr;						//�ڴ����ʼ��ַ(��λ KB)
		long BlockLength;					//�ڴ�鳤��(��λ KB)
		int JobIndex;						//�����Ǹ���ҵ��nBelongToJob=0 ��ʾ�����С�

		MemoryBlock * nextPointer;			//ָ����һ��MemoryBlock
		MemoryBlock * prePointer;			//ָ����һ��MemoryBlock
	};

	/*��ҵ���ƿ���Ϣ�ṹ*/
	typedef struct JCBInfo					
	{
		char* JobName;						//��ҵ��
		int JobIndex;						//��ҵ���
		int JobLength;						//��ҵ��С
		int* JobPageTable;					//ҳ���׵�ַ

		JCBInfo * nextPointer;				//ָ����һ��JCBInfo
		JCBInfo * prePointer;				//ָ����һ��JCBInfo
	};

public:
	CMemAllocate();
	virtual ~CMemAllocate();

private:
	MemoryBlock * m_MemList;				//����ռ�ռ���б�(�������ʾ)
	JCBInfo * m_JobsHead, * m_JobsEnd;		//��ҵ���ƿ�(�������ʾ)
	MemoryBlock * lastFind;					//�����ڽ����䱣����һ�ε�λ��

public:
	void DrawMemory( CDC* pDC);				//�ѵ�ǰ���ڴ�״̬��ͼ�λ�����
	void InitMemoryBlock();					//�Ѷ�����г�ʼ���ڴ�ռ䡣��ʼ״̬Ϊһ��1M(1024KB)�Ŀռ�
	void InitJobs();						//��ʼ����ҵ
	void AllocateMem_FirstAdapt(JCBInfo& job);		//(�״���Ӧ�㷨)��һ����ҵ���䵽�ڴ���
	void AllocateMem_BestAdapt(JCBInfo& job);      //��������㷨
	void AllocateMem_NextAdapt(JCBInfo& job);      //�ڽ������㷨
	void AddAJobInEnd(char * JobName,int JobIndex,int JobLength,int* JobPageTable=NULL);//���һ����ҵ����ҵ�����ĩβ

	void test();
};

#endif // !defined(AFX_MEMALLOCATE_H__B3EE818A_71BA_4271_A81D_03613CC7ECF9__INCLUDED_)
