#pragma once
#include <fstream>
#include "In.h"
#include "Parm.h"
#include "Error.h"
#include "stdafx.h"
#include "LT.h"
#include "IT.h"
using namespace std;

namespace Log
{
	struct LOG
	{
		wchar_t logfile[PARM_MAX_SIZE];
		ofstream* stream;
	};

	static const LOG INITLOG{ L"", NULL };
	LOG getlog(wchar_t logfile[]);
	void WriteLine(LOG log, const char* c, ...);
	void WriteLine(LOG log, const wchar_t* c, ...);
	void WriteLog(LOG log);
	void WriteParm(LOG log, Parm::PARM parm);
	void WriteIn(LOG log, In::IN in);
	void WriteError(LOG log, Error::ERROR error);
	void Close(LOG log);
	void WriteLex(LOG log, LT::LexTable &lextable, IT::IdTable &idtable);
};