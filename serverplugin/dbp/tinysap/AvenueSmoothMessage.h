#ifndef _AVENUE_SMOOTH_MESSAGE_H_
#define _AVENUE_SMOOTH_MESSAGE_H_
#include "AvenueBuffer.h"
//#include "AvenueTLVBody.h"
#include <map>
#include <vector>
#include <string.h>

using std::map;
using std::vector;
using std::string;

namespace sdo{
namespace commonsdk{

typedef enum
{
	SAP_PACKET_REQUEST=0xA1,
	SAP_PACKET_RESPONSE=0xA2
}EAvenuePacketType;

typedef struct tagAvenueMsgHeader
{
	unsigned char byIdentifer;
	unsigned char byHeadLen;
	unsigned char byVersion;
	unsigned char byM;

	unsigned int dwPacketLen;
	unsigned int dwServiceId;
	unsigned int dwMsgId;
	unsigned int dwSequence;

	unsigned char byContext;
	unsigned char byPrio;
	unsigned char byBodyType;
	unsigned char byCharset;
	
	unsigned int dwCode;
	unsigned char bySignature[16];
}SAvenueMsgHeader;

typedef struct tagAvenueMsgAttribute
{
	unsigned short wType;
	unsigned short wLength;
	unsigned char acValue[0];
}SAvenueMsgAttribute;

typedef struct tagAvenueValueNode
{
	void * pLoc;
	unsigned int nLen;
}SAvenueValueNode;

class CAvenueSmoothEncoder
{
public:
	CAvenueSmoothEncoder();
	CAvenueSmoothEncoder(unsigned char byIdentifer,unsigned int dwServiceId,unsigned int dwMsgId,unsigned int dwCode=0);
	void Reset();
	void SetService(unsigned char byIdentifer,unsigned int dwServiceId,unsigned int dwMsgId,unsigned int dwCode=0);
	unsigned int CreateAndSetSequence();//never return 0;
	void SetSequence(unsigned int dwSequence);
	void SetMsgOption(unsigned int dwOption);
	void SetExtHeader(const void *pBuffer, unsigned int nLen);
	void SetBody(const void *pBuffer, unsigned int nLen);
	void AesEnc(unsigned char abyKey[16]);
	void SetSignature(const char * szKey, unsigned int nLen);

	void SetValue(unsigned short wKey,const void* pValue,unsigned int nValueLen);
	void SetValue(unsigned short wKey,const string &strValue);
	void SetValue(unsigned short wKey,unsigned int wValue);

	void BeginValue(unsigned short wType);
	void AddValueBloc(const void *pData,unsigned int nLen);
	void EndValue(unsigned short dwLen=0);

	const void * GetBuffer()const{return m_buffer.base();}
	int GetLen()const{return m_buffer.len();}
private:
	static unsigned int sm_dwSeq;
	CAvenueBuffer m_buffer;

	unsigned char *pAttriBlock;
};

class CAvenueSmoothDecoder
{
	typedef std::multimap<unsigned short,const unsigned char *> AttriMultiMap;
public:
	CAvenueSmoothDecoder(const void *pBuffer,int nLen);//can't malloc memory, directly using pBuffer
	CAvenueSmoothDecoder();
	void Reset(const void *pBuffer,int nLen);
	int VerifySignature(const char * szKey, unsigned int nLen);
	void AesDec(unsigned char abyKey[16]);
	void GetService(unsigned char * pIdentifer,unsigned int * pServiceId,unsigned int * pMsgId,unsigned int * pdwCode);
	unsigned char GetIdentifier();
	unsigned int GetServiceId();
	unsigned int GetMsgId();
	unsigned int GetCode();
	unsigned int GetSequence();
	unsigned int GetMsgOption();
	void GetExtHeader(void **ppBuffer,  int * pLen);
	void GetBody(void **ppBuffer, unsigned int * pLen);

	void DecodeBodyAsTLV();
	int GetValue(unsigned short wKey,void** pValue, unsigned int * pValueLen) ;
	int GetValue(unsigned short wKey, string & strValue);
	int GetValue(unsigned short wKey, unsigned int * pValue) ;
	
	void GetValues(unsigned short wKey,vector<SAvenueValueNode> &vecValues);
	void GetValues(unsigned short wKey,vector<string> &vecValues);
	void GetValues(unsigned short wKey,vector<unsigned int> &vecValues);

	const void * GetBuffer()const{return m_pBuffer;}
	int GetLen()const{return m_nLen;}
private:
	void * m_pBuffer;
	unsigned int m_nLen;

	AttriMultiMap m_mapMultiAttri;
};

}
}
#endif

