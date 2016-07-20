#include "Judge.h"
#include "Code.h"

using namespace std;
using namespace ACJudge;

Grades Judge::JudgeCode(const Task &t, const Submission &s)
{
	Grades res;
	Return ret;

	//准备Special Judge
	ret = t.Prepare();
	switch(ret)
	{
	case Return::ERROR:
		
	case:
		;
	}

	//准备选手代码
	Array<Data> standard = t.GetData();
	s.Prepare();

	//开始评测！
	for (auto i = standard.begin(); i != standard.end(); i++)
	{
		//放置数据
		i->Prepare(_T("data"));

		//运行
		Return ret = box.Run(_T("SOL"), _T("data.in"), _T("sol.out"), _T("sol.err"));
		if (ret == Return::OK)
		{

		}


	}
}