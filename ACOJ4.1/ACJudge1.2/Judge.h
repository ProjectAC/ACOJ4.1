#pragma once

#include "Type.h"
#include "SandBox.h"
#include "Task.h"
#include "Grade.h"
#include "Submission.h"

namespace ACJudge
{
	class Judge
	{
	private:
		Text name;
		SandBox box;
		
	protected:
		Grades JudgeCode(const Task &t, const Submission &s);
		Grades JudgeAnswer();

	public:
		void Start(const Task &t, const Submission &s);
	};
}