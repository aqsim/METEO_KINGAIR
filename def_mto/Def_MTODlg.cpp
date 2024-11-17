//---------------------------------------------------------------------------
//
// Name:        Def_MTODlg.cpp
// Author:      titan
// Created:     15/12/2015 13:36:51
// Description: Def_MTODlg class implementation
//
//---------------------------------------------------------------------------



//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
#include "Images/Def_MTODlg_WxStaticBitmap1_XPM.xpm"
#include "Images/Def_MTODlg_WxLedE2_XPM.xpm"
#include "Images/Def_MTODlg_WxLedE3_XPM.xpm"
#include "Images/Def_MTODlg_WxLedV3_XPM.xpm"
#include "Images/Def_MTODlg_WxLedR3_XPM.xpm"
#include "Images/Def_MTODlg_WxLedV2_XPM.xpm"
#include "Images/Def_MTODlg_WxLedE1_XPM.xpm"
#include "Images/Def_MTODlg_WxLedR1_XPM.xpm"
#include "Images/Def_MTODlg_WxLedV1_XPM.xpm"
////Header Include End
#include "Def_MTODlg.h"
//#include "Images/logo_aq.ico"
//----------------------------------------------------------------------------
// Def_MTODlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Def_MTODlg,wxDialog)
	////Manual Code Start
	//EVT_SOCKET(SERVER_ID,Def_MTODlg::OnServerEvent)//(wxSocketEvent& event)
	//EVT_SOCKET(SOCKET_ID,Def_MTODlg::OnSocketEvent)//(wxSocketEvent& event)
	////Manual Code End
	
	EVT_CLOSE(Def_MTODlg::OnClose)
	EVT_TIMER(ID_WXTIMER1,Def_MTODlg::WxTimer1Timer)
	EVT_TIMER(ID_WXTIMER2,Def_MTODlg::WxTimer2Timer)
END_EVENT_TABLE()
////Event Table End

Def_MTODlg::Def_MTODlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	        
        GetCurrentDirectory(258,RepCourant);
        strcat(RepCourant,"\\MTO_MA.ini");
        strcpy(CleALire," ");
        strcpy(CleALire,"px");    
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("POS",CleALire,NULL,ValeurLue,45,RepCourant);
	    p.x=atoi(ValeurLue);
        strcpy(CleALire," ");
        strcpy(CleALire,"py");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("POS",CleALire,NULL,ValeurLue,45,RepCourant);
	    p.y=atoi(ValeurLue);
        strcpy(CleALire," ");
        strcpy(CleALire,"sx");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("POS",CleALire,NULL,ValeurLue,45,RepCourant);
	    s.x=atoi(ValeurLue);
         strcpy(CleALire," ");
        strcpy(CleALire,"sy");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("POS",CleALire,NULL,ValeurLue,45,RepCourant);
	    s.y=atoi(ValeurLue);
    
    
    CreateGUIControls();


            //Initialisation();
            init=0;
            ini=0;
            bAvion=false;
            bMTO=false;
            bVisi=false;
            bIO=false;
            numClients=0;
            bOffsets=false;
            cBlocAvion=new char[36];
            strcpy(Sep,wxT(","));
_shAltAvion=-1;
            cMTO=_cMTO=1; // affichage météo 1 au lancement
            cZone=-1;
            _cZone=-1;
            bInitOffset=false;
            bStop=false;
            WxLedV1->Show(false);
            WxLedR1->Show(false);
            //WxLedE1->Show(true);
            
            WxLedV2->Show(false);
           //WxLedR2->Show(false);
            //WxLedE2->Show(true);
            
            WxLedV3->Show(false);
            WxLedR3->Show(false);
            //WxLedE3->Show(true); 
                       
strcpy(Kts[0],wxT("00"));strcpy(Kts[1],wxT("10"));strcpy(Kts[2],wxT("20"));
strcpy(Kts[3],wxT("30"));strcpy(Kts[4],wxT("40"));strcpy(Kts[5],wxT("50"));
strcpy(Kts[6],wxT("60"));

strcpy(Z1[0],wxT("0"));strcpy(Z1[1],wxT("50"));strcpy(Z1[2],wxT("100"));strcpy(Z1[3],wxT("150"));strcpy(Z1[4],wxT("200"));
strcpy(Z1[5],wxT("250"));strcpy(Z1[6],wxT("300"));strcpy(Z1[7],wxT("350"));strcpy(Z1[8],wxT("400"));strcpy(Z1[9],wxT("450"));
strcpy(Z1[10],wxT("500"));strcpy(Z1[11],wxT("600"));strcpy(Z1[12],wxT("700"));strcpy(Z1[13],wxT("800"));strcpy(Z1[14],wxT("900"));
strcpy(Z1[15],wxT("1000"));strcpy(Z1[16],wxT("1500"));strcpy(Z1[17],wxT("2000"));strcpy(Z1[18],wxT("2500"));strcpy(Z1[19],wxT("3000"));

strcpy(Z2[0],wxT("500"));strcpy(Z2[1],wxT("1000"));strcpy(Z2[2],wxT("1500"));strcpy(Z2[3],wxT("2000"));strcpy(Z2[4],wxT("2500"));
strcpy(Z2[5],wxT("3000"));strcpy(Z2[6],wxT("3500"));strcpy(Z2[7],wxT("4000"));strcpy(Z2[8],wxT("4500"));strcpy(Z2[9],wxT("5000"));
strcpy(Z2[10],wxT("6000"));strcpy(Z2[11],wxT("7000"));strcpy(Z2[12],wxT("8000"));strcpy(Z2[13],wxT("9000"));strcpy(Z2[14],wxT("10000"));
strcpy(Z2[15],wxT("11000"));strcpy(Z2[16],wxT("12000"));strcpy(Z2[17],wxT("13000"));strcpy(Z2[18],wxT("14000"));strcpy(Z2[19],wxT("15000"));


strcpy(IncV[0],wxT("16 m"));strcpy(IncV[1],wxT("100 m"));strcpy(IncV[2],wxT("200 m"));strcpy(IncV[3],wxT("400 m"));strcpy(IncV[4],wxT("800 m"));
strcpy(IncV[5],wxT("1200 m"));strcpy(IncV[6],wxT("1600 m"));strcpy(IncV[7],wxT("3.2 km"));strcpy(IncV[8],wxT("8 km"));strcpy(IncV[9],wxT("16 km"));
strcpy(IncV[10],wxT("32 km"));strcpy(IncV[11],wxT("64 km"));strcpy(IncV[12],wxT("illimité"));

TVis[0]=1;TVis[1]=6;TVis[2]=12;TVis[3]=24;TVis[4]=50;TVis[5]=75;TVis[6]=100;TVis[7]=200;
TVis[8]=500;TVis[9]=994;TVis[10]=1988;TVis[11]=3977;TVis[12]=7954;

strcpy(Vent[0],wxT("0"));strcpy(Vent[1],wxT("30"));strcpy(Vent[2],wxT("60"));strcpy(Vent[3],wxT("90"));strcpy(Vent[4],wxT("120"));strcpy(Vent[5],wxT("150"));
strcpy(Vent[6],wxT("180"));strcpy(Vent[7],wxT("210"));strcpy(Vent[8],wxT("240"));strcpy(Vent[9],wxT("270"));strcpy(Vent[10],wxT("300"));
strcpy(Vent[11],wxT("330"));

strcpy(Nuages[0],wxT("ST-1"));strcpy(Nuages[1],wxT("ST-2"));strcpy(Nuages[2],wxT("ST-3"));strcpy(Nuages[3],wxT("ST-4"));
strcpy(Nuages[4],wxT("ST-5"));strcpy(Nuages[5],wxT("ST-6"));strcpy(Nuages[6],wxT("ST-7"));strcpy(Nuages[7],wxT("ST-8"));
strcpy(Nuages[8],wxT("CU-1"));strcpy(Nuages[9],wxT("CU-2"));strcpy(Nuages[10],wxT("CU-3"));strcpy(Nuages[11],wxT("CU-4"));
strcpy(Nuages[12],wxT("CU-5"));strcpy(Nuages[13],wxT("CU-6"));strcpy(Nuages[14],wxT("CU-7"));strcpy(Nuages[15],wxT("CU-8"));

strcpy(Nuages[16],wxT("CI-1"));strcpy(Nuages[17],wxT("CI-2"));strcpy(Nuages[18],wxT("CI-3"));strcpy(Nuages[19],wxT("CI-4"));
strcpy(Nuages[20],wxT("CI-5"));strcpy(Nuages[21],wxT("CI-6"));strcpy(Nuages[22],wxT("CI-7"));strcpy(Nuages[23],wxT("CI-8"));
strcpy(Nuages[24],wxT("OR-1"));strcpy(Nuages[25],wxT("OR-2"));strcpy(Nuages[26],wxT("OR-3"));strcpy(Nuages[27],wxT("OR-4"));
strcpy(Nuages[28],wxT("OR-5"));strcpy(Nuages[29],wxT("OR-6"));strcpy(Nuages[30],wxT("OR-7"));strcpy(Nuages[31],wxT("OR-8"));
strcpy(Nuages[32],wxT("Sans"));

strcpy(IncT[0],wxT("0"));strcpy(IncT[1],wxT("50"));strcpy(IncT[2],wxT("100"));strcpy(IncT[3],wxT("200"));
strcpy(IncT[4],wxT("300"));strcpy(IncT[5],wxT("400"));strcpy(IncT[6],wxT("500"));

strcpy(MTO1[0],wxT("M1Z1_T1"));strcpy(MTO1[1],wxT("M1Z1_T2"));strcpy(MTO1[2],wxT("M1Z1_V"));strcpy(MTO1[3],wxT("M1Z1_C"));strcpy(MTO1[4],wxT("M1Z1_W"));strcpy(MTO1[5],wxT("M1Z1_K"));
strcpy(MTO1[6],wxT("M1Z2_T1"));strcpy(MTO1[7],wxT("M1Z2_T2"));strcpy(MTO1[8],wxT("M1Z2_V"));strcpy(MTO1[9],wxT("M1Z2_C"));strcpy(MTO1[10],wxT("M1Z2_W"));strcpy(MTO1[11],wxT("M1Z2_K"));
strcpy(MTO1[12],wxT("M1Z3_T1"));strcpy(MTO1[13],wxT("M1Z3_T2"));strcpy(MTO1[14],wxT("M1Z3_V"));strcpy(MTO1[15],wxT("M1Z3_C"));strcpy(MTO1[16],wxT("M1Z3_W"));strcpy(MTO1[17],wxT("M1Z3_K"));
strcpy(MTO1[18],wxT("M1_Z"));strcpy(MTO1[19],wxT("M1_Q"));strcpy(MTO1[20],wxT("M1_T"));

strcpy(MTO2[0],wxT("M2Z1_T1"));strcpy(MTO2[1],wxT("M2Z1_T2"));strcpy(MTO2[2],wxT("M2Z1_V"));strcpy(MTO2[3],wxT("M2Z1_C"));strcpy(MTO2[4],wxT("M2Z1_W"));strcpy(MTO2[5],wxT("M2Z1_K"));
strcpy(MTO2[6],wxT("M2Z2_T1"));strcpy(MTO2[7],wxT("M2Z2_T2"));strcpy(MTO2[8],wxT("M2Z2_V"));strcpy(MTO2[9],wxT("M2Z2_C"));strcpy(MTO2[10],wxT("M2Z2_W"));strcpy(MTO2[11],wxT("M2Z2_K"));
strcpy(MTO2[12],wxT("M2Z3_T1"));strcpy(MTO2[13],wxT("M2Z3_T2"));strcpy(MTO2[14],wxT("M2Z3_V"));strcpy(MTO2[15],wxT("M2Z3_C"));strcpy(MTO2[16],wxT("M2Z3_W"));strcpy(MTO2[17],wxT("M2Z3_K"));
strcpy(MTO2[18],wxT("M2_Z"));strcpy(MTO2[19],wxT("M2_Q"));strcpy(MTO2[20],wxT("M2_T"));

strcpy(MTO3[0],wxT("M3Z1_T1"));strcpy(MTO3[1],wxT("M3Z1_T2"));strcpy(MTO3[2],wxT("M3Z1_V"));strcpy(MTO3[3],wxT("M3Z1_C"));strcpy(MTO3[4],wxT("M3Z1_W"));strcpy(MTO3[5],wxT("M3Z1_K"));
strcpy(MTO3[6],wxT("M3Z2_T1"));strcpy(MTO3[7],wxT("M3Z2_T2"));strcpy(MTO3[8],wxT("M3Z2_V"));strcpy(MTO3[9],wxT("M3Z2_C"));strcpy(MTO3[10],wxT("M3Z2_W"));strcpy(MTO3[11],wxT("M3Z2_K"));
strcpy(MTO3[12],wxT("M3Z3_T1"));strcpy(MTO3[13],wxT("M3Z3_T2"));strcpy(MTO3[14],wxT("M3Z3_V"));strcpy(MTO3[15],wxT("M3Z3_C"));strcpy(MTO3[16],wxT("M3Z3_W"));strcpy(MTO3[17],wxT("M3Z3_K"));
strcpy(MTO3[18],wxT("M3_Z"));strcpy(MTO3[19],wxT("M3_Q"));strcpy(MTO3[20],wxT("M3_T"));

strcpy(MTO4[0],wxT("M4Z1_T1"));strcpy(MTO4[1],wxT("M4Z1_T2"));strcpy(MTO4[2],wxT("M4Z1_V"));strcpy(MTO4[3],wxT("M4Z1_C"));strcpy(MTO4[4],wxT("M4Z1_W"));strcpy(MTO4[5],wxT("M4Z1_K"));
strcpy(MTO4[6],wxT("M4Z2_T1"));strcpy(MTO4[7],wxT("M4Z2_T2"));strcpy(MTO4[8],wxT("M4Z2_V"));strcpy(MTO4[9],wxT("M4Z2_C"));strcpy(MTO4[10],wxT("M4Z2_W"));strcpy(MTO4[11],wxT("M4Z2_K"));
strcpy(MTO4[12],wxT("M4Z3_T1"));strcpy(MTO4[13],wxT("M4Z3_T2"));strcpy(MTO4[14],wxT("M4Z3_V"));strcpy(MTO4[15],wxT("M4Z3_C"));strcpy(MTO4[16],wxT("M4Z3_W"));strcpy(MTO4[17],wxT("M4Z3_K"));
strcpy(MTO4[18],wxT("M4_Z"));strcpy(MTO4[19],wxT("M4_Q"));strcpy(MTO4[20],wxT("M4_T"));

strcpy(MTO5[0],wxT("M5Z1_T1"));strcpy(MTO5[1],wxT("M5Z1_T2"));strcpy(MTO5[2],wxT("M5Z1_V"));strcpy(MTO5[3],wxT("M5Z1_C"));strcpy(MTO5[4],wxT("M5Z1_W"));strcpy(MTO5[5],wxT("M5Z1_K"));
strcpy(MTO5[6],wxT("M5Z2_T1"));strcpy(MTO5[7],wxT("M5Z2_T2"));strcpy(MTO5[8],wxT("M5Z2_V"));strcpy(MTO5[9],wxT("M5Z2_C"));strcpy(MTO5[10],wxT("M5Z2_W"));strcpy(MTO5[11],wxT("M5Z2_K"));
strcpy(MTO5[12],wxT("M5Z3_T1"));strcpy(MTO5[13],wxT("M5Z3_T2"));strcpy(MTO5[14],wxT("M5Z3_V"));strcpy(MTO5[15],wxT("M5Z3_C"));strcpy(MTO5[16],wxT("M5Z3_W"));strcpy(MTO5[17],wxT("M5Z3_K"));
strcpy(MTO5[18],wxT("M5_Z"));strcpy(MTO5[19],wxT("M5_Q"));strcpy(MTO5[20],wxT("M5_T"));


strcpy(MTO6[0],wxT("M6Z1_T1"));strcpy(MTO6[1],wxT("M6Z1_T2"));strcpy(MTO6[2],wxT("M6Z1_V"));strcpy(MTO6[3],wxT("M6Z1_C"));strcpy(MTO6[4],wxT("M6Z1_W"));strcpy(MTO6[5],wxT("M6Z1_K"));
strcpy(MTO6[6],wxT("M6Z2_T1"));strcpy(MTO6[7],wxT("M6Z2_T2"));strcpy(MTO6[8],wxT("M6Z2_V"));strcpy(MTO6[9],wxT("M6Z2_C"));strcpy(MTO6[10],wxT("M6Z2_W"));strcpy(MTO6[11],wxT("M6Z2_K"));
strcpy(MTO6[12],wxT("M6Z3_T1"));strcpy(MTO6[13],wxT("M6Z3_T2"));strcpy(MTO6[14],wxT("M6Z3_V"));strcpy(MTO6[15],wxT("M6Z3_C"));strcpy(MTO6[16],wxT("M6Z3_W"));strcpy(MTO6[17],wxT("M6Z3_K"));
strcpy(MTO6[18],wxT("M6_Z"));strcpy(MTO6[19],wxT("M6_Q"));strcpy(MTO6[20],wxT("M6_T"));

strcpy(O_Offsets[0],wxT("O_MTO"));strcpy(O_Offsets[1],wxT("O_Zone"));strcpy(O_Offsets[2],wxT("O_Cde"));strcpy(O_Offsets[3],wxT("O_AltAirPort"));
strcpy(O_Offsets[4],wxT("O_QNH"));strcpy(O_Offsets[5],wxT("O_Temperature"));strcpy(O_Offsets[6],wxT("O_ZRef"));
strcpy(O_Offsets[7],wxT("O_WindDir"));strcpy(O_Offsets[8],wxT("O_Knots"));strcpy(O_Offsets[9],wxT("O_Visibility"));
strcpy(O_Offsets[10],wxT("O_Transition"));strcpy(O_Offsets[11],wxT("O_Nuages"));

TZ1[0]=0;TZ1[1]=50;TZ1[2]=100;TZ1[3]=150;TZ1[4]=200;TZ1[5]=250;TZ1[6]=300;TZ1[7]=350;TZ1[8]=400;TZ1[9]=450;
TZ1[10]=500;TZ1[11]=600;TZ1[12]=700;TZ1[13]=800;TZ1[14]=900;TZ1[15]=1000;TZ1[16]=1500;TZ1[17]=2000;TZ1[18]=2500;TZ1[19]=3000;

TZ2[0]=500;TZ2[1]=1000;TZ2[2]=1500;TZ2[3]=2000;TZ2[4]=2500;TZ2[5]=3000;TZ2[6]=3500;
TZ2[7]=4000;TZ2[8]=4500;TZ2[9]=5000;TZ2[10]=6000;TZ2[11]=7000;TZ2[12]=8000;TZ2[13]=9000;TZ2[14]=10000;
TZ2[15]=11000;TZ2[16]=12000;TZ2[17]=13000;TZ2[18]=14000;TZ2[19]=15000;

TKts[0]=0;TKts[1]=10; TKts[2]=20; TKts[3]=30; TKts[4]=40; TKts[5]=50; TKts[6]=60;

TWinDir[0]=0;TWinDir[1]=30;TWinDir[2]=60;TWinDir[3]=90;TWinDir[4]=120;TWinDir[5]=150;
TWinDir[6]=180;TWinDir[7]=210;TWinDir[8]=240;TWinDir[9]=270;TWinDir[10]=300;TWinDir[11]=330;

TR[0]=0;TR[1]=50;TR[2]=100;TR[3]=200;TR[4]=300;TR[5]=400;TR[6]=500;

}

Def_MTODlg::~Def_MTODlg()
{
 /*
    bStop=true;
    WxTimer1->Stop();
	WxTimer2->Stop();
    FSUIPC_Close();
    Close();
    */
}

void Def_MTODlg::CreateGUIControls()
{

	
    SetTitle(wxT("Paramétrage MTO"));
	SetIcon(wxNullIcon);
	SetSize(p.x,p.y,s.x,s.y);
	//Center();


	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start
/*
	SetTitle(wxT("Paramétrage MTO"));
	SetIcon(wxNullIcon);
	SetSize(8,8,515,578);
	Center();
*/	

	WxTimer1 = new wxTimer();
	WxTimer1->SetOwner(this, ID_WXTIMER1);
	WxTimer1->Start(100);

	WxTimer2 = new wxTimer();
	WxTimer2->SetOwner(this, ID_WXTIMER2);

	wxBitmap WxStaticBitmap1_BITMAP(Def_MTODlg_WxStaticBitmap1_XPM);
	WxStaticBitmap1 = new wxStaticBitmap(this, ID_WXSTATICBITMAP1, WxStaticBitmap1_BITMAP, wxPoint(441,1), wxSize(50,38));
	WxStaticBitmap1->Enable(false);
	WxStaticBitmap1->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText32 = new wxStaticText(this, ID_WXSTATICTEXT32, wxT(""), wxPoint(420,598), wxDefaultSize, 0, wxT("WxStaticText32"));
	WxStaticText32->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText13 = new wxStaticText(this, ID_WXSTATICTEXT13, wxT(""), wxPoint(485,38), wxDefaultSize, 0, wxT("WxStaticText13"));
	WxStaticText13->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText8 = new wxStaticText(this, ID_WXSTATICTEXT8, wxT(""), wxPoint(443,609), wxDefaultSize, 0, wxT("WxStaticText8"));
	WxStaticText8->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	wxBitmap WxLedE2_BITMAP(Def_MTODlg_WxLedE2_XPM);
	WxLedE2 = new wxStaticBitmap(this, ID_WXLEDE2, WxLedE2_BITMAP, wxPoint(12,232), wxSize(25,25));
	WxLedE2->Enable(false);
	WxLedE2->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	wxBitmap WxLedE3_BITMAP(Def_MTODlg_WxLedE3_XPM);
	WxLedE3 = new wxStaticBitmap(this, ID_WXLEDE3, WxLedE3_BITMAP, wxPoint(13,93), wxSize(25,25));
	WxLedE3->Enable(false);
	WxLedE3->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	wxBitmap WxLedV3_BITMAP(Def_MTODlg_WxLedV3_XPM);
	WxLedV3 = new wxStaticBitmap(this, ID_WXLEDV3, WxLedV3_BITMAP, wxPoint(13,88), wxSize(27,30));
	WxLedV3->Enable(false);
	WxLedV3->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	wxBitmap WxLedR3_BITMAP(Def_MTODlg_WxLedR3_XPM);
	WxLedR3 = new wxStaticBitmap(this, ID_WXLEDR3, WxLedR3_BITMAP, wxPoint(13,85), wxSize(25,28));
	WxLedR3->Enable(false);
	WxLedR3->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	wxBitmap WxLedV2_BITMAP(Def_MTODlg_WxLedV2_XPM);
	WxLedV2 = new wxStaticBitmap(this, ID_WXLEDV2, WxLedV2_BITMAP, wxPoint(9,230), wxSize(28,30));
	WxLedV2->Enable(false);
	WxLedV2->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	wxBitmap WxLedE1_BITMAP(Def_MTODlg_WxLedE1_XPM);
	WxLedE1 = new wxStaticBitmap(this, ID_WXLEDE1, WxLedE1_BITMAP, wxPoint(10,369), wxSize(25,25));
	WxLedE1->Enable(false);
	WxLedE1->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	wxBitmap WxLedR1_BITMAP(Def_MTODlg_WxLedR1_XPM);
	WxLedR1 = new wxStaticBitmap(this, ID_WXLEDR1, WxLedR1_BITMAP, wxPoint(10,366), wxSize(25,28));
	WxLedR1->Enable(false);
	WxLedR1->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	wxBitmap WxLedV1_BITMAP(Def_MTODlg_WxLedV1_XPM);
	WxLedV1 = new wxStaticBitmap(this, ID_WXLEDV1, WxLedV1_BITMAP, wxPoint(10,366), wxSize(27,30));
	WxLedV1->Enable(false);
	WxLedV1->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, wxT("A-S"), wxPoint(406,10), wxDefaultSize, 0, wxT("WxStaticText4"));
	WxStaticText4->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Segoe UI")));

	WxStaticLine5 = new wxStaticLine(this, ID_WXSTATICLINE5, wxPoint(317,176), wxSize(35,-1), wxLI_HORIZONTAL);
	WxStaticLine5->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine5->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticLine1 = new wxStaticLine(this, ID_WXSTATICLINE1, wxPoint(321,315), wxSize(39,-1), wxLI_HORIZONTAL);
	WxStaticLine1->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine1->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText31 = new wxStaticText(this, ID_WXSTATICTEXT31, wxT("°"), wxPoint(460,333), wxDefaultSize, 0, wxT("WxStaticText31"));
	WxStaticText31->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText30 = new wxStaticText(this, ID_WXSTATICTEXT30, wxT("°"), wxPoint(464,199), wxDefaultSize, 0, wxT("WxStaticText30"));
	WxStaticText30->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText29 = new wxStaticText(this, ID_WXSTATICTEXT29, wxT("°"), wxPoint(470,69), wxDefaultSize, 0, wxT("WxStaticText29"));
	WxStaticText29->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText28 = new wxStaticText(this, ID_WXSTATICTEXT28, wxT("AIRPORT GROUND ( 0 à 6000ft par pas de 10ft)"), wxPoint(91,500), wxDefaultSize, 0, wxT("WxStaticText28"));
	WxStaticText28->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_Tp = new wxTextCtrl(this, ID_WXEDIT_TP, wxT(""), wxPoint(360,463), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_Tp"));
	WxEdit_Tp->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_QNH = new wxTextCtrl(this, ID_WXEDIT_QNH, wxT(""), wxPoint(241,463), wxSize(96,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_QNH"));
	WxEdit_QNH->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_Z = new wxTextCtrl(this, ID_WXEDIT_Z, wxT(""), wxPoint(64,460), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_Z"));
	WxEdit_Z->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_Z1T1 = new wxTextCtrl(this, ID_WXEDIT_Z1T1, wxT(""), wxPoint(367,295), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_Z1T1"));
	WxEdit_Z1T1->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_Z1T2 = new wxTextCtrl(this, ID_WXEDIT_Z1T2, wxT(""), wxPoint(65,298), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_Z1T2"));
	WxEdit_Z1T2->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticLine4 = new wxStaticLine(this, ID_WXSTATICLINE4, wxPoint(175,313), wxSize(27,-1), wxLI_HORIZONTAL);
	WxStaticLine4->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine4->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticLine3 = new wxStaticLine(this, ID_WXSTATICLINE3, wxPoint(153,48), wxSize(213,-1), wxLI_HORIZONTAL);
	WxStaticLine3->SetForegroundColour(*wxGREEN);
	WxStaticLine3->SetFont(wxFont(13, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticLine2 = new wxStaticLine(this, ID_WXSTATICLINE2, wxPoint(174,176), wxSize(27,-1), wxLI_HORIZONTAL);
	WxStaticLine2->SetBackgroundColour(*wxBLUE);
	WxStaticLine2->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_Z2T1 = new wxTextCtrl(this, ID_WXEDIT_Z2T1, wxT(""), wxPoint(366,158), wxSize(96,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_Z2T1"));
	WxEdit_Z2T1->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_Z2T2 = new wxTextCtrl(this, ID_WXEDIT_Z2T2, wxT(""), wxPoint(64,162), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_Z2T2"));
	WxEdit_Z2T2->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_K1 = new wxTextCtrl(this, ID_WXEDIT_K1, wxT(""), wxPoint(366,390), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_K1"));
	WxEdit_K1->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_W1 = new wxTextCtrl(this, ID_WXEDIT_W1, wxT(""), wxPoint(365,343), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_W1"));
	WxEdit_W1->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_C1 = new wxTextCtrl(this, ID_WXEDIT_C1, wxT(""), wxPoint(211,384), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_C1"));
	WxEdit_C1->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_V1 = new wxTextCtrl(this, ID_WXEDIT_V1, wxT(""), wxPoint(210,345), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_V1"));
	WxEdit_V1->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_K2 = new wxTextCtrl(this, ID_WXEDIT_K2, wxT(""), wxPoint(366,235), wxSize(96,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_K2"));
	WxEdit_K2->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_W2 = new wxTextCtrl(this, ID_WXEDIT_W2, wxT(""), wxPoint(366,202), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_W2"));
	WxEdit_W2->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_C2 = new wxTextCtrl(this, ID_WXEDIT_C2, wxT(""), wxPoint(211,237), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_C2"));
	WxEdit_C2->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_V2 = new wxTextCtrl(this, ID_WXEDIT_V2, wxT(""), wxPoint(211,201), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_V2"));
	WxEdit_V2->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_K3 = new wxTextCtrl(this, ID_WXEDIT_K3, wxT(""), wxPoint(367,108), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_K3"));
	WxEdit_K3->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_W3 = new wxTextCtrl(this, ID_WXEDIT_W3, wxT(""), wxPoint(366,74), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_W3"));
	WxEdit_W3->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_C3 = new wxTextCtrl(this, ID_WXEDIT_C3, wxT(""), wxPoint(211,108), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_C3"));
	WxEdit_C3->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxEdit_V3 = new wxTextCtrl(this, ID_WXEDIT_V3, wxT(""), wxPoint(211,74), wxSize(97,25), wxSIMPLE_BORDER | wxTE_CENTRE, wxDefaultValidator, wxT("WxEdit_V3"));
	WxEdit_V3->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText27 = new wxStaticText(this, ID_WXSTATICTEXT27, wxT("TP °C"), wxPoint(373,428), wxDefaultSize, 0, wxT("WxStaticText27"));
	WxStaticText27->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText26 = new wxStaticText(this, ID_WXSTATICTEXT26, wxT("QNH mb"), wxPoint(251,427), wxDefaultSize, 0, wxT("WxStaticText26"));
	WxStaticText26->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText25 = new wxStaticText(this, ID_WXSTATICTEXT25, wxT("KTS"), wxPoint(328,397), wxDefaultSize, 0, wxT("WxStaticText25"));
	WxStaticText25->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText24 = new wxStaticText(this, ID_WXSTATICTEXT24, wxT("KTS"), wxPoint(333,243), wxDefaultSize, 0, wxT("WxStaticText24"));
	WxStaticText24->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText23 = new wxStaticText(this, ID_WXSTATICTEXT23, wxT("KTS"), wxPoint(337,115), wxDefaultSize, 0, wxT("WxStaticText23"));
	WxStaticText23->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText22 = new wxStaticText(this, ID_WXSTATICTEXT22, wxT("CLOUDS"), wxPoint(136,387), wxDefaultSize, 0, wxT("WxStaticText22"));
	WxStaticText22->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText21 = new wxStaticText(this, ID_WXSTATICTEXT21, wxT("CLOUDS"), wxPoint(141,244), wxDefaultSize, 0, wxT("WxStaticText21"));
	WxStaticText21->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText20 = new wxStaticText(this, ID_WXSTATICTEXT20, wxT("CLOUDS"), wxPoint(145,114), wxDefaultSize, 0, wxT("WxStaticText20"));
	WxStaticText20->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText19 = new wxStaticText(this, ID_WXSTATICTEXT19, wxT("WIND"), wxPoint(318,345), wxDefaultSize, 0, wxT("WxStaticText19"));
	WxStaticText19->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText18 = new wxStaticText(this, ID_WXSTATICTEXT18, wxT("WIND"), wxPoint(317,201), wxDefaultSize, 0, wxT("WxStaticText18"));
	WxStaticText18->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText17 = new wxStaticText(this, ID_WXSTATICTEXT17, wxT("WIND"), wxPoint(321,79), wxDefaultSize, 0, wxT("WxStaticText17"));
	WxStaticText17->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText16 = new wxStaticText(this, ID_WXSTATICTEXT16, wxT("VISIBILITY"), wxPoint(134,355), wxDefaultSize, 0, wxT("WxStaticText16"));
	WxStaticText16->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText15 = new wxStaticText(this, ID_WXSTATICTEXT15, wxT("VISIBILITY"), wxPoint(134,208), wxDefaultSize, 0, wxT("WxStaticText15"));
	WxStaticText15->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText14 = new wxStaticText(this, ID_WXSTATICTEXT14, wxT("VISIBILITY"), wxPoint(139,81), wxDefaultSize, 0, wxT("WxStaticText14"));
	WxStaticText14->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxZone1 = new wxStaticText(this, ID_WXZONE1, wxT("ZONE 1"), wxPoint(46,366), wxDefaultSize, wxSIMPLE_BORDER | wxALIGN_LEFT | wxALIGN_RIGHT | wxALIGN_CENTRE, wxT("WxZone1"));
	WxZone1->SetForegroundColour(wxColour(*wxBLACK));
	WxZone1->SetBackgroundColour(*wxLIGHT_GREY);
	WxZone1->SetFont(wxFont(13, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Segoe UI")));

	WxStaticText12 = new wxStaticText(this, ID_WXSTATICTEXT12, wxT("Z Ref."), wxPoint(79,430), wxDefaultSize, 0, wxT("WxStaticText12"));
	WxStaticText12->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText11 = new wxStaticText(this, ID_WXSTATICTEXT11, wxT("Transition"), wxPoint(208,300), wxDefaultSize, 0, wxT("WxStaticText11"));
	WxStaticText11->SetFont(wxFont(13, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Segoe UI")));

	WxStaticText10 = new wxStaticText(this, ID_WXSTATICTEXT10, wxT("Z 1"), wxPoint(16,305), wxDefaultSize, 0, wxT("WxStaticText10"));
	WxStaticText10->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText9 = new wxStaticText(this, ID_WXSTATICTEXT9, wxT("Z Ref+"), wxPoint(68,270), wxDefaultSize, 0, wxT("WxStaticText9"));
	WxStaticText9->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxZone2 = new wxStaticText(this, ID_WXZONE2, wxT("ZONE 2"), wxPoint(44,228), wxDefaultSize, wxSIMPLE_BORDER | wxALIGN_CENTRE, wxT("WxZone2"));
	WxZone2->SetBackgroundColour(*wxLIGHT_GREY);
	WxZone2->SetFont(wxFont(13, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Segoe UI")));

	WxStaticText7 = new wxStaticText(this, ID_WXSTATICTEXT7, wxT("Transition"), wxPoint(211,163), wxDefaultSize, 0, wxT("WxStaticText7"));
	WxStaticText7->SetFont(wxFont(13, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Segoe UI")));

	WxStaticText6 = new wxStaticText(this, ID_WXSTATICTEXT6, wxT("Z 2"), wxPoint(9,171), wxDefaultSize, 0, wxT("WxStaticText6"));
	WxStaticText6->SetFont(wxFont(11, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText5 = new wxStaticText(this, ID_WXSTATICTEXT5, wxT("Z Ref+"), wxPoint(66,137), wxDefaultSize, 0, wxT("WxStaticText5"));
	WxStaticText5->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxZone3 = new wxStaticText(this, ID_WXZONE3, wxT("ZONE 3"), wxPoint(48,92), wxDefaultSize, wxSIMPLE_BORDER | wxALIGN_CENTRE, wxT("WxZone3"));
	WxZone3->SetBackgroundColour(*wxLIGHT_GREY);
	WxZone3->SetFont(wxFont(13, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Segoe UI")));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, wxT("20.000"), wxPoint(80,43), wxDefaultSize, wxSIMPLE_BORDER, wxT("WxStaticText3"));
	WxStaticText3->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, wxT("Z max"), wxPoint(69,13), wxDefaultSize, 0, wxT("WxStaticText2"));
	WxStaticText2->SetFont(wxFont(10, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Segoe UI")));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("METEO"), wxPoint(201,6), wxDefaultSize, 0, wxT("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(15, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Segoe UI")));
	////GUI Items Creation End
 //           char *Z1[]={"0","50","100","150","200","250","300","350","400","450","500","600","700","800","1000","1500","2000","2500","3000"};
 
	WxTimer1->Start(100);
}

void Def_MTODlg::OnClose(wxCloseEvent& )//event)
{
    
    SetTitle("Paramétres MTO");
	HWND hWnd = FindWindowEx(NULL, NULL, NULL,"Paramétres MTO");
	if(hWnd!=NULL)
	{
	//sprintf(tmp,"%l",hWnd);
	    //wxMessageBox(_("Valeur "),tmp, _("Alerte !"));
    GetWindowRect(hWnd,&Pos);
    

  	    //GetCurrentDirectory(258,RepCourant);
        //strcat(RepCourant,"\\MTO_MA.ini");
        sprintf(tmp,"%ld",Pos.left);

//strcpy(CleAEcr,(int)Pos.left);
        dwCRLecture=WritePrivateProfileString("POS","px",tmp,RepCourant);
        sprintf(tmp,"%ld",Pos.top);        
        dwCRLecture=WritePrivateProfileString("POS","py",tmp,RepCourant);
        
        sprintf(tmp,"%ld",Pos.right-Pos.left);        
        dwCRLecture=WritePrivateProfileString("POS","sx",tmp,RepCourant);
             //SetTitle(tmp); 
         sprintf(tmp,"%ld",Pos.bottom-Pos.top);       
        dwCRLecture=WritePrivateProfileString("POS","sy",tmp,RepCourant);

}
else
	    wxMessageBox(_("Valeur NULL Erreur sauvegarde"), _("Alerte !"));
    
    


  Destroy();	


}


void Def_MTODlg::Initialisation()  // lancement par timer1
{

   short i=0;

        GetCurrentDirectory(258,RepCourant);
        strcat(RepCourant,"\\MTO_MA.ini");


        i=0;
    do
      {
        strcpy(CleALire," ");
        strcpy(CleALire,MTO1[i]);    
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("MTO1",CleALire,NULL,ValeurLue,45,RepCourant);
		// indice valeurs à affichées
        TMTO1Val[i]=atoi(ValeurLue);   // valeurs de codage   kaikai pour qnh,tp altz     
//sprintf(bufftps,"%i",TMTO1Val[i]);
//SetTitle(bufftps);
//Sleep(3000);
        i++;
      }while(i<21);
    //TMTO1Val[18]=(TMTO1Val[18])*10;

    i=0;

    do
      {
        strcpy(CleALire," ");
        strcpy(CleALire,MTO2[i]);
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("MTO2",CleALire,NULL,ValeurLue,45,RepCourant);
        TMTO2Val[i]=atoi(ValeurLue); 
             
        i++;
      }while(i<21);
//      SetTitle(wxT("Initialisation 2"));


 i=0;
    do
      {
        strcpy(CleALire," ");
        strcpy(CleALire,MTO3[i]);
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("MTO3",CleALire,NULL,ValeurLue,45,RepCourant);
        TMTO3Val[i]=atoi(ValeurLue);
        i++;
      }while(i<21);
 
   i=0;
    do
      {
        strcpy(CleALire," ");
        strcpy(CleALire,MTO4[i]);
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("MTO4",CleALire,NULL,ValeurLue,45,RepCourant);
        TMTO4Val[i]=atoi(ValeurLue);
        i++;
      }while(i<21);
 //         SetTitle(wxT("Initialisation 4"));

   i=0;
    do
      {
        strcpy(CleALire," ");
        strcpy(CleALire,MTO5[i]);
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("MTO5",CleALire,NULL,ValeurLue,45,RepCourant);
        TMTO5Val[i]=atoi(ValeurLue);
        i++;
      }while(i<21);
          // SetTitle(wxT("Initialisation 5"));

     i=0;
    do
      {
        strcpy(CleALire," ");
        strcpy(CleALire,MTO6[i]);
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("MTO6",CleALire,NULL,ValeurLue,45,RepCourant);
        TMTO6Val[i]=atoi(ValeurLue);
        i++;
      }while(i<21);
          //SetTitle(wxT("Initialisation 6"));
		// tempo entre NW_CLEAR et NW_SET pour affichage FS

        strcpy(CleALire," ");
        strcpy(CleALire,"Tempo");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Conf",CleALire,NULL,ValeurLue,45,RepCourant);
        Tempo=atoi(ValeurLue);
        strcpy(CleALire," ");
        strcpy(CleALire,"Clear");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Conf",CleALire,NULL,ValeurLue,45,RepCourant);
        bClear=atoi(ValeurLue);
        strcpy(CleALire," ");
        strcpy(CleALire,"Dynamic");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Conf",CleALire,NULL,ValeurLue,45,RepCourant);
        shDynamic=atoi(ValeurLue);
        strcpy(CleALire," ");
        strcpy(CleALire,"CDE");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Conf",CleALire,NULL,ValeurLue,45,RepCourant);
        shCDE=atoi(ValeurLue);
        strcpy(CleALire," ");
        strcpy(CleALire,"Global");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Conf",CleALire,NULL,ValeurLue,45,RepCourant);
        shGlobal=atoi(ValeurLue);
        strcpy(CleALire," ");
        strcpy(CleALire,"NWSET");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Conf",CleALire,NULL,ValeurLue,45,RepCourant);
        shSet=atoi(ValeurLue);
        strcpy(CleALire," ");
        strcpy(CleALire,"Port");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Conf",CleALire,NULL,ValeurLue,45,RepCourant);
       iPort=atoi(ValeurLue);



        // lecture offsets de travail iocard
        
        strcpy(CleALire," ");
        strcpy(CleALire,"O_MTO");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Offsets",CleALire,NULL,ValeurLue,45,RepCourant);
        ushAdr_MTO=strtol(ValeurLue,&pTampon,16);
        strcpy(CleALire," ");
        strcpy(CleALire,"O_Zone");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Offsets",CleALire,NULL,ValeurLue,45,RepCourant);
        ushAdr_Zone=strtol(ValeurLue,&pTampon,16);
        strcpy(CleALire," ");
        strcpy(CleALire,"O_Cde");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Offsets",CleALire,NULL,ValeurLue,45,RepCourant);
        ushAdr_Cde=strtol(ValeurLue,&pTampon,16);
        strcpy(CleALire," ");
        strcpy(CleALire,"O_AltAirPort");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Offsets",CleALire,NULL,ValeurLue,45,RepCourant);
        ushAdr_AltAirPort=strtol(ValeurLue,&pTampon,16);
        strcpy(CleALire," ");
        strcpy(CleALire,"O_QNH");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Offsets",CleALire,NULL,ValeurLue,45,RepCourant);
        ushAdr_QNH=strtol(ValeurLue,&pTampon,16);
        strcpy(CleALire," ");
        strcpy(CleALire,"O_Temperature");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Offsets",CleALire,NULL,ValeurLue,45,RepCourant);
        ushAdr_Temperature=strtol(ValeurLue,&pTampon,16);
        strcpy(CleALire," ");
        strcpy(CleALire,"O_ZRef");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Offsets",CleALire,NULL,ValeurLue,45,RepCourant);
        ushAdr_ZRef=strtol(ValeurLue,&pTampon,16);
        strcpy(CleALire," ");
        strcpy(CleALire,"O_WindDir");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Offsets",CleALire,NULL,ValeurLue,45,RepCourant);
        ushAdr_WindDir=strtol(ValeurLue,&pTampon,16);
        strcpy(CleALire," ");
        strcpy(CleALire,"O_Knots");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Offsets",CleALire,NULL,ValeurLue,45,RepCourant);
        ushAdr_Knots=strtol(ValeurLue,&pTampon,16);
        strcpy(CleALire," ");
        strcpy(CleALire,"O_Visibility");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Offsets",CleALire,NULL,ValeurLue,45,RepCourant);
        ushAdr_Visibility=strtol(ValeurLue,&pTampon,16);
        strcpy(CleALire," ");
        strcpy(CleALire,"O_Transition");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Offsets",CleALire,NULL,ValeurLue,45,RepCourant);
        ushAdr_Transition=strtol(ValeurLue,&pTampon,16);
        strcpy(CleALire," ");
        strcpy(CleALire,"O_Nuages");
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("Offsets",CleALire,NULL,ValeurLue,45,RepCourant);
        ushAdr_Nuages=strtol(ValeurLue,&pTampon,16);


        
        
        
        
 /*    
sprintf(bufftps,"adr  %i",ushAdr_AltAirPort);
SetTitle(bufftps);
Sleep(3000);
*/
        
//         SetTitle(wxT("Initialisation"));
		 //sprintf(bufftps,"Tempo %i  Clear %i  Dynamic %i",Tempo,bClear,shDynamic);
//SetTitle(bufftps);
//Sleep(3000);

}

void Def_MTODlg::Affichage_MTO(short num)
{
cZone=1;
  if(num==1)
  {
 		WxStaticText1->SetLabel("Météo 1");
	
		_cTrans1=cTrans=char(TMTO1Val[0]);		
		_cAlt_Z1=cAlt_Z=char(TMTO1Val[1]);	
/*
sprintf(bufftps,"%i",_cAlt_Z1);
SetTitle(bufftps);
Sleep(1000);
*/
		_cVisibility1=cVisibility=char(TMTO1Val[2]);	//	?
		_cClouds1=cClouds=char(TMTO1Val[3]);
		_cWindDir1=cWindDir=char(TMTO1Val[4]);
		_cKts1=cKts=char(TMTO1Val[5]);  // ?
		_cTrans2=cTrans=char(TMTO1Val[6]);
		_cAlt_Z2=cAlt_Z=char(TMTO1Val[7]);
		_cVisibility2=cVisibility=char(TMTO1Val[8]);
		_cClouds2=cClouds=char(TMTO1Val[9]);
		_cWindDir2=cWindDir=char(TMTO1Val[10]);
		_cKts2=cKts=char(TMTO1Val[11]);
/*
sprintf(bufftps,"%i",_cKts2);
SetTitle(bufftps);
Sleep(1000);
*/
		_cVisibility3=cVisibility=char(TMTO1Val[14]);
		_cClouds3=cClouds=char(TMTO1Val[15]);
		_cWindDir3=cWindDir=char(TMTO1Val[16]);
		_cKts3=cKts=char(TMTO1Val[17]);
		_shZRef=(TMTO1Val[18])*10;
		_shQNH=TMTO1Val[19];
		_cTp=TMTO1Val[20];
	
            WxEdit_Z1T1->SetValue(wxString::Format(wxT("%s"),IncT[TMTO1Val[0]]));
            WxEdit_Z1T2->SetValue(Z1[TMTO1Val[1]]);	

//sprintf(bufftps,"%i",_cKts2);
//SetTitle(Z1[TMTO1Val[1]]);
//Sleep(1000);
           WxEdit_V1->SetValue(IncV[TMTO1Val[2]]);
           WxEdit_C1->SetValue(Nuages[TMTO1Val[3]]);
           WxEdit_W1->SetValue(Vent[TMTO1Val[4]]);
           WxEdit_K1->SetValue(Kts[TMTO1Val[5]]);
           WxEdit_Z2T1->SetValue(IncT[TMTO1Val[6]]);
           WxEdit_Z2T2->SetValue(Z2[TMTO1Val[7]]);
           WxEdit_V2->SetValue(IncV[TMTO1Val[8]]);
           WxEdit_C2->SetValue(Nuages[TMTO1Val[9]]);
           WxEdit_W2->SetValue(Vent[TMTO1Val[10]]);
           WxEdit_K2->SetValue(Kts[TMTO1Val[11]]);
           WxEdit_V3->SetValue(IncV[TMTO1Val[14]]);
           WxEdit_C3->SetValue(Nuages[TMTO1Val[15]]);
           WxEdit_W3->SetValue(Vent[TMTO1Val[16]]);
           WxEdit_K3->SetValue(Kts[TMTO1Val[17]]);
      
//            WxEdit_V1->SetValue(wxString::Format(wxT("%s"),IncV[TMTO1Val[2]]));	
//            WxEdit_C1->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO1Val[3]]));	
//            WxEdit_W1->SetValue(wxString::Format(wxT("%s"),Vent[TMTO1Val[4]]));
//            WxEdit_K1->SetValue(wxString::Format(wxT("%s"),Kts[TMTO1Val[5]]));
//            WxEdit_Z2T1->SetValue(wxString::Format(wxT("%s"),IncT[TMTO1Val[6]]));
//            WxEdit_Z2T2->SetValue(wxString::Format(wxT("%s"),Z2[TMTO1Val[7]]));
//            WxEdit_V2->SetValue(wxString::Format(wxT("%s"),IncV[TMTO1Val[8]]));	
//            WxEdit_C2->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO1Val[9]]));
//            WxEdit_W2->SetValue(wxString::Format(wxT("%s"),Vent[TMTO1Val[10]]));
            //WxEdit_K2->SetValue(wxString::Format(wxT("%s"),Kts[TMTO1Val[11]]));
//            WxEdit_K2->SetValue(wxString::Format(wxT("%s"),Kts[TMTO1Val[11]]));
//            WxEdit_V3->SetValue(wxString::Format(wxT("%s"),IncV[TMTO1Val[14]]));
//            WxEdit_C3->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO1Val[15]]));
//            WxEdit_W3->SetValue(wxString::Format(wxT("%s"),Vent[TMTO1Val[16]]));
//            WxEdit_K3->SetValue(wxString::Format(wxT("%s"),Kts[TMTO1Val[17]]));

            WxEdit_Z->SetValue(wxString::Format(wxT("%i"),(TMTO1Val[18])*10));
            WxEdit_QNH->SetValue(wxString::Format(wxT("%d"),TMTO1Val[19]));
            WxEdit_Tp->SetValue(wxString::Format(wxT("%i"),TMTO1Val[20]));
            if(bConnect==1) Init_Offsets();				
  
  
   }
			
  if(num==2)
  {

		WxStaticText1->SetLabel("Météo 2");

		_cTrans1=cTrans=TMTO2Val[0];		
		_cAlt_Z1=cAlt_Z=TMTO2Val[1];	
		_cVisibility1=cVisibility=TMTO2Val[2];		
		_cClouds1=cClouds=TMTO2Val[3];
		_cWindDir1=cWindDir=TMTO2Val[4];
		_cKts1=cKts=TMTO2Val[5];
		_cTrans2=cTrans=TMTO2Val[6];
		_cAlt_Z2=cAlt_Z=TMTO2Val[7];
		_cVisibility2=cVisibility=TMTO2Val[8];
		_cClouds2=cClouds=TMTO2Val[9];
		_cWindDir2=_cWindDir=TMTO2Val[10];
		_cKts2=cKts=TMTO2Val[11];
		_cVisibility3=cVisibility=TMTO2Val[14];
		_cClouds3=cClouds=TMTO2Val[15];
		_cWindDir3=cWindDir=TMTO2Val[16];
		_cKts3=cKts=TMTO2Val[17];
		_shZRef=shZRef=TMTO2Val[18]*10;
		_shQNH=shQNH=TMTO2Val[19];
		_cTp=cTp=TMTO2Val[20];
            WxEdit_Z1T1->SetValue(wxString::Format(wxT("%s"),IncT[TMTO2Val[0]]));
            WxEdit_Z1T2->SetValue(wxString::Format(wxT("%s"),Z1[TMTO2Val[1]]));	
            WxEdit_V1->SetValue(wxString::Format(wxT("%s"),IncV[TMTO2Val[2]]));	
            WxEdit_C1->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO2Val[3]]));	
            WxEdit_W1->SetValue(wxString::Format(wxT("%s"),Vent[TMTO2Val[4]]));
            WxEdit_K1->SetValue(wxString::Format(wxT("%s"),Kts[TMTO2Val[5]]));
            WxEdit_Z2T1->SetValue(wxString::Format(wxT("%s"),IncT[TMTO2Val[6]]));
            WxEdit_Z2T2->SetValue(wxString::Format(wxT("%s"),Z2[TMTO2Val[7]]));
            WxEdit_V2->SetValue(wxString::Format(wxT("%s"),IncV[TMTO2Val[8]]));	
            WxEdit_C2->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO2Val[9]]));
            WxEdit_W2->SetValue(wxString::Format(wxT("%s"),Vent[TMTO2Val[10]]));
            WxEdit_K2->SetValue(wxString::Format(wxT("%s"),Kts[TMTO2Val[11]]));
            WxEdit_V3->SetValue(wxString::Format(wxT("%s"),IncV[TMTO2Val[14]]));
            WxEdit_C3->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO2Val[15]]));
            WxEdit_W3->SetValue(wxString::Format(wxT("%s"),Vent[TMTO2Val[16]]));
            WxEdit_K3->SetValue(wxString::Format(wxT("%s"),Kts[TMTO2Val[17]]));
            WxEdit_Z->SetValue(wxString::Format(wxT("%i"),TMTO2Val[18]));
            WxEdit_QNH->SetValue(wxString::Format(wxT("%d"),TMTO2Val[19]));
            WxEdit_Tp->SetValue(wxString::Format(wxT("%i"),TMTO2Val[20]));
            if(bConnect==1) Init_Offsets();	// ?					
            }						
             
  if(num==3)
  {

		WxStaticText1->SetLabel("Météo 3");

		_cTrans1=cTrans=TMTO3Val[0];		
		_cAlt_Z1=cAlt_Z=TMTO3Val[1];	
		_cVisibility1=cVisibility=TMTO3Val[2];		
		_cClouds1=cClouds=TMTO3Val[3];
		_cWindDir1=cWindDir=TMTO3Val[4];
		_cKts1=cKts=TMTO3Val[5];
		_cTrans2=cTrans=TMTO3Val[6];
		_cAlt_Z2=cAlt_Z=TMTO3Val[7];
		_cVisibility2=cVisibility=TMTO3Val[8];
		_cClouds2=cClouds=TMTO3Val[9];
		_cWindDir2=_cWindDir=TMTO3Val[10];
		_cKts2=cKts=TMTO3Val[11];
		_cVisibility3=cVisibility=TMTO3Val[14];
		_cClouds3=cClouds=TMTO3Val[15];
		_cWindDir3=cWindDir=TMTO3Val[16];
		_cKts3=cKts=TMTO3Val[17];
		_shZRef=shZRef=TMTO3Val[18]*10;
		_shQNH=shQNH=TMTO3Val[19];
		_cTp=cTp=TMTO3Val[20];
            WxEdit_Z1T1->SetValue(wxString::Format(wxT("%s"),IncT[TMTO3Val[0]]));
            WxEdit_Z1T2->SetValue(wxString::Format(wxT("%s"),Z1[TMTO3Val[1]]));	
            WxEdit_V1->SetValue(wxString::Format(wxT("%s"),IncV[TMTO3Val[2]]));	
            WxEdit_C1->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO3Val[3]]));	
            WxEdit_W1->SetValue(wxString::Format(wxT("%s"),Vent[TMTO3Val[4]]));
            WxEdit_K1->SetValue(wxString::Format(wxT("%s"),Kts[TMTO3Val[5]]));
            WxEdit_Z2T1->SetValue(wxString::Format(wxT("%s"),IncT[TMTO3Val[6]]));
            WxEdit_Z2T2->SetValue(wxString::Format(wxT("%s"),Z2[TMTO3Val[7]]));
            WxEdit_V2->SetValue(wxString::Format(wxT("%s"),IncV[TMTO3Val[8]]));	
            WxEdit_C2->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO3Val[9]]));
            WxEdit_W2->SetValue(wxString::Format(wxT("%s"),Vent[TMTO3Val[10]]));
            WxEdit_K2->SetValue(wxString::Format(wxT("%s"),Kts[TMTO3Val[11]]));
            WxEdit_V3->SetValue(wxString::Format(wxT("%s"),IncV[TMTO3Val[14]]));
            WxEdit_C3->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO3Val[15]]));
            WxEdit_W3->SetValue(wxString::Format(wxT("%s"),Vent[TMTO3Val[16]]));
            WxEdit_K3->SetValue(wxString::Format(wxT("%s"),Kts[TMTO3Val[17]]));
            WxEdit_Z->SetValue(wxString::Format(wxT("%i"),TMTO3Val[18]));
            WxEdit_QNH->SetValue(wxString::Format(wxT("%d"),TMTO3Val[19]));
            WxEdit_Tp->SetValue(wxString::Format(wxT("%i"),TMTO3Val[20]));
            if(bConnect==1) Init_Offsets();	// ?					
            }						
           
   if(num==4)
  {

		WxStaticText1->SetLabel("Météo 4");

		_cTrans1=cTrans=TMTO4Val[0];		
		_cAlt_Z1=cAlt_Z=TMTO4Val[1];	
		_cVisibility1=cVisibility=TMTO4Val[2];		
		_cClouds1=cClouds=TMTO4Val[3];
		_cWindDir1=cWindDir=TMTO4Val[4];
		_cKts1=cKts=TMTO4Val[5];
		_cTrans2=cTrans=TMTO4Val[6];
		_cAlt_Z2=cAlt_Z=TMTO4Val[7];
		_cVisibility2=cVisibility=TMTO4Val[8];
		_cClouds2=cClouds=TMTO4Val[9];
		_cWindDir2=_cWindDir=TMTO4Val[10];
		_cKts2=cKts=TMTO4Val[11];
		_cVisibility3=cVisibility=TMTO4Val[14];
		_cClouds3=cClouds=TMTO4Val[15];
		_cWindDir3=cWindDir=TMTO4Val[16];
		_cKts3=cKts=TMTO4Val[17];
		_shZRef=shZRef=TMTO4Val[18]*10;
		_shQNH=shQNH=TMTO4Val[19];
		_cTp=cTp=TMTO4Val[20];
            WxEdit_Z1T1->SetValue(wxString::Format(wxT("%s"),IncT[TMTO4Val[0]]));
            WxEdit_Z1T2->SetValue(wxString::Format(wxT("%s"),Z1[TMTO4Val[1]]));	
            WxEdit_V1->SetValue(wxString::Format(wxT("%s"),IncV[TMTO4Val[2]]));	
            WxEdit_C1->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO4Val[3]]));	
            WxEdit_W1->SetValue(wxString::Format(wxT("%s"),Vent[TMTO4Val[4]]));
            WxEdit_K1->SetValue(wxString::Format(wxT("%s"),Kts[TMTO4Val[5]]));
            WxEdit_Z2T1->SetValue(wxString::Format(wxT("%s"),IncT[TMTO4Val[6]]));
            WxEdit_Z2T2->SetValue(wxString::Format(wxT("%s"),Z2[TMTO4Val[7]]));
            WxEdit_V2->SetValue(wxString::Format(wxT("%s"),IncV[TMTO4Val[8]]));	
            WxEdit_C2->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO4Val[9]]));
            WxEdit_W2->SetValue(wxString::Format(wxT("%s"),Vent[TMTO4Val[10]]));
            WxEdit_K2->SetValue(wxString::Format(wxT("%s"),Kts[TMTO4Val[11]]));
            WxEdit_V3->SetValue(wxString::Format(wxT("%s"),IncV[TMTO4Val[14]]));
            WxEdit_C3->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO4Val[15]]));
            WxEdit_W3->SetValue(wxString::Format(wxT("%s"),Vent[TMTO4Val[16]]));
            WxEdit_K3->SetValue(wxString::Format(wxT("%s"),Kts[TMTO4Val[17]]));
            WxEdit_Z->SetValue(wxString::Format(wxT("%i"),TMTO4Val[18]));
            WxEdit_QNH->SetValue(wxString::Format(wxT("%d"),TMTO4Val[19]));
            WxEdit_Tp->SetValue(wxString::Format(wxT("%i"),TMTO4Val[20]));
            if(bConnect==1) Init_Offsets();	// ?					
            }
				
            
  if(num==5)
  {

		WxStaticText1->SetLabel("Météo 5");

		_cTrans1=cTrans=TMTO5Val[0];		
		_cAlt_Z1=cAlt_Z=TMTO5Val[1];	
		_cVisibility1=cVisibility=TMTO5Val[2];		
		_cClouds1=cClouds=TMTO5Val[3];
		_cWindDir1=cWindDir=TMTO5Val[4];
		_cKts1=cKts=TMTO5Val[5];
		_cTrans2=cTrans=TMTO5Val[6];
		_cAlt_Z2=cAlt_Z=TMTO5Val[7];
		_cVisibility2=cVisibility=TMTO5Val[8];
		_cClouds2=cClouds=TMTO5Val[9];
		_cWindDir2=_cWindDir=TMTO5Val[10];
		_cKts2=cKts=TMTO5Val[11];
		_cVisibility3=cVisibility=TMTO5Val[14];
		_cClouds3=cClouds=TMTO5Val[15];
		_cWindDir3=cWindDir=TMTO5Val[16];
		_cKts3=cKts=TMTO5Val[17];
		_shZRef=shZRef=TMTO5Val[18]*10;
		_shQNH=shQNH=TMTO5Val[19];
		_cTp=cTp=TMTO5Val[20];
            WxEdit_Z1T1->SetValue(wxString::Format(wxT("%s"),IncT[TMTO5Val[0]]));
            WxEdit_Z1T2->SetValue(wxString::Format(wxT("%s"),Z1[TMTO5Val[1]]));	
            WxEdit_V1->SetValue(wxString::Format(wxT("%s"),IncV[TMTO5Val[2]]));	
            WxEdit_C1->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO5Val[3]]));	
            WxEdit_W1->SetValue(wxString::Format(wxT("%s"),Vent[TMTO5Val[4]]));
            WxEdit_K1->SetValue(wxString::Format(wxT("%s"),Kts[TMTO5Val[5]]));
            WxEdit_Z2T1->SetValue(wxString::Format(wxT("%s"),IncT[TMTO5Val[6]]));
            WxEdit_Z2T2->SetValue(wxString::Format(wxT("%s"),Z2[TMTO5Val[7]]));
            WxEdit_V2->SetValue(wxString::Format(wxT("%s"),IncV[TMTO5Val[8]]));	
            WxEdit_C2->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO5Val[9]]));
            WxEdit_W2->SetValue(wxString::Format(wxT("%s"),Vent[TMTO5Val[10]]));
            WxEdit_K2->SetValue(wxString::Format(wxT("%s"),Kts[TMTO5Val[11]]));
            WxEdit_V3->SetValue(wxString::Format(wxT("%s"),IncV[TMTO5Val[14]]));
            WxEdit_C3->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO5Val[15]]));
            WxEdit_W3->SetValue(wxString::Format(wxT("%s"),Vent[TMTO5Val[16]]));
            WxEdit_K3->SetValue(wxString::Format(wxT("%s"),Kts[TMTO5Val[17]]));
            WxEdit_Z->SetValue(wxString::Format(wxT("%i"),TMTO5Val[18]));
            WxEdit_QNH->SetValue(wxString::Format(wxT("%d"),TMTO5Val[19]));
            WxEdit_Tp->SetValue(wxString::Format(wxT("%i"),TMTO5Val[20]));
            if(bConnect==1) Init_Offsets();	// ?					
            }						
        
  if(num==6)
  {
		WxStaticText1->SetLabel("Météo 6");

		_cTrans1=cTrans=TMTO6Val[0];		
		_cAlt_Z1=cAlt_Z=TMTO6Val[1];	
		_cVisibility1=cVisibility=TMTO6Val[2];		
		_cClouds1=cClouds=TMTO6Val[3];
		_cWindDir1=cWindDir=TMTO6Val[4];
		_cKts1=cKts=TMTO6Val[5];
		_cTrans2=cTrans=TMTO6Val[6];
		_cAlt_Z2=cAlt_Z=TMTO6Val[7];
		_cVisibility2=cVisibility=TMTO6Val[8];
		_cClouds2=cClouds=TMTO6Val[9];
		_cWindDir2=_cWindDir=TMTO6Val[10];
		_cKts2=cKts=TMTO6Val[11];
		_cVisibility3=cVisibility=TMTO6Val[14];
		_cClouds3=cClouds=TMTO6Val[15];
		_cWindDir3=cWindDir=TMTO6Val[16];
		_cKts3=cKts=TMTO6Val[17];
		_shZRef=shZRef=TMTO6Val[18]*10;
		_shQNH=shQNH=TMTO6Val[19];
		_cTp=cTp=TMTO6Val[20];
            WxEdit_Z1T1->SetValue(wxString::Format(wxT("%s"),IncT[TMTO6Val[0]]));
            WxEdit_Z1T2->SetValue(wxString::Format(wxT("%s"),Z1[TMTO6Val[1]]));	
            WxEdit_V1->SetValue(wxString::Format(wxT("%s"),IncV[TMTO6Val[2]]));	
            WxEdit_C1->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO6Val[3]]));	
            WxEdit_W1->SetValue(wxString::Format(wxT("%s"),Vent[TMTO6Val[4]]));
            WxEdit_K1->SetValue(wxString::Format(wxT("%s"),Kts[TMTO6Val[5]]));
            WxEdit_Z2T1->SetValue(wxString::Format(wxT("%s"),IncT[TMTO6Val[6]]));
            WxEdit_Z2T2->SetValue(wxString::Format(wxT("%s"),Z2[TMTO6Val[7]]));
            WxEdit_V2->SetValue(wxString::Format(wxT("%s"),IncV[TMTO6Val[8]]));	
            WxEdit_C2->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO6Val[9]]));
            WxEdit_W2->SetValue(wxString::Format(wxT("%s"),Vent[TMTO6Val[10]]));
            WxEdit_K2->SetValue(wxString::Format(wxT("%s"),Kts[TMTO6Val[11]]));
            WxEdit_V3->SetValue(wxString::Format(wxT("%s"),IncV[TMTO6Val[14]]));
            WxEdit_C3->SetValue(wxString::Format(wxT("%s"),Nuages[TMTO6Val[15]]));
            WxEdit_W3->SetValue(wxString::Format(wxT("%s"),Vent[TMTO6Val[16]]));
            WxEdit_K3->SetValue(wxString::Format(wxT("%s"),Kts[TMTO6Val[17]]));
            WxEdit_Z->SetValue(wxString::Format(wxT("%i"),TMTO6Val[18]));
            WxEdit_QNH->SetValue(wxString::Format(wxT("%d"),TMTO6Val[19]));
            WxEdit_Tp->SetValue(wxString::Format(wxT("%i"),TMTO6Val[20]));
            if(bConnect==1) Init_Offsets();	// ?					
            }
}

void Def_MTODlg::Init_Offsets()
{
   // if ((bConnect==true)&&(bInitOffset==false)) // faire init offset
       // {
          short shZRefT=_shZRef/10;
          // ****
          // short shQNHT=_shQNH*16;
          // *****
          short shQNHT=_shQNH;
          cVal=0; // pour ne pas envoyer de MTO au chargemen, action volontaire pour l'envoi
          FSUIPC_Write(ushAdr_MTO,sizeof(cMTO),&cMTO,&dwResultat);
          FSUIPC_Write(ushAdr_Zone,sizeof(cZone),&cZone,&dwResultat);  
          FSUIPC_Write(ushAdr_Cde,sizeof(cVal),&cVal,&dwResultat);          
          FSUIPC_Write(ushAdr_AltAirPort,sizeof(shZRefT),&shZRefT,&dwResultat); 
          FSUIPC_Write(ushAdr_QNH,sizeof(shQNH),&shQNHT,&dwResultat);
          FSUIPC_Write(ushAdr_Temperature,sizeof(_cTp),&_cTp,&dwResultat);
          FSUIPC_Write(ushAdr_ZRef,sizeof(_cAlt_Z1),&_cAlt_Z1,&dwResultat);
          FSUIPC_Write(ushAdr_WindDir,sizeof(cWindDir),&_cWindDir1,&dwResultat);
          FSUIPC_Write(ushAdr_Knots,sizeof(cKts),&_cKts1,&dwResultat);
          FSUIPC_Write(ushAdr_Visibility,sizeof(cVisibility),&_cVisibility1,&dwResultat);
          FSUIPC_Write(ushAdr_Transition,sizeof(cTrans),&_cTrans1,&dwResultat);
          FSUIPC_Write(ushAdr_Nuages,sizeof(cClouds),&_cClouds1,&dwResultat);

          FSUIPC_Process(&dwResultat);
// Pour eviter des erreurs d'affichage 
		  _cClouds=cClouds;
		  _cTrans=cTrans;
		  _cVisibility=cVisibility;
		  _cKts=cKts;
		  _cWindDir=cWindDir;
		  _cAlt_Z=cAlt_Z;
		  //_cTrans1=cTrans;
		  //_cTrans2=cTrans;
		  //_cAlt_Z1=cAlt_Z;
		  //_cAlt_Z2=cAlt_Z;
          bInitOffset=true;             
        //}           
}

void Def_MTODlg::timestamp()
{
    time(&tt);
    tmt=localtime(&tt);
    _ftime(&tmtb);
    tps=GetTickCount(),
    strcpy(bufftps,"");
    ttms=(((((((tmt->tm_hour*60)+tmt->tm_min)*60)+tmt->tm_sec)*1000)+tmt->tm_sec)+tmtb.millitm);
    sprintf(bufftps,"MTO %02d:%02d:%02d:%04d::%10ld",tmt->tm_hour,tmt->tm_min,tmt->tm_sec,tmtb.millitm,ttms);

/*
    if(bConnect==true)
    {
    sprintf(bufftps," MTO %02d:%02d:%02d:%04d::%10ld-> Connexion FS Réussie",tmt->tm_hour,tmt->tm_min,tmt->tm_sec,tmtb.millitm,ttms);
    SetTitle(wxT(bufftps));
    }
    else
    {
       //GetCurrentDirectory(258,RepCourant);
       //SetTitle(wxT(RepCourant));
        SetTitle(wxT(bufftps));

    }
 */
}
/*
 * WxTimer1Timer
 */
void Def_MTODlg::WxTimer1Timer(wxTimerEvent& event)
{

	// insert your code here
          //SetTitle(wxT("Initialisation début"));

      if(init==0)
      {
             Initialisation(); // lecture du fichier ini pour les 6 MTO
             Affichage_MTO(cMTO); // à l'init mto 1
             init=1;
          //SetTitle(wxT("Initialisation fin"));
                //CreateSocket();
      }
	WxTimer1->Stop();
	if(FSUIPC_Open(SIM_ANY,&dwResultat))
	{
      bConnect=true;
      bStop=false;
      Affichage_MTO(_cMTO); // à l'init mto1

      //bEnvoi_FS_Ok=false;
       //Init_Offsets();
        SetTitle(wxT("Connexion MTO-> FSUIPC")); 
     // CreateSocket(); // pour transmettre la structure ou la visi  
     // commentaire : suppression pour appli srv exterieure 20161210     

/*
        wxIPV4address addr;
        wxString s=addr.Hostname();

        addr.Hostname(addr.Hostname()) ;//
        addr.Service(iPort);
        wxSocket=new wxSocketServer(addr); // création socket
   */      
    

       WxTimer2->Start(250);  // timer appli
  //            SetTitle(wxT("Lancement Timer"));
 //EnvoiConfFs(); 
   
timetimer=0;
   
    }
    else
    {

        SetTitle(wxT("Non connecté à FSUIPC"));
//Sleep(3000);
if(bStop!=true)
{
        WxTimer1->Start(50);
    }
}
}

/*
 * WxTimer2Timer
*/
void Def_MTODlg::WxTimer2Timer(wxTimerEvent& event)
{
	// insert your code here
/*
timetimer++;
wxString s;
s.Printf("%d",timetimer);
SetTitle(s);
*/
	
    WxTimer2->Stop();
	LectureOffsets();      // lecture offsets

	
    TraitementOffsets();  //  traitement des changements d'état, mise à jour forme
    if(bStop!=true)
    {	
        WxTimer2->Start(50);
    }
    	
}

// Lecture Offsets
void Def_MTODlg::LectureOffsets()
{


    FSUIPC_Read(ushAdr_MTO,sizeof(cMTO),&cMTO,&dwResultat);  // 1 à 6 MTO
    FSUIPC_Read(ushAdr_Zone,sizeof(cZone),&cZone,&dwResultat);  // 1 à 3  Zones
    FSUIPC_Read(ushAdr_Cde,sizeof(cVal),&cVal,&dwResultat);  // =1 Sauvegarde MTO,=2  Envoi MTO à FS
    FSUIPC_Read(ushAdr_AltAirPort,sizeof(shZRef),&shZRef,&dwResultat);  // 0-3000 pas 10ft sol
    FSUIPC_Read(ushAdr_QNH,sizeof(shQNH),&shQNH,&dwResultat);  // QNH à diviser par 16 pour affichage
    FSUIPC_Read(ushAdr_Temperature,sizeof(cTp),&cTp,&dwResultat);  // +/- 127
    FSUIPC_Read(ushAdr_ZRef,sizeof(cAlt_Z),&cAlt_Z,&dwResultat);  //   0-19 zone 1, 0-19 zone 2  
    FSUIPC_Read(ushAdr_WindDir,sizeof(cWindDir),&cWindDir,&dwResultat); // 0 à 11
    FSUIPC_Read(ushAdr_Knots,sizeof(cKts),&cKts,&dwResultat);  // 0 à 6
    FSUIPC_Read(ushAdr_Visibility,sizeof(cVisibility),&cVisibility,&dwResultat);  // 0-11
    FSUIPC_Read(ushAdr_Transition,sizeof(cTrans),&cTrans,&dwResultat);   // ZxT1   0-6
    FSUIPC_Read(ushAdr_Nuages,sizeof(cClouds),&cClouds,&dwResultat); // 4x8
    //FSUIPC_Read(0x0560,36,&cBlocAvion,&dwResultat); // alt avion
          	     FSUIPC_Read(0x0570,4,&dwAltLo,&dwResultat);
      			 FSUIPC_Read(0x0574,4,&dwAltHi,&dwResultat);    
    FSUIPC_Process(&dwResultat);
      			 shAltAvion=short((ceil)(dwAltHi*3.28084)+(dwAltLo /65536)*(3.28084/65536));
     //wxString s;
     //s.Printf("%d",dwAltAvion);
     //SetTitle(s);  
         
    bAvion=true;// infos avion valides
//sprintf(bufftps,"alt %s",Z1[3]);
 //   SetTitle(wxT("Coucou Lec Offsets"));
	
 }
      
// Traitement Offsets

void Def_MTODlg::TraitementOffsets()
{
/*
            char *Z1[]={"0","50","100","150","200","250","300","350","400","450","500","600","700","800","1000","1500","2000","2500","3000"};
            char *Z2[]={"3000","4000","5000","6000","7000","8000","9000","10000","15000","20000"};
            char *IncV[]={"100m","200m","400m","800m","1200m","1600m","3.2km","8km","16km","32km","64km","illimite"};
            
            //char *Kts[]={"0","10","20","30","40","50","60"};
            char *Vent[]={"0","30","60","90","120","150","180","210","240","270","300","330"};
            char *IncT[]={"0","50","100","200","300","400","500"};
            char *Nuages[]={"ST-1","ST-2","ST-3","ST-4","ST-5","ST-6","ST-7","ST-8","CU-1","CU-2","CU-3","CU-4","CU-5","CU-6","CU-7","CU-8","CI-1","CI-2","CI-3","CI-4","CI-5","CI-6","CI-7","CI-8",
                            "OR-1","OR-2","OR-3","OR-4","OR-5","OR-6","OR-7","OR-8"};
*/
//    timestamp();
//    sprintf(bufftps,"%10ld",ttms);
//    SetTitle(wxT(bufftps));
 // ne faut il pas sauvegarder avant de changer   
 
//  affichage MTO sur 9102=2 ( sur validation de l'opérateur par cVal=2)
 if(_cMTO!=cMTO)  // traitement du changement d'état
{
bInitOffset=false;
    switch(cMTO)
    {
        case 1:
             Affichage_MTO(1);            
            break;
        case 2:
             Affichage_MTO(2);            
            break;
            
        case 3:
             Affichage_MTO(3);            
            break;
        case 4:
             Affichage_MTO(4);
             break;
        case 5:
             Affichage_MTO(5);          
            break;
        case 6:
             Affichage_MTO(6);            
            break;               
    } 
    _cMTO=cMTO; 
    bOffsets=true;  
}
   if(_cZone!=cZone)
    {

                      WxLedV1->Show(false);
                       //  WxLedE1->Show(true);                       

                         WxLedV2->Show(false);
                        // WxLedE2->Show(true);                       
                         WxLedV3->Show(false);
                      //  WxLedE3->Show(true);
               // WxEdit_C1->SetBackgroundColour(*wxWHITE);



       switch(cZone)
        {
            case 1:
                FSUIPC_Write(ushAdr_ZRef,sizeof(_cAlt_Z1),&_cAlt_Z1,&dwResultat);
                FSUIPC_Write(ushAdr_WindDir,sizeof(_cWindDir1),&_cWindDir1,&dwResultat);
                FSUIPC_Write(ushAdr_Knots,sizeof(_cKts1),&_cKts1,&dwResultat);
                FSUIPC_Write(ushAdr_Visibility,sizeof(_cVisibility1),&_cVisibility1,&dwResultat);
                FSUIPC_Write(ushAdr_Transition,sizeof(_cTrans1),&_cTrans1,&dwResultat);
                FSUIPC_Write(ushAdr_Nuages,sizeof(_cClouds1),&_cClouds1,&dwResultat);
                FSUIPC_Process(&dwResultat);              
                WxLedV1->Show(true);
               /* 
                WxEdit_C1->SetBackgroundColour(*wxWHITE);
                WxEdit_Z1T2->SetBackgroundColour(*wxCYAN);
                WxEdit_W1->SetBackgroundColour(*wxCYAN);
                WxEdit_K1->SetBackgroundColour(*wxCYAN);
                WxEdit_V1->SetBackgroundColour(*wxCYAN);
                WxEdit_Z1T1->SetBackgroundColour(*wxCYAN);
               */ 
                        
            break;
            case 2:
                FSUIPC_Write(ushAdr_ZRef,sizeof(_cAlt_Z2),&_cAlt_Z2,&dwResultat);
                FSUIPC_Write(ushAdr_WindDir,sizeof(_cWindDir2),&_cWindDir2,&dwResultat);
                FSUIPC_Write(ushAdr_Knots,sizeof(_cKts2),&_cKts2,&dwResultat);
                FSUIPC_Write(ushAdr_Visibility,sizeof(_cVisibility2),&_cVisibility2,&dwResultat);
                FSUIPC_Write(ushAdr_Transition,sizeof(_cTrans2),&_cTrans2,&dwResultat);
                FSUIPC_Write(ushAdr_Nuages,sizeof(_cClouds2),&_cClouds2,&dwResultat);
                FSUIPC_Process(&dwResultat);
                WxLedV2->Show(true);
                
                
            break;
            case 3:
                //FSUIPC_Write(0x9108,1,&_cAlt_Z1,&dwResultat);
                FSUIPC_Write(ushAdr_WindDir,sizeof(_cWindDir3),&_cWindDir3,&dwResultat);
                FSUIPC_Write(ushAdr_Knots,sizeof(_cKts3),&_cKts3,&dwResultat);
                FSUIPC_Write(ushAdr_Visibility,sizeof(_cVisibility3),&_cVisibility3,&dwResultat);
                //FSUIPC_Write(0x910C,1,&_cTrans1,&dwResultat);
                FSUIPC_Write(ushAdr_Nuages,sizeof(_cClouds3),&_cClouds3,&dwResultat);
                FSUIPC_Process(&dwResultat);
                         WxLedV3->Show(true);
                         
            break;
        }
                _cZone=cZone;
                    bOffsets=true;


}
 //   SetTitle(wxT("Coucou TR Offsets"));
    if(_shZRef!=shZRef)
        {
            WxEdit_Z->SetValue(wxString::Format(wxT("%i"),shZRef*10)); // valeur à sauvegarder
            _shZRef=shZRef;
                bOffsets=true;
        }
    if(_shQNH!=shQNH)
        {
             WxEdit_QNH->SetValue(wxString::Format(wxT("%i"),shQNH)); // /16)); //  valeur à sauvegarder

            _shQNH=shQNH;
                bOffsets=true;
        }
    if(_cTp!=cTp)
        {
            WxEdit_Tp->SetValue(wxString::Format(wxT("%i"),cTp));
            _cTp=cTp;
                bOffsets=true;
        }
////////////////////////////////////////////////////////////////////////////////////////
    //if((_cClouds!=cClouds)&&(cClouds<32))
	//{
      switch(cZone)
      {
          
          case 1:
                
            // WxStaticText4->SetLabel("Zone active : 1");
			if((_cClouds!=cClouds)&&(cClouds<33))
				{
                WxEdit_C1->SetValue(Nuages[cClouds]);
                _cClouds1=cClouds;
                _cClouds=cClouds;
                    bOffsets=true;
				}

				
			if((_cAlt_Z!=cAlt_Z)&&(cAlt_Z<20))
			{
				WxEdit_Z1T2->SetValue(wxT(Z1[cAlt_Z]));
				_cAlt_Z1=cAlt_Z;
				_cAlt_Z=cAlt_Z;
				    bOffsets=true;
			}			  
			if(_cWindDir!=cWindDir)
				{
				WxEdit_W1->SetValue(Vent[cWindDir]);
				_cWindDir1=cWindDir;
				_cWindDir=cWindDir;
				    bOffsets=true;
				}			  
			if(_cKts!=cKts)
				{
				WxEdit_K1->SetValue(Kts[cKts]);
				_cKts1=cKts;
				_cKts=cKts;
				    bOffsets=true;
				}				
			if(_cVisibility!=cVisibility)
				{
				WxEdit_V1->SetValue(IncV[cVisibility]);
				_cVisibility1=cVisibility;
				_cVisibility=cVisibility;
				    bOffsets=true;
				}				
			if(_cTrans!=cTrans)
				{
				WxEdit_Z1T1->SetValue(IncT[cTrans]);
				_cTrans1=cTrans;
				_cTrans=cTrans;
				    bOffsets=true;
				}			  
          break;
		  
          case 2 :
               //  WxStaticText4->SetLabel("Zone active : 2");
			if((_cClouds!=cClouds)&&(cClouds<33))
				{
                    WxEdit_C2->SetValue(Nuages[cClouds]);
                    _cClouds2=cClouds;
                    _cClouds=cClouds;
                        bOffsets=true;
                }
			if((_cAlt_Z!=cAlt_Z)&&(cAlt_Z<20))
				{
				WxEdit_Z2T2->SetValue(Z2[cAlt_Z]);
				_cAlt_Z2=cAlt_Z;
				_cAlt_Z=cAlt_Z;
				    bOffsets=true;
				}				
			if(_cWindDir!=cWindDir)
				{
				WxEdit_W2->SetValue(Vent[cWindDir]);
				_cWindDir2=cWindDir;
				_cWindDir=cWindDir;
				    bOffsets=true;
				}				
			if(_cKts!=cKts)
				{
				WxEdit_K2->SetValue(Kts[cKts]);
				_cKts2=cKts;
				_cKts=cKts;
				    bOffsets=true;
				}				
			if(_cVisibility!=cVisibility)
				{
				WxEdit_V2->SetValue(IncV[cVisibility]);
				_cVisibility2=cVisibility;
				_cVisibility=cVisibility;
				    bOffsets=true;
				}				
			if(_cTrans!=cTrans)
				{
				WxEdit_Z2T1->SetValue(IncT[cTrans]);
				_cTrans2=cTrans;
				_cTrans=cTrans;
				    bOffsets=true;
				}								
          break;
          case 3 :
               //  WxStaticText4->SetLabel("Zone active : 3");
			if((_cClouds!=cClouds)&&(cClouds<33))
				{
                    WxEdit_C3->SetValue(Nuages[cClouds]);
                    _cClouds3=cClouds;
                    _cClouds=cClouds;
                        bOffsets=true;
                }
			if(_cWindDir!=cWindDir)
				{
				WxEdit_W3->SetValue(Vent[cWindDir]);
				_cWindDir3=cWindDir;
				_cWindDir=cWindDir;
				    bOffsets=true;
				}				
			if(_cKts!=cKts)
				{
				WxEdit_K3->SetValue(Kts[cKts]);
				_cKts3=cKts;
				_cKts=cKts;
				    bOffsets=true;
				}				
			if(_cVisibility!=cVisibility)
				{
				WxEdit_V3->SetValue(IncV[cVisibility]);
				_cVisibility3=cVisibility;
				_cVisibility=cVisibility;
				    bOffsets=true;
				}								
          break;      
      }
	  
  if(_cVal!=cVal)
      {
                    //SetTitle("il passe par ici!");
		  switch(cVal)
		   {
            case 1:
                SauvegardeConf(); // Sauvegarde MTO en cours dans ini ( donc sélectionnée)
                    SetTitle(wxT("Sauvegarde MTO"));
                break;
/*            case 2:
                // SetTitle(wxT("hello")); 
                AffichageConf();         
                //AffichageConf();   // Affichage MTO sélectionnée à partir du ini
                break;
*/  
          case 2 :
                if(bConnect==true)
                {
                    EnvoiConfFs(); // Envoi FS de la MTO sélectionnée et affichée  
                    SetTitle(wxT("Envoi MTO->FSUIPC"));
                }
                break;
            }
        _cVal=cVal;
            bOffsets=true;
        }
    if(bEnvoi_FS_Ok==true)
     {
        if(_shAltAvion!=shAltAvion)
           {
              //SetTitle(wxT("Coucou Je suis là : gestion avion")); 
                GestionAltAvion();
                _shAltAvion=shAltAvion;
                    bOffsets=true;
            }
      }
 //    SetTitle(wxT("Coucou Fin"));     
}



// rappel de la météo sélectionnée
void Def_MTODlg::AffichageConf()  //  // 9102=2
{
    Initialisation();
    Affichage_MTO(cMTO);            
}
// validation = 1: sauvegarde des informations affichées  9102=1
void Def_MTODlg::SauvegardeConf()  //
{

        int i=0;
        //GetCurrentDirectory(258,RepCourant);
        //strcat(RepCourant,"\\MTO_MA.ini");
        
// Valeurs indice tableaux ( = offsets lus)
             sprintf(TMTO[0],"%d",_cTrans1);
             sprintf(TMTO[1],"%d",_cAlt_Z1);
             sprintf(TMTO[2],"%d",_cVisibility1);
             sprintf(TMTO[3],"%d",_cClouds1);
             sprintf(TMTO[4],"%d",_cWindDir1);
             sprintf(TMTO[5],"%d",_cKts1);
             
             sprintf(TMTO[6],"%d",_cTrans2);
             sprintf(TMTO[7],"%d",_cAlt_Z2);
             sprintf(TMTO[8],"%d",_cVisibility2);
             sprintf(TMTO[9],"%d",_cClouds2);
             sprintf(TMTO[10],"%d",_cWindDir2);
             sprintf(TMTO[11],"%d",_cKts2);
             
             sprintf(TMTO[12],"%d",0);
             sprintf(TMTO[13],"%d",20000);
             sprintf(TMTO[14],"%d",_cVisibility3);
             sprintf(TMTO[15],"%d",_cClouds3);
             sprintf(TMTO[16],"%d",_cWindDir3);
             sprintf(TMTO[17],"%d",_cKts3);
             
             sprintf(TMTO[18],"%d",_shZRef);
             sprintf(TMTO[19],"%d",_shQNH); ///16);
             sprintf(TMTO[20],"%d",_cTp);
   i=0;
    switch(cMTO)
    {
		case 1 :
          i=0;  
        do
         {
            strcpy(CleAEcr,"         ");
            strcpy(CleAEcr,MTO1[i]);           
            dwCRLecture=WritePrivateProfileString("MTO1",CleAEcr,TMTO[i],RepCourant);

           i++;
          }while(i<21);   
                                              
        i=0;
        do
        {
        strcpy(CleALire," ");
        strcpy(CleALire,MTO1[i]);
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("MTO1",CleALire,NULL,ValeurLue,45,RepCourant);
		// indice valeurs à affichées
        TMTO1Val[i]=atoi(ValeurLue);   // valeurs de codage   kaikai pour qnh,tp altz

        i++;
        }while(i<21);
        Affichage_MTO(cMTO);
			break;

        case 2 :
        i=0;      
        do
         {
            strcpy(CleAEcr,"       ");
            strcpy(CleAEcr,MTO2[i]);
            dwCRLecture=WritePrivateProfileString("MTO2",CleAEcr,TMTO[i],RepCourant);
//SetTitle(CleAEcr);
//Sleep(50);
			i++;
          }while(i<21); 
        i=0;
        do
        {
        strcpy(CleALire," ");
        strcpy(CleALire,MTO2[i]);
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("MTO2",CleALire,NULL,ValeurLue,45,RepCourant);
		// indice valeurs à affichées
        TMTO2Val[i]=atoi(ValeurLue);   // valeurs de codage   kaikai pour qnh,tp altz
        i++;
        }while(i<21);
        Affichage_MTO(cMTO);  
          
                    
            break;
           
        case 3 :
        i=0;
        do
         {
            strcpy(CleAEcr,"     ");
            strcpy(CleAEcr,MTO3[i]);
            dwCRLecture=WritePrivateProfileString("MTO3",CleAEcr,TMTO[i],RepCourant);

			i++;
          }while(i<21);  
        i=0;
        do
        {
        strcpy(CleALire," ");
        strcpy(CleALire,MTO3[i]);
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("MTO3",CleALire,NULL,ValeurLue,45,RepCourant);
		// indice valeurs à affichées
        TMTO3Val[i]=atoi(ValeurLue);   // valeurs de codage   kaikai pour qnh,tp altz
//sprintf(bufftps,"%i",TMTO1Val[i]);
//SetTitle(bufftps);
//Sleep(3000);
        i++;
        }while(i<21);
        Affichage_MTO(cMTO);  
          
          
          
                    		 
            break; 
        case 4 :
        i=0;
        do
         {
            strcpy(CleAEcr,"     ");
            strcpy(CleAEcr,MTO4[i]);
            dwCRLecture=WritePrivateProfileString("MTO4",CleAEcr,TMTO[i],RepCourant);

			i++;
          }while(i<21);	
                i=0;
        do
        {
        strcpy(CleALire," ");
        strcpy(CleALire,MTO4[i]);
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("MTO4",CleALire,NULL,ValeurLue,45,RepCourant);
		// indice valeurs à affichées
        TMTO4Val[i]=atoi(ValeurLue);   // valeurs de codage   kaikai pour qnh,tp altz
//sprintf(bufftps,"%i",TMTO1Val[i]);
//SetTitle(bufftps);
//Sleep(3000);
        i++;
        }while(i<21);
        Affichage_MTO(cMTO);  
          
          	
			break;
			
		case 5 :
        i=0;
        do
         {
            strcpy(CleAEcr,"     ");
            strcpy(CleAEcr,MTO5[i]);
            dwCRLecture=WritePrivateProfileString("MTO5",CleAEcr,TMTO[i],RepCourant);

			i++;
          }while(i<21);	
                 i=0;
        do
        {
        strcpy(CleALire," ");
        strcpy(CleALire,MTO5[i]);
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("MTO5",CleALire,NULL,ValeurLue,45,RepCourant);
		// indice valeurs à affichées
        TMTO5Val[i]=atoi(ValeurLue);   // valeurs de codage   kaikai pour qnh,tp altz
//sprintf(bufftps,"%i",TMTO1Val[i]);
//SetTitle(bufftps);
//Sleep(3000);
        i++;
        }while(i<21);
        Affichage_MTO(cMTO); 
          
          
			break;
            			
		case 6 :
        i=0;
        do
         {
            strcpy(CleAEcr,"     ");
            strcpy(CleAEcr,MTO6[i]);
            dwCRLecture=WritePrivateProfileString("MTO6",CleAEcr,TMTO[i],RepCourant);

			i++;
          }while(i<21);	
               i=0;
        do
        {
        strcpy(CleALire," ");
        strcpy(CleALire,MTO6[i]);
        strcpy(ValeurLue,"");
        dwCRLecture=GetPrivateProfileString("MTO6",CleALire,NULL,ValeurLue,45,RepCourant);
		// indice valeurs à affichées
        TMTO6Val[i]=atoi(ValeurLue);   // valeurs de codage   kaikai pour qnh,tp altz
//sprintf(bufftps,"%i",TMTO1Val[i]);
//SetTitle(bufftps);
//Sleep(3000);
        i++;
        }while(i<21);
        Affichage_MTO(cMTO);   
          
			break;       
        default :
			break;
         
    }
}
// envoi FS météo sélectionnée et affichée ( sauvegarde par précaution )  9102=3
void Def_MTODlg::EnvoiConfFs()
{


 //SetTitle("Coucou, je sduis là");
//timestamp();
    ushAltLo1=short((_shZRef*10)/3.28); 
    ushAltUp3=short(20000/3.28)+ushAltLo1;
    ushAltLo3=short (( TZ2[_cAlt_Z2])/3.28)+ushAltLo1;;
    ushAltUp2= short((TZ2[_cAlt_Z2])/3.28)+ushAltLo1;;
    ushAltLo2= short((TZ1[_cAlt_Z1])/3.28)+ushAltLo1;;
    ushAltUp1=short((TZ1[_cAlt_Z1])/3.28)+ushAltLo1;;

    
    ushKnots3=short(TKts[_cKts3]);
    ushKnots2=short(TKts[_cKts2]);
    ushKnots1=short(TKts[_cKts1]);
    
    ushWindDir3=short(((TWinDir[_cWindDir3])*65535)/360);
    ushWindDir2=short(((TWinDir[_cWindDir2])*65535)/360);
    ushWindDir1=short(((TWinDir[_cWindDir1])*65535)/360);
    
    ushVisibility1=short(TVis[_cVisibility1]);
    //ushVisibility2=short(TVis[_cVisibility2]);
    //ushVisibility3=short(TVis[_cVisibility3]);

    switch(_cClouds1/8)
    {
     case 0:
        ucNuages1=8;
        ucCoverage1=char((_cClouds1%8)+1);
        break;
     case 1:
        ucNuages1=9;
         ucCoverage1=char((_cClouds1%8)+1);
        break;
     case 2:
        ucNuages1=1;
        ucCoverage1=char((_cClouds1%8)+1);
        break;
     case 3:
        ucNuages1=10;
        ucCoverage1=char((_cClouds1%8)+1);
        break;
    }

    switch(_cClouds2/8)
    {
     case 0:
        ucNuages2=8;
        ucCoverage2=char((_cClouds2%8)+1);
        break;
     case 1:
        ucNuages2=9;
         ucCoverage2=char((_cClouds2%8)+1);
        break;
     case 2:
        ucNuages2=1;
        ucCoverage2=char((_cClouds2%8)+1);
        break;
     case 3:
        ucNuages2=10;
        ucCoverage2=char((_cClouds2%8)+1);
        break;
    }

    switch(_cClouds3/8)
    {
     case 0:
        ucNuages3=8;
        ucCoverage3=char( (_cClouds3%8)+1);
        break;
     case 1:
        ucNuages3=9;
         ucCoverage3=char(( _cClouds3%8)+1);
        break;
     case 2:
        ucNuages3=1;
        ucCoverage3=char(( _cClouds3%8)+1);
        break;
     case 3:
        ucNuages3=10;
        ucCoverage3= char((_cClouds3%8)+1);
        break;
    }
//    sprintf(bufftps,"%02d:%02d:%02d:%04d::%10ld",tmt->tm_hour,tmt->tm_min,tmt->tm_sec,tmtb.millitm,ttms);
//int k=tmt->tm_hour+tmt->tm_min+tmt->tm_sec+tmtb.millitm+ttms;
  	//timestamp();
//  	sprintf(bufftps,"C1 %i  C2 %i  C3  %i",ucCoverage1,ucCoverage2,ucCoverage3);
//  	SetTitle(bufftps);
//  	Sleep(3000);
	
//    sprintf(bufftps,"%10ld",ttms);
///////////////////////////////////////////////////////////////////////////////
// ****************************************************** debut NWI

   // if(bClear==1)
   // {
        NWI0.uCommand=NW_DYNAMICS;
        NWI0.uDynamics=shDynamic;
        uiTimeTicks=GetTickCount();
        NWI0.ulTimeStamp=uiTimeTicks;
        FSUIPC_Write(0xC800,1024,&NWI0,&dwResultat);  // 38 en 1024
        FSUIPC_Process(&dwResultat);
        Sleep(Tempo);
        NWI0.uCommand=NW_CLEAR;
        NWI0.uDynamics=shDynamic;
        uiTimeTicks=GetTickCount();
        NWI0.ulTimeStamp=uiTimeTicks;
        FSUIPC_Write(0xC800,1024,&NWI0,&dwResultat); // 38 en 1024
        FSUIPC_Process(&dwResultat);
        Sleep(Tempo);
   // }


 NWI.uCommand=shSet; // NW_SET ou NW_SETEXACT
 //NWI.ulSignature=0;
 NWI.uDynamics=shDynamic;
 //NWI.nElevation=0;
 (shGlobal==1)? strcpy(NWI.chICAO,"GLOB"):strcpy(NWI.chICAO,"LFBD");

 NWI.Press.Pressure=_shQNH*16; // ok modif du 22 04 2017
 
 NWI.Vis.UpperAlt=ushAltUp3;
 NWI.Vis.LowerAlt=ushAltLo1;         //m
 NWI.Vis.Range=ushVisibility1;  // zone 1

 NWI.nTempCtr=1;
 
 NWI.Temp[0].Alt=ushAltLo1;
 NWI.Temp[0].Day=short(_cTp); // °
 
 NWI.nWindsCtr=3;
 NWI.Wind[0].UpperAlt=ushAltUp1; // m Z1
 NWI.Wind[0].Speed=ushKnots1;
 NWI.Wind[0].Direction=ushWindDir1;
 
 NWI.Wind[1].UpperAlt=ushAltUp2;
 NWI.Wind[1].Speed=ushKnots2;
 NWI.Wind[1].Direction=ushWindDir2;
 
 NWI.Wind[2].UpperAlt=ushAltUp3;
 NWI.Wind[2].Speed=ushKnots3;
 NWI.Wind[2].Direction=ushWindDir3;

 NWI.nCloudsCtr=3;
 NWI.Cloud[0].UpperAlt=ushAltUp1;
 NWI.Cloud[0].LowerAlt=ushAltLo1;
 NWI.Cloud[0].Type=ucNuages1;
 NWI.Cloud[0].Coverage=ucCoverage1; 
 
 NWI.Cloud[1].UpperAlt=ushAltUp2;
 NWI.Cloud[1].LowerAlt=ushAltLo2;
 NWI.Cloud[1].Type=ucNuages2;
 NWI.Cloud[1].Coverage=ucCoverage2; 
 
 NWI.Cloud[2].UpperAlt=ushAltUp3;
 NWI.Cloud[2].LowerAlt=ushAltLo3;
 NWI.Cloud[2].Type=ucNuages3;
 NWI.Cloud[2].Coverage=ucCoverage3;
 
 uiTimeTicks=GetTickCount();
 NWI.ulTimeStamp=uiTimeTicks;
 FSUIPC_Write(0xC800,1024,&NWI,&dwResultat);
 if(FSUIPC_Process(&dwResultat))
 {
    bEnvoi_FS_Ok=true; 
    bMTO=true;   // infos MTO valides  
 }
       /*
        NWI.uCommand=NW_SET;
        //NWI.uDynamics=shDynamic;
        uiTimeTicks=GetTickCount();
        NWI.ulTimeStamp=uiTimeTicks;
        FSUIPC_Write(0xC800,38,&NWI,&dwResultat);
        FSUIPC_Process(&dwResultat);
*/

//Sleep(5000);
//FSUIPC_Write(0xDC00,1024,&NWI,&dwResultat);
//FSUIPC_Process(&dwResultat);
 ///////////////////////////////////////////////////////////////////////
 // ***************************************** fin NWI
 
}
void Def_MTODlg::GestionAltAvion()
{
    ushAltLo1=short(_shZRef*10); //     ushAltLo1=short((_shZRef*10)/3.28);
    ushAltUp3=short(20000+ushAltLo1); //     ushAltUp3=short(20000/3.28)+ushAltLo1
    ushAltLo3=short (( TZ2[_cAlt_Z2])+ushAltLo1);//    ushAltLo3=short (( TZ2[_cAlt_Z2])/3.28)+ushAltLo1
    ushAltUp2= short((TZ2[_cAlt_Z2])+ushAltLo1);//    ushAltUp2= short((TZ2[_cAlt_Z2])/3.28)+ushAltLo1
    ushAltLo2= short((TZ1[_cAlt_Z1])+ushAltLo1);//    ushAltLo2= short((TZ1[_cAlt_Z1])/3.28)+ushAltLo1
    ushAltUp1=short((TZ1[_cAlt_Z1])+ushAltLo1);//    ushAltUp1=short((TZ1[_cAlt_Z1])/3.28)+ushAltLo1

    ushAltAvion=(unsigned short)(shAltAvion); // lecture/calcul altitude avec lectures offsets
    ushVisibility1=short(TVis[_cVisibility1]);//
	ushVisiTR1=short((TR[_cTrans1])/2);//	ushVisiTR1=short(((TR[_cTrans1])/2)/3.28)
	ushVisiTR2=short((TR[_cTrans2])/2);//	ushVisiTR2=short(((TR[_cTrans2])/2)/3.28)
	ushTransition1=short(TR[_cTrans1]);//	ushTransition1=short((TR[_cTrans1])/3.28)
	ushTransition2=short(TR[_cTrans2]);//	ushTransition2=short((TR[_cTrans2])/3.28)

	ushAltTransition1=short(  ushAltUp1-ushVisiTR1 );
	ushAltTransition2=short (ushAltLo2+ushVisiTR1);
	ushAltTransition3=short(ushAltUp2-ushVisiTR2);
	ushAltTransition4=short(ushAltLo3+ushVisiTR2);	
    ushVisibility2=short(TVis[_cVisibility2]);
    ushVisibility3=short(TVis[_cVisibility3]);  
  
     if((ushAltAvion > ushAltLo1) && (ushAltAvion<ushAltUp1)) // zone 1
        {
            if((ushAltAvion > ushAltTransition1) && (ushAltAvion<ushAltUp1)) // transtion basse z1
			{
              GestionTransitionZ1(); // calcul variation de visi
            }
            else
            {
    		  FSUIPC_Write(0x0E8A,2,&ushVisibility1,&dwResultat);  // envoi visi zone 1
			  FSUIPC_Process(&dwResultat);			    
		    }
        }
		else
		{
			if((ushAltAvion > ushAltLo2) && (ushAltAvion<ushAltUp2)) // zone 2
			{
				if((ushAltAvion > ushAltLo2) && (ushAltAvion<ushAltTransition2)) // transition basse de z1/z2
				{
				    GestionTransitionZ1();// calcul variation de visi
				}
				else
				{
					if((ushAltAvion > ushAltTransition3) && (ushAltAvion < ushAltUp2)) // transition haute de z2
					{
					   //SetTitle("TR3");
                       GestionTransitionZ2();
					   
					}
					else
					{			   
						FSUIPC_Write(0x0E8A,2,&ushVisibility2,&dwResultat);		// envoi visi 2					
						FSUIPC_Process(&dwResultat);												
					}	
				}
			}
			else
			{	
				if((ushAltAvion > ushAltLo3) && (ushAltAvion<ushAltUp3)) // zone 3
				{
					if((ushAltAvion > ushAltLo3) && (ushAltAvion<ushAltTransition4)) // transition basse z3
					{
					  //SetTitle("TR4");
                      GestionTransitionZ2();
					}
					else
					{
    				    FSUIPC_Write(0x0E8A,2,&ushVisibility3,&dwResultat);		// envoi visi 3					
    					FSUIPC_Process(&dwResultat);												
					}
				}
			}
		}
}			

void Def_MTODlg::GestionTransitionZ1()  // z1/z2 transition 1/2
{
 
             if(ushVisibility2>ushVisibility1)
                 {
                	shDiffVisiZ1=short (ushVisibility2-ushVisibility1);  // transition 1
                    ushVisiCalculTR1=short(ushVisibility2-((shDiffVisiZ1*(ushTransition1-(ushAltAvion-ushAltTransition1))/ushTransition1))); // calcul
                 }	
            else
                {
                	shDiffVisiZ1=short (ushVisibility1-ushVisibility2);  // transition 1	
                    ushVisiCalculTR1=short(ushVisibility2+((shDiffVisiZ1*(ushTransition1-(ushAltAvion-ushAltTransition1))/ushTransition1))); // calcul	
                } 
    		 FSUIPC_Write(0x0E8A,2,&ushVisiCalculTR1,&dwResultat);				
    		 FSUIPC_Process(&dwResultat);	
             		
}
void Def_MTODlg::GestionTransitionZ2()  // z2/z3 transition 3/4
{

            if(ushVisibility3>ushVisibility2)
            {
                shDiffVisiZ2=short(ushVisibility3-ushVisibility2 );  // transition 3
                ushVisiCalculTR2=short(ushVisibility3-((shDiffVisiZ2*(ushTransition2-(ushAltAvion-ushAltTransition3))/ushTransition2))); // calcul
            }
            else
            {
                shDiffVisiZ2=short (ushVisibility2-ushVisibility3 );  // transition 4
                ushVisiCalculTR2=short(ushVisibility3+((shDiffVisiZ2*(ushTransition2-(ushAltAvion-ushAltTransition3))/ushTransition2))); // calcul               
            }
    		FSUIPC_Write(0x0E8A,2,&ushVisiCalculTR2,&dwResultat);				
			FSUIPC_Process(&dwResultat);
            				
}
/*
void Def_MTODlg::CreateSocket()
{
        wxIPV4address addr;   
        wxString s=addr.Hostname();       
        addr.Hostname(s) ;// 
        addr.Service(iPort);
   
        wxSocket=new wxSocketServer(addr); // création socket

            if(wxSocket->Ok())
                {
                    wxSocket->SetEventHandler(*this,SERVER_ID);
                    wxSocket->SetNotify(wxSOCKET_CONNECTION_FLAG);
                    wxSocket->Notify(true);             
                }
            else 
                {
                    s.Printf(_("%s : %s-> échec création"),(addr.Hostname()).c_str(),(addr.IPAddress()).c_str());
                    SetTitle(s);
                    //Sleep(3000);
                    ini=0;        
                    return;
                }
           
        numClients=0;
}

void Def_MTODlg::OnServerEvent(wxSocketEvent& event)
{
     SetTitle("Event Server");
     wxString s;       //{
     wxSocketBase *sock;
     sock=wxSocket->Accept(false);
                if(sock)
                {
                        sock->SetEventHandler(*this,SOCKET_ID);
                        sock->SetNotify(wxSOCKET_INPUT_FLAG |wxSOCKET_LOST_FLAG);
                        sock->Notify(true);                       
                        sock->GetPeer(addr);

                        //s.Printf(_("%s : %s %s connecté"),(addr.IPAddress()).c_str(),addr.Service(),(addr.Hostname()).c_str());
                        //SetTitle(s);
                        numClients++;
                        //Sleep(3000);                       
                }
                else
                {
                        s.Printf(_("%s : %s %s non connecté"),(addr.IPAddress()).c_str(),addr.Service(),(addr.Hostname()).c_str());
                        SetTitle(s);
                        Sleep(3000);   
                }
     //SetTitle("Connexion");
     //Sleep(3000);
    //wxString s;    
     //s.Printf(_("Connexion à : %s : %s"),(addr.Hostname()).c_str(),(sockbase->addr.IPAddress()).c_str());
     //SetTitle(s);
}

void Def_MTODlg::OnSocketEvent(wxSocketEvent& event)
{
    SetTitle("Even Socket");
    wxSocketBase *sock=event.GetSocket();
 //wxMessageBox(_("Création socket"), _("Alert !"));
    switch(event.GetSocketEvent())
    {
        case wxSOCKET_INPUT :
            {            
                sock->SetNotify(wxSOCKET_LOST_FLAG);
                    wxString s;
     
              unsigned char c;
                sock->Read(&c,1);                                 
                switch(c)
                {
                    case 0x0A : /// lat,long,alt , pitch, bank, heading
                          {
                            //unsigned char d;// // code Bloc 6
                            bMTO=false;
                            char *buf;
                            buf=new char[60];
                            sock->SetFlags(wxSOCKET_WAITALL);
                            buf[0]=0x01; // validation infos attitudes et altitudes
                            //buf[38]=bVisi; 
                            //buf[41]=bMTO; 
                            buf[41]=bOffsets;   // offses mto                      
                            FSUIPC_Read(0x0560,36,&buf[1],&dwResultat); // alt avion
                            //FSUIPC_Read(0x0E8A,2,&buf[39],&dwResultat);
                            //FSUIPC_Read(0xC800,1024,&buf[42],&dwResultat);
                            FSUIPC_Read(0x9100,14,&buf[42],&dwResultat);    
                            FSUIPC_Process(&dwResultat);                            
                             bVisi=false;
                             bMTO=false;
                             bOffsets=false;
                             sock->Write(buf,60); // envoi au cliens demandeur
                            break;      
                        } 
                        default:;                   
                } // switc c
            sock->SetNotify(wxSOCKET_LOST_FLAG | wxSOCKET_INPUT_FLAG);
            break;
            } // input
        case wxSOCKET_LOST :
        {
            numClients--;
            sock->Close();
            sock->Destroy();
            SetTitle("Destroy Socket");
            break;            
        }
        default:;                      
    }
       
}

void *wxThreadCli::Entry()
{
    
    
  return NULL;  
}

wxThreadCli *Def_MTODlg::CreateThread()
{
    Client=new wxThreadCli(this);
    Client->Create();
    Client->Run();
    
   //return NULL;
}
void wxThreadCli::OnExit()
{
    
}
*/

/*
 * WxASClick
 */

