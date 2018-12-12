/*********************************************************************************
 *                   Copyright (c) 2016 - 2020,Tencent
 *                      All rights reserved.
 *
 * File Name:   at_for_bc28.h
 *
 * Description:   net api based on at cmd for bc28
 *
 * History:      <author>          <time>        <version>
 *               yougaliu          2018-11-26        1.0
 * Desc:           ORG.
 ********************************************************************************/

#ifndef __NET_BC28_H_
#define __NET_BC28_H_

#define NET_SEND_MAXLEN_ONCE		(1352)		
#define NET_READ_MAXLEN_ONCE		(1460)     

#define RET_OK						(0)
#define RET_ERR						(-1)

#define TIME_STR_LEN				(32)
#define TIME_BASE_YEAR				(2000)
#define TIME_OFFSET					(167394976)

#define IP_CMD_LEN				    (128)
#define IP_STR_LEN				    (30)

#define READ_CMD_ACK_PATTEN		    "+CIPRXGET: 2,"
#define RECV_LEN_NUM_MAX			(4)
#define NUM_END_PATTEN				','

#define END_PATTEN1					(0X0A)
#define END_PATTEN2					(0X0D)

#define POWER_OFF_TIME				(2000)
#define AT_REPEAT_TIME				(5)
#define AT_CHECK_STAT_TIME	    	(9)

#define ZONE_FOR_BEIJING			(8)


void HwInitBc28(void);
int net_init_by_at(void);
int net_connect_by_at(const char *host,  int port, int *pfd,  eNetProto protocol, void* pdata);
int net_disconnect_by_at(uint32_t fd, void* pdata);
int net_connectState_by_at(uint32_t fd, void* pdata);
int net_destroy_by_at(uint32_t fd, void* pdata);
int net_read_by_at(uint32_t fd, uint8_t *pRecvbuf, int len, uint16_t timeOut);
int net_write_by_at(uint32_t fd, uint8_t *pSendbuf, int len, uint16_t timeOut);
int GetLocalTimeByAt(uint8_t * strTime);
long GetTimeStampByAt(void *zone);

#endif

