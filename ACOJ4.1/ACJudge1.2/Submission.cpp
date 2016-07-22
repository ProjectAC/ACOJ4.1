#include "Submission.h"

using namespace ACJudge;

Return Submission::Prepare() const
{
	return code.Compile(_T("sol"));
}