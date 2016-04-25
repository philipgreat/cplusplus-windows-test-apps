package com.channelsoft.voicebrowser;


public class MediaEventSender extends Thread {
	private IVoiceGateway gateway;
	private VoiceEventQueue queue;

	private boolean running=true;

	public MediaEventSender(IVoiceGateway gateway,VoiceEventQueue queue) {
		this.gateway = gateway;
		this.queue=queue;
	}
	public synchronized void exit()
	{
		running=false;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Thread#run()
	 */
	@Override
	public void run() {
		// TODO Auto-generated method stub
		while (running) {	
			try{
				VoiceBrowserEvent event = gateway.getMediaEvent(100);
				if(null!=event){
					queue.addEvent(event);
				}
			}catch(Ice.SocketException e){
				gateway.reinitialize();
			}
		}
	}

}
