package com.channelsoft.voicebrowser;

public class SignalEventSender extends Thread {
	private IVoiceGateway gateway;

	private VoiceEventQueue queue;

	private boolean running = true;

	public SignalEventSender(IVoiceGateway gateway, VoiceEventQueue queue) {
		this.gateway = gateway;
		this.queue = queue;
	}

	public synchronized void exit() {
		running = false;
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

			VoiceBrowserEvent event = gateway.getSignalEvent(100);
			if (null != event) {
				queue.addEvent(event);
			}

		}
	}

}
/*
 * }catch(Ice.SocketException e){ gateway.reinitialize(); } *
 */
