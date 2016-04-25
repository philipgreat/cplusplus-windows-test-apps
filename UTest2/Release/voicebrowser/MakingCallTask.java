//Source file: F:\\suddy\\java\\com\\channelsoft\\voicebrowser\\MakingCallTask.java

package com.channelsoft.voicebrowser;
//呼出异常: event=userhangup, userpoweroff, outofservice, rejected, calltimeout

public class MakingCallTask extends VoiceTask {
	static final String EVENT_USER_HANG_UP="userhangup";
	static final String EVENT_USERP_POWEROFF="userpoweroff";
	static final String EVENT_OUT_OF_SERVICE="outofservice";
	static final String EVENT_USER_REJECTED="rejected";
	static final String EVENT_CALL_TIMEOUT="calltimeout";
	
	private String source;
	private String destination;
	public MakingCallTask() {

	}

	public boolean execute() {
		// TODO Auto-generated method stub
		return true;
	}

	/**
	 * @param destination the destination to set
	 */
	public void setDestination(String destination) {
		this.destination = destination;
	}

	/**
	 * @param source the source to set
	 */
	public void setSource(String source) {
		this.source = source;
	}
	//成功拨出电话后窗口的状态不再设置闲的状态
	@Override
	public boolean onEvent(VoiceBrowserEvent event) {
		// TODO Auto-generated method stub
		if(event!=null){
			//IVoiceGateway gateway = event.getGateway();
			if(event.foundFaxDevice()){
				context.setParameter("event", "发现传真设备");
				return true;
			}
			if(event.isConnected()){
				context.setParameter("event", "呼叫建立");
				return true;
			}
			if(event.isRemoteBusy()){
				context.setParameter("event", "对方忙");
				return true;
			}
			if(event.isRemotePowerOff()){
				context.setParameter("event", "用户关机");
				return true;
			}
			if(event.isRemoteOutOfService()){
				context.setParameter("event", "不在服务区");
				return true;
			}
			if(event.isRemoteNumberError()){
				context.setParameter("event", "号码错误");
				return true;
			}
			if(event.isCallTimeout()){
				context.setParameter("event", "长时间没有应答");
				return true;
			}
			if(event.isUnknownErrorCall()){
				context.setParameter("event", "未知错误");
				return true;
			}
		}else{
			context.onCallStart(this.source,this.destination,100);
			System.out.println(this.source+"->"+this.destination);
		}
		
		return false;
		
	}
	public String toString()
	{
		return "<makecall src='"+this.source+"' dest='"+this.destination+"'/>";
	}



	@Override
	public void parse() {
		// TODO Auto-generated method stub
		
	}

}
