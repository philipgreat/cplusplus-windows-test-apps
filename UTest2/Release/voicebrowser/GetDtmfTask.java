//Source file: F:\\suddy\\java\\com\\channelsoft\\voicebrowser\\DTMFAcquisitionTask.java

package com.channelsoft.voicebrowser;
/*
 收健: <getdtmf  name='event' key='?'  rule='*(#|*)'  timeout='10' />
收健异常: getdtmftimeout, illegalstate
*/
public class GetDtmfTask extends VoiceTask {
	
	static final String EVENT_GET_DTMF_TIMEOUT="getdtmftimeout";
	static final String EVENT_ILLEGAL_STATE="illegalstate";
	private String maxExpr;
	private String interruptKeys;
	private String firstWaitExpr;
	private String intervalExpr;
	private String clearBufferExpr="yes";
	
	private int maxKeys;
	private int firstWaitInMs;
	private int intervalInMs;
	private boolean isNeedClearBuffer=false;
	/**
	 * @roseuid 45ECE5710138
	 */
	public GetDtmfTask() {

	}


	@Override
	public boolean onEvent(VoiceBrowserEvent event) {
		
		if(event==null){
			int maxKeys=1;
			if(isNeedClearBuffer){
				context.clearDtmfBuffer();
			} 
			context.onGetDTMF(maxKeys,interruptKeys,firstWaitInMs,intervalInMs);
		}else{			
			if(event.hasEnoughKeyWhenGetKey()){
				context.setParameter(this.getTaskName().toString(), "收到足够的键");
				this.setValue(event.getEventData());
				if(!this.isEventTask()){
					context.setParameter("event", "收到足够的键");
				}
				return true;
			}else if(event.isKeyBreakWhenGetKey()){
				context.setParameter(this.getTaskName().toString(), "收到中断的键");
				this.setValue(event.getEventData());
				if(!this.isEventTask()){
					context.setParameter("event", "按键中断");
				}
				return true;
			}else if(event.isStopIoWhenWhenGetKey()){
				context.setParameter(this.getTaskName(), "系统停止收键");
				context.setParameter( this.getName(), event.getEventData());
				return true;
			}else if(event.isDisconnectedWhenGetKey()){
				context.setParameter(this.getTaskName(), "用户挂断");
				//context.onCallEnd();
				//context.setParameter( this.getName(), event.getEventData());
				return false;
			}
		}
		//gateway.playFile(context.getResourceId(), context.getCallId(), this.voiceFileURL);
		//(window.getResourceId(), window.getCallId());
		return false;	
	}
	public String toString()
	{
		return "<getdtmf name="+this.getName()+" max="+this.maxKeys+"/>";
	}

	public void setMaxExpr(String maxExpr) {		
		this.maxExpr=maxExpr;
	}

	public void setInterruptKeys(String interruptKeys) {		
		this.interruptKeys=interruptKeys;
	}

	public void setFirstWaitExpr(String firstWaitExpr) {		
		this.firstWaitExpr=firstWaitExpr;		
	}

	public void setIntervalExpr(String intervalExpr) {
		
		this.intervalExpr=intervalExpr;
		
	}

	@Override
	public void parse() {

		try {
			this.maxKeys = Integer.parseInt(this.maxExpr);
		} catch (Exception e) {
			this.warn(e.toString());
			maxKeys = 1;
		}
		try {
			this.firstWaitInMs = Integer.parseInt(this.firstWaitExpr);
		} catch (Exception e) {
			this.warn(e.toString());
			this.firstWaitInMs = 1000;
		}
		try {
			this.intervalInMs = Integer.parseInt(this.intervalExpr);
		} catch (Exception e) {
			this.warn(e.toString());
			this.intervalInMs = 1000;
		}
		try {
			if(this.clearBufferExpr.equals("yes")){
				this.isNeedClearBuffer=true;
			}else if(this.clearBufferExpr.equals("no")){
				this.isNeedClearBuffer=false;				
			}else{
				this.isNeedClearBuffer=false;				
				this.warn("不认识的设置,期望的设置是yes和no");
			}
		} catch (Exception e) {
			this.warn(e.toString());
			//this.intervalInMs = 1000;
		}
		

	}


	/**
	 * @param clearBufferExpr the clearBufferExpr to set
	 */
	public void setClearBufferExpr(String clearBufferExpr) {
		this.clearBufferExpr = clearBufferExpr;
	}
}
