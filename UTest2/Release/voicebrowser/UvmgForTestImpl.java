package com.channelsoft.voicebrowser;

import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

import Ice.IntHolder;

public class UvmgForTestImpl implements IVoiceGateway {

	private static final int Ver_Dialogic_1_0 = 0x1010;// Dialogic

	private static final int Ver_NMS_1_0 = 0x2010;// NMS

	private static final int Ver_UVMG_1_0 = 0x3010;// UVMG

	private static final int GATEWAY_SUCCESS = 0x0;// 操作成功

	private static final int ERR_GENERALERROR = 0x100;// 操作失败

	private static final int ERR_INVALID_RESID = 0x101;// 无效的资源ID

	private static final int ERR_INVALID_FILE = 0x102;// 无效的文件名

	private static final int ERR_UNSUPPORTED_STATE = 0x103;// 资源所在状态不支持当前操作

	private static final int ERR_RES_ALREADYOPEN = 0x104;// 资源已经被打开

	private static final int ERR_NOCALL_STATE = 0x105;// 资源上不存在呼叫

	private static final int ERR_EXISTCALL_STATE = 0x106;// 资源上已存在呼叫

	private static final int ERR_FATALERROR = 0x107;// 严重操作失败，需要上层重置通道

	private static final int ERR_INVLAIDARG = 0x108;// 外呼时传入参数错误

	private static final int ERR_REMOTE_DISCONNECT = 0x109;// 永于，同步的媒体操作接口，执行媒体操作时远端挂断

	private static final int ERR_TTS_CONVERT = 0x150;// TTS转换失败

	private static final int ERR_ASR_EXCEPTION = 0x151;// ASR异常

	private static final int SHORT_STRING_LENGTH = 16;

	private static final int LONG_STRING_LENGTH = 128;

	private static final int MAX_BREAK_KEYS = 5;

	private static final int SG_INCOMINGCALL = 0x2001;// 入呼叫到达，如果采用globalcall协议，EventData字段存储呼叫的CRN号码

	private static final int SG_CALLCONNECTED = 0x2003;// 呼叫建立，如果是系统发起的外呼，则EventData字段存储呼叫建立时，对方设备的情况

	private static final int SG_CALLDISCONNECTED = 0x2004;// 对方挂机

	private static final int SG_CALLRELEASED = 0x2005;// 呼叫清除

	private static final int SG_TASKFAIL = 0x2006;// 任务执行失败,暂不使用

	private static final int SG_FATALERROR = 0x2007;// 发生严重错误,可能需要重新初始化设备资源,暂不使用

	private static final int SG_DAILED = 0x2008;// 呼叫发起成功

	private static final int SG_LINE_START = 0x2009;// 资源开始工作

	private static final int SG_LINE_DOWN = 0x2010;// 资源停止工作

	private static final int SG_LINE_IN_SERVICE = 0x2011;// 话路通道因为网络故障，暂不可用

	private static final int SG_LINE_OUT_SERVICE = 0x2012;// 话路通道网络故障恢复，变为可用

	private static final int SG_CALLALERTING = 0x2013;// 外呼成功,被叫已收到连接请求

	private static final int SG_NO_ENOUGH_DIAL_RES = 0x2020;// 没有足够的外部资源

	private static final int REASON_DESTBUSY = 0x51;// 被叫忙

	private static final int REASON_DESTNOANSWER = 0x52;// 被叫未应答

	private static final int REASON_DESTUNKNOWN = 0x53;// 被叫状态未知

	private static final int REASON_DESTFAXTONE = 0x54;// 被叫为传真设备

	private static final int REASON_DESTNOTFAX = 0x55;// 被叫为非传真设备

	private static final int REASON_INVLAIDNUM = 0x56;// 被叫号码非法

	private static final int REASON_VOICE_DETECTED = 0x57;// 检测到语音应答

	private static final int REASON_POWER_OFF = 0x5a;

	private static final int REASON_OUT_AREA = 0x2b;

	private static final int REASON_NUMBER_NULL = 0x2c;

	private static final int REASON_REFUSE = 0x2d;

	private static final int MG_SUCCESS = 0x1001;// 异步操作成功

	private static final int MG_FAIL = 0x1002;// 异步操作失败

	private static final int MG_TDX_PLAY = 0x1004;// 播放结束

	private static final int MG_TDX_RECORD = 0x1005;// 录音结束

	private static final int MG_TDX_GETDIGIT = 0x1006;// 收键结束

	private static final int MG_TFX_SEND = 0x1007;// 传真发送结束

	private static final int MG_TFX_RECV = 0x10008;// 传真接受结束

	private static final int MG_TFX_FAIL = 0x10009;// 传真操作失败

	private static final int MG_TDX_ASR = 0x10050;// 语音识别完成

	private static final int MGREASON_TM_EOD = 0x01;// 文件播放操作结束

	private static final int MGREASON_TM_DIGIT = 0x02;// 收到指定键

	private static final int MGREASON_TM_MAXDTMF = 0x03;// 收到的DTMF数达到指定最大数

	private static final int MGREASON_TM_MAXTIME = 0x04;// 操作时间达到指定时长

	private static final int MGREASON_TM_DISCONNECT = 0x05;// 操作过程中设备挂机

	private static final int MGREASON_TM_USRSTOP = 0x06;// 操作被外界终止

	private static final int MGREASON_TM_INVALIDFILE = 0x07;// 无效的文件（例如文件格式错误）

	private static final int MGREASON_ASR_RECGNIZED = 0x50;// 识别完成，有结果返回

	private static final int MGREASON_ASR_NO_SPEECH = 0x51;// 放完提示音后用户长时间不说话

	private static final int MGREASON_ASR_TOOMUCH_SPEECH = 0x52;// 用户说的太多

	private static final int MGREASON_ASR_REC_SLOW = 0x53;// 识别超时

	private static final int MGREASON_ASR_SPEECH_TOO_EARLY = 0x54;// 用户说的太早了，放提示音之前就开始说话了

	private static final int MGREASON_ASR_REJECT = 0x55;// 没有超过设定的分数，识别被拒绝

	private static final int MGREASON_ASR_EXCEPTION = 0x56;// 有其他异常发生

	private static final int MGREASON_ASR_MEMRECORD = 0x57;// 内存录音失败

	private static final int MGREASON_ARS_PLAYPROMPT = 0x58;// 放提示音失败

	private static final int MGREASON_ARS_ABORT = 0x59;// 识别被取消

	private static final int DM3CARD = 0x1;// DM3

	private static final int SPWARECARD = 0x2;// springware卡

	private static final int SGST_NULL = 0x00;// 呼叫处于NULL状态，已经被释放

	private static final int SGST_OTHERS = 0x01;// 呼叫处于其他状态，未被释放

	private static final int IOST_IDLE = 0x01;

	private static final int IOST_BUSY = 0x02;

	private static Map<Integer, String> eventmap;

	public static final String PROXY_CONFIG_ITEM = "uvmg.proxy";

	public static final String VOICE_ROOT_CONFIG = "voice.root";

	private static Map<Integer, String> reasonmap;
	static {
		initEventMap();
		initReasonMap();
	}

	private static void initEventMap() {
		if (eventmap == null) {

			eventmap = new HashMap<Integer, String>();

			eventmap.put(new Integer(SG_INCOMINGCALL), "入呼叫到达");
			eventmap.put(new Integer(SG_CALLCONNECTED), "呼叫建立");
			eventmap.put(new Integer(SG_CALLDISCONNECTED), "对方挂机");
			eventmap.put(new Integer(SG_CALLRELEASED), "呼叫清除");
			eventmap.put(new Integer(SG_TASKFAIL), "任务执行失败,暂不使用");
			eventmap.put(new Integer(SG_FATALERROR),
					"发生严重错误,可能需要重新初始化设备资源,暂不使用");

			eventmap.put(new Integer(SG_DAILED), "呼叫发起成功");
			eventmap.put(new Integer(SG_LINE_START), "资源开始工作");
			eventmap.put(new Integer(SG_LINE_DOWN), "资源停止工作");
			eventmap.put(new Integer(SG_LINE_IN_SERVICE), "话路通道因为网络故障，暂不可用");
			eventmap.put(new Integer(SG_LINE_OUT_SERVICE), "话路通道网络故障恢复，变为可用");

			eventmap.put(new Integer(SG_CALLALERTING), "外呼成功,被叫已收到连接请求");

			eventmap.put(new Integer(SG_NO_ENOUGH_DIAL_RES), "没有足够的外部资源");
			eventmap.put(new Integer(MG_SUCCESS), "异步操作成功");
			eventmap.put(new Integer(MG_FAIL), "异步操作失败");
			eventmap.put(new Integer(MG_TDX_PLAY), "播放结束");
			eventmap.put(new Integer(MG_TDX_RECORD), "录音结束");
			eventmap.put(new Integer(MG_TDX_GETDIGIT), "收键结束");
			eventmap.put(new Integer(MG_TFX_SEND), "传真发送结束");
			eventmap.put(new Integer(MG_TFX_RECV), "传真接受结束");
			eventmap.put(new Integer(MG_TFX_FAIL), "传真操作失败");

			eventmap.put(new Integer(MG_TDX_ASR), "语音识别完成");
			eventmap.put(new Integer(DM3CARD), "DM3");
			eventmap.put(new Integer(SPWARECARD), "springware卡");
		}

	}

	private static void initReasonMap() {
		if (reasonmap == null) {

			reasonmap = new HashMap<Integer, String>();

			reasonmap.put(new Integer(Ver_Dialogic_1_0), "Dialogic 1.0");
			reasonmap.put(new Integer(Ver_NMS_1_0), "NMS1.0");
			reasonmap.put(new Integer(Ver_UVMG_1_0), "UVMG1.0");
			reasonmap.put(new Integer(GATEWAY_SUCCESS), "操作成功");
			reasonmap.put(new Integer(ERR_GENERALERROR), "操作失败");
			reasonmap.put(new Integer(ERR_INVALID_RESID), "无效的资源ID");
			reasonmap.put(new Integer(ERR_INVALID_FILE), "无效的文件名");
			reasonmap.put(new Integer(ERR_UNSUPPORTED_STATE), "资源所在状态不支持当前操作");
			reasonmap.put(new Integer(ERR_RES_ALREADYOPEN), "资源已经被打开");
			reasonmap.put(new Integer(ERR_NOCALL_STATE), "资源上不存在呼叫");
			reasonmap.put(new Integer(ERR_EXISTCALL_STATE), "资源上已存在呼叫");
			reasonmap.put(new Integer(ERR_FATALERROR), "严重操作失败，需要上层重置通道");
			reasonmap.put(new Integer(ERR_INVLAIDARG), "外呼时传入参数错误");
			reasonmap.put(new Integer(ERR_REMOTE_DISCONNECT),
					"永于，同步的媒体操作接口，执行媒体操作时远端挂断");
			reasonmap.put(new Integer(ERR_TTS_CONVERT), "TTS转换失败");
			reasonmap.put(new Integer(ERR_ASR_EXCEPTION), "ASR异常");
			reasonmap.put(new Integer(SHORT_STRING_LENGTH), "");
			reasonmap.put(new Integer(LONG_STRING_LENGTH), "");
			reasonmap.put(new Integer(MAX_BREAK_KEYS), "");

			// reasonmap.put(new Integer(EventData),"");

			reasonmap.put(new Integer(REASON_DESTBUSY), "被叫忙");
			reasonmap.put(new Integer(REASON_DESTNOANSWER), "被叫未应答");
			reasonmap.put(new Integer(REASON_DESTUNKNOWN), "被叫状态未知");
			reasonmap.put(new Integer(REASON_DESTFAXTONE), "被叫为传真设备");
			reasonmap.put(new Integer(REASON_DESTNOTFAX), "被叫为非传真设备");
			reasonmap.put(new Integer(REASON_INVLAIDNUM), "被叫号码非法");
			reasonmap.put(new Integer(REASON_VOICE_DETECTED), "检测到语音应答");
			reasonmap.put(new Integer(REASON_POWER_OFF), "用户关机");
			reasonmap.put(new Integer(REASON_OUT_AREA), "用户不在服务区");
			reasonmap.put(new Integer(REASON_NUMBER_NULL), "号码是空号");
			reasonmap.put(new Integer(REASON_REFUSE), "用户拒接电话");

			reasonmap.put(new Integer(MGREASON_TM_EOD), "文件播放操作结束");
			reasonmap.put(new Integer(MGREASON_TM_DIGIT), "收到指定键");
			reasonmap.put(new Integer(MGREASON_TM_MAXDTMF), "收到的DTMF数达到指定最大数");
			reasonmap.put(new Integer(MGREASON_TM_MAXTIME), "操作时间达到指定时长");
			reasonmap.put(new Integer(MGREASON_TM_DISCONNECT), "操作过程中设备挂机");
			reasonmap.put(new Integer(MGREASON_TM_USRSTOP), "操作被外界终止");
			reasonmap.put(new Integer(MGREASON_TM_INVALIDFILE),
					"无效的文件（例如文件格式错误）");

			reasonmap.put(new Integer(MGREASON_ASR_RECGNIZED), "识别完成，有结果返回");
			reasonmap
					.put(new Integer(MGREASON_ASR_NO_SPEECH), "放完提示音后用户长时间不说话");
			reasonmap.put(new Integer(MGREASON_ASR_TOOMUCH_SPEECH), "用户说的太多");
			reasonmap.put(new Integer(MGREASON_ASR_REC_SLOW), "识别超时");
			reasonmap.put(new Integer(MGREASON_ASR_SPEECH_TOO_EARLY),
					"用户说的太早了，放提示音之前就开始说话了");
			reasonmap.put(new Integer(MGREASON_ASR_REJECT), "没有超过设定的分数，识别被拒绝");
			reasonmap.put(new Integer(MGREASON_ASR_EXCEPTION), "有其他异常发生");
			reasonmap.put(new Integer(MGREASON_ASR_MEMRECORD), "内存录音失败");
			reasonmap.put(new Integer(MGREASON_ARS_PLAYPROMPT), "放提示音失败");
			reasonmap.put(new Integer(MGREASON_ARS_ABORT), "识别被取消");
			reasonmap.put(new Integer(DM3CARD), "DM3");
			reasonmap.put(new Integer(SPWARECARD), "springware卡");
			reasonmap.put(new Integer(SGST_NULL), "呼叫处于NULL状态，已经被释放");
			reasonmap.put(new Integer(SGST_OTHERS), "呼叫处于其他状态，未被释放");
			reasonmap.put(new Integer(IOST_IDLE), "IO闲置");
			reasonmap.put(new Integer(IOST_BUSY), "IO忙");
		}

	}

	private enum CALLSTATES {
		CALL_IDLE, CALL_OFFERED, CALL_CONNECTED, CALL_DIALING, CALL_DISCONNECTED, CALL_ACCEPTED, CALL_DISCONNECTING,
	};

	// 设备所处的媒体操作状态
	private enum MEDIAPROCEEDING {
		PLAYING, RECORDING, FAXPROCEEDING, DTMFSENDING, DIGITSGETTING, MEDIAIDLE, BUFPLAYING, STOPPINGIO
	};

	// 中继组类型定义
	private enum TRUNKTYPE {
		TKINBOUND, // 入
		TKOUTBOUND, // 出
		TKBOTH
		// 双向
	};

	private enum PTCOLTYPE {
		PANAPI, PICAPI, PSIU, PPCCS6, PISDN, PUNKNOWN
	};

	private static final int RM_VOX = 0x01;

	private static final int RM_LSI = 0x02;

	private static final int RM_DTI = 0x03;

	private static final int RM_FAX = 0x04;

	private static final int RM_FULLDUP = 0x00;

	private static final int RM_HALFDUP = 0x01;

	private static final int RM_CCR_GroupID = 0;// CCR组的起始ID

	private static final int RM_SPR_GroupID = 3000;// SPR组的起始ID

	private static final int RM_CPR_GroupID = 6000;// CPR组的起始ID

	private static final int TTS_TYPE_TEXT_BUF_TO_AUDIO_BUF = 1;// 把文本内存转换为语音内存播放

	private static final int TTS_TYPE_TEXT_FILE_TO_AUDIO_BUF = 2;// 把文本文件转换为语音内存播放

	private static final int TTS_TYPE_TEXT_BUF_TO_AUDIO_FILE = 3;// 把文本内存转换为语音文件后再播放

	private static final int TTS_TYPE_TEXT_FILE_TO_AUDIO_FILE = 4;// 把文本文件转换为语音文件后再播放

	private static final int TTS_VOICE_LIB_WOMAN = 1;// 女声普通话音库

	private static final int TTS_VOICE_LIB_MAN = 2;// 男声普通话音库

	private static final int TTS_VOICE_LIB_WOMAN_CANTONESE = 3;// 女声广东话音库

	private static final int TTS_VOICE_LIB_MAN_CANTONESE = 4;// 男声广东话音库

	private static final int TTS_VOICE_LIB_WOMAN_ENGLISH = 5;// 女声英语话音库

	private static final int TTS_VOICE_LIB_MAN_ENGLISH = 6;// 男声英语话音库

	private static final int ASR_GRAMMAR_COMPILED = 1;// 语法文件经过编译

	private static final int ASR_GRAMMAR_UNCOMPILED = 2;// 语法文件未经过编译

	private static final int UVMG_DOWN = 123234455;// 语法文件未经过编译

	private VoiceEventQueue sgEventQueue;
	private VoiceEventQueue mgEventQueue;
	private int callid;
	public  UvmgForTestImpl()
	{
		sgEventQueue=new VoiceEventQueue();
		mgEventQueue=new VoiceEventQueue();
		callid++;
	}
	public int answerCall(int resourceId, int callId) {		
		return 0;
	}

	public int blindMakeCall(IntHolder resourceId, IntHolder callId,
			String src, String dest, int timeout) {
		callid++;
		VoiceBrowserEvent event = new VoiceBrowserEvent();
		event.setSource("sg");
		event.setReasonId(0);
		event.setEventId(SG_CALLCONNECTED);
		event.setCallId(callid);
		event.setResourceId(callid%500);
		sgEventQueue.addEvent(event);
		resourceId.value=callid%500;
		callId.value=callid;
		
		return 0;
	}

	public int clearDtmfBuffer(int resourceId, int callId) {
		
		return 0;
	}

	public int getDTMF(int resourceId, int callId, int nKeyCount,
			String szInteruptKeys, int nMax1stkeyTime, int nTimeBetweenKey) {
		VoiceBrowserEvent event = new VoiceBrowserEvent();
		event.setSource("mg");
		event.setReasonId(MGREASON_TM_MAXDTMF);
		event.setEventId(MG_TDX_GETDIGIT);
		event.setCallId(callId);
		event.setResourceId(resourceId);
		event.setEventData("1");
		mgEventQueue.addEvent(event);
		return 0;
	}

	public String getFatalMessage() {
		
		return null;
	}

	public VoiceBrowserEvent getMediaEvent(int i) {
		try {
			return this.mgEventQueue.getEvent(10);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			return null;
		}
	}

	public int getResourceCount() {
		
		return 0;
	}

	public String getResourceId(int index) {
		
		return null;
	}

	public int getResourceType(int index) {
		
		return 0;
	}

	public VoiceBrowserEvent getSignalEvent(int i) {
		try {
			return this.sgEventQueue.getEvent(10);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			return null;
		}

	}

	public boolean initialize(Properties config) {
		
		return false;
	}

	public int playFile(int resourceId, int callId, String filePath,
			String interruptKeys, int samplingRate) {
		VoiceBrowserEvent event = new VoiceBrowserEvent();
		event.setSource("mg");
		event.setEventId(MG_TDX_PLAY);
		event.setReasonId(MGREASON_TM_EOD);		
		event.setCallId(callId);
		event.setResourceId(resourceId);
		mgEventQueue.addEvent(event);
		return 0;
	}

	public int playTTS(int resourceId, int callId, String text) {
		
		return 0;
	}

	public int receiveDtmf(int resourceId, int callId) {
		VoiceBrowserEvent event = new VoiceBrowserEvent();
		event.setSource("mg");
		event.setEventId(MG_TDX_GETDIGIT);
		event.setReasonId(MGREASON_TM_MAXDTMF);
		event.setCallId(callId);
		event.setResourceId(resourceId);
		event.setEventData("1");
		mgEventQueue.addEvent(event);
		return 0;
	}

	public void recordToFile(int resourceId, int callId, String url,
			long maxLength) {
	}

	public boolean reinitialize() {
		
		return false;
	}

	public int releaseCall(int resourceId, int callId) {
		VoiceBrowserEvent event = new VoiceBrowserEvent();
		event.setSource("sg");
		event.setEventId(SG_CALLDISCONNECTED);
		event.setReasonId(0);
		event.setCallId(callId);
		event.setResourceId(resourceId);
		mgEventQueue.addEvent(event);
		return 0;
	}

	public int stopIO(int resourceId, int callId) {
		
		return 0;
	}

}
