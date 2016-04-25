package com.channelsoft.voicebrowser;

import java.util.LinkedList;

public class VoiceEventQueue {
	private LinkedList<VoiceBrowserEvent> queue ;
	public VoiceEventQueue()
	{
		queue = new LinkedList<VoiceBrowserEvent>();		
	}
    public synchronized void addEvent(VoiceBrowserEvent o) {
        queue.addLast(o);
        notifyAll();
    }
    public synchronized int size() {
        return this.queue.size();
    }
    public synchronized VoiceBrowserEvent getEvent(int timeoutInMillionSeconds) throws InterruptedException {
        if (queue.isEmpty()) {
            wait(timeoutInMillionSeconds);            
        }
        if(queue.isEmpty()){
        	throw new InterruptedException("wait time out");
        }
        return queue.removeFirst();
    }
}
