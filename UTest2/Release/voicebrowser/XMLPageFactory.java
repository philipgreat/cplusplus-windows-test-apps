package com.channelsoft.voicebrowser;

import java.io.IOException;
import java.io.StringReader;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.Attributes;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

public class XMLPageFactory {
	public static VoicePage getPageByString(String content)
			throws SAXException, IOException, ParserConfigurationException {
		InputSource is = new InputSource(new StringReader(content));
		SAXParserFactory factory = SAXParserFactory.newInstance();
		factory.setValidating(true);
		VoicePageHandler handler = new VoicePageHandler();
		factory.newSAXParser().parse(is, handler);
		return handler.getVoicePage();
	}

	public static VoicePage getPageByString(String content,VoiceWindow context)
			throws SAXException, IOException, ParserConfigurationException,ResourceNotAvailableException {
		
		if(context==null){			
			throw new ResourceNotAvailableException("bad widnow context");
		}
		InputSource is = new InputSource(new StringReader(content));
		SAXParserFactory factory = SAXParserFactory.newInstance();
		factory.setValidating(true);
		VoicePageHandler handler = new VoicePageHandler();
		VoicePage page=handler.getVoicePage();
		page.setContext(context);
		factory.newSAXParser().parse(is, handler);
		
		return page;
	}
	

}
