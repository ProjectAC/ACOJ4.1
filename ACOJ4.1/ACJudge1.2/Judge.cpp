#include "Judge.h"
#include "Code.h"

using namespace std;
using namespace ACJudge;

Grades Judge::JudgeCode(const Task &t, const Submission &s)
{
	Grades res;
	Return ret;

	//׼��Special Judge
	ret = t.Prepare();
	switch(ret)
	{
	case Return::ERROR:
		
	case:
		;
	}

	//׼��ѡ�ִ���
	Array<Data> standard = t.GetData();
	s.Prepare();

	//��ʼ���⣡
	for (auto i = standard.begin(); i != standard.end(); i++)
	{
		//��������
		i->Prepare(_T("data"));

		//����
		Return ret = box.Run(_T("SOL"), _T("data.in"), _T("sol.out"), _T("sol.err"));
		if (ret == Return::OK)
		{

		}


	}
}