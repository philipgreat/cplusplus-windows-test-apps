//Source file: F:\\suddy\\java\\com\\channelsoft\\voicebrowser\\VoiceBrowser.java

package com.channelsoft.voicebrowser;


import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.MalformedURLException;
import java.util.Iterator;
import java.util.List;
import java.util.Properties;
import java.util.Vector;

import javax.xml.parsers.ParserConfigurationException;

import org.xml.sax.SAXException;


/**
 * 启动VoiceBrowser的主类,该类负责管理多个通道,每个通道(包含一个信令和语音通道)就是 一个窗口.
 */
public class VoiceBrowser extends Thread {
	private String startPage;

	private String popupPage;

	private boolean isOfflinePreparationState;

	private List<VoiceWindow> voiceWindowList;

	private String localVoiceFilePath;

	private MediaEventSender mediaEvnetSender;

	private SignalEventSender signalEvnetSender;

	private TimerEventSender timerEventSender;

	private DownloadingTaskExecutor downloadingTaskExecutor;

	private VoiceEventQueue voiceEventQueue;

	private IVoiceGateway gateway;
	private Properties config;

	private boolean running = true;

	/**
	 * @roseuid 45ECE5720157
	 */
	public VoiceBrowser() {
		voiceWindowList = new Vector<VoiceWindow>();
		config=new Properties();
		
		
	}

	public void config() throws ResourceNotAvailableException {
		config.put(UvmgImplementation.PROXY_CONFIG_ITEM,
				"VGProxy:default -h 10.130.29.168 -p 10000");
		
		config.put(UvmgImplementation.VOICE_ROOT_CONFIG, "d:\\voicefiles");
		gateway = new UvmgImplementation();
		if(!gateway.initialize(config)){			
			throw new ResourceNotAvailableException(gateway.getFatalMessage());			
		}
		voiceEventQueue = new VoiceEventQueue();		
		mediaEvnetSender = new MediaEventSender(gateway, voiceEventQueue);
		signalEvnetSender = new SignalEventSender(gateway, voiceEventQueue);
		timerEventSender = new TimerEventSender(voiceEventQueue);
		downloadingTaskExecutor = new DownloadingTaskExecutor(voiceEventQueue);
	}

	/**
	 * @roseuid 45C45436029F
	 */
	public void browsePage() {

	}

	/**
	 * @roseuid 45C455880186
	 */
	public void goHome() {

	}

	/**
	 * @param event
	 * @roseuid 45C45B3202DE
	 */
	boolean poped = false;

	private void popupWindow(VoiceBrowserEvent event)
			throws MalformedURLException, FileNotFoundException, IOException,
			SAXException, ParserConfigurationException,
			ResourceNotAvailableException {
		if (!poped) {
			System.out.println("popupWindow");
			VoiceWindow window = createVoiceWindow();
			//window.browse("http://suddy.channel.com:8080/voice/voicedialect");
			//window.browse("http://10.130.28.198:8080/xsmFlowLogic/voicedialect");
			//window.browse("http://suddy.channel.com/perf/simpleflow.jsp");
			window.browse(this.popupPage);			
			poped = true;
		}
	}

	private VoiceWindow createVoiceWindow() {
		VoiceWindow window = new VoiceWindow();
		window.setVoiceGateway(gateway);
		this.voiceWindowList.add(window);
		return window;
	}

	/**
	 * @roseuid 45C45B4D004E
	 */
	public void startBrowser() {

		mediaEvnetSender.start();
		signalEvnetSender.start();
		timerEventSender.start();
		downloadingTaskExecutor.start();
		this.start();
		try {
			mediaEvnetSender.join();
			signalEvnetSender.join();
			timerEventSender.join();
			downloadingTaskExecutor.join();

		} catch (InterruptedException e) {
			
			e.printStackTrace();
		}
	}

	public void exitBrowser() {
		mediaEvnetSender.exit();
		signalEvnetSender.exit();
		timerEventSender.exit();
		downloadingTaskExecutor.exit();
	}

	/**
	 * @roseuid 45C45CA7000F
	 */
	private VoiceWindow findAnIdleWindow(VoiceBrowserEvent event) {
		Iterator iter = this.voiceWindowList.iterator();
		VoiceWindow selectedWindow = null;

		while (iter.hasNext()) {
			VoiceWindow window = (VoiceWindow) iter.next();
			if (window.isIdle()) {
				selectedWindow = window;
				break;
			}
		}

		return selectedWindow;
	}

	private VoiceWindow selectWindowForProcEvent(VoiceBrowserEvent event) {
		Iterator iter = this.voiceWindowList.iterator();
		VoiceWindow selectedWindow = null;

		while (iter.hasNext()) {
			VoiceWindow window = (VoiceWindow) iter.next();
			if (window.getResourceId() == event.getResourceId()) {
				selectedWindow = window;
				break;
			}
		}
		return selectedWindow;
	}

	public void dispatchEvent(VoiceBrowserEvent event) {
		// TODO Auto-generated method stub
		VoiceWindow selectedWindow = null;
		event.setGateway(gateway);
		if (event.hasInboundCall()) {
			selectedWindow = findAnIdleWindow(event);
		} else if (event.isTimer()) {
			try {
				popupWindow(event);
			} catch (MalformedURLException e) {				
				e.printStackTrace();
			} catch (FileNotFoundException e) {				
				e.printStackTrace();
			} catch (IOException e) {				
				e.printStackTrace();
			} catch (SAXException e) {				
				e.printStackTrace();
			} catch (ParserConfigurationException e) {				
				e.printStackTrace();
			} catch (ResourceNotAvailableException e) {				
				e.printStackTrace();
			}
			broadCastTimerEvent(event);
		} else {
			selectedWindow = selectWindowForProcEvent(event);
		}
		if (selectedWindow != null) {
			selectedWindow.dispatchEvent(event);
		}

	}
	private void broadCastTimerEvent(VoiceBrowserEvent event)
	{
		Iterator iter = this.voiceWindowList.iterator();
		while (iter.hasNext()) {
			VoiceWindow window = (VoiceWindow) iter.next();
			window.dispatchEvent(event);
		}		
	}
	
	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Thread#run()
	 */
	@Override
	public void run() {
		// TODO Auto-generated method stub
		while (running) {

			try {
				VoiceBrowserEvent event = voiceEventQueue.getEvent(100);
				//System.out.println(event);
				this.dispatchEvent(event);
			} catch (InterruptedException e) {
				
				// e.printStackTrace();
			}

		}
	}

	public static void main(String[] args) {
		
		if(args.length<1){
			
			System.out.println("please use like this:\r\n\t");
			System.out.println("\tjava -jar voicebrowser.jar <your flowlogic url>");			
			System.exit(1);			
		}
		
		VoiceBrowser browser = new VoiceBrowser();
		try {
			browser.setPopupPage(args[0]);
			browser.config();
			browser.startBrowser();
		} catch (ResourceNotAvailableException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	private void setPopupPage(String popupPage) {
		// TODO Auto-generated method stub
		this.popupPage=popupPage;
	}
}
