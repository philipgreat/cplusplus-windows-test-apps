; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUTest2View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "UTest2.h"
LastPage=0

ClassCount=11
Class1=CUTest2App
Class2=CUTest2Doc
Class3=CUTest2View
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CDebugUDP
Class7=CEToolBar
Class8=CEStatusBar
Class9=CEComoBox
Class10=CEComboBox
Resource2=IDR_MAINFRAME
Class11=CTerapicoOptionDialog
Resource3=IDD_TERAPICO_OPTION_DIALOG

[CLS:CUTest2App]
Type=0
HeaderFile=UTest2.h
ImplementationFile=UTest2.cpp
Filter=N

[CLS:CUTest2Doc]
Type=0
HeaderFile=UTest2Doc.h
ImplementationFile=UTest2Doc.cpp
Filter=N

[CLS:CUTest2View]
Type=0
HeaderFile=UTest2View.h
ImplementationFile=UTest2View.cpp
Filter=C
BaseClass=CEditView
VirtualFilter=VWC
LastObject=CUTest2View


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=UTest2.cpp
ImplementationFile=UTest2.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_SELECT_ALL
Command15=IDM_EDIT_OPTION
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=ID_APP_ABOUT
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_SELECT_ALL
Command2=ID_EDIT_COPY
Command3=ID_FILE_NEW
Command4=ID_FILE_OPEN
Command5=ID_FILE_PRINT
Command6=ID_FILE_SAVE
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_CUT
Command15=ID_EDIT_UNDO
CommandCount=15

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_FILE_PRINT
Command7=ID_APP_ABOUT
Command8=ID_FILE_SAVE
Command9=ID_BUTTON32773
Command10=ID_BUTTON32774
Command11=IDC_CLEARCOMBO
CommandCount=11

[CLS:CDebugUDP]
Type=0
HeaderFile=DebugUDP.h
ImplementationFile=DebugUDP.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CDebugUDP

[CLS:CEToolBar]
Type=0
HeaderFile=EToolBar.h
ImplementationFile=EToolBar.cpp
BaseClass=CToolBar
Filter=W
LastObject=CEToolBar

[CLS:CEStatusBar]
Type=0
HeaderFile=EStatusBar.h
ImplementationFile=EStatusBar.cpp
BaseClass=CStatusBar
Filter=W
LastObject=CEStatusBar

[CLS:CEComoBox]
Type=0
HeaderFile=EComoBox.h
ImplementationFile=EComoBox.cpp
BaseClass=CComboBox
Filter=W
VirtualFilter=cWC
LastObject=CEComoBox

[CLS:CEComboBox]
Type=0
HeaderFile=EComboBox.h
ImplementationFile=EComboBox.cpp
BaseClass=CComboBox
Filter=W
VirtualFilter=cWC
LastObject=CEComboBox

[CLS:CTerapicoOptionDialog]
Type=0
HeaderFile=TerapicoOptionDialog.h
ImplementationFile=TerapicoOptionDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CTerapicoOptionDialog
VirtualFilter=dWC

[DLG:IDD_TERAPICO_OPTION_DIALOG]
Type=1
Class=CTerapicoOptionDialog
ControlCount=5
Control1=IDC_STATIC,button,1342177287
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_EDIT_MAX_LENGH,edit,1350631552
Control5=IDC_STATIC,static,1342308352

