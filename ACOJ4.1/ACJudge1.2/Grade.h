#pragma once

#include "Type.h"

namespace ACJudge
{
	class Grade
	{
	private:
	public:
		ID sid;  //提交号
		ID did;  //数据号
		Score score;  //打分
		Result result;  //单点评测结果
		Text msg;  //返回错误信息

	public:
		Grade(Result r, Score s, ID si, ID di)
			:result(r), score(s), sid(si), did(di) {}
	};

	class Grades
	{
		Array<Grade> grades;
		Result result;
		ID sid;

	public:
		void SetResult(Result r) { result = r; }
		Result GetResult() { return result; }
		ID GetID() { return sid; }
		void Push(Grade g) { grades.push_back(g); }
		Array<Grade> GetGrade() { return grades; }
	};
}