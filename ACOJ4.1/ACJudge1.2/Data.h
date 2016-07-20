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

	public:
		void Init(ID i, Database db);  //从数据库中加载
		void Prepare(Text file);  //准备数据点

		Limit get_time();
		Limit get_space();
	};
}