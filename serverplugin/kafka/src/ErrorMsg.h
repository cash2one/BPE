#ifndef _MQS_ERROR_MSG_H_
#define _MQS_ERROR_MSG_H_

#include <string>
using std::string;

typedef enum enErrorCode
{
	MQS_SUCESS = 0,							    //�ɹ�
	MQS_SYSTEM_ERROR = -10901201,				//ϵͳ����
	MQS_SERIALIZE_ERROR = -10901202,			//���л�����
	MQS_CONNECT_ERROR = -10901203,				//����������ʧ��
	MQS_QUEUE_FULL = -10901204,			        //���������
	MQS_AVENUE_PACKET_ERROR = -10901205,		//Avenue������,ȱ�ٲ���
	MQS_NO_CALLBACK_FUNC = -10901206,			//���û�����ûص�����
	MQS_NO_INITIALIZE = -10901207,				//���û�г�ʼ��
	MQS_NEW_SPACE_ERROR = -10901208,			//����ռ�ʧ��
	MQS_UNKNOWN_SERVICE = -10901209,			//��֧�ֵķ����
	MQS_PRODUCE_ERROR = -10901210,		        //��Ϣ���ʹ���
	MQS_CONFIG_ERROR = -10901211,			    //�����������ļ�����
	MQS_NO_TOPIC = -10901212,				    //����û�ж�Ӧ��topic
	MQS_WARN_CONFIG_ERROR = -10901213,		    //Warn�����ļ�����
	MQS_PARAMETER_ERROR = -10901214,		    //��������
	MQS_OTHER_ERROR = -10901299					//��������
}MQSErrorCode;

string GetErrorMsg(MQSErrorCode code);
string GetErrorMsg(int nCode);

#endif
