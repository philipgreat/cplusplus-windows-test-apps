//Source file: F:\\suddy\\java\\com\\channelsoft\\voicebrowser\\VoiceBrowserTask.java

package com.channelsoft.voicebrowser;

import java.util.Date;

public abstract class VoiceTask {
	private String taskName;

	private String name="event";

	private String value;

	private Date startTime;

	private Date endTime;

	VoiceWindow context;

	private StringBuffer warnings;

	/**
	 * @roseuid 45ECE572002E
	 */
	public VoiceTask() {
		warnings = new StringBuffer();
		startTime = new Date();
	}
	public void warn(String info)
	{
		warnings.append(info);		
	}
	public String getWarning()
	{
		return this.warnings.toString();
	}
	/**
	 * @return the name
	 */
	public String getName() {
		return name;
	}

	/**
	 * @return the value
	 */
	public String getValue() {
		return value;
	}

	public void start(){};
	/**
	 * @roseuid 45C4536001D4
	 */
	public void end() {
		endTime = new Date();
	}

	public long span() {
		return endTime.getTime() - startTime.getTime();
	}

	/**
	 * @param value
	 * @roseuid 45C453E20000
	 */
	public void setName(String name) {
		if(name==null){
			this.name="event";
		}else{
			this.name = name;
		}
	}

	public void setValue(String value) {
		context.setParameter(this.getName(),value);	
		this.value = value;
	}

	public String toString() {
		return this.name + "=" + value;
	}
	public boolean isEventTask()
	{
		if(name==null){
			return false;
		}else{
			return this.name.equals("event");		
		}
	}
	/**
	 * @param event
	 * @roseuid 45CD85650290
	 */
	public abstract boolean onEvent(VoiceBrowserEvent event);

	// public abstract boolean check();

	public void setContext(VoiceWindow context) {
		// TODO Auto-generated method stub
		this.context = context;
	}

	/**
	 * @return the taskName
	 */
	public String getTaskName() {
		return taskName;
	}

	public abstract void parse();

	/**
	 * @param taskName
	 *            the taskName to set
	 */
	public void setTaskName(String taskName) {
		this.taskName = taskName;
	}
	public void setTaskExecuteInfo(String param)
	{
		context.setParameter(this.getTaskName(),param);		
	}

	

}
