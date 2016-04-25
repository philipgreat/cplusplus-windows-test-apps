package com.channelsoft.voicebrowser;

public class TimerEventSender extends Thread {
	private VoiceEventQueue queue;
	private boolean running=true;

	public TimerEventSender(VoiceEventQueue queue) {
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
			try {
				VoiceBrowserEvent event=new VoiceBrowserEvent();
				event.setSource("timer");
				queue.addEvent(event);
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				
			}

		}

		
	}

}
