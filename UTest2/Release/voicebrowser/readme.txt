
�����б�
================================================================
	�ӵ绰: <answer/>
	����: <makecall src='13900000' dst='13800000' timeout=''/>
	�����쳣: event=userhangup, userpoweroff, outofservice, rejected, calltimeout
	����: <playfile url=''  count='3'/>
	�����쳣: filenotexists, badformatfile, illegalstate, keybreak, playvoicetimeout
	�ս�: <getdtmf  name='event' key='?'  rule='*(#|*)'  timeout='10' />
	�ս��쳣: getdtmftimeout, illegalstate
	¼��: <record file='' maxlength='2M' />
	�ս��쳣: waitrecordtimeout, recordtimeout, illegalstate, 
	�����ı�: <playtext  text='' count='2'/>
	�����ı��쳣: enginenotavailable, voicefontnotsupported
	�һ�: <hangup/>
	Ĭ���¼�: event=ok
	��֪����ʲôԭ��: unknown
	ȫ���쳣:
	Page�Ļ�����ʽ
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