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
}

void Database::Read(Task &task, Submission &submission)
{
	MYSQL_RES *result;
	MYSQL_ROW row;

	//Ѱ�����һ���ύ
	mysql_query(&conn, "SELECT sid, submission.tid, submission.language, type, task.language FROM submission, task WHERE result = -1 AND submission.tid = task.tid ORDER BY time");
	result = mysql_store_result(&conn);
	row = mysql_fetch_row(result);

	//�ύ�š���Ŀ��
	ID sid, tid;
	Language lsub, lspj;
	sscanf(row[0], "%llu", &sid);
	sscanf(row[1], "%llu", &tid);

	//ѡ������
	if (row[2][0] == '1')
		lsub = Language::CPP;

	//��Ŀ����
	TaskType type;
	if (row[3][0] == '0')
		type = TaskType::OI;

	//Spj����
	if (row[4][0] == '1')
		lsub = Language::CPP;

	//��ȡ�ύ��
	Array<Answer> ans;

	//��ȡ��������
	TCHAR *cmd = new TCHAR[1000];
	sprintf(cmd, "SELECT * FROM data WHERE tid = %d", tid);
	mysql_query(&conn, cmd);
	result = mysql_store_result(&conn);
	Array<Data> data;
	while (row = mysql_fetch_row(result))
	{
		ID did;
		Limit time, space;
		Score score;

		sscanf(row[0], "%llu", &did);
		sscanf(row[1], "%u", &time);
		sscanf(row[2], "%u", &space);
		sscanf(row[3], "%u", &score);

		data.push_back(Data(did, time, space, score));
	}
	
	//����Task����
	sprintf(cmd, "spj/%d/spj.src", tid);
	task = Task(tid, type, data, Code(cmd, lspj));
	//����Submission����
	sprintf(cmd, "submission/%d/sol.src", sid);
	submission = Submission(sid, tid, ans, Code(cmd, lsub));
}

void Database::Write(Grades g)
{
	TCHAR *cmd = new TCHAR[1000];
	sprintf(cmd, "UPDATE submission SET result = %d WHERE sid = %d", g.GetResult(), g.GetID());
	mysql_query(&conn, cmd);

	Array<Grade> grade = g.GetGrade();
	for (auto &i : grade)
	{
		sprintf(cmd, "UPDATE submission SET score = %d, result = %d, message='%s' WHERE sid = %d AND did = %d", i.score, i.result, i.msg, i.sid, i.did);
	}
}