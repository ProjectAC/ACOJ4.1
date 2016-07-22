#pragma once

#include "Type.h"

namespace ACJudge
{
	class Data
	{
	private:
		ID did;  //数据ID
		Limit time;  //时间限制
		Limit space;  //空间限制
		Score score;  //测试点得分

	public:
		void Prepare();  //准备数据点
		Data(ID d, Limit t, Limit s, Score sc);

		ID GetID() const { return did; }
		Limit GetTime() const { return time; }
		Limit GetSpace() const { return space; }
		Score GetScore() const { return score; }
	};
}