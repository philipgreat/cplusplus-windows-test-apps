package com.channelsoft.voicebrowser;

public interface ITelephoneSystemEvent  {


	public int getCallId();
	public IVoiceGateway getGateway();
	public int getResourceId();
	//  资源生命周期
	public boolean isResourceStarted();
	public boolean isResourceReleased();
	//  呼叫的生命周期
	public boolean hasInboundCall();
	public boolean isDialedOutSuccess();
	public boolean isDialedOut();
	//用户拒接电话|长时间没有应答|对方忙|号码错误|用户关机|不在服务区|未知错误
	//呼叫建立
	public boolean isRemoteRejected();
	public boolean isCallTimeout();
	public boolean isRemoteBusy();
	public boolean isRemoteNumberError();
	public boolean isRemotePowerOff();
	public boolean foundFaxDevice();
	public boolean isRemoteOutOfService();
	public boolean isUnknownErrorCall();
	
	
	//public boolean isRemoteHangup();
	public boolean isConnected();
	public boolean isDisconnected();
	public boolean isReleased();
	//	播放语音的生命周期
	public boolean isPlayFileFinished();
	public boolean isKeyBreakWhenPlayFile();
	public boolean isDisconnectedWhenPlayFile();
	public boolean isStopIoWhenPlayFile();
	// 收键生命周期
	public boolean hasEnoughKeyWhenGetKey();
	public boolean isKeyBreakWhenGetKey();
	public boolean isDisconnectedWhenGetKey();
	public boolean isStopIoWhenWhenGetKey();
	public boolean isTimeoutWhenGetKey();
	
	//	录制语音的生命周期
	public boolean isRecordFileFailed();
	public boolean isRecordFileFinished();
	//  收键生命周期

	public void setCallId(int callId);
	public void setGateway(IVoiceGateway gateway);
	public void setResourceId(int resourceId);

}
