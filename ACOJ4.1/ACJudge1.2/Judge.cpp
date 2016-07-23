#include "Judge.h"
#include "Code.h"

using namespace std;
using namespace ACJudge;

Grades Judge::JudgeCode(const Task &t, const Submission &s)
{
	Grades res;
	Return ret;
	int val;

	//准备Special Judge
	ret = t.Prepare();
	switch (ret)
	{
	case Return::FAIL:
	case Return::TLE:
	case Return::MLE:
		res.SetResult(Result::IT);
		return res;
	}

	//准备选手代码
	ret = s.Prepare();
	switch (ret)
	{
	case Return::FAIL:
		
		res.SetResult(Result::CE);
		return res;
	case Return::TLE:
	case Return::MLE:
		res.SetResult(Result::CRTE);
		return res;
	}

	//开始评测！
	Array<Data> standard = t.GetData();
	for (auto i = standard.begin(); i != standard.end(); i++)
	{
		//放置数据
		i->Prepare();

		//运行
		Return ret = s.GetCode().Run(_T("sol"), val, i->GetTime(), i->GetSpace(), _T("err"), _T("data.in"), _T("data.out"));
		switch (ret)
		{
		case Return::TLE:
			res.Push(Grade(Result::TLE, 0, s.GetID(), i->GetID()));
			break;
		case Return::MLE:
			res.Push(Grade(Result::MLE, 0, s.GetID(), i->GetID()));
			break;
		case Return::FAIL:
			res.Push(Grade(Result::RTE, 0, s.GetID(), i->GetID()));
			break;
		default:
			//评测
			Return ret = t.GetCode().Run(_T("spj"), val, 5000);
			res.Push(Grade((val == i->GetScore() ? Result::AC : Result::WA), val, s.GetID(), i->GetID()));
		}
	}

	res.SetResult(Result::AC);
	return res;
}

Grades Judge::Judges(const Task &t, const Submission &s)
{
	Grades res;

	if (t.GetType() == TaskType::OI)
		res = JudgeCode(t, s);

	return res;
}