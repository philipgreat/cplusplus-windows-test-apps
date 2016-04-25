//Source file: D:\\resin-2.1.16\\doc\\xsm\\com\\channelsoft\\voicebrowser\\Page.java

package com.channelsoft.voicebrowser;

import java.util.Iterator;
import java.util.LinkedList;

public class VoicePage {
	private VoiceWindow context;	
	private String documentURL;
	private String sessionId;
	private VoiceTask currentTask;
	private LinkedList<VoiceTask> taskList = null;
	private StringBuffer checkInfoBuffer;
	/**
	 * @return the currentTask
	 */
	public VoicePage() {
		taskList = new LinkedList<VoiceTask>();
		checkInfoBuffer=new StringBuffer(1024);
	}
	public VoiceTask getCurrentTask() {
		return currentTask;
	}

	public void addTask(VoiceTask task) {
		task.setContext(this.context);
		taskList.add(task);
	}

	/**
	 * @param currentTask
	 *            the currentTask to set
	 */
	public void setCurrentTask(VoiceTask currentTask) {
		this.currentTask = currentTask;
	}


	/**
	 * @return the documentURL
	 */
	public String getDocumentURL() {
		return documentURL;
	}

	/**
	 * @param documentURL
	 *            the documentURL to set
	 */
	public void setDocumentURL(String documentURL) {
		this.documentURL = documentURL;
	}



	/**
	 * @return the context
	 */
	public VoiceWindow getContext() {
		return context;
	}

	
	public boolean showPage() {
		//从第一个执行到停止为止
		boolean canBeContinue = true;
		
		while(getTaskCountInQueue()>0&&canBeContinue){
			VoiceTask task=taskList.removeFirst();
			this.currentTask = task;
			canBeContinue=task.onEvent(null);
		}
		if(getTaskCountInQueue()==0){
			if(canBeContinue){
				this.currentTask=null;
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}
	/**
	 * @param context2
	 * @roseuid 45C45BC503A9
	 */
	public void setContext(VoiceWindow context2) {
		this.context = context2;
		Iterator iter=this.taskList.iterator();
		while (iter.hasNext()) {
			VoiceTask element = (VoiceTask) iter.next();
			element.setContext(context2);			
		}		
	}

	public boolean onEvent(VoiceBrowserEvent event) {
		if(currentTask == null)
		{
			return true;
		}
		boolean canBeContinue=false;
		canBeContinue = currentTask.onEvent(event);
		while(canBeContinue&&getTaskCountInQueue()>0){
			VoiceTask task=taskList.removeFirst();
			this.currentTask = task;
			canBeContinue=task.onEvent(null);
		}
		if(getTaskCountInQueue()==0){
			if(canBeContinue){
				//this.currentTask=null;
				return true;
			}else{
				//there at lest one is active
				return false;
			}
		}else{
			return false;
		}
	}

	public void log(String where,String info)
	{
		this.checkInfoBuffer.append(where+": "+info+"\r\n");		
	}
	public int getTaskCountInQueue() {
		// TODO Auto-generated method stub
		return this.taskList.size();
	}
	public String toString()
	{
		StringBuffer buffer =new StringBuffer();
		buffer.append("<page>\r\n");
		for(int i=0; i<this.taskList.size();i++){
			VoiceTask task = taskList.get(i);
			buffer.append(task.toString());
			buffer.append("\r\n");
		}
		buffer.append("</page>");
		
		return buffer.toString();
	}
	/**
	 * @return the sessionId
	 */
	public String getSessionId() {
		return sessionId;
	}
	/**
	 * @param sessionId the sessionId to set
	 */
	public void setSessionId(String sessionId) {
		this.sessionId = sessionId;
	}
}
