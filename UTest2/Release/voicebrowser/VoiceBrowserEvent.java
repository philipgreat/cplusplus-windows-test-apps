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
	private static final int REASON_POWER_OFF = 0x5a;
	private static final int REASON_OUT_AREA = 0x2b;
	private static final int REASON_NUMBER_NULL = 0x2c;
	private static final int REASON_REFUSE = 0x2d;
	
	private static final int REASON_VOICE_DETECTED = 0x57;// 检测到语音应答
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

