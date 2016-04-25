//Source file: F:\\suddy\\java\\com\\channelsoft\\voicebrowser\\RecordingToFileTask.java
//<record url='' maxlength='2M' />
package com.channelsoft.voicebrowser;

public class RecordingToFileTask extends VoiceTask {
	private String 	url;
	private long 	maxLength;

	public RecordingToFileTask()
	{	
	}
	
	/**
	 * @param maxLength the maxLength to set
	 */
	public void setMaxLength(long maxLength) {
		this.maxLength = maxLength;
	}
	
	/**
	 * @param url the url to set
	 */
	public void setUrl(String url) {
		this.url = url;
	}
	public boolean execute() {
		// TODO Auto-generated method stub
		return true;
	}
	//input like '2M', 102K

	@Override
	public boolean onEvent(VoiceBrowserEvent event) {
		// TODO Auto-generated method stub
		IVoiceGateway gateway = event.getGateway();
		int resourceId = 0;
		int callId=0;
		boolean finished=true;
		if(finished){
			return false;
		}
		gateway.recordToFile(resourceId,callId,url,maxLength);
		return false;
	}


	@Override
	public void parse() {
		// TODO Auto-generated method stub
		
	}
	
}
