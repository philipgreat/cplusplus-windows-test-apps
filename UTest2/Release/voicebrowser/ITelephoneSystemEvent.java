package com.channelsoft.voicebrowser;

public interface ITelephoneSystemEvent  {


	public int getCallId();
	public IVoiceGateway getGateway();
	public int getResourceId();
	//  ��Դ��������
	public boolean isResourceStarted();
	public boolean isResourceReleased();
	//  ���е���������
	public boolean hasInboundCall();
	public boolean isDialedOutSuccess();
	public boolean isDialedOut();
	//�û��ܽӵ绰|��ʱ��û��Ӧ��|�Է�æ|�������|�û��ػ�|���ڷ�����|δ֪����
	//���н���
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
	//	������������������
	public boolean isPlayFileFinished();
	public boolean isKeyBreakWhenPlayFile();
	public boolean isDisconnectedWhenPlayFile();
	public boolean isStopIoWhenPlayFile();
	// �ռ���������
	public boolean hasEnoughKeyWhenGetKey();
	public boolean isKeyBreakWhenGetKey();
	public boolean isDisconnectedWhenGetKey();
	public boolean isStopIoWhenWhenGetKey();
	public boolean isTimeoutWhenGetKey();
	
	//	¼����������������
	public boolean isRecordFileFailed();
	public boolean isRecordFileFinished();
	//  �ռ���������

	public void setCallId(int callId);
	public void setGateway(IVoiceGateway gateway);
	public void setResourceId(int resourceId);

}
