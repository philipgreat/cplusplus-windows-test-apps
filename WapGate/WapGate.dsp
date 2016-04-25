# Microsoft Developer Studio Project File - Name="WapGate" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=WapGate - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "WapGate.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WapGate.mak" CFG="WapGate - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WapGate - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "WapGate - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WapGate - Win32 Release"

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
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WS2_32.LIB /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "WapGate - Win32 Debug"

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
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 WS2_32.LIB kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "WapGate - Win32 Release"
# Name "WapGate - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TeraPicoClientSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\TeraPicoHttpBody.cpp
# End Source File
# Begin Source File

SOURCE=.\TeraPicoHttpContent.cpp
# End Source File
# Begin Source File

SOURCE=.\TeraPicoHttpHeader.cpp
# End Source File
# Begin Source File

SOURCE=.\TeraPicoHttpRequest.cpp
# End Source File
# Begin Source File

SOURCE=.\TeraPicoLocalUdpSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\TeraPicoLogFile.cpp
# End Source File
# Begin Source File

SOURCE=.\TeraPicoMemoryPool.cpp
# End Source File
# Begin Source File

SOURCE=.\TeraPicoRemoteSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\TeraPicoRemoteUdpSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\TeraPicoServerSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\TeraPicoWapGateService.cpp
# End Source File
# Begin Source File

SOURCE=.\WapGate.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoClientSocket.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoCommon.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoHttpBody.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoHttpContent.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoHttpHeader.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoHttpRequest.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoHttpRequst.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoLocalUdpSocket.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoLogFile.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoMemoryPool.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoRemoteSocket.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoRemoteUdpSocket.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoServerSocket.h
# End Source File
# Begin Source File

SOURCE=.\TeraPicoWapGateService.h
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
