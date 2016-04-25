// mysql.h: interface for the mysql class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSQL_H__6EE9AC6F_A8BD_11D4_933B_0000E8233645__INCLUDED_)
#define AFX_MYSQL_H__6EE9AC6F_A8BD_11D4_933B_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#pragma comment (lib,"libmysql.lib")
#include "mysql_m.h"


class mysql  
{
public:
	const char* error(MYSQL *mysql);
	int drop_db(MYSQL *mysql, CString db);
	int create_db(MYSQL *mysql, CString db);
	void data_seek(MYSQL_RES *result,unsigned int offset);
	MYSQL_RES * list_fields(MYSQL *mysql, CString table,CString wild);
	MYSQL_RES * list_tables(MYSQL *mysql,CString wild);
	MYSQL_RES * list_dbs(MYSQL *mysql,CString wild);
	int select_db(MYSQL *mysql, CString db);
	void escape_string(CString  from);
	int mysql_exec(MYSQL *con,CString sql);
	void free_result(MYSQL_RES *rs);
	unsigned long num_fields(MYSQL_RES *rs);
	unsigned long num_rows(MYSQL_RES *rs);

	MYSQL_ROW fetch_row(MYSQL_RES *rs);
	MYSQL_RES * store_result(MYSQL *con);
	
	MYSQL *con;

	int mysql_exec(MYSQL *con,char *statment);
	void disconnect(MYSQL *con);
	
	MYSQL * connect(char *host_name,char *user_name,char *password,char *db_name,unsigned int port_num,char *sock_name,unsigned int flag);
	mysql();
	mysql(char *host_name,char *user_name,char *password,char *db_name,unsigned int port_num);

	virtual ~mysql();

};

#endif // !defined(AFX_MYSQL_H__6EE9AC6F_A8BD_11D4_933B_0000E8233645__INCLUDED_)
