package com.channelsoft.voicebrowser;

import com.channelsoft.common.HttpSession;

public class DownloadingTaskExecutor extends Thread {

	/* (non-Javadoc)
	 * @see java.lang.Thread#run()
	 */
	private boolean running;
	HttpSession session;
	VoiceBrowser context;
	private VoiceEventQueue voiceQueue;
	private VoiceEventQueue downloadingTaskQueue; 
	
	public DownloadingTaskExecutor(VoiceEventQueue queue)
	{
		this.voiceQueue=queue;
		downloadingTaskQueue=new VoiceEventQueue();
		session=new HttpSession();		
	}
	public synchronized void exit()
	{
		running=false;
	}
	public void addDownloadingTask(String url)
	{
		//downloadingTaskQueue.addEvent(o);		
	}
	@Override
	public void run() {
		//
		// TODO Auto-generated method stub
		//super.run();
	}

		
}
