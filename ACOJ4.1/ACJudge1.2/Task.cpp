#include "Task.h"

using namespace std;
using namespace ACJudge;

Return Task::Prepare() const
{
	return spj.Compile(_T("spj"));
}
