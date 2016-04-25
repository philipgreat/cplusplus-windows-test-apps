
TestCom2ps.dll: dlldata.obj TestCom2_p.obj TestCom2_i.obj
	link /dll /out:TestCom2ps.dll /def:TestCom2ps.def /entry:DllMain dlldata.obj TestCom2_p.obj TestCom2_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del TestCom2ps.dll
	@del TestCom2ps.lib
	@del TestCom2ps.exp
	@del dlldata.obj
	@del TestCom2_p.obj
	@del TestCom2_i.obj
