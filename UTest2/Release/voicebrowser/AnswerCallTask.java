package com.channelsoft.voicebrowser;


public class AnswerCallTask extends VoiceTask {

	public boolean execute() {
		// TODO Auto-generated method stub
		return true;
	}
	//成功接听电话后窗口的状态不再设置闲的状态
	public boolean onEvent(VoiceBrowserEvent event) {
		// TODO Auto-generated method stub
		if(event!=null)
		{
			IVoiceGateway gateway = event.getGateway();
			//VoiceWindow window = event.getWindow();
			//window.onCallStart();
			gateway.answerCall(context.getResourceId(), context.getCallId());
		}else{
			//this.context.onCallStart();			
		}
		//gateway.sendEvent(event);
		return false;
	}

	@Override
	public void parse() {
		// TODO Auto-generated method stub
		
	}

}
