# Microsoft Developer Studio Project File - Name="CWService" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=CWService - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CWService.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CWService.mak" CFG="CWService - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CWService - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "CWService - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/IPTV/2.开发区/4.机顶盒应用/testing/LicenseServiceTesting", QNPAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CWService - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "CWService - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /D "VCPROJECT_DEBUG" /FR /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "CWService - Win32 Release"
# Name "CWService - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AbstractHandle.cpp
# End Source File
# Begin Source File

SOURCE=.\BaseCertificate.cpp
# End Source File
# Begin Source File

SOURCE=.\CertificateManager.cpp
# End Source File
# Begin Source File

SOURCE=.\CertificateParserHelper.cpp
# End Source File
# Begin Source File

SOURCE=.\CWService.cpp
# End Source File
# Begin Source File

SOURCE=.\DirectoryHelper.cpp
# End Source File
# Begin Source File

SOURCE=.\FackHandle.cpp
# End Source File
# Begin Source File

SOURCE=.\GenericSAXParser.cpp
# End Source File
# Begin Source File

SOURCE=.\HttpUtil.cpp
# End Source File
# Begin Source File

SOURCE=.\Parameter.cpp
# End Source File
# Begin Source File

SOURCE=.\Parameters.cpp
# End Source File
# Begin Source File

SOURCE=.\RequestQueue.cpp
# End Source File
# Begin Source File

SOURCE=.\SerializableCertificate.cpp
# End Source File
# Begin Source File

SOURCE=.\ServiceObject.cpp
# End Source File
# Begin Source File

SOURCE=.\ServiceRequest.cpp
# End Source File
# Begin Source File

SOURCE=.\STBConfiguration.cpp
# End Source File
# Begin Source File

SOURCE=.\UdpServer.cpp
# End Source File
# Begin Source File

SOURCE=.\URLParameters.cpp
# End Source File
# Begin Source File

SOURCE=.\VolatileCertificate.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AbstractHandle.h
# End Source File
# Begin Source File

SOURCE=.\BaseCertificate.h
# End Source File
# Begin Source File

SOURCE=.\CertificateManager.h
# End Source File
# Begin Source File

SOURCE=.\CertificateParserHelper.h
# End Source File
# Begin Source File

SOURCE=.\DirectoryHelper.h
# End Source File
# Begin Source File

SOURCE=.\FackHandle.h
# End Source File
# Begin Source File

SOURCE=.\FileListHandle.h
# End Source File
# Begin Source File

SOURCE=.\GenericSAXParser.h
# End Source File
# Begin Source File

SOURCE=.\HttpUtil.h
# End Source File
# Begin Source File

SOURCE=.\Parameter.h
# End Source File
# Begin Source File

SOURCE=.\Parameters.h
# End Source File
# Begin Source File

SOURCE=.\RequestQueue.h
# End Source File
# Begin Source File

SOURCE=.\SerializableCertificate.h
# End Source File
# Begin Source File

SOURCE=.\ServiceObject.h
# End Source File
# Begin Source File

SOURCE=.\ServiceRequest.h
# End Source File
# Begin Source File

SOURCE=.\STBConfiguration.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\UDPServer.h
# End Source File
# Begin Source File

SOURCE=.\URLParameters.h
# End Source File
# Begin Source File

SOURCE=.\VolatileCertificate.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
