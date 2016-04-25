
任务列表
================================================================
	接电话: <answer/>
	呼出: <makecall src='13900000' dst='13800000' timeout=''/>
	呼出异常: event=userhangup, userpoweroff, outofservice, rejected, calltimeout
	放音: <playfile url=''  count='3'/>
	放音异常: filenotexists, badformatfile, illegalstate, keybreak, playvoicetimeout
	收健: <getdtmf  name='event' key='?'  rule='*(#|*)'  timeout='10' />
	收健异常: getdtmftimeout, illegalstate
	录音: <record file='' maxlength='2M' />
	收健异常: waitrecordtimeout, recordtimeout, illegalstate, 
	播放文本: <playtext  text='' count='2'/>
	播放文本异常: enginenotavailable, voicefontnotsupported
	挂机: <hangup/>
	默认事件: event=ok
	不知道是什么原因: unknown
	全局异常:
	Page的基本样式
======================================================================================	
@start
<page>
	<makecall src='12312' dest='82008'/>
	<playfile url='welcome.wav' repeat='3' interrup=''/>
	<voiceedit tips='xuanzetaocan.wav' name='event' interrupt='123*' max='1'/>
</page>


@start:1:10yuan
<page>
	<playfile url='xiexie10yuan.wav' />
	<playfile url='qingguaji.wav' />
	<hangup/>
 </page>

@start:3:8yuan
<page>
	<playfile url='xiexie8yuan.wav' />
	<playfile url='qingguaji.wav' />
	<hangup/>
</page>

@start:2:5yuan
<page>
	<playfile url='xiexie5yuan.wav' />
	<playfile url='qingguaji.wav' />
	<hangup/>
</page>

@start:*:start
<page>
	<playfile url='PV_BC_Welcome1.wav' />
	<playfile url='PV_InputNum.wav'/>
	<getdtmf name='event' interrupt='#'/>
</page>

	
/*.jar, JRE*, *billing, *common, *smsagent, *mqclient, *mqserver, *mqprotocol, *flowlogic
RCPTest,TERA_WORKFLOW,TestPlugIn,liveThought,GWTTest,HightPerformanceServer,AttatchMessage,

*.jar, JRE*, *billing, *common, *smsagent, *mqclient, *mqserver, *mqprotocol, *flowlogic,AnswerCallTask.java,DownloadingTask.java,DTMFAcquisitionTask.java,FilePlayingTask.java,FlowLogicNotAvailableException.java,HangUpTask.java,HttpSession.java,IVoiceSignalCombinedGateway.java,MakingCallTask.java,readme.txt,RecordingToFileTask.java,ResourceNotAvailableException.java,TextPlayingTask.java,VoiceBrowser.java,VoiceChannelNotAvailableException.java,VoicePage.java,VoicePageHandler.java,VoiceTask.java,VoiceWindow.java,XMLPageFactory.java