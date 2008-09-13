#ifndef __LOGFRAME_H__
#define __LOGFRAME_H__

#if _MSC_VER > 1000
	#pragma once
#endif // _MSC_VER > 1000

#include "precomp.h"

#include "events.h"
#include "childframe.h"
#include "listview.h"
#include "debugger.h"

//////////////////////////////////////////////////////////////////////////
// ����� ���� Log
class LogFrame : public ChildFrame
{
public:
	// ����������� ����
	LogFrame(wxMDIParentFrame *parent, const wxString& title);

	// ����������
	~LogFrame();

	// ������� �������� ��������� �� dbg_event � Log
	void DbgEventToLog(TrcDebugEvent &event);

	// ������� �������� ��������� �� except_event � Log
	void ExceptEventToLog(TrcExceptEvent &event);

	// ������� �������� ��������� �� proc_event � Log
	void ProcEventToLog(TrcProcEvent &event);

	void OnSize(wxSizeEvent& event);

	// ������� ������ ��������� � Log
	void Print(const wxString &str);

private:
	virtual void SaveParams();
	virtual void LoadParams();

private:
	wxTextCtrl m_textCtrl;
	size_t m_counter;

private:
	DECLARE_EVENT_TABLE()
};

#endif // __LOGFRAME_H__