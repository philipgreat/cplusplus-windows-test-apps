//Source file: F:\\suddy\\java\\com\\channelsoft\\voicebrowser\\FilePlayingTask.java

package com.channelsoft.voicebrowser;

/*
 * 呼出: <makecall src='13900000' dst='13800000'/>
 呼出异常: event=userhangup, userpoweroff, outofservice, rejected, calltimeout
 放音: <playfile url=''  count='3'/>
 放音异常: filenotexists, badformatfile, illegalstate, keybreak, playvoicetimeout
 收健: <getdtmf  name='event' key='?'  rule='*(#|*)'  timeout='10' />
 收健异常: getdtmftimeout,  illegalstate
 录音: <record file='' maxlength='2M' />
 收健异常: recordtimeout,  illegalstate
 播放文本: <playtext  text='' count='2'/>
 播放文本异常: enginenotavailable, voicefontnotsupported
 挂机: <hangup/>
 默认事件: event=ok
 不知道是什么愿意: unknown
 全局异常:
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
				
				context.setParameter(this.getName(), "用户挂机");
				return false;
			}
			if (event.isPlayFileFinished()) {
				if(playedCount<this.count){					
					context.playFile(voiceFileURL, this.interruptKeys, 0);
					context.setParameter(this.getTaskName(), "播放完成"+playedCount+"次");
					playedCount++;		
					return false;
				}else{
					context.setParameter(this.getName(), "播放完成");
					if(!this.isEventTask()){
						context.setParameter("event", "播放完成");
					}
					return true;
				}
			}
			if (event.isKeyBreakWhenPlayFile()) {
				context.setParameter(this.getName(), "用户按键中断");
				if(!this.isEventTask()){
					context.setParameter("event", "按键中断");
				}
				return true;
			}
			if (event.isStopIoWhenPlayFile()) {
				context.setParameter(this.getName(), "系统停止放音");
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
