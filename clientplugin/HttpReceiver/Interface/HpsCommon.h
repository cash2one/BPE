#ifndef _HPS_COMMON_H_
#define _HPS_COMMON_H_

const unsigned int MAX_SIZE_OF_DEQUE = 1000;

enum OSAP_CHACK_STATUS
{
	OSAP_NOT_CHECK = 0,
	OSAP_OK,
	OSAP_NO_USER_PARAM,
	OSAP_NO_AUTHEN,
	OSAP_IP_FORBIDEN,
	OSAP_NO_PASSWORD,
	OSAP_ERROR_SIG,
	OSAP_NO_USER_COFG,
	OSAP_SYS_ERR,
};


typedef enum
{
	SUCCESS = 0,
		
	ERROR_BAD_REQUEST_INNER = -10250000, //soplugin return the message
		

	ERROR_TRANSFER_REQUEST_FAILED = -10250001,
	ERROR_TRANSFER_RESPONSE_FAILED = -10250002,
	ERROR_TRANSFER_NOT_FOUND = -10250003, 

	ERROR_NO_SOS_AVAILABLE = -10250004, 
	ERROR_SOS_CAN_NOT_REACH = -10250008,
	ERROR_SOS_RESPONSE_TIMEOUT = -10250005,
	ERROR_SOS_REQUEST_NOT_SUPPORT = -10250010,
	ERROR_SOS_SEND_FAIL = -10250011,
	ERROR_SOS_QUEUE_FULL = -10250012,

	ERROR_HPS_OUTOF_QUEUE_MAXSIZE = -10250006,
	ERROR_UNDEFINED = -10250007,

	ERROR_HEAD_NOT_IMPLEMENTED = -10250009,	
	ERROR_URL_NOT_SUPPORT = -10250013,
	ERROR_DEOCDE_REQUEST_ERROR = -10250014,
	ERROR_CLIENT_CANCEL = -10250015,

	ERROR_SERVER_REJECT = -10250016,
	ERROR_CHECK_AUTHEN = -10250017,
	ERROR_CHECK_SIGNATURE = -10250018,
	ERROR_OSAP_REQUEST_FAIL = -10250019,

	ERROR_SLS_REQUEST_NOT_USERNAME = -10250020,
	ERROR_SLS_REQUEST_NOT_REGINFO = -10250021,
	ERROR_SLS_REQUEST_NOT_URL = -10250022,
	ERROR_SLS_TIMEOUT = -10250023,
	ERROR_SLS_RESPONSE_NOT_REGINFO = -10250024,

	ERROR_CONNECT_TO_HTTP_SERVER_FAIL = -10250025,
	ERROR_SEND_HTTP_REQUEST_FAIL = -10250026,
	ERROR_DECODE_HTTP_RESPONSE_FAIL = -10250027,
	ERROR_HTTP_SERVER_RESPONSE_TIMEOUT = -10250028,
	ERROR_HTTP_REQUEST_URL_ILLEGAL = -10250029,
	ERROR_HTTP_SERVER_RESPONSE_FAIL = -10250030,
	ERROR_CHECK_AUTHEN_IPLIST = -10250031,
	ERROR_SOS_DISCONNECTED = -10250032,
	ERROR_HPS_ERROR_INTERRUPT = -10250033,
                
    ERROR_JSONRPC_ERROR_SAMEIDENTIFIER = -10250034,
                
    ERROR_JSONRPC_PARSE_ERROR = -32700,
    ERROR_JSONRPC_INVAILD_REQUEST = -32600,
    ERROR_JSONRPC_METHOD_NOT_FOUND = -32601,
    ERROR_JSONRPC_INVAILD_PARAMS = -32602,

    ERROR_HPS_ERROR_ATTACK = -10250035
}EErrorCode;


typedef enum
{
	HTTP_CODE_CONNECT_HTTP_SERVER_FAIL = 701,
	HTTP_CODE_SEND_REQUEST_FAIL = 702,
	HTTP_CODE_DECODE_RESPONSE_FAIL = 703,
	HTTP_CODE_RESPONSE_TIME_OUT = 704
}HttpCode;

typedef enum
{
	TYPE_CONNECT = 1,
	TYPE_CONNECT_RESULT = 2,
	TYPE_CLOSE = 3,
	TYPE_REQ_RES = 4
}ESosSessionRequestType;

typedef enum emSosConnectState
{
	E_SOS_DISCONNECTED=1,
	E_SOS_CONNECTING=2,
	E_SOS_CONNECTED=3
	
}ESosConnectState;

typedef enum emHttpConnectType
{
	E_Http_Connect = 1,
	E_Http_Close = 2
}EHttpConnectType;

typedef enum emRequestType
{
    E_None_Request=1,
    E_Normal_Request=2,
    E_JsonRpc_Request=3
}ERequestType;



#endif


