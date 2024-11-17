//---------------------------------------------------------------------------
//
// Name:        Def_MTOApp.h
// Author:      titan
// Created:     15/12/2015 13:36:50
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __DEF_MTODLGApp_h__
#define __DEF_MTODLGApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class Def_MTODlgApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
