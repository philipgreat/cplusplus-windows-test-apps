
//rtp.h
#ifndef	_RTO_HEADER
#define _RTO_HEADER

typedef unsigned char  u_int8;
typedef unsigned short u_int16;
typedef unsigned int   u_int32;
typedef          short int16;

/*
* Current protocol version.
*/
#define RTP_VERSION    2

#define RTP_SEQ_MOD (1<<16)
#define RTP_MAX_SDES 255      /* maximum text length for SDES */

typedef enum {
		RTCP_SR   = 200,
		RTCP_RR   = 201,
		RTCP_SDES = 202,
		RTCP_BYE  = 203,
		RTCP_APP  = 204
} rtcp_type_t;


typedef enum {
	RTCP_SDES_END   = 0,
		RTCP_SDES_CNAME = 1,
		RTCP_SDES_NAME  = 2,
		RTCP_SDES_EMAIL = 3,
		RTCP_SDES_PHONE = 4,
		RTCP_SDES_LOC   = 5,
		RTCP_SDES_TOOL  = 6,
		RTCP_SDES_NOTE  = 7,
		RTCP_SDES_PRIV  = 8
} rtcp_sdes_type_t;

/*
* RTP data header
*/
typedef struct {
	unsigned int version:2;   /* protocol version */
	unsigned int p:1;         /* padding flag */
	unsigned int x:1;         /* header extension flag */
	unsigned int cc:4;        /* CSRC count */
	unsigned int m:1;         /* marker bit */
	unsigned int pt:7;        /* payload type */
	unsigned int seq:16;      /* sequence number */
	u_int32 ts;               /* timestamp */
	u_int32 ssrc;             /* synchronization source */
	u_int32 csrc[1];          /* optional CSRC list */
} rtp_hdr_t;

#endif
