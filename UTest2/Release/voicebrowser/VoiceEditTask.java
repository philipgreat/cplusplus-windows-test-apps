package com.channelsoft.voicebrowser;

public class VoiceEditTask extends VoiceTask {

	private String interruptKeys;

	private String maxExpr;

	private String firstWaitExpr;

	private String intervalExpr;

	private String tips;

	private int maxKeys = 1;

	private int firstWaitInSeconds = 10;
	private int intervalInSeconds = 10;

	@Override
	public boolean onEvent(VoiceBrowserEvent event) {
		if (event == null) {
			// clear buffer
			context.clearDtmfBuffer();
			// play file
			context.playFile(tips, interruptKeys, 0);
			return false;
		} else {
			
			if (event.isDisconnectedWhenPlayFile()) {
				System.out.println(this.getTaskName());
				this.setValue("用户挂断");
				return false;
			} else if (event.isPlayFileFinished()) {
				this.setTaskExecuteInfo("播放完成");
				context.onGetDTMF(maxKeys, interruptKeys, firstWaitInSeconds,
						intervalInSeconds);
				return false;
			}else if (event.isKeyBreakWhenPlayFile()) {
				this.setValue("用户按键中断");
				context.onGetDTMF(maxKeys, interruptKeys, firstWaitInSeconds,
						intervalInSeconds);
				return false;
			}else if (event.isStopIoWhenPlayFile()) {
				this.setTaskExecuteInfo("系统终止放音");
				this.setValue("系统终止放音");
				return true;
			}else if (event.isTimeoutWhenGetKey()) {
				this.setTaskExecuteInfo("收键超时");
				this.setValue("收键超时");
				return true;
			}else if (event.hasEnoughKeyWhenGetKey()) {
				this.setTaskExecuteInfo("收到足够的键");				
				System.out.printf("event = %x %s\n",event.getEventId(),event.getEventData());
				this.setValue(event.getEventData());
				if(!this.isEventTask()){
					context.setParameter("event", "收到足够的键");
				}
				return true;
			} else if (event.isKeyBreakWhenGetKey()) {
				this.setTaskExecuteInfo( "按键中断");
				this.setValue(event.getEventData());

				if(!this.isEventTask()){
					context.setParameter("event", "按键中断");
				}
				//context.setParameter(firstWaitExpr, intervalExpr);
				
				return true;
			} else if (event.isStopIoWhenWhenGetKey()) {
				this.setTaskExecuteInfo( "系统停止收键");
				this.setValue("系统终止收键");
				return true;
			} else if (event.isDisconnectedWhenGetKey()) {
				this.setValue("用户挂断");
				// context.onCallEnd();
				// context.setParameter( this.getName(), event.getEventData());
				return false;
			}else{
				//System.out.println(event);
			}
		}
		return false;

	}

	public void parse() {
		try {
			maxKeys = Integer.parseInt(this.maxExpr);
		} catch (Exception e) {
			this.warn(e.toString());
			maxKeys = 1;
		}
		try {
			firstWaitInSeconds = Integer.parseInt(this.firstWaitExpr);
		} catch (Exception e) {
			this.warn(e.toString());
			firstWaitInSeconds = 10;
		}
		try {
			intervalInSeconds = Integer.parseInt(this.intervalExpr);
		} catch (Exception e) {
			this.warn(e.toString());
			intervalInSeconds = 10;
		}
		
	}

	public void setMaxExpr(String maxExpr) {
		this.maxExpr = maxExpr;
	}

	public void setInterruptKeys(String interruptKeys) {
		this.interruptKeys = interruptKeys;
	}

	public void setFirstWaitExpr(String firstWaitExpr) {
		this.firstWaitExpr = firstWaitExpr;
	}

	public void setIntervalExpr(String intervalExpr) {
		this.intervalExpr = intervalExpr;
	}

	public void setTips(String tips) {
		this.tips = tips;
	}
	public String toString()
	{
		return "<voiceedit name="+this.getName()+" tips="+this.tips+" max="+this.maxKeys+" />";
	}

}
