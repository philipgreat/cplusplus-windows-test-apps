package com.channelsoft.voicebrowser;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import com.channelsoft.common.StringTool;

public class VoicePageHandler extends DefaultHandler {
	private VoicePage page;
	/*
	 * (non-Javadoc)
	 * 
	 * @see org.xml.sax.helpers.DefaultHandler#endDocument()
	 */
	public VoicePageHandler(){
		page = new VoicePage();	
	}
	@Override
	public void endDocument() throws SAXException {
		// TODO Auto-generated method stub
		super.endDocument();
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see org.xml.sax.helpers.DefaultHandler#endElement(java.lang.String,
	 *      java.lang.String, java.lang.String)
	 */
	@Override
	public void endElement(String uri, String localName, String qName)
			throws SAXException {
		// TODO Auto-generated method stub
		super.endElement(uri, localName, qName);
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see org.xml.sax.helpers.DefaultHandler#startDocument()
	 */
	@Override
	public void startDocument() throws SAXException {
		// TODO Auto-generated method stub
		
		super.startDocument();
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see org.xml.sax.helpers.DefaultHandler#startElement(java.lang.String,
	 *      java.lang.String, java.lang.String, org.xml.sax.Attributes)
	 */
	@Override
	public void startElement(String uri, String localName, String qName,
			Attributes attributes) throws SAXException {
		// TODO Auto-generated method stub
		VoiceTask  task=initiateTask(qName,attributes);
		if(task!=null){			
			page.addTask(task);
		}
		super.startElement(uri, localName, qName, attributes);
	}

	public VoicePage getVoicePage() {
		return this.page;
	}

	public static VoiceTask initiateTask(String qName, Attributes attributes) {
		VoiceTask task = null;
		try {
			if (qName.equals("download")) {
				DownloadingTask tempTask = new DownloadingTask();				
				task = tempTask;
			} else if (qName.equals("makecall")) {
				MakingCallTask tempTask = new MakingCallTask();
				task = tempTask;
				String src= attributes.getValue("src");
				String dest = attributes.getValue("dest");
				tempTask.setSource(src);
				tempTask.setDestination(dest);
			} else if (qName.equals("playfile")) {
				FilePlayingTask tempTask = new FilePlayingTask();
				task = tempTask;
				String url = attributes.getValue("url");				
				String interruptKeys = attributes.getValue("interrupt");
				String countExpr=attributes.getValue("repeat");
				tempTask.setVoiceFileURL(url);
				tempTask.setInterruptKeys(interruptKeys);				
				tempTask.setCountExpr(countExpr);	
				
			} else if (qName.equals("voiceedit")) {
				VoiceEditTask tempTask = new VoiceEditTask();
				task = tempTask;				
				String maxExpr = attributes.getValue("max");
				String interruptKeys = attributes.getValue("interrupt");
				String tips = attributes.getValue("tips");
				String firstWaitExpr = attributes.getValue("firstwait");
				String intervalExpr = attributes.getValue("interval");
				String waitExpr = attributes.getValue("wait");
				
				tempTask.setTips(tips);
				tempTask.setMaxExpr(maxExpr);
				tempTask.setInterruptKeys(interruptKeys);
				tempTask.setFirstWaitExpr(firstWaitExpr);
				tempTask.setIntervalExpr(intervalExpr);
		
				
				
			} else if (qName.equals("getdtmf")) {
				GetDtmfTask tempTask = new GetDtmfTask();
				task = tempTask;
				
				String maxExpr = attributes.getValue("max");
				String interruptKeys = attributes.getValue("interrupt");
				String firstWaitExpr = attributes.getValue("firstwait");
				String intervalExpr = attributes.getValue("interval");
				String clearBufferExpr = attributes.getValue("clearbuffer");
				
				tempTask.setMaxExpr(maxExpr);
				tempTask.setInterruptKeys(interruptKeys);
				tempTask.setFirstWaitExpr(firstWaitExpr);
				tempTask.setIntervalExpr(intervalExpr);
				tempTask.setClearBufferExpr(clearBufferExpr);
				
			} else if (qName.equals("record")) {
				RecordingToFileTask tempTask = new RecordingToFileTask();
				task = tempTask;
				String url = attributes.getValue("url");
				String maxLengthExpr = attributes.getValue("maxlength");
				tempTask.setUrl(url);
				long maxLength=StringTool.parseLengthExpr(maxLengthExpr);
				tempTask.setMaxLength(maxLength);
			} else if (qName.equals("playtext")) {
				TextPlayingTask tempTask = new TextPlayingTask();
				task = tempTask;
				String text = attributes.getValue("url");
				int count = Integer.parseInt(attributes.getValue("count"));
				tempTask.setText(text);
				tempTask.setCount(count);
			} else if (qName.equals("hangup")) {
				HangUpTask tempTask = new HangUpTask();
				task = tempTask;
			} else if (qName.equals("answercall")) {
				AnswerCallTask tempTask = new AnswerCallTask();
				task = tempTask;
			} else {
				// task is null;
			}
			
		} catch(Exception e){
			System.out.println(e);			
		}finally {
			if (task != null) {
				String name=attributes.getValue("name");
				task.setTaskName(qName);				
				task.setName(name);
				task.parse();
			}
			return task;
		}

	}
}
