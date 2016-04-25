#ifndef TCP_PROTOCAL_HEADER
#define TCP_PROTOCAL_HEADER

#define SIO_RCVALL            _WSAIOW(IOC_VENDOR,1)
#define SIO_RCVALL_MCAST      _WSAIOW(IOC_VENDOR,2)
#define SIO_RCVALL_IGMPMCAST  _WSAIOW(IOC_VENDOR,3)
#define SIO_KEEPALIVE_VALS    _WSAIOW(IOC_VENDOR,4)
#define SIO_ABSORB_RTRALERT   _WSAIOW(IOC_VENDOR,5)
#define SIO_UCAST_IF          _WSAIOW(IOC_VENDOR,6)
#define SIO_LIMIT_BROADCASTS  _WSAIOW(IOC_VENDOR,7)
#define SIO_INDEX_BIND        _WSAIOW(IOC_VENDOR,8)
#define SIO_INDEX_MCASTIF     _WSAIOW(IOC_VENDOR,9)
#define SIO_INDEX_ADD_MCAST   _WSAIOW(IOC_VENDOR,10)
#define SIO_INDEX_DEL_MCAST   _WSAIOW(IOC_VENDOR,11)




typedef struct tsd_hdr //定义TCP伪首部 
{ 
	unsigned long saddr; //源地址 
	unsigned long daddr; //目的地址 
	char mbz; 
	char ptcl; //协议类型 
	unsigned short tcpl; //TCP长度 
}PSDHEADER; 

typedef struct tcp_hdr //定义TCP首部 
{ 
	USHORT th_sport; //16位源端口 
	USHORT th_dport; //16位目的端口 
	unsigned int th_seq; //32位序列号 
	unsigned int th_ack; //32位确认号 
	unsigned char th_lenres; //4位首部长度/6位保留字 
	unsigned char th_flag; //6位标志位 
	USHORT th_win; //16位窗口大小 
	USHORT th_sum; //16位校验和 
	USHORT th_urp; //16位紧急数据偏移量 
}TCPHEADER; 


#define STATUS_FAILED 0xFFFF //错误返回值
typedef struct _PROTN2T
{ 
	int  proto ;
	char *pprototext ;
}PROTN2T ; 
#define PROTO_NUM  11 

typedef struct _iphdr //定义IP首部 

{ 
	unsigned char h_verlen; //4位首部长度,4位IP版本号 
	unsigned char tos; //8位服务类型TOS 
	unsigned short total_len; //16位总长度（字节） 
	unsigned short ident; //16位标识 
	unsigned short frag_and_flags; //3位标志位 
	unsigned char ttl; //8位生存时间 TTL 
	unsigned char proto; //8位协议 (TCP, UDP 或其他) 
	unsigned short checksum; //16位IP首部校验和 
	unsigned int sourceIP; //32位源IP地址 
	unsigned int destIP; //32位目的IP地址 
	
}IP_HEADER; 




typedef struct _tcphdr //定义TCP首部 
{ 
	
	USHORT th_sport; //16位源端口 
	USHORT th_dport; //16位目的端口 
	unsigned int th_seq; //32位序列号 
	unsigned int th_ack; //32位确认号 
	unsigned char th_lenres; //4位首部长度/6位保留字 
	unsigned char th_flag; //6位标志位 
	USHORT th_win; //16位窗口大小 
	USHORT th_sum; //16位校验和 
	USHORT th_urp; //16位紧急数据偏移量 

}TCP_HEADER; 

typedef struct _udphdr //定义UDP首部 
{ 
	unsigned short uh_sport; 
	unsigned short uh_dport; 
	unsigned short uh_len;
	unsigned short uh_sum; 
} UDP_HEADER;  

typedef struct _icmphdr //定义ICMP首部 
{ 
	BYTE i_type; //8位类型 
	BYTE i_code; //8位代码 
	USHORT i_cksum; //16位校验和 
	USHORT i_id; //识别号（一般用进程号作为识别号） 
	USHORT i_seq; //报文序列号 
	ULONG timestamp; //时间戳 
}ICMP_HEADER; 


#endif