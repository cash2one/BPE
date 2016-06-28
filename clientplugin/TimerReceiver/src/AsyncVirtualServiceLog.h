#ifndef _ASYNC_VIRTUAL_SERVICE_LOG_H_
#define _ASYNC_VIRTUAL_SERVICE_LOG_H_

#include "LogManager.h"

const int SAP_VIRTUAL_MODULE = 11;
DEFINE_MODULE_XLOG(SAP_VIRTUAL_MODULE,SV_XLOG)

const int ASYNC_VIRTUAL_MODULE = 81;
DEFINE_MODULE_XLOG(ASYNC_VIRTUAL_MODULE,AVS_XLOG)


#endif