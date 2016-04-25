
SecuritySetManagementps.dll: dlldata.obj SecuritySetManagement_p.obj SecuritySetManagement_i.obj
	link /dll /out:SecuritySetManagementps.dll /def:SecuritySetManagementps.def /entry:DllMain dlldata.obj SecuritySetManagement_p.obj SecuritySetManagement_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del SecuritySetManagementps.dll
	@del SecuritySetManagementps.lib
	@del SecuritySetManagementps.exp
	@del dlldata.obj
	@del SecuritySetManagement_p.obj
	@del SecuritySetManagement_i.obj
