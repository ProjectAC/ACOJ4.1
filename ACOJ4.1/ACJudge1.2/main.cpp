#include "Database.h"
#include "Judge.h"
#include <thread>
#include <mutex>
#include <utility>
#include <chrono>
#include <functional>
#include <atomic>
#include <iostream>

using namespace std;
using namespace ACJudge;

void action(mutex &m, Database &db, Text n)
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
	mutex m;

	thread t1(action, ref(m), ref(db), _T("Œ∫‰Ï≥–"));
	t1.join();
	thread t2(action, ref(m), ref(db), _T("Œ∫‰Ïº≈"));
	t2.join();
}

int _tmain()
{
	thread t(start);
	t.join();

	return 0;
}