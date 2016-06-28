#ifndef _CVS_ERROR_MSG_H_
#define _CVS_ERROR_MSG_H_

#include <string>
using std::string;

typedef enum enErrorCode
{
	CVS_SUCESS = 0,							//�ɹ�
	CVS_SYSTEM_ERROR = -10901101,					//ϵͳ����
	CVS_SERIALIZE_ERROR = -10901102,				//���л�����
	CVS_KEY_TOO_LONG = -10901103,				//Key����
	CVS_READ_QUEUE_FULL = -10901104,			//�����������
	CVS_WRITE_QUEUE_FULL = -10901105,			//����д������
	CVS_NO_CALLBACK_FUNC = -10901110,				//���û�����ûص�����
	CVS_NO_INITIALIZE = -10901111,				//���û�г�ʼ��
	CVS_NEW_SPACE_ERROR = -10901112,			//����ռ�ʧ��
	CVS_UNKNOWN_SERVICE = -10901120,				//��֧�ֵķ����
	CVS_UNKNOWN_MSG = -10901121,					//��֧�ֵ���Ϣ�ţ�Ŀǰ��֧��1,2,3,4
	CVS_BUSINESS_CONFIG_ERROR = -10901122,		//ҵ�������ļ�����
	CVS_CACHE_CONFIG_ERROR = -10901123,			//Cache�����������ļ�����
	CVS_NO_CACHE_SERVER = -10901124,				//����û�ж�Ӧ��Cache������
	CVS_WARN_CONFIG_ERROR = -10901125,				//Warn�����ļ�����
	CVS_PARAMETER_ERROR = -10901130,				//��������
	CVS_AVENUE_PACKET_ERROR = -10901131,			//Avenue������,ȱ�ٲ���
	CVS_CACHE_CONNECT_ERROR = -10901141,			//Cache����������ʧ��
	CVS_CACHE_KEY_NOT_FIND = -10901142,			//Cache��������ĩ�ҵ���Ӧ��keyֵ
	CVS_CACHE_KEY_VERSION_NOT_ACCORD = -10901143,	//keyֵversion��һ��
	CVS_CACHE_CAS_NOT_SUPPORT = -10901144,			//cache��֧��cas
	CVS_CACHE_ALREADY_EXIST = -10901145,			//key�Ѿ����ڲ�����add
	CVS_OTHER_ERROR = -10901199					//��������
}CVSErrorCode;

string GetErrorMsg(CVSErrorCode code);
string GetErrorMsg(int nCode);

#endif
