#include        <windows.h>
#include	<stdio.h>
#include	<string.h>
#include	"mysql_m.h"

MYSQL *do_connect(char *host_name,char *user_name,char *password,char *db_name,unsigned int port_num,char *sock_name,unsigned int flag)
{

	MYSQL *con;
	con=mysql_init(NULL);

	//mysql_options(con,1,&con);
	mysql_options(con,MYSQL_SET_CHARSET_NAME,"gbk");

	if(con==NULL)
	{
		
		return NULL;
	}
	if(mysql_real_connect(con,host_name,user_name,password,db_name,port_num,sock_name,flag)==NULL)
	{
		
		return NULL;
	}
	return(con);
}
void do_disconnect(MYSQL *con)
{
	mysql_close(con);

}

void process_result_set(MYSQL *con,MYSQL_RES *rs)
{

	MYSQL_ROW row;
	unsigned int count;
	while ((row=mysql_fetch_row(rs))!=NULL)
	{
		for(count=0;count<mysql_num_fields(rs);count++)

		{	if (count>0) printf("\t ; ");
			printf("%10s",row[count]!=NULL?row[count]:"NULL");
		}
		printf("\n");
	}//while()

	printf("There are %lu rows affected by the query!!\n\n ",mysql_num_rows(rs)) ;
}