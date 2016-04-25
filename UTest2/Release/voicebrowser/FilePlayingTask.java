//Source file: F:\\suddy\\java\\com\\channelsoft\\voicebrowser\\FilePlayingTask.java

package com.channelsoft.voicebrowser;

/*
 * ����: <makecall src='13900000' dst='13800000'/>
 �����쳣: event=userhangup, userpoweroff, outofservice, rejected, calltimeout
 ����: <playfile url=''  count='3'/>
 �����쳣: filenotexists, badformatfile, illegalstate, keybreak, playvoicetimeout
 �ս�: <getdtmf  name='event' key='?'  rule='*(#|*)'  timeout='10' />
 �ս��쳣: getdtmftimeout,  illegalstate
 ¼��: <record file='' maxlength='2M' />
 �ս��쳣: recordtimeout,  illegalstate
 �����ı�: <playtext  text='' count='2'/>
 �����ı��쳣: enginenotavailable, voicefontnotsupported
 �һ�: <hangup/>
 Ĭ���¼�: event=ok
 ��֪����ʲôԸ��: unknown
 ȫ���쳣:
 * */
public class FilePlayingTask extends VoiceTask {
	private String voiceFileURL;
	private int count = 1;
	private int playedCount=0;
	private String interruptKeys = DEFAULT_INTERRUPT_KEY;
	private String coutExpr;
	private static final String DEFAULT_INTERRUPT_KEY = "01234546789*#";

	/**
	 * @roseuid 45ECE57100BB
	 */
	public FilePlayingTask() {

	}


	/**
	 * @param voiceFileURL
	 *            the voiceFileURL to set
	 */
	public void setVoiceFileURL(String voiceFileURL) {
		this.voiceFileURL = voiceFileURL;
	}

	@Override
	public boolean onEvent(VoiceBrowserEvent event) {
		// TODO Auto-generated method stub
		if (event == null) {
			System.out.println("file url: " + voiceFileURL);
			context.playFile(voiceFileURL, this.interruptKeys, 0);
			playedCount++;
			// IVoiceGateway gateway=event.getGateway();
		} else {
			if (event.isDisconnectedWhenPlayFile()) {
				
				context.setParameter(this.getName(), "�û��һ�");
				return false;
			}
			if (event.isPlayFileFinished()) {
				if(playedCount<this.count){					
					context.playFile(voiceFileURL, this.interruptKeys, 0);
					context.setParameter(this.getTaskName(), "�������"+playedCount+"��");
					playedCount++;		
					return false;
				}else{
					context.setParameter(this.getName(), "�������");
					if(!this.isEventTask()){
						context.setParameter("event", "�������");
					}
					return true;
				}
			}
			if (event.isKeyBreakWhenPlayFile()) {
				context.setParameter(this.getName(), "�û������ж�");
				if(!this.isEventTask()){
					context.setParameter("event", "�����ж�");
				}
				return true;
			}
			if (event.isStopIoWhenPlayFile()) {
				context.setParameter(this.getName(), "ϵͳֹͣ����");
				return true;
			}

		}
		// gateway.playFile(context.getResourceId(), context.getCallId(),
		// this.voiceFileURL);
		// (window.getResourceId(), window.getCallId());
		return false;
	}

	public void setInterruptKeys(String interruptKeys) {
		// TODO Auto-generated method stub
		this.interruptKeys = interruptKeys;
	}

	@Override
	public void parse() {
		try {
			this.count = Integer.parseInt(this.coutExpr);
		} catch (Exception e) {
			this.warn(e.toString());
			this.count = 1;
		}
		if (interruptKeys == null) {
			interruptKeys = DEFAULT_INTERRUPT_KEY;
		}
		if (interruptKeys.equals("")) {
			// interruptKeys=DEFAULT_INTERRUPT_KEY;
			// interrupt is not allowed
		}
		try {
			this.count = Integer.parseInt(this.coutExpr);
		} catch (Exception e) {
			this.warn(e.toString());
			this.count = 1;
		}

	}


	public void setCountExpr(String countExpr) {
		// TODO Auto-generated method stub
		this.coutExpr=countExpr;
	}

}
