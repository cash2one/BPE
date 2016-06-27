#ifndef _SERVICE_CONFIG_H_
#define _SERVICE_CONFIG_H_

#include <map>
#include <vector>
#include <string>
#include "tinyxml/tinyxml.h"

using std::string;
using std::map;
using std::multimap;
using std::make_pair;
using std::vector;
using std::pair;

namespace HT{

typedef enum
{
	MSG_FIELD_INT=1,
	MSG_FIELD_STRING=2,
	MSG_FIELD_ARRAY=3,
	MSG_FIELD_TLV=4,
	MSG_FIELD_STRUCT=5,
	MSG_FIELD_ALL
}EValueType;

typedef enum
{
	HTTP_DATA_JSON=1,
	HTTP_DATA_KEYVALUE=2,
	HTTP_DATA_VALUE=3,
	HTTP_DATA_BODY=4,
	HTTP_DATA_ALL
}EHttpDataFormat;

typedef enum
{
	ENCODE_UTF8=1,
	ENCODE_GBK=2,
	ENCODE_UNKNOWN=3,
	ENCODE_ALL
}EEncodeMode;

//field 
typedef struct stConfigField
{
	string strName;
	string strOriName;
	string strTypeName;
	bool   bUrlParameter;
	string strSuffix;
	bool   bReturnField;
	bool   bRequested;
	bool   bAutoSet;
	string strConfigField;
	int    nMaxLen;
	int    nMinLen;
	string strRegex;
	string strJsonPath;
	bool   hiddenLog; //default is true; else false ****
	EEncodeMode eEncodeMode;
	//for struct
	bool bStruct;
	EValueType eStructFieldType;
	int nLen;

	//for struct's default value
	bool bHasDefault;
	int nDefaultValue;
	string strDefaultValue;
}SConfigField;

//type
typedef struct stConfigType
{
	string strName;										//������
	EValueType eType;									//��������
	int    nCode;										//��������
	string strItemType;									//����ò���Ϊ���飬���ʾ�����и��������,ÿ�������Ϊtype
	map<string, SConfigField> mapFieldByName;			//�ò����е�field by name,��Է�struct
	map<string, SConfigField> mapFieldByType;			//�ò����е�filed by code,��Է�struct
	map<string, unsigned int> mapPosByName;				//��name��λ����Ϣmap
	vector<SConfigField> vecConfigField;				//����ò���Ϊstruct,���ʾstruct�����е�field
	int operator <(const stConfigType &p)const
	{
		 return ( this->nCode< p.nCode);
	}

	//for array
	bool bArrayField;									//�Ƿ�Ϊ����
	string strArraryName;								//�����и�����

	//for int or string default value
	bool bHasDefault;									//�Ƿ���ȱʡֵ
	int nDefaultValue;									//int��ȱʡֵ
	string strDefaultValue;								//string��ȱʡֵ
}SConfigType;


//message 
typedef struct stConfigMessage
{
	string strName;										//��Ϣ��
	unsigned int dwId;									//��ϢID
	
	string url;                                         //url
	string SendFunc;									//����http����ĺ�����Ϊ����ΪĬ�Ϻ���
	string ReceiveFunc;									//httpת��Ϊjson�ĺ�����Ϊ����ΪĬ�Ϻ���
	string method;										//�������󷽷�
	
										
	SConfigType oRequestType;							//�������
	SConfigType oResponseType;							//Ӧ�����
	string strUserDefineHost;                           
	map<unsigned int, string> mapArraryTypeNameByCode;
}SConfigMessage;


typedef struct stConfigTypePair
{
	string strPreviousTypeName;							//��ǰ�ֶ�����
	string strCurrentTypeName;							//��ǰ�ֶ�����������
}SConfigTypePair;

class CServiceConfig
{
public:
	CServiceConfig();
	~CServiceConfig(){}
	int	LoadServiceConfig(const string &strConfig);
	
	//type and field
	int GetTypeByName(const string &strName, SConfigType& oConfigType);
	int GetTypeByCode(int nCode, SConfigType& oConfigType);
	int GetTypeNameByFieldName(const string &strPreviousTypeName, const string & strFieldName, string & strTypeName, bool bFirst = false);

	map<int, SConfigType>& GetTypeByCodeMap(){return m_mapTypeByCode;}
	bool IsExist(unsigned int dwMsgId);
	//message
	int GetMessageTypeByName(const string &strName, SConfigMessage ** oMessageType);
	int GetMessageTypeById(unsigned int dwMessageId, SConfigMessage ** oMessageType);
	
	const string & GetServiceName() {return m_strServiceName;}
	unsigned int GetServiceId() {return m_dwServiceId;}
	const string & GetServiceEncoding(){return m_strServiceEncoding;}
	const string & GetSdkEncoding(){return m_strSdkEncoding;}
	bool GetIsTreeStruct(){return m_bIsTreeStruct;}
	void Dump()const;
	
private:
	
	int LoadConfigTypeConfig_(TiXmlElement * pConfigType);
	int LoadConfigMsgConfig_(TiXmlElement * pConfigMsg);
	int LoadMsgField_(SConfigMessage & oConfigMessage, TiXmlElement * pConfigFields, bool bRequest = true);
	
	int GetTypeAttr_(const TiXmlElement* pElement, SConfigType& oConfigType);
	int GetFieldAttr_(const TiXmlElement* pElement, SConfigField& oConfigField, bool bStruct = false);
	
	int GetMsgAttr_(const TiXmlElement* pElement, SConfigMessage& oConfigMessage);
	int GetMsgFieldAttr_(const TiXmlElement* pElement, SConfigField& oConfigField);
private:

	//type config
	map<string, SConfigType> m_mapTypeByName;		
	map<int, SConfigType> m_mapTypeByCode;

	//message config
	map<string, SConfigMessage> m_mapMessageByName;
	map<unsigned int, SConfigMessage> m_mapMessageById;

	//type map by field
	multimap<string, SConfigTypePair> m_mapTypePairByFieldName;

	//type map by class
	map<string, EValueType> m_mapETypeByName;
	map<string, EHttpDataFormat> m_mapEHttpDataFormatByName;

	string m_strServiceName;
	unsigned int m_dwServiceId;
	string m_strServiceEncoding;
	string m_strSdkEncoding;
	bool m_bIsTreeStruct;
};

}
#endif


