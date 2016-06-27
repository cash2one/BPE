#ifndef _HT_INFO_H_
#define _HT_INFO_H_

#include "pluginInterface.h"
#include <map>
#include <string>
#include <vector>
using std::map;
using std::string;
using std::vector;


namespace HT {
#define GUID_CODE 9
#define		VALUE_SPLITTER		"|^_^|"
#define IN
#define OUT


/*
*���ݸ�����Ĳ�������
*������ַ
*/
typedef struct confValue
{
	string name;      //ǩ�����õ�name
	string key;       //ǩ�����õ�key
	string hostName;  //������ַ
	
}ahConfValue;


typedef map<unsigned int, unsigned int> CODE_TYPE_MAP;
typedef map<unsigned int, vector<ahConfValue> > SID_HOST_MAP;

typedef map<string, PLUGIN_FUNC_SEND> NAME_TO_ADD_SEND;               //������ͺ������͵�ַ��Ӧ��map
typedef map<string, PLUGIN_FUNC_RECV> NAME_TO_ADD_RECV;               //������ܺ������͵�ַ��Ӧ��map

//���Ĭ���Դ�����
typedef ssoConfig*(*callFunc)(void);
}

#endif
