//Source file: F:\\suddy\\java\\com\\channelsoft\\voicebrowser\\VoiceWindow.java

package com.channelsoft.voicebrowser;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.MalformedURLException;
import java.util.Date;
import java.util.Properties;

import javax.xml.parsers.ParserConfigurationException;

import org.xml.sax.SAXException;

import Ice.IntHolder;

import com.channelsoft.common.HttpSession;
import com.channelsoft.common.NetLogger;
import com.channelsoft.common.StringTool;

/**
 * 处理所有的异常情况, 作为事件报告给服务器
 */
public class VoiceWindow {
	private boolean isIdleState = true;

	private NetLogger log;

	private String currentUrl;

	private HttpSession session;

	private VoicePage currentPage;

	private static final int BAD_CALL_STATE = 0xffffff;

	private int callId = 0xffffffff;

	private int resourceId = 0xffffffff;

	private IVoiceGateway gateway;

	private Properties properties;

	public VoiceWindow() {
		properties = new Properties();
		log = NetLogger.getDefaultLogger(VoiceWindow.class);
	}

	public void setParameter(String name, String value) {
		if (name != null && value != null) {
			properties.put(name, value);
		} else {
			System.out.println("set " + name + "=" + value + "");
		}
	}

	public void setVoiceGateway(IVoiceGateway gateway) {
		this.gateway = gateway;
	}

	public void dispatchEvent(VoiceBrowserEvent event) {
		// TODO 任何时候收到挂机信号,或者callId发生了变化,则把当前的状态设置为闲的状态
		System.out.println(event);
		log.info(event.toString());
		if (event.isDisconnected()) {
			this.setParameter("event", "用户挂机");
			this.onCallEnd();
			return;
		}

		// 并且提交页面
		if (currentPage != null) {
			// open a new page for open
			boolean ret = currentPage.onEvent(event);
			if (ret) {
				onPageEnd();
				// isIdleState = true;
			}
		}
	}

	/**
	 * @param url
	 * @throws IOException
	 * @throws FileNotFoundException
	 * @throws MalformedURLException
	 * @throws ParserConfigurationException
	 * @throws SAXException
	 * @roseuid 45C458F70157
	 */
	public boolean loadAndShowPage(String url) throws MalformedURLException,
			FileNotFoundException, IOException, SAXException,
			ParserConfigurationException, ResourceNotAvailableException {
		currentPage = new VoicePage();
		if (session == null) {
			session = new HttpSession();
			session.setUserAgent("VoiceBrowser(" + this.resourceId + "/"
					+ this.callId + ")");
		}
		String text = session.downloadText(url);
		System.out.println("page:" + text);
		log.info(text);
		currentPage = XMLPageFactory.getPageByString(text, this);
		currentPage.setDocumentURL(url);
		boolean endThisPage = currentPage.showPage();
		if (endThisPage && !this.isIdleState) {
			// 发现了当前页面结束并且当前还没有挂机
			return true;
		} else {
			return false;
		}

	}

	// 如果这个页面结束，并且没有更新的任务，则不再发送新的请求
	// 设置窗口为idle状态的只是存在于HangupTask中
	// 设置窗口为非idle状态的存在于Answercall和hangup中
	// send new request to server; or set it to idle
	public void browse(String url) throws MalformedURLException,
			FileNotFoundException, IOException, SAXException,
			ParserConfigurationException, ResourceNotAvailableException {

		boolean continueToShowAnotherPage;
		this.currentUrl = url;
		System.out.println("req: " + url);
		properties = new Properties();

		do {
			continueToShowAnotherPage = loadAndShowPage(url);
		} while (continueToShowAnotherPage);

	}

	public void browse(VoicePage page)  {
		currentPage = page;
		boolean endThisPage = currentPage.showPage();
		if(endThisPage){
			//send another download request
			this.onPageEnd();
		}
	}


	public int getCallId() {
		// TODO Auto-generated method stub
		return callId;
	}

	public int getResourceId() {
		// TODO Auto-generated method stub
		return resourceId;
	}

	/**
	 * @param callId
	 *            the callId to set
	 */
	public void setCallId(int callId) {
		this.callId = callId;
	}

	/**
	 * @param resourceId
	 *            the resourceId to set
	 */
	public void setResourceId(int resourceId) {
		this.resourceId = resourceId;
	}

	public boolean isIdle() {
		// TODO Auto-generated method stub
		return this.isIdleState;
	}

	public void onCallStart(String src, String dest, int timeout) {
		// theBrowser

		IntHolder resourceId = new IntHolder(0);
		IntHolder callId = new IntHolder(0);
		// this.setParameter("date", (new Date()).toString());

		int ret = gateway.blindMakeCall(resourceId, callId, src, dest, timeout);
		if (ret == 0) {
			this.resourceId = resourceId.value;
			this.callId = callId.value;
			this.isIdleState = false;
		} else {
			this.isIdleState = true;
			this.onCallEnd();
		}
	}

	public int playFile(String file, String interrupt, int rate) {
		if (callId >= 0 && resourceId >= 0) {
			return gateway.playFile(this.resourceId, this.callId, file,
					interrupt, rate);
		} else {
			return BAD_CALL_STATE;
		}
	}

	public void onPageEnd() {

		try {
			String req = StringTool
					.buildRequestUrl(currentUrl, this.properties);
			log.info("event: " + this.properties.get("event"));
			// this.session.downloadText(req);
			// System.out.println(Thread.currentThread().getName());
			// Thread.sleep(1000);
			this.browse(req);
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
	}

	public void onCallEnd() {

		if (callId >= 0 && resourceId >= 0) {
			gateway.releaseCall(this.resourceId, this.callId);
		}
		resourceId = -1;
		this.callId = -1;
		this.isIdleState = true;
		try {
			String req = StringTool
					.buildRequestUrl(currentUrl, this.properties);
			// System.out.println("event: " + this.properties.get("event"));
			log.info("event: " + this.properties.get("event"));
			String text = this.sendRequest(req); // released
			log.info(text);
			// Thread.sleep(1000);
			this.session.newSession();
			this.browse(req);

		} catch (MalformedURLException e) {
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (SAXException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ParserConfigurationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ResourceNotAvailableException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private String sendRequest(String req) throws MalformedURLException,
			FileNotFoundException, IOException {
		// TODO Auto-generated method stub
		return session.downloadText(req);
	}

	public int onGetDTMF(int maxKeys, String interruptKeys,
			int firstKeyWaitMillionSeconds, int intervalKeyWaitMillionSeconds) {
		if (callId >= 0 && resourceId >= 0) {
			return gateway.getDTMF(this.resourceId, this.callId, maxKeys,
					interruptKeys, firstKeyWaitMillionSeconds,
					intervalKeyWaitMillionSeconds);
		} else {
			return BAD_CALL_STATE;
		}
	}

	public int clearDtmfBuffer() {
		if (callId >= 0 && resourceId >= 0) {
			return gateway.clearDtmfBuffer(this.resourceId, this.callId);
		} else {
			return BAD_CALL_STATE;
		}
	}

}
