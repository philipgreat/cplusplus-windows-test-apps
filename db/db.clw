; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFindResultView
LastTemplate=CListView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "db.h"
LastPage=0

ClassCount=18
Class1=CDbApp
Class2=CDbDoc
Class3=CDbView
Class4=CMainFrame
Class7=editor
Class9=tor

ResourceCount=9
Resource1=IDR_MENU1
Resource2=IDR_TOOLBAR1
Resource3="IDR_TOOLBAR1"
Resource4=IDR_MAINFRAME
Class5=CChildFrame
Class6=CAboutDlg
Class8=listor
Resource5=IDR_MENU2
Class10=title
Class11=browse
Class12=look
Resource6=IDD_ABOUTBOX
Resource7=IDR_MENU3
Class13=rename
Class14=fm
Class15=mailto
Class16=cfont_combo
Class17=CFindToolBar
Class18=CFindResultView
Resource8=IDR_DBTYPE
Resource9=IDD_FORMVIEW

[CLS:CDbApp]
Type=0
HeaderFile=db.h
ImplementationFile=db.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=ID_MENUITEM32797

[CLS:CDbDoc]
Type=0
HeaderFile=dbDoc.h
ImplementationFile=dbDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CDbDoc

[CLS:CDbView]
Type=0
HeaderFile=dbView.h
ImplementationFile=dbView.cpp
Filter=C
LastObject=ID_MENUITEM32773
BaseClass=CEditView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CMDIFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M
BaseClass=CMDIChildWnd
VirtualFilter=mfWC
LastObject=CChildFrame


[CLS:CAboutDlg]
Type=0
HeaderFile=db.cpp
ImplementationFile=db.cpp
Filter=D

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
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_MENUITEM32773
Command9=ID_APP_ABOUT
CommandCount=9

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_APP_ABOUT
Command6=ID_BUTTON32783
Command7=ID_BUTTON32784
Command8=ID_BUTTON32785
Command9=IDC_COMBO1
Command10=IDC_FIND_BUTTON
Command11=ID_BUTTONSAY
Command12=ID_BUTTON32800
CommandCount=12

[MNU:IDR_DBTYPE]
Type=1
Class=CDbView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_MENUITEM32782
Command12=ID_MENUITEM32795
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_MENUITEM32773
Command16=ID_BUTTON32783
Command17=ID_BUTTON32784
Command18=ID_BUTTON32785
Command19=ID_WINDOW_NEW
Command20=ID_WINDOW_CASCADE
Command21=ID_WINDOW_TILE_HORZ
Command22=ID_WINDOW_ARRANGE
Command23=ID_MENUITEM32780
Command24=ID_MENUITEM32781
Command25=ID_MENUITEM32790
Command26=ID_MENUITEM32791
Command27=ID_MENUITEM32792
Command28=ID_MENUITEM32793
Command29=ID_APP_ABOUT
CommandCount=29

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_MENUITEM32782
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
Command14=ID_MENUITEM32773
Command15=ID_EDIT_CUT
Command16=ID_EDIT_UNDO
CommandCount=16

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=ID_BUTTON32771
Command2=ID_BUTTON32772
CommandCount=2

[CLS:editor]
Type=0
HeaderFile=editor.h
ImplementationFile=editor.cpp
BaseClass=CEdit
Filter=W

[CLS:listor]
Type=0
HeaderFile=listor.h
ImplementationFile=listor.cpp
BaseClass=CListView
Filter=C

[TB:"IDR_TOOLBAR1"]
Type=1
Class=?
Command1=ID_BUTTON32771
Command2=ID_BUTTON32772
CommandCount=2

[CLS:tor]
Type=0
HeaderFile=tor.h
ImplementationFile=tor.cpp
BaseClass=CTreeView
Filter=C

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_VIEW_TOOLBAR
Command2=ID_VIEW_STATUS_BAR
Command3=ID_MENUITEM32773
CommandCount=3

[CLS:title]
Type=0
HeaderFile=title.h
ImplementationFile=title.cpp
BaseClass=CTreeCtrl
Filter=W

[CLS:browse]
Type=0
HeaderFile=browse.h
ImplementationFile=browse.cpp
BaseClass=CTreeView
Filter=C

[CLS:look]
Type=0
HeaderFile=look.h
ImplementationFile=look.cpp
BaseClass=CTreeView
Filter=C
VirtualFilter=VWC
LastObject=look

[MNU:IDR_MENU2]
Type=1
Class=look
Command1=ID_MENUITEM32774
Command2=ID_MENUITEM32775
Command3=ID_MENUITEM32776
Command4=ID_MENUITEM32777
Command5=ID_MENUITEM32778
Command6=ID_MENUITEM32779
CommandCount=6

[CLS:rename]
Type=0
HeaderFile=rename.h
ImplementationFile=rename.cpp
BaseClass=CDialog
Filter=D

[CLS:fm]
Type=0
HeaderFile=fm.h
ImplementationFile=fm.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_LIST1
VirtualFilter=VWC

[DLG:IDD_FORMVIEW]
Type=1
Class=fm
ControlCount=10
Control1=IDC_COMBO1,combobox,1344340227
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_LIST1,listbox,1352728833
Control5=IDC_BUTTON2,button,1342242816
Control6=IDC_BUTTON3,button,1342242816
Control7=IDC_EDIT2,edit,1484849280
Control8=IDC_BUTTON4,button,1342242816
Control9=IDC_BUTTON5,button,1342242816
Control10=IDC_BUTTON_DELETE_ITEM,button,1342242816

[CLS:mailto]
Type=0
HeaderFile=mailto.h
ImplementationFile=mailto.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT

[CLS:cfont_combo]
Type=0
HeaderFile=cfont_combo.h
ImplementationFile=cfont_combo.cpp
BaseClass=CComboBox
Filter=W
VirtualFilter=cWC
LastObject=cfont_combo

[CLS:CFindToolBar]
Type=0
HeaderFile=FindToolBar.h
ImplementationFile=FindToolBar.cpp
BaseClass=CToolBarCtrl
Filter=W
LastObject=CFindToolBar

[CLS:CFindResultView]
Type=0
HeaderFile=FindResultView.h
ImplementationFile=FindResultView.cpp
BaseClass=CListView
Filter=C
VirtualFilter=VWC
LastObject=CFindResultView

[MNU:IDR_MENU3]
Type=1
Class=CMainFrame
Command1=ID_MENUITEM32796
Command2=ID_MENUITEM32797
Command3=ID_MENUITEM32798
CommandCount=3

