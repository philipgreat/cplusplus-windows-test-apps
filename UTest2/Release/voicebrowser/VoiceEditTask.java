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
				this.setValue("�û��Ҷ�");
				return false;
			} else if (event.isPlayFileFinished()) {
				this.setTaskExecuteInfo("�������");
				context.onGetDTMF(maxKeys, interruptKeys, firstWaitInSeconds,
						intervalInSeconds);
				return false;
			}else if (event.isKeyBreakWhenPlayFile()) {
				this.setValue("�û������ж�");
				context.onGetDTMF(maxKeys, interruptKeys, firstWaitInSeconds,
						intervalInSeconds);
				return false;
			}else if (event.isStopIoWhenPlayFile()) {
				this.setTaskExecuteInfo("ϵͳ��ֹ����");
				this.setValue("ϵͳ��ֹ����");
				return true;
			}else if (event.isTimeoutWhenGetKey()) {
				this.setTaskExecuteInfo("�ռ���ʱ");
				this.setValue("�ռ���ʱ");
				return true;
			}else if (event.hasEnoughKeyWhenGetKey()) {
				this.setTaskExecuteInfo("�յ��㹻�ļ�");				
				System.out.printf("event = %x %s\n",event.getEventId(),event.getEventData());
				this.setValue(event.getEventData());
				if(!this.isEventTask()){
					context.setParameter("event", "�յ��㹻�ļ�");
				}
				return true;
			} else if (event.isKeyBreakWhenGetKey()) {
				this.setTaskExecuteInfo( "�����ж�");
				this.setValue(event.getEventData());

				if(!this.isEventTask()){
					context.setParameter("event", "�����ж�");
				}
				//context.setParameter(firstWaitExpr, intervalExpr);
				
				return true;
			} else if (event.isStopIoWhenWhenGetKey()) {
				this.setTaskExecuteInfo( "ϵͳֹͣ�ռ�");
				this.setValue("ϵͳ��ֹ�ռ�");
				return true;
			} else if (event.isDisconnectedWhenGetKey()) {
				this.setValue("�û��Ҷ�");
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
