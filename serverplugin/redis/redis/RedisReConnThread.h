#ifndef _REDIS_RECONN_THREAD_H_
#define _REDIS_RECONN_THREAD_H_

#include "detail/_time.h"

#include <MsgTimerThread.h>
#include <string>
#include <vector>
#include <set>

using std::string;
using std::vector;
using std::set;
using namespace sdo::common;

typedef struct stRedisReConnMsg
{
	timeval_a tmLastWarn;		//�ϴθ澯ʱ��
	string strAddr;

	stRedisReConnMsg(){}
	virtual ~stRedisReConnMsg(){}
}SRedisReConnMsg;

class CRedisVirtualService;

class CRedisReConnThread : public CMsgTimerThread
{
public:
	CRedisReConnThread();
	virtual ~CRedisReConnThread(){}
	int Start(CRedisVirtualService *pRedisVirtualService);
	void OnReConn(const string &strAddr);
	virtual void StartInThread();
	virtual void Deal(void *pData);
private:
	void DoReConn();
	void Warn(const string &strAddr);
private:
	vector<SRedisReConnMsg *> m_vecReConnMsg;
	set<string> m_setAddrFilter;
	CThreadTimer m_timerReConn;
	CRedisVirtualService *m_pRedisVirtualService;
	//ĳ����ַ����ʧ��ʱ�����ϴ�����ʧ�ܱ�����ʱ��������ֵ���������ٴα���
	unsigned int m_dwAlarmFrequency;

};
#endif
