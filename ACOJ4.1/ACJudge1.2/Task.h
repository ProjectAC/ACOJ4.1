#pragma once

#include "Type.h"
#include "Data.h"
#include "Code.h"

namespace ACJudge
{
	class Task
	{
	private:
		ID tid;
		TaskType type;
		Array<Data> data;
		Code spj;

	public:
		Return Prepare() const;
		Task();

		const Array<Data>& GetData() const { return data; }
		const Code& GetCode() const { return spj; }
		const TaskType& GetType() const { return type; }
	};
}