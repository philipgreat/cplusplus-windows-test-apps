
SecuritySetps.dll: dlldata.obj SecuritySet_p.obj SecuritySet_i.obj
	link /dll /out:SecuritySetps.dll /def:SecuritySetps.def /entry:DllMain dlldata.obj SecuritySet_p.obj SecuritySet_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del SecuritySetps.dll
	@del SecuritySetps.lib
	@del SecuritySetps.exp
	@del dlldata.obj
	@del SecuritySet_p.obj
	@del SecuritySet_i.obj
