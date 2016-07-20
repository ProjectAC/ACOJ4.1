#pragma once

#include "Type.h"

namespace ACJudge
{
	class Data
	{
	private:
		ID did;  //数据ID
		Text in;  //输入文件内容
		Text out;  //输出文件内容
		Limit time;  //时间限制
		Limit space;  //空间限制
		Score score;  //测试点得分

	public:
		void Prepare(Text file);  //准备数据点

		ID GetID() const { return did; }
		Limit GetTime() const { return time; }
		Limit GetSpace() const { return space; }
		Score GetScore() const { return score; }
	};
}