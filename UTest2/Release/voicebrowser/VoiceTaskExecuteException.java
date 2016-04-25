package com.channelsoft.voicebrowser;

public class VoiceTaskExecuteException extends Exception {
	private int resId;

	private int callId;

	private int eventId;

	private int reasonId;

	public VoiceTaskExecuteException(int resId, int callId, int eventId,
			int reasonId) {
		this.resId = resId;
		this.callId = callId;
		this.eventId = eventId;
		this.reasonId = reasonId;
	}

	public String toString() {
		return null;
	}
}
