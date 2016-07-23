#pragma once

#include "Type.h"
#include "Data.h"
#include "Answer.h"
#include "Code.h"

namespace ACJudge
{
	class Submission
	{
	private:
		ID sid;  //提交号
		ID tid;  //题目号
		Array<Answer> data;  //提交答案题：答案
		Code code;  //非提交答案：代码

	public:
		Submission(ID s, ID t, Array<Answer> d, Code c) : sid(s), tid(t), data(d), code(c) {}
		Submission() {}
		Return Prepare() const;  //准备选手代码或答案

		const Array<Answer>& GetData() const { return data; }
		const Code& GetCode() const { return code; }
		const ID& GetID() const { return sid; }
	};
}