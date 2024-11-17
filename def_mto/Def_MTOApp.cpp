//---------------------------------------------------------------------------
//
// Name:        Def_MTOApp.cpp
// Author:      titan
// Created:     15/12/2015 13:36:50
// Description: 
//
//---------------------------------------------------------------------------

#include "Def_MTOApp.h"
#include "Def_MTODlg.h"

IMPLEMENT_APP(Def_MTODlgApp)

bool Def_MTODlgApp::OnInit()
{
	Def_MTODlg* dialog = new Def_MTODlg(NULL);
	SetTopWindow(dialog);

	dialog->Show(true);		
	return true;
}
 
int Def_MTODlgApp::OnExit()
{
	return 0;
}
