#pragma once

#include "Type.h"

namespace ACJudge
{
	class Grade
	{
	private:
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
		void SetResult(Result);
		void Push(Grade);
	};
}