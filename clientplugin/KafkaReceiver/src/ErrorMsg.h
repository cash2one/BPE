#ifndef _MQR_ERROR_MSG_H_
#define _MQR_ERROR_MSG_H_

#include <string>
using std::string;

typedef enum enErrorCode
{
	MQR_SUCESS = 0,							    //�ɹ�
	MQR_SYSTEM_ERROR = -10901301,				//ϵͳ����
	MQR_SERIALIZE_ERROR = -10901302,			//���л�����
	MQR_ZOOKEEPER_CONNECT_ERROR = -10901303,	//zookeeper����������ʧ��
	MQR_NO_CORRESPONDING_REQUEST = -10901304,	//��Ӧ�޶�Ӧ������
	MQR_AVENUE_PACKET_ERROR = -10901305,		//Avenue������,ȱ�ٲ���
	MQR_NO_CALLBACK_FUNC = -10901306,			//���û�����ûص�����
	MQR_NO_INITIALIZE = -10901307,				//���û�г�ʼ��
	MQR_NEW_SPACE_ERROR = -10901308,			//����ռ�ʧ��
	MQR_UNKNOWN_SERVICE = -10901309,			//��֧�ֵķ����
	MQR_PRODUCE_ERROR = -10901310,		        //��Ϣ���ʹ���
	MQR_CONFIG_ERROR = -10901311,			    //�����������ļ�����
	MQR_NO_TOPIC = -10901312,				    //����û�ж�Ӧ��topic
	MQR_WARN_CONFIG_ERROR = -10901313,		    //Warn�����ļ�����
	MQR_PARAMETER_ERROR = -10901314,		    //��������
	MQR_KAFKA_CONNECT_ERROR = -10901315,		    //kafka����������ʧ��
	MQR_OTHER_ERROR = -10901399					//��������
}MQRErrorCode;

string GetErrorMsg(MQRErrorCode code);
string GetErrorMsg(int nCode);

#endif
