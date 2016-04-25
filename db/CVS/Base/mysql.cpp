// mysql.cpp: implementation of the mysql class.
//
//////////////////////////////////////////////////////////////////////

#include	 "stdafx.h"
//#include	 "vc_my.h"
#include     <winsock.h>
#include	 "mysql.h"
#include     "mysql_add.h"

//#pragma   comment("libmysql.lib")                                                                                                                                                                                                                                                                                                                                                                  
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

mysql::mysql()
{

}
mysql::mysql(char *host_name,char *user_name,char *password,char *db_name,unsigned int port_num)
{

}

mysql::~mysql()
{

}

MYSQL * mysql::connect(char *host_name, char *user_name, char *password, char *db_name, unsigned int port_num, char *sock_name, unsigned int flag)
{
	return do_connect(host_name,user_name,password,db_name, port_num,sock_name,flag);
	//return NULL;
	//con=do_connect( "csi04", "root","gftjak", "chat", 0, "csi04", 0 )

}

void mysql::disconnect(MYSQL *con)
{
	mysql_close(con);

}

int mysql::mysql_exec(MYSQL *con, char *statment)
{
	return mysql_query(con,statment);
}

MYSQL_RES * mysql::store_result(MYSQL *con)
{
	return mysql_store_result(con);

}

MYSQL_ROW mysql::fetch_row(MYSQL_RES *rs)
{
	return mysql_fetch_row(rs);
}

unsigned long mysql::num_rows(MYSQL_RES *rs)
{
	return (unsigned long)mysql_num_rows(rs);
}

unsigned long mysql::num_fields(MYSQL_RES *rs)
{
	return mysql_num_fields(rs);
}

void mysql::free_result(MYSQL_RES *rs)
{
	mysql_free_result(rs);

}

int mysql::mysql_exec(MYSQL *con, CString sql)
{
	char *stat;
	stat=sql.GetBuffer (sql.GetLength ());

	return mysql_query(con,stat);
}

void mysql::escape_string(CString from)
{
	
	from.Replace ("\\","\\\\");
	from.Replace ("\'","\\\'");	

}

int mysql::select_db(MYSQL *mysql, CString db)
{
	return mysql_select_db(mysql, db.GetBuffer (db.GetLength ()));
}

MYSQL_RES * mysql::list_dbs(MYSQL *mysql,CString wild )
{
	return  mysql_list_dbs(mysql,wild.GetBuffer (wild.GetLength() ) );

}

MYSQL_RES * mysql::list_tables(MYSQL *mysql, CString wild)
{
	return  mysql_list_tables(mysql,wild.GetBuffer (wild.GetLength() ) );
}

MYSQL_RES * mysql::list_fields(MYSQL *mysql, CString table, CString wild)
{
	return  mysql_list_fields(mysql,table.GetBuffer(table.GetLength ()),wild.GetBuffer (wild.GetLength()));
}

void mysql::data_seek(MYSQL_RES *result, unsigned int offset)
{
	mysql_data_seek(result, offset);
}

int mysql::create_db(MYSQL *mysql, CString db)
{
	return mysql_create_db(mysql, db.GetBuffer (db.GetLength ()));

}

int mysql::drop_db(MYSQL *mysql, CString db)
{
	return mysql_drop_db(mysql, db.GetBuffer (db.GetLength ()));
}

char* mysql::error(MYSQL *mysql)
{
	return mysql_error(mysql);

}
