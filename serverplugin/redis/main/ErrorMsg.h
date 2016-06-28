#ifndef _RVS_REDIS_ERROR_MSG_H_
#define _RVS_REDIS_ERROR_MSG_H_

#include <string>
using std::string;

typedef enum enRedisErrorCode
{
	RVS_SUCESS = 0,							        //�ɹ�
	RVS_SYSTEM_ERROR = -10903001,					//ϵͳ����
	RVS_SERIALIZE_ERROR = -10903002,				//���л�����
	RVS_KEY_IS_NULL = -10903003,                    //KeyΪ��
	RVS_KEY_TOO_LONG = -10903004,				    //Key����
	RVS_READ_QUEUE_FULL = -10903005,			    //�����������
	RVS_WRITE_QUEUE_FULL = -10903006,			    //����д������
	RVS_NO_CALLBACK_FUNC = -10903007,				//���û�����ûص�����
	RVS_NO_INITIALIZE = -10903008,				    //���û�г�ʼ��
	RVS_NEW_SPACE_ERROR = -10903009,			    //����ռ�ʧ��
	RVS_UNKNOWN_SERVICE = -10903010,				//��֧�ֵķ����
	RVS_UNKNOWN_REDIS_TYPE = -10903011,             //��֧�ֵ�redis��������
	RVS_UNKNOWN_MSG = -10903012,					//��֧�ֵ���Ϣ��
	RVS_BUSINESS_CONFIG_ERROR = -10903013,		    //ҵ�������ļ�����
	RVS_REDIS_CONFIG_ERROR = -10903014,			    //Redis���������ļ�����
	RVS_NO_REDIS_SERVER = -10903015,				//����û�ж�Ӧ��Redis������
	RVS_WARN_CONFIG_ERROR = -10903016,				//Warn�����ļ�����
	RVS_PARAMETER_ERROR = -10903017,				//��������
	RVS_AVENUE_PACKET_ERROR = -10903018,			//Avenue������,ȱ�ٲ���
	RVS_REDIS_CONNECT_ERROR = -10903019,			//Redis����������ʧ��
	RVS_REDIS_KEY_NOT_FOUND = -10903020,			//Redis��������ĩ�ҵ���Ӧ��keyֵ
	RVS_REDIS_KEY_VERSION_NOT_ACCORD = -10903021,	//keyֵversion��һ��
	RVS_REDIS_STRUCT_IS_WRONG = -10903022,          //struct�ṹ���������
	RVS_REDIS_FIELD_IS_NULL = -10903023,            //Hash�ṹʱFieldΪ��
	RVS_REDIS_VALUE_IS_NULL = -10903024,            //Hash�ṹʱValueΪ��
	RVS_REDIS_OPERATION_FAILED = -10903025,         //����ʧ��
	RVS_REDIS_NOT_SET_EXPIRE_TIME = -10903026,        //keyû�����ó�ʱʱ��
	RVS_REDIS_LIST_INDEX_OUT_RANGE = -10903027,      //list��indexԽ���ָ��key������
	RVS_REDIS_ZSET_NO_MEMBERS = -10903028,           //zset��ĳ���䷶Χ��û��Ԫ��
	RVS_OTHER_ERROR = -10903029,				          //��������
	RVS_REDIS_DATA_FORMAT_ERROR = -10903030               //���ݸ�ʽ����
}RVSErrorCode;

#endif
