package com.channelsoft.voicebrowser;

public class HangUpTask extends VoiceTask {

	  
	
	@Override
	public boolean onEvent(VoiceBrowserEvent event) {
		// TODO Auto-generated method stub
		if(event==null){
			context.setParameter("event", "ÏµÍ³¹Ò»ú");
			context.onCallEnd();			
			System.out.println("hangup");
		}
		return false;	
	}
	
	public String toString()
	{
		return "<hangup/>";
	}

	@Override
	public void parse() {
		// TODO Auto-generated method stub
		
	}

}
