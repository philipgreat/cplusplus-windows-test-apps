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




typedef struct tsd_hdr //����TCPα�ײ� 
{ 
	unsigned long saddr; //Դ��ַ 
	unsigned long daddr; //Ŀ�ĵ�ַ 
	char mbz; 
	char ptcl; //Э������ 
	unsigned short tcpl; //TCP���� 
}PSDHEADER; 

typedef struct tcp_hdr //����TCP�ײ� 
{ 
	USHORT th_sport; //16λԴ�˿� 
	USHORT th_dport; //16λĿ�Ķ˿� 
	unsigned int th_seq; //32λ���к� 
	unsigned int th_ack; //32λȷ�Ϻ� 
	unsigned char th_lenres; //4λ�ײ�����/6λ������ 
	unsigned char th_flag; //6λ��־λ 
	USHORT th_win; //16λ���ڴ�С 
	USHORT th_sum; //16λУ��� 
	USHORT th_urp; //16λ��������ƫ���� 
}TCPHEADER; 


#define STATUS_FAILED 0xFFFF //���󷵻�ֵ
typedef struct _PROTN2T
{ 
	int  proto ;
	char *pprototext ;
}PROTN2T ; 
#define PROTO_NUM  11 

typedef struct _iphdr //����IP�ײ� 

{ 
	unsigned char h_verlen; //4λ�ײ�����,4λIP�汾�� 
	unsigned char tos; //8λ��������TOS 
	unsigned short total_len; //16λ�ܳ��ȣ��ֽڣ� 
	unsigned short ident; //16λ��ʶ 
	unsigned short frag_and_flags; //3λ��־λ 
	unsigned char ttl; //8λ����ʱ�� TTL 
	unsigned char proto; //8λЭ�� (TCP, UDP ������) 
	unsigned short checksum; //16λIP�ײ�У��� 
	unsigned int sourceIP; //32λԴIP��ַ 
	unsigned int destIP; //32λĿ��IP��ַ 
	
}IP_HEADER; 




typedef struct _tcphdr //����TCP�ײ� 
{ 
	
	USHORT th_sport; //16λԴ�˿� 
	USHORT th_dport; //16λĿ�Ķ˿� 
	unsigned int th_seq; //32λ���к� 
	unsigned int th_ack; //32λȷ�Ϻ� 
	unsigned char th_lenres; //4λ�ײ�����/6λ������ 
	unsigned char th_flag; //6λ��־λ 
	USHORT th_win; //16λ���ڴ�С 
	USHORT th_sum; //16λУ��� 
	USHORT th_urp; //16λ��������ƫ���� 

}TCP_HEADER; 

typedef struct _udphdr //����UDP�ײ� 
{ 
	unsigned short uh_sport; 
	unsigned short uh_dport; 
	unsigned short uh_len;
	unsigned short uh_sum; 
} UDP_HEADER;  

typedef struct _icmphdr //����ICMP�ײ� 
{ 
	BYTE i_type; //8λ���� 
	BYTE i_code; //8λ���� 
	USHORT i_cksum; //16λУ��� 
	USHORT i_id; //ʶ��ţ�һ���ý��̺���Ϊʶ��ţ� 
	USHORT i_seq; //�������к� 
	ULONG timestamp; //ʱ��� 
}ICMP_HEADER; 


#endif