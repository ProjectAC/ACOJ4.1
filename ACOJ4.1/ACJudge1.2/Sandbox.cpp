#include "SandBox.h"

using namespace ACJudge;

JOBOBJECT_EXTENDED_LIMIT_INFORMATION SandBox::Limits(Limit time, Limit space)
{
	JOBOBJECT_EXTENDED_LIMIT_INFORMATION ex_lim;

	//清零标记
	ZeroMemory(&ex_lim, sizeof(ex_lim));

	//设置最大进程数
	ex_lim.BasicLimitInformation.LimitFlags |= JOB_OBJECT_LIMIT_ACTIVE_PROCESS;
	ex_lim.BasicLimitInformation.ActiveProcessLimit = 1;

	//设置内存限制
	ex_lim.BasicLimitInformation.LimitFlags |= JOB_OBJECT_LIMIT_JOB_MEMORY;
	ex_lim.JobMemoryLimit = SIZE_T(space * 1000);

	//设置时间限制
	ex_lim.BasicLimitInformation.LimitFlags |= JOB_OBJECT_LIMIT_JOB_TIME;
	ex_lim.BasicLimitInformation.PerJobUserTimeLimit.QuadPart = time * 10000;

	return ex_lim;
}

JOBOBJECT_BASIC_UI_RESTRICTIONS SandBox::Restrictions()
{
	JOBOBJECT_BASIC_UI_RESTRICTIONS bs_ui;
	bs_ui.UIRestrictionsClass =
		JOB_OBJECT_UILIMIT_EXITWINDOWS |
		JOB_OBJECT_UILIMIT_READCLIPBOARD |
		JOB_OBJECT_UILIMIT_WRITECLIPBOARD |
		JOB_OBJECT_UILIMIT_SYSTEMPARAMETERS |
		JOB_OBJECT_UILIMIT_DISPLAYSETTINGS |
		JOB_OBJECT_UILIMIT_GLOBALATOMS |
		JOB_OBJECT_UILIMIT_DESKTOP |
		JOB_OBJECT_UILIMIT_HANDLES;
	return bs_ui;
}

STARTUPINFO SandBox::StartUpInfo(Text input, Text output, Text error)
{
	//创建IO接口
	STARTUPINFO s = { sizeof(s) };
	ZeroMemory(&s, sizeof(s));
	s.cb = sizeof(STARTUPINFO);
	s.dwFlags = STARTF_USESTDHANDLES;

	//创建文件
	if (input.length())
	{
		HANDLE fin = CreateFile(input.c_str(),
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ,
			0,
			CREATE_ALWAYS,
			FILE_FLAG_OVERLAPPED,
			0);
		s.hStdInput = fin;
	}
	if (output.length())
	{
		HANDLE fout = CreateFile(output.c_str(),
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ,
			0,
			CREATE_ALWAYS,
			FILE_FLAG_OVERLAPPED,
			0);
		s.hStdInput = fout;
	}
	if (error.length())
	{
		HANDLE ferr = CreateFile(error.c_str(),
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ,
			0,
			CREATE_ALWAYS,
			FILE_FLAG_OVERLAPPED,
			0);
		s.hStdError = ferr;
	}
	
	return s;
}

Return SandBox::Run(Text name, int &val, Limit time, Limit space, Text error, Text input, Text output)
{
#if defined WINDOWS
	//初始化
	JOBOBJECT_EXTENDED_LIMIT_INFORMATION ex_lim = Limits(time, space);
	JOBOBJECT_BASIC_UI_RESTRICTIONS bs_ui = Restrictions();
	STARTUPINFO s = StartUpInfo(input, output, error);
	_PROCESS_INFORMATION p;

	//创建作业
	HANDLE job = CreateJobObject(NULL, NULL);
	SetInformationJobObject(job, JobObjectExtendedLimitInformation, &ex_lim, sizeof(ex_lim));
	SetInformationJobObject(job, JobObjectBasicUIRestrictions, &bs_ui, sizeof(bs_ui));

	TCHAR *str = new TCHAR[10000];
	_tcscpy(str, name.c_str());
	
	//创建进程

	DWORD ret =
		CreateProcess(NULL, str,
			NULL,
			NULL,
			FALSE,
			CREATE_SUSPENDED,
			NULL,
			NULL,
			&s,
			&p);
	if (!ret)
		return Return::FAIL;

	//将进程绑定到作业，然后搞起！
	AssignProcessToJobObject(job, p.hProcess);
	ResumeThread(p.hThread);

	//开始计时
	HANDLE handles[2];
	handles[0] = p.hProcess;
	handles[1] = job;
	ret = WaitForMultipleObjects(2, handles, FALSE, INFINITE);
	switch (ret)
	{
	case WAIT_OBJECT_0:
		//进程退出了
		GetExitCodeProcess(p.hProcess, &ret);
		val = ret;
		if (ret == 1816)
			return Return::TLE;
		else if (ret)
			return Return::FAIL;
		else
			return Return::OK;

	case WAIT_TIMEOUT:
		//进程超时了
		return Return::TLE;

	case WAIT_FAILED:
		//进程爆炸了
		return Return::FAIL;
	}

	//未知错误
	return Return::FAIL;
#endif
}