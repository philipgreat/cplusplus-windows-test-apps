//Source file: F:\\suddy\\java\\com\\channelsoft\\voicebrowser\\TextPlayingTask.java

package com.channelsoft.voicebrowser;

public class TextPlayingTask extends VoiceTask {
	private String text;
	private int count;
	/**
	 * @roseuid 45ECE571034B
	 */
	public TextPlayingTask()   {

	}
	public boolean execute() {
		// TODO Auto-generated method stub
		return true;
	}
	public void setText(String text) {
		this.text = text;
	}
	public void setCount(int count) {
		// TODO Auto-generated method stub
		this.count = count;
	}
	@Override
	public boolean onEvent(VoiceBrowserEvent event) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public void parse() {
		// TODO Auto-generated method stub
		
	}
}
