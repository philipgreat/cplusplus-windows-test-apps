package com.channelsoft.voicebrowser;


import java.text.Format;
import java.text.SimpleDateFormat;
import java.util.Date;


/**
 * @author qnadmin
 *
 */
public class VoiceBrowserEvent implements ITelephoneSystemEvent{

	private IVoiceGateway 	gateway;
	private int eventId;
	private int reasonId;	
	private int resourceId;
	private int callId;
	private long time;
	private Format formatter;
	private String source;
	private String eventData;
	private VoicePage page;
	
	/**
	 * @return the page
	 */
	public VoicePage getPage() {
		return page;
	}
	/**
	 * @param page the page to set
	 */
	public void setPage(VoicePage page) {
		this.page = page;
	}
	public VoiceBrowserEvent()
	{
		time=System.currentTimeMillis();
		formatter=new SimpleDateFormat("yyyy.MM.dd HH:mm:ss");
	}
	public long getTime()
	{
		return this.time;		
	}
	/**
	 * @return the gateway
	 */
	public IVoiceGateway getGateway() {
		return gateway;
	}
	/**
	 * @param gateway the gateway to set
	 */
	public void setGateway(IVoiceGateway gateway) {
		this.gateway = gateway;
	}
	/**
	 * @return the callId
	 */
	public int getCallId() {
		return callId;
	}
	/**
	 * @param callId the callId to set
	 */
	public void setCallId(int callId) {
		this.callId = callId;
	}
	/**
	 * @return the resourceId
	 */
	public int getResourceId() {
		return resourceId;
	}
	/**
	 * @param resourceId the resourceId to set
	 */
	public void setResourceId(int resourceId) {
		this.resourceId = resourceId;
	}
	
	public boolean isDialedOutSuccess() {		
		return (eventId == SG_CALLALERTING);
	}
	public boolean isDialedOut() {		
		return (eventId == SG_DAILED);
	}
	public boolean hasInboundCall() {		
		return (eventId == SG_INCOMINGCALL);
	}
	public boolean isConnected() {		
		return (eventId == SG_CALLCONNECTED);
	}
	public boolean isDisconnected() {		
		return (eventId == SG_CALLDISCONNECTED);
	}

	public boolean isRecordFileFinished() {		
		return (eventId == SG_CALLCONNECTED);
	}
	public boolean isResourceFinished() {		
		return (eventId == SG_LINE_DOWN);
	}
	public boolean isReleased() {		
		return (SG_CALLRELEASED==eventId) ;
	}
	public boolean isResourceStarted() {		
		return (eventId == SG_LINE_START);
	}
	public boolean isRecordFileFailed() {
		
		return false;
	}
	public boolean isResourceReleased() {		
		return (eventId == SG_LINE_START);
	}
	public boolean isTimer() {
		
		return this.source.equals("timer");
	}
	public void setSource(String sg) {
		
		this.source=sg;
	}
	public String toString()
	{
		Date dt=new Date(this.time);
		String eventExpr=UvmgImplementation.translateEvent(this.eventId);
		String reasonExpr=UvmgImplementation.translateReason(this.reasonId);
		String dateExpr=formatter.format(dt);
		
		return ""+this.source+"@"+dateExpr
		+"{("+this.resourceId+","+this.callId+")"
		+eventExpr+", "
		+reasonExpr+"}";  
		
	}
	public void setEventId(int eventID) {
		
		this.eventId=eventID;
	}
	/**
	 * @return the reasonId
	 */
	public int getReasonId() {
		return reasonId;
	}
	/**
	 * @param reasonId the reasonId to set
	 */
	public void setReasonId(int reasonId) {
		this.reasonId = reasonId;
	}
	/**
	 * @return the eventId
	 */
	public int getEventId() {
		return eventId;
	}
	/**
	 * @return the source
	 */
	public String getSource() {
		return source;
	}
	public void setEventData(String eventData) {
		
		this.eventData=eventData;
	}
	public String getEventData()
	{
		return this.eventData;
	}
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
	private static final int REASON_POWER_OFF = 0x5a;
	private static final int REASON_OUT_AREA = 0x2b;
	private static final int REASON_NUMBER_NULL = 0x2c;
	private static final int REASON_REFUSE = 0x2d;
	
	private static final int REASON_VOICE_DETECTED = 0x57;// ��⵽����Ӧ��
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
	public boolean isDisconnectedWhenGetKey() {
		
		return (eventId==MG_TDX_GETDIGIT)&&(reasonId==MGREASON_TM_DISCONNECT);
	}
	public boolean isDisconnectedWhenPlayFile() {
		
		return (eventId==MG_TDX_PLAY)&&(reasonId==MGREASON_TM_DISCONNECT);
	}
	public boolean hasEnoughKeyWhenGetKey() {
		
		return (eventId==MG_TDX_GETDIGIT)&&(reasonId==MGREASON_TM_MAXDTMF);
	}
	public boolean isKeyBreakWhenGetKey() {
		
		return (eventId==MG_TDX_GETDIGIT)&&(reasonId==MGREASON_TM_DIGIT);
	}
	public boolean isKeyBreakWhenPlayFile() {
		
		return (eventId==MG_TDX_PLAY)&&(reasonId==MGREASON_TM_DIGIT);
	}
	public boolean isPlayFileFinished() {
		
		return (eventId==MG_TDX_PLAY)&&(reasonId==MGREASON_TM_EOD);
	}
	public boolean isStopIoWhenPlayFile() {
		
		return (eventId==MG_TDX_PLAY)&&(reasonId==MGREASON_TM_USRSTOP);
	}
	public boolean isStopIoWhenWhenGetKey() {		
		return (eventId==MG_TDX_GETDIGIT)&&(reasonId==MGREASON_TM_USRSTOP);
	}
	public boolean isTimeoutWhenGetKey() {
		
		return (eventId==MG_TDX_GETDIGIT)&&(reasonId==MGREASON_TM_MAXTIME);
	}
	public boolean isCallTimeout() {
		return (eventId==SG_CALLDISCONNECTED)&&(reasonId==REASON_DESTNOANSWER);
	}
	public boolean isRemoteBusy() {
		return (eventId==SG_CALLDISCONNECTED)&&(reasonId==REASON_DESTBUSY);
	}
	public boolean isRemoteNumberError() {		
		return (eventId==SG_CALLDISCONNECTED)&&(reasonId==REASON_INVLAIDNUM);
	}
	public boolean isRemoteOutOfService() {		
		return (eventId==SG_CALLDISCONNECTED)&&(reasonId==REASON_OUT_AREA);
	}
	public boolean isRemotePowerOff() {		
		return (eventId==SG_CALLDISCONNECTED)&&(reasonId==REASON_POWER_OFF);
	}
	public boolean isRemoteRejected() {		
		return (eventId==SG_CALLDISCONNECTED)&&(reasonId==REASON_REFUSE);
	}
	public boolean isUnknownErrorCall() {		
		return (eventId==SG_CALLDISCONNECTED)&&(reasonId==REASON_DESTUNKNOWN);
	}
	public boolean foundFaxDevice() {
		
		return (eventId==SG_CALLCONNECTED)&&(reasonId==REASON_DESTFAXTONE);
	}

}

