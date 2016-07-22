#pragma once

#include "Type.h"
#include "Submission.h"
#include "Task.h"
#include "Grade.h"
#if defined WINDOWS
#include <Windows.h>
#endif
#include "header/mysql.h"

namespace ACJudge
{
	class Database
	{
	private:
		MYSQL conn;

	public:
		Database();
		void Read(Task &t, Submission &s);
		void Write(Grades g);
	};
}