#pragma once

#include "Type.h"
#include "SandBox.h"
#include "Task.h"
#include "Grade.h"
#include "Submission.h"
#include "Database.h"

namespace ACJudge
{
	class Judge
	{
	private:
		Text name;
		
	protected:
		Grades JudgeCode(const Task &t, const Submission &s);
		//Grades JudgeAnswer();

	public:
		Grades Judges(const Task &t, const Submission &s);
		Judge(Text n) { name = n; }
	};
}