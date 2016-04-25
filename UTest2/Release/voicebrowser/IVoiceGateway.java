package com.channelsoft.voicebrowser;

import java.util.Properties;

import Ice.IntHolder;

public interface IVoiceGateway {

	public boolean initialize(Properties config);
	public boolean reinitialize();

	public int playFile(int resourceId, int callId, String filePath,String interruptKeys,int samplingRate);

	public void recordToFile(int resourceId, int callId, String url,
			long maxLength);


	public int blindMakeCall(IntHolder resourceId, IntHolder callId,String src, String dest,int timeout);

	public int answerCall(int resourceId, int callId);

	public int releaseCall(int resourceId, int callId);


	public int receiveDtmf(int resourceId, int callId);

	public int playTTS(int resourceId, int callId, String text);


	public int stopIO(int resourceId, int callId);

	public int getResourceCount();

	public int getResourceType(int index);
	public String getResourceId(int index);
	public int getDTMF(int resourceId, int callId, int nKeyCount, String szInteruptKeys, int nMax1stkeyTime, int nTimeBetweenKey);
	public VoiceBrowserEvent getSignalEvent(int i);

	public VoiceBrowserEvent getMediaEvent(int i);

	public int clearDtmfBuffer(int resourceId, int callId);

	public String getFatalMessage();

	//public void sendEvent(VoiceBrowserEvent event);

}
