package com.channelsoft.voicebrowser;

import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

import Ice.IntHolder;

public class UvmgForTestImpl implements IVoiceGateway {

	private static final int Ver_Dialogic_1_0 = 0x1010;// Dialogic

	private static final int Ver_NMS_1_0 = 0x2010;// NMS

	private static final int Ver_UVMG_1_0 = 0x3010;// UVMG

	private static final int GATEWAY_SUCCESS = 0x0;// �����ɹ�

	private static final int ERR_GENERALERROR = 0x100;// ����ʧ��

	private static final int ERR_INVALID_RESID = 0x101;// ��Ч����ԴID

	private static final int ERR_INVALID_FILE = 0x102;// ��Ч���ļ���

	private static final int ERR_UNSUPPORTED_STATE = 0x103;// ��Դ����״̬��֧�ֵ�ǰ����

	private static final int ERR_RES_ALREADYOPEN = 0x104;// ��Դ�Ѿ�����

	private static final int ERR_NOCALL_STATE = 0x105;// ��Դ�ϲ����ں���

	private static final int ERR_EXISTCALL_STATE = 0x106;// ��Դ���Ѵ��ں���

	private static final int ERR_FATALERROR = 0x107;// ���ز���ʧ�ܣ���Ҫ�ϲ�����ͨ��

	private static final int ERR_INVLAIDARG = 0x108;// ���ʱ�����������

	private static final int ERR_REMOTE_DISCONNECT = 0x109;// ���ڣ�ͬ����ý������ӿڣ�ִ��ý�����ʱԶ�˹Ҷ�

	private static final int ERR_TTS_CONVERT = 0x150;// TTSת��ʧ��

	private static final int ERR_ASR_EXCEPTION = 0x151;// ASR�쳣

	private static final int SHORT_STRING_LENGTH = 16;

	private static final int LONG_STRING_LENGTH = 128;

	private static final int MAX_BREAK_KEYS = 5;

	private static final int SG_INCOMINGCALL = 0x2001;// ����е���������globalcallЭ�飬EventData�ֶδ洢���е�CRN����

	private static final int SG_CALLCONNECTED = 0x2003;// ���н����������ϵͳ������������EventData�ֶδ洢���н���ʱ���Է��豸�����

	private static final int SG_CALLDISCONNECTED = 0x2004;// �Է��һ�

	private static final int SG_CALLRELEASED = 0x2005;// �������

	private static final int SG_TASKFAIL = 0x2006;// ����ִ��ʧ��,�ݲ�ʹ��

	private static final int SG_FATALERROR = 0x2007;// �������ش���,������Ҫ���³�ʼ���豸��Դ,�ݲ�ʹ��

	private static final int SG_DAILED = 0x2008;// ���з���ɹ�

	private static final int SG_LINE_START = 0x2009;// ��Դ��ʼ����

	private static final int SG_LINE_DOWN = 0x2010;// ��Դֹͣ����

	private static final int SG_LINE_IN_SERVICE = 0x2011;// ��·ͨ����Ϊ������ϣ��ݲ�����

	private static final int SG_LINE_OUT_SERVICE = 0x2012;// ��·ͨ��������ϻָ�����Ϊ����

	private static final int SG_CALLALERTING = 0x2013;// ����ɹ�,�������յ���������

	private static final int SG_NO_ENOUGH_DIAL_RES = 0x2020;// û���㹻���ⲿ��Դ

	private static final int REASON_DESTBUSY = 0x51;// ����æ

	private static final int REASON_DESTNOANSWER = 0x52;// ����δӦ��

	private static final int REASON_DESTUNKNOWN = 0x53;// ����״̬δ֪

	private static final int REASON_DESTFAXTONE = 0x54;// ����Ϊ�����豸

	private static final int REASON_DESTNOTFAX = 0x55;// ����Ϊ�Ǵ����豸

	private static final int REASON_INVLAIDNUM = 0x56;// ���к���Ƿ�

	private static final int REASON_VOICE_DETECTED = 0x57;// ��⵽����Ӧ��

	private static final int REASON_POWER_OFF = 0x5a;

	private static final int REASON_OUT_AREA = 0x2b;

	private static final int REASON_NUMBER_NULL = 0x2c;

	private static final int REASON_REFUSE = 0x2d;

	private static final int MG_SUCCESS = 0x1001;// �첽�����ɹ�

	private static final int MG_FAIL = 0x1002;// �첽����ʧ��

	private static final int MG_TDX_PLAY = 0x1004;// ���Ž���

	private static final int MG_TDX_RECORD = 0x1005;// ¼������

	private static final int MG_TDX_GETDIGIT = 0x1006;// �ռ�����

	private static final int MG_TFX_SEND = 0x1007;// ���淢�ͽ���

	private static final int MG_TFX_RECV = 0x10008;// ������ܽ���

	private static final int MG_TFX_FAIL = 0x10009;// �������ʧ��

	private static final int MG_TDX_ASR = 0x10050;// ����ʶ�����

	private static final int MGREASON_TM_EOD = 0x01;// �ļ����Ų�������

	private static final int MGREASON_TM_DIGIT = 0x02;// �յ�ָ����

	private static final int MGREASON_TM_MAXDTMF = 0x03;// �յ���DTMF���ﵽָ�������

	private static final int MGREASON_TM_MAXTIME = 0x04;// ����ʱ��ﵽָ��ʱ��

	private static final int MGREASON_TM_DISCONNECT = 0x05;// �����������豸�һ�

	private static final int MGREASON_TM_USRSTOP = 0x06;// �����������ֹ

	private static final int MGREASON_TM_INVALIDFILE = 0x07;// ��Ч���ļ��������ļ���ʽ����

	private static final int MGREASON_ASR_RECGNIZED = 0x50;// ʶ����ɣ��н������

	private static final int MGREASON_ASR_NO_SPEECH = 0x51;// ������ʾ�����û���ʱ�䲻˵��

	private static final int MGREASON_ASR_TOOMUCH_SPEECH = 0x52;// �û�˵��̫��

	private static final int MGREASON_ASR_REC_SLOW = 0x53;// ʶ��ʱ

	private static final int MGREASON_ASR_SPEECH_TOO_EARLY = 0x54;// �û�˵��̫���ˣ�����ʾ��֮ǰ�Ϳ�ʼ˵����

	private static final int MGREASON_ASR_REJECT = 0x55;// û�г����趨�ķ�����ʶ�𱻾ܾ�

	private static final int MGREASON_ASR_EXCEPTION = 0x56;// �������쳣����

	private static final int MGREASON_ASR_MEMRECORD = 0x57;// �ڴ�¼��ʧ��

	private static final int MGREASON_ARS_PLAYPROMPT = 0x58;// ����ʾ��ʧ��

	private static final int MGREASON_ARS_ABORT = 0x59;// ʶ��ȡ��

	private static final int DM3CARD = 0x1;// DM3

	private static final int SPWARECARD = 0x2;// springware��

	private static final int SGST_NULL = 0x00;// ���д���NULL״̬���Ѿ����ͷ�

	private static final int SGST_OTHERS = 0x01;// ���д�������״̬��δ���ͷ�

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

			eventmap.put(new Integer(SG_INCOMINGCALL), "����е���");
			eventmap.put(new Integer(SG_CALLCONNECTED), "���н���");
			eventmap.put(new Integer(SG_CALLDISCONNECTED), "�Է��һ�");
			eventmap.put(new Integer(SG_CALLRELEASED), "�������");
			eventmap.put(new Integer(SG_TASKFAIL), "����ִ��ʧ��,�ݲ�ʹ��");
			eventmap.put(new Integer(SG_FATALERROR),
					"�������ش���,������Ҫ���³�ʼ���豸��Դ,�ݲ�ʹ��");

			eventmap.put(new Integer(SG_DAILED), "���з���ɹ�");
			eventmap.put(new Integer(SG_LINE_START), "��Դ��ʼ����");
			eventmap.put(new Integer(SG_LINE_DOWN), "��Դֹͣ����");
			eventmap.put(new Integer(SG_LINE_IN_SERVICE), "��·ͨ����Ϊ������ϣ��ݲ�����");
			eventmap.put(new Integer(SG_LINE_OUT_SERVICE), "��·ͨ��������ϻָ�����Ϊ����");

			eventmap.put(new Integer(SG_CALLALERTING), "����ɹ�,�������յ���������");

			eventmap.put(new Integer(SG_NO_ENOUGH_DIAL_RES), "û���㹻���ⲿ��Դ");
			eventmap.put(new Integer(MG_SUCCESS), "�첽�����ɹ�");
			eventmap.put(new Integer(MG_FAIL), "�첽����ʧ��");
			eventmap.put(new Integer(MG_TDX_PLAY), "���Ž���");
			eventmap.put(new Integer(MG_TDX_RECORD), "¼������");
			eventmap.put(new Integer(MG_TDX_GETDIGIT), "�ռ�����");
			eventmap.put(new Integer(MG_TFX_SEND), "���淢�ͽ���");
			eventmap.put(new Integer(MG_TFX_RECV), "������ܽ���");
			eventmap.put(new Integer(MG_TFX_FAIL), "�������ʧ��");

			eventmap.put(new Integer(MG_TDX_ASR), "����ʶ�����");
			eventmap.put(new Integer(DM3CARD), "DM3");
			eventmap.put(new Integer(SPWARECARD), "springware��");
		}

	}

	private static void initReasonMap() {
		if (reasonmap == null) {

			reasonmap = new HashMap<Integer, String>();

			reasonmap.put(new Integer(Ver_Dialogic_1_0), "Dialogic 1.0");
			reasonmap.put(new Integer(Ver_NMS_1_0), "NMS1.0");
			reasonmap.put(new Integer(Ver_UVMG_1_0), "UVMG1.0");
			reasonmap.put(new Integer(GATEWAY_SUCCESS), "�����ɹ�");
			reasonmap.put(new Integer(ERR_GENERALERROR), "����ʧ��");
			reasonmap.put(new Integer(ERR_INVALID_RESID), "��Ч����ԴID");
			reasonmap.put(new Integer(ERR_INVALID_FILE), "��Ч���ļ���");
			reasonmap.put(new Integer(ERR_UNSUPPORTED_STATE), "��Դ����״̬��֧�ֵ�ǰ����");
			reasonmap.put(new Integer(ERR_RES_ALREADYOPEN), "��Դ�Ѿ�����");
			reasonmap.put(new Integer(ERR_NOCALL_STATE), "��Դ�ϲ����ں���");
			reasonmap.put(new Integer(ERR_EXISTCALL_STATE), "��Դ���Ѵ��ں���");
			reasonmap.put(new Integer(ERR_FATALERROR), "���ز���ʧ�ܣ���Ҫ�ϲ�����ͨ��");
			reasonmap.put(new Integer(ERR_INVLAIDARG), "���ʱ�����������");
			reasonmap.put(new Integer(ERR_REMOTE_DISCONNECT),
					"���ڣ�ͬ����ý������ӿڣ�ִ��ý�����ʱԶ�˹Ҷ�");
			reasonmap.put(new Integer(ERR_TTS_CONVERT), "TTSת��ʧ��");
			reasonmap.put(new Integer(ERR_ASR_EXCEPTION), "ASR�쳣");
			reasonmap.put(new Integer(SHORT_STRING_LENGTH), "");
			reasonmap.put(new Integer(LONG_STRING_LENGTH), "");
			reasonmap.put(new Integer(MAX_BREAK_KEYS), "");

			// reasonmap.put(new Integer(EventData),"");

			reasonmap.put(new Integer(REASON_DESTBUSY), "����æ");
			reasonmap.put(new Integer(REASON_DESTNOANSWER), "����δӦ��");
			reasonmap.put(new Integer(REASON_DESTUNKNOWN), "����״̬δ֪");
			reasonmap.put(new Integer(REASON_DESTFAXTONE), "����Ϊ�����豸");
			reasonmap.put(new Integer(REASON_DESTNOTFAX), "����Ϊ�Ǵ����豸");
			reasonmap.put(new Integer(REASON_INVLAIDNUM), "���к���Ƿ�");
			reasonmap.put(new Integer(REASON_VOICE_DETECTED), "��⵽����Ӧ��");
			reasonmap.put(new Integer(REASON_POWER_OFF), "�û��ػ�");
			reasonmap.put(new Integer(REASON_OUT_AREA), "�û����ڷ�����");
			reasonmap.put(new Integer(REASON_NUMBER_NULL), "�����ǿպ�");
			reasonmap.put(new Integer(REASON_REFUSE), "�û��ܽӵ绰");

			reasonmap.put(new Integer(MGREASON_TM_EOD), "�ļ����Ų�������");
			reasonmap.put(new Integer(MGREASON_TM_DIGIT), "�յ�ָ����");
			reasonmap.put(new Integer(MGREASON_TM_MAXDTMF), "�յ���DTMF���ﵽָ�������");
			reasonmap.put(new Integer(MGREASON_TM_MAXTIME), "����ʱ��ﵽָ��ʱ��");
			reasonmap.put(new Integer(MGREASON_TM_DISCONNECT), "�����������豸�һ�");
			reasonmap.put(new Integer(MGREASON_TM_USRSTOP), "�����������ֹ");
			reasonmap.put(new Integer(MGREASON_TM_INVALIDFILE),
					"��Ч���ļ��������ļ���ʽ����");

			reasonmap.put(new Integer(MGREASON_ASR_RECGNIZED), "ʶ����ɣ��н������");
			reasonmap
					.put(new Integer(MGREASON_ASR_NO_SPEECH), "������ʾ�����û���ʱ�䲻˵��");
			reasonmap.put(new Integer(MGREASON_ASR_TOOMUCH_SPEECH), "�û�˵��̫��");
			reasonmap.put(new Integer(MGREASON_ASR_REC_SLOW), "ʶ��ʱ");
			reasonmap.put(new Integer(MGREASON_ASR_SPEECH_TOO_EARLY),
					"�û�˵��̫���ˣ�����ʾ��֮ǰ�Ϳ�ʼ˵����");
			reasonmap.put(new Integer(MGREASON_ASR_REJECT), "û�г����趨�ķ�����ʶ�𱻾ܾ�");
			reasonmap.put(new Integer(MGREASON_ASR_EXCEPTION), "�������쳣����");
			reasonmap.put(new Integer(MGREASON_ASR_MEMRECORD), "�ڴ�¼��ʧ��");
			reasonmap.put(new Integer(MGREASON_ARS_PLAYPROMPT), "����ʾ��ʧ��");
			reasonmap.put(new Integer(MGREASON_ARS_ABORT), "ʶ��ȡ��");
			reasonmap.put(new Integer(DM3CARD), "DM3");
			reasonmap.put(new Integer(SPWARECARD), "springware��");
			reasonmap.put(new Integer(SGST_NULL), "���д���NULL״̬���Ѿ����ͷ�");
			reasonmap.put(new Integer(SGST_OTHERS), "���д�������״̬��δ���ͷ�");
			reasonmap.put(new Integer(IOST_IDLE), "IO����");
			reasonmap.put(new Integer(IOST_BUSY), "IOæ");
		}

	}

	private enum CALLSTATES {
		CALL_IDLE, CALL_OFFERED, CALL_CONNECTED, CALL_DIALING, CALL_DISCONNECTED, CALL_ACCEPTED, CALL_DISCONNECTING,
	};

	// �豸������ý�����״̬
	private enum MEDIAPROCEEDING {
		PLAYING, RECORDING, FAXPROCEEDING, DTMFSENDING, DIGITSGETTING, MEDIAIDLE, BUFPLAYING, STOPPINGIO
	};

	// �м������Ͷ���
	private enum TRUNKTYPE {
		TKINBOUND, // ��
		TKOUTBOUND, // ��
		TKBOTH
		// ˫��
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

	private static final int RM_CCR_GroupID = 0;// CCR�����ʼID

	private static final int RM_SPR_GroupID = 3000;// SPR�����ʼID

	private static final int RM_CPR_GroupID = 6000;// CPR�����ʼID

	private static final int TTS_TYPE_TEXT_BUF_TO_AUDIO_BUF = 1;// ���ı��ڴ�ת��Ϊ�����ڴ沥��

	private static final int TTS_TYPE_TEXT_FILE_TO_AUDIO_BUF = 2;// ���ı��ļ�ת��Ϊ�����ڴ沥��

	private static final int TTS_TYPE_TEXT_BUF_TO_AUDIO_FILE = 3;// ���ı��ڴ�ת��Ϊ�����ļ����ٲ���

	private static final int TTS_TYPE_TEXT_FILE_TO_AUDIO_FILE = 4;// ���ı��ļ�ת��Ϊ�����ļ����ٲ���

	private static final int TTS_VOICE_LIB_WOMAN = 1;// Ů����ͨ������

	private static final int TTS_VOICE_LIB_MAN = 2;// ������ͨ������

	private static final int TTS_VOICE_LIB_WOMAN_CANTONESE = 3;// Ů���㶫������

	private static final int TTS_VOICE_LIB_MAN_CANTONESE = 4;// �����㶫������

	private static final int TTS_VOICE_LIB_WOMAN_ENGLISH = 5;// Ů��Ӣ�ﻰ����

	private static final int TTS_VOICE_LIB_MAN_ENGLISH = 6;// ����Ӣ�ﻰ����

	private static final int ASR_GRAMMAR_COMPILED = 1;// �﷨�ļ���������

	private static final int ASR_GRAMMAR_UNCOMPILED = 2;// �﷨�ļ�δ��������

	private static final int UVMG_DOWN = 123234455;// �﷨�ļ�δ��������

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
