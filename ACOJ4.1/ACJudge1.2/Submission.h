#pragma once

#include "Type.h"
#include "Data.h"
#include "Code.h"

namespace ACJudge
{
	class Submission
	{
	private:
		ID sid;  //提交号
		Array<Data> data;  //提交答案题：答案
		Code code;  //非提交答案：代码

	public:

		Return Prepare() const;  //准备选手代码或答案

		const Array<Data>& GetData() const { return data; }
		const Code& GetCode() const { return code; }
		const ID& GetID() const { return sid; }
	};
}