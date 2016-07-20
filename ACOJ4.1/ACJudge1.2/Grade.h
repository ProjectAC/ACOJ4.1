#pragma once

#include "Type.h"

namespace ACJudge
{
	class Grade
	{
	private:
		ID sid;
		ID did;
		Score score;
		Result result;

	public:
		Grade(Result r, Score s, ID si, ID di)
			:result(r), score(s), sid(si), did(di) {}
	};

	class Grades
	{
		Array<Grade> grades;
		Result s;
		ID sid;
	};
}