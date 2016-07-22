#include "Database.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace ACJudge;

Database::Database()
{
	mysql_init(&conn);
	if (!mysql_real_connect(&conn, "localhost", "judgeaccess", "judgeaccess", "ACOJ", 3306, NULL, 0))
		return;

	mysql_query(&conn, "SET NAMES UTF-8");
	cout << "Database connected successfully!" << endl;
}

void Database::Read(Task &task, Submission &submission)
{
	MYSQL_RES *result;
	MYSQL_ROW row;
	int ret;

	ret = mysql_query(&conn, "SELECT * FROM submission WHERE status = -1 ORDER BY time");  //²éÑ¯
	if (!ret)
	{
		result = mysql_store_result(&conn);
		row = mysql_fetch_row(result);
	}

	task = Task();
}
