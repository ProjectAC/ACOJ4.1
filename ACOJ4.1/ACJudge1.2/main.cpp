#include "Database.h"
#include "Judge.h"
#include <thread>
#include <mutex>
#include <iostream>

using namespace std;
using namespace ACJudge;

void action(mutex &m, Database &db, Text n, int cnt)
{
	Judge judge(n);
	Task t;
	Submission s;

	while (true)
	{
		{lock_guard<mutex> lock(m); db.Read(t, s); }
		Grades g = judge.Judges(t, s);
		{lock_guard<mutex> lock(m); db.Write(g);}

#if defined WINDOWS
		Sleep(1000);
#endif
	}
}

void start()
{
	Database db;
	int cnt;

	thread t1(action, db, _T("Œ∫‰Ï≥–"), cnt);
	t1.join();
	thread t2(action, db, _T("Œ∫‰Ïº≈"), cnt);
	t2.join();
}

int _tmain()
{
	thread t(start);
	t.join();

	return 0;
}