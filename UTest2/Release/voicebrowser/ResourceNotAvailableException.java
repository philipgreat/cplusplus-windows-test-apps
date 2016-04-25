//Source file: F:\\suddy\\java\\com\\channelsoft\\voicebrowser\\ResourceNotAvailableException.java

package com.channelsoft.voicebrowser;

public class ResourceNotAvailableException extends Exception {


	private static final long serialVersionUID = -4363087016914492475L;
	private String message;
	public ResourceNotAvailableException(String msg) {
		this.message=msg;
	}
	public String toString()
	{
		return "exception: "+this.message;
		
	}
}
