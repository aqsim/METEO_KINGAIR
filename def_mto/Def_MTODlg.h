//---------------------------------------------------------------------------
//
// Name:        Def_MTODlg.h
// Author:      titan
// Created:     15/12/2015 13:36:51
// Description: Def_MTODlg class declaration
//
//---------------------------------------------------------------------------

#ifndef __DEF_MTODLG_h__
#define __DEF_MTODLG_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/timer.h>
#include <wx/statbmp.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
////Header Include End
#include "FSUIPC_User.h"
#include "NewWeather.h"
#include <time.h>
#include <sys/timeb.h>
#include <sys/types.h>
#include <stdio.h>
#include <wx/string.h>
//#include <wx/socket.h>
#include <wx/msgdlg.h>
//#include <wx/thread.h>
#include <wx/colour.h>


//#include <wx/arrstr.h>
//#include <wx/dynarray.h>
////Dialog Style Start
#undef Def_MTODlg_STYLE
#define Def_MTODlg_STYLE wxSIMPLE_BORDER | wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End
//class wxThreadCli;


class Def_MTODlg : public wxDialog
{
	private:
   //wxThreadCli *CreateThread();
  //wxThreadCli *Client;       
		DECLARE_EVENT_TABLE();
		
	public:
		Def_MTODlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Def_MTO"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = Def_MTODlg_STYLE);
		virtual ~Def_MTODlg();
//enum{SERVER_ID,SOCKET_ID)
	   NewWeather NWI;
	   NewWeather NWI0;
	    wxPoint p;
        wxSize s;
        RECT Pos;
	   struct Att
	   {
          int LatLo;
          int LatHi;
          int LongLo;
          int LongHi;
          int AltLo; 
          int AltHi;
          int Pitch;
          int Bank;
          int Heading;
          int VisiFS;
        }Avion;
        char *cBlocAvion;
        bool bAvion;
        bool bMTO;
        bool bVisi;
        bool bIO;
        int timetimer;
        struct RZO
        {
           int Commande;
           struct Att Attitude;
           struct _NewWeather MTO_FS; 
            
        }Envoi_RZO;


    	DWORD dwResultat;
        bool bConnect;
        bool bClear;
        bool bInitOffset;
        bool bOffsets;
		void LectureOffsets();
	    void TraitementOffsets();
	    void timestamp();
	    void Initialisation();
	    void Affichage_MTO(short);
	    void SauvegardeConf();
	    void AffichageConf();
	    void EnvoiConfFs();
	   void Init_Offsets();
	   void GestionAltAvion();
	   void GestionTransition1();
	   void GestionTransition2();
	   void GestionTransition3();
	   void GestionTransition4();
	   void GestionTransitionZ1();
	   void GestionTransitionZ2();
	   //void CreateSocket();
	   //void Envoi(wxSocketBase *sock);
	   void EnvoiInfos(short);
	   short shDynamic;
	    short shPression;
	    short _shPression;
	    char cValidation;
	    char _cValidation;
	    time_t tt;
	    struct tm *tmt;
	    struct _timeb tmtb;
	    char bufftps[256];
	    char RepCourant[256];
	    char tmp[25];
	    char Lec[256];
	    char buff1[1024];
	    char buff2[2];
	    unsigned char len;
	    int iun;
	    DWORD dwAltLo;
DWORD dwAltHi;
	    DWORD tps;
	    DWORD ttms;
	    DWORD ReadConf;
	    char CleALire[10];
	    char CleAEcr[10];
	    char ValeurLue[20];
	    DWORD dwCRLecture;
	    short shAltAvion;
	    short _shAltAvion;
        char Sep[1];
       short TMTO1Val[21];
 //       char Sep[1];


        short TMTO2Val[21];
        short TMTO3Val[21];
        short TMTO4Val[21];
        short TMTO5Val[21];
        short TMTO6Val[21];
        char TMTO[21][25];
	    char TMTO1[21][25];
	    //char *TMTO1[21];
	    char O_Offsets[13][15];
	    unsigned short ushAdr_MTO;
	    unsigned short ushAdr_Zone;
	    unsigned short ushAdr_Cde;
	    unsigned short ushAdr_AltAirPort;
	    unsigned short ushAdr_QNH;
	    unsigned short ushAdr_Temperature;
	    unsigned short ushAdr_ZRef;
	    unsigned short ushAdr_WindDir;
	    unsigned short ushAdr_Knots;
	    unsigned short ushAdr_Visibility;
	    unsigned short ushAdr_Transition;
	    unsigned short ushAdr_Nuages;
	    char *pTampon;
        char MTO1[21][10];
	    //char *MTO1[];
	    char TMTO2[21][25];
	    //char *MTO2[];	 
        char MTO2[21][10];           
	    char TMTO3[21][25];
	    //char *MTO3[];
        char MTO3[21][10];        	    
	    char TMTO4[21][25];
	    //char *MTO4[];
        char MTO4[21][10];        	    
	    char TMTO5[21][25];
	    //char *MTO5[];
        char MTO5[21][10];        	    
	    char TMTO6[21][25];
	   // char *MTO6[];
        char MTO6[21][10];        	    
	    short init;
	    short Tempo;
	    short shGlobal;
	    short shSet;
	    unsigned int uiTimeTicks;
      bool binit_MTO;
      bool bEnvoi_FS_Ok;
      short shLu1;
      short shLu2;
      short shLu3;
    struct OTM
    {
	    short _shZRef;
	    short _shQNH;
	    char _cTp;
	    byte _cAlt_Z1;
	    byte _cAlt_Z2;
	    byte _cAlt_Z3;
	    short _shWindDir1;
	    short _shWindDir2;
	    short _shWindDir3;
	    byte _cKts1;
	    byte _cKts2;
	    byte _cKts3;
	    byte _cVisibility3;
	    byte _cVisibility2;
	    byte _cVisibility1;
	    byte _cTrans1;
	    byte _cTrans2;
	    byte _cClouds1;
	    byte _cClouds2;
	    byte _cClouds3;       
    } OTM1,OTM2,OTM3,OTM4,OTM5,OTM6;


short shCDE;
	    char Z1[21][5];
	    char Z2[21][6];
	    char IncV[13][10];
	    char Kts[7][4];
	    char Vent[12][5];
	    char IncT[8][5];
	    char Nuages[33][8];
	    
	    char cMTO;
	    char _cMTO;
	    char cZone;
	    char _cZone;
	    char cVal;
	    char _cVal;
	    short shZRef;
	    short _shZRef;
	    short shQNH;
	    short _shQNH;
	    char cTp;
	    char _cTp;
	    byte cAlt_Z;
	    byte _cAlt_Z;	    
	    byte _cAlt_Z1;
	    byte _cAlt_Z2;	    
	    byte _cAlt_Z3;	    
	    byte cWindDir;
	    byte _cWindDir;	    
	    byte _cWindDir1;
	    byte _cWindDir2;	    
	    byte _cWindDir3;	    
	    byte cKts;
	    byte _cKts;	    
	    byte _cKts1;
	    byte _cKts2;	    
	    byte _cKts3;	    
	    byte cVisibility;
	    byte _cVisibility;	    
	    byte _cVisibility3;
	    byte _cVisibility2;	    
	    byte _cVisibility1;	    
	    byte cTrans;
	    byte _cTrans;	    
	    byte _cTrans1;
	    byte _cTrans2;	    
	    byte cClouds;
	    byte _cClouds;	    
	    byte _cClouds1;
	    byte _cClouds2;
	    byte _cClouds3;
        unsigned char ucNuages1;
        unsigned char ucNuages2;
        unsigned char ucNuages3;
        unsigned char ucCoverage1;
        unsigned char ucCoverage2;
        unsigned char ucCoverage3;	    
        unsigned short ushAltUp3;
        unsigned short ushAltLo3;
        unsigned short ushAltUp2;
        unsigned short ushAltLo2;
        unsigned short ushAltUp1;
        unsigned short ushAltLo1;
        unsigned short ushAltAvion;
        unsigned short ushKnots3;
        unsigned short ushKnots2;
        unsigned short ushKnots1;
        
        unsigned short ushWindDir3;
        unsigned short ushWindDir2;
        unsigned short ushWindDir1;
        
        unsigned short ushVisibility1;
        unsigned short ushVisibility2;
        unsigned short ushVisibility3;
        unsigned short ushVisiEnvoi1;
        unsigned short ushVisiEnvoi2;
        unsigned short ushVisiEnvoi3;
        unsigned short ushAltTransition1;
        unsigned short ushAltTransition2;
        unsigned short ushAltTransition3;
        short shDiffVisiZ1;
        short shDiffVisiZ2;
        unsigned short ushTransition1;
        unsigned short ushTransition2;
        unsigned short ushVisiCalculTR1;
        unsigned short ushVisiCalculTR2;
        unsigned short ushAltTransition4;
        unsigned short ushVisiTR1;
        unsigned short ushVisiTR2; 
        unsigned short ushTrDif1;
        unsigned short ushTrDif2;
        unsigned short ushTrAlt1;
        unsigned short ushTrAlt2;
        unsigned short ushTrAlt3;
        unsigned short ushTrAlt4;        
        unsigned short ushDemiTR1;
        unsigned short ushDemiTR2;
        unsigned short ushVisiCalcul1;  
        unsigned short ushVisiCalcul2;
        unsigned short ushVisiCalcul3;
        unsigned short ushVisiCalcul4;
        
        short TZ1[21];
        short TZ2[21];
        //char TVis[12]={100,200,400,800,1200,1600,3200,8000,16000,32000,64000,128000};
        short TVis[13];
        short TKts[7];
        short TWinDir[12];
        short TR[7];
		void WxTimer1Timer(wxTimerEvent& event);
		void WxTimer2Timer(wxTimerEvent& event);
        //wxSocketServer *wxSocket;
        //void OnServerEvent(wxSocketEvent& event);
        //void OnSocketEvent(wxSocketEvent& event);
        //wxIPV4address addr;
        wxString strHostAdr;
        int short iPort;
        int ini;
        int numClients;
		//void Def_MTODlgActivate(wxActivateEvent& event);
bool bStop;
		void WxASClick(wxCommandEvent& event);

 
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxTimer *WxTimer1;
		wxTimer *WxTimer2;
		wxStaticBitmap *WxStaticBitmap1;
		wxStaticText *WxStaticText32;
		wxStaticText *WxStaticText13;
		wxStaticText *WxStaticText8;
		wxStaticBitmap *WxLedE2;
		wxStaticBitmap *WxLedE3;
		wxStaticBitmap *WxLedV3;
		wxStaticBitmap *WxLedR3;
		wxStaticBitmap *WxLedV2;
		wxStaticBitmap *WxLedE1;
		wxStaticBitmap *WxLedR1;
		wxStaticBitmap *WxLedV1;
		wxStaticText *WxStaticText4;
		wxStaticLine *WxStaticLine5;
		wxStaticLine *WxStaticLine1;
		wxStaticText *WxStaticText31;
		wxStaticText *WxStaticText30;
		wxStaticText *WxStaticText29;
		wxStaticText *WxStaticText28;
		wxTextCtrl *WxEdit_Tp;
		wxTextCtrl *WxEdit_QNH;
		wxTextCtrl *WxEdit_Z;
		wxTextCtrl *WxEdit_Z1T1;
		wxTextCtrl *WxEdit_Z1T2;
		wxStaticLine *WxStaticLine4;
		wxStaticLine *WxStaticLine3;
		wxStaticLine *WxStaticLine2;
		wxTextCtrl *WxEdit_Z2T1;
		wxTextCtrl *WxEdit_Z2T2;
		wxTextCtrl *WxEdit_K1;
		wxTextCtrl *WxEdit_W1;
		wxTextCtrl *WxEdit_C1;
		wxTextCtrl *WxEdit_V1;
		wxTextCtrl *WxEdit_K2;
		wxTextCtrl *WxEdit_W2;
		wxTextCtrl *WxEdit_C2;
		wxTextCtrl *WxEdit_V2;
		wxTextCtrl *WxEdit_K3;
		wxTextCtrl *WxEdit_W3;
		wxTextCtrl *WxEdit_C3;
		wxTextCtrl *WxEdit_V3;
		wxStaticText *WxStaticText27;
		wxStaticText *WxStaticText26;
		wxStaticText *WxStaticText25;
		wxStaticText *WxStaticText24;
		wxStaticText *WxStaticText23;
		wxStaticText *WxStaticText22;
		wxStaticText *WxStaticText21;
		wxStaticText *WxStaticText20;
		wxStaticText *WxStaticText19;
		wxStaticText *WxStaticText18;
		wxStaticText *WxStaticText17;
		wxStaticText *WxStaticText16;
		wxStaticText *WxStaticText15;
		wxStaticText *WxStaticText14;
		wxStaticText *WxZone1;
		wxStaticText *WxStaticText12;
		wxStaticText *WxStaticText11;
		wxStaticText *WxStaticText10;
		wxStaticText *WxStaticText9;
		wxStaticText *WxZone2;
		wxStaticText *WxStaticText7;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText5;
		wxStaticText *WxZone3;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXTIMER1 = 1088,
			ID_WXTIMER2 = 1089,
			ID_WXSTATICBITMAP1 = 1094,
			ID_WXSTATICTEXT32 = 1092,
			ID_WXSTATICTEXT13 = 1091,
			ID_WXSTATICTEXT8 = 1090,
			ID_WXLEDE2 = 1087,
			ID_WXLEDE3 = 1086,
			ID_WXLEDV3 = 1085,
			ID_WXLEDR3 = 1084,
			ID_WXLEDV2 = 1083,
			ID_WXLEDE1 = 1080,
			ID_WXLEDR1 = 1079,
			ID_WXLEDV1 = 1078,
			ID_WXSTATICTEXT4 = 1065,
			ID_WXSTATICLINE5 = 1064,
			ID_WXSTATICLINE1 = 1063,
			ID_WXSTATICTEXT31 = 1060,
			ID_WXSTATICTEXT30 = 1059,
			ID_WXSTATICTEXT29 = 1058,
			ID_WXSTATICTEXT28 = 1057,
			ID_WXEDIT_TP = 1054,
			ID_WXEDIT_QNH = 1053,
			ID_WXEDIT_Z = 1052,
			ID_WXEDIT_Z1T1 = 1051,
			ID_WXEDIT_Z1T2 = 1050,
			ID_WXSTATICLINE4 = 1048,
			ID_WXSTATICLINE3 = 1044,
			ID_WXSTATICLINE2 = 1043,
			ID_WXEDIT_Z2T1 = 1041,
			ID_WXEDIT_Z2T2 = 1040,
			ID_WXEDIT_K1 = 1039,
			ID_WXEDIT_W1 = 1038,
			ID_WXEDIT_C1 = 1037,
			ID_WXEDIT_V1 = 1036,
			ID_WXEDIT_K2 = 1035,
			ID_WXEDIT_W2 = 1034,
			ID_WXEDIT_C2 = 1033,
			ID_WXEDIT_V2 = 1032,
			ID_WXEDIT_K3 = 1031,
			ID_WXEDIT_W3 = 1030,
			ID_WXEDIT_C3 = 1029,
			ID_WXEDIT_V3 = 1028,
			ID_WXSTATICTEXT27 = 1027,
			ID_WXSTATICTEXT26 = 1026,
			ID_WXSTATICTEXT25 = 1025,
			ID_WXSTATICTEXT24 = 1024,
			ID_WXSTATICTEXT23 = 1023,
			ID_WXSTATICTEXT22 = 1022,
			ID_WXSTATICTEXT21 = 1021,
			ID_WXSTATICTEXT20 = 1020,
			ID_WXSTATICTEXT19 = 1019,
			ID_WXSTATICTEXT18 = 1018,
			ID_WXSTATICTEXT17 = 1017,
			ID_WXSTATICTEXT16 = 1016,
			ID_WXSTATICTEXT15 = 1015,
			ID_WXSTATICTEXT14 = 1014,
			ID_WXZONE1 = 1013,
			ID_WXSTATICTEXT12 = 1012,
			ID_WXSTATICTEXT11 = 1011,
			ID_WXSTATICTEXT10 = 1010,
			ID_WXSTATICTEXT9 = 1009,
			ID_WXZONE2 = 1008,
			ID_WXSTATICTEXT7 = 1007,
			ID_WXSTATICTEXT6 = 1006,
			ID_WXSTATICTEXT5 = 1005,
			ID_WXZONE3 = 1004,
			ID_WXSTATICTEXT3 = 1003,
			ID_WXSTATICTEXT2 = 1002,
			ID_WXSTATICTEXT1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};
/*
class wxThreadCli : public wxThread
{
   public:
   wxThreadCli(Def_MTODlg *frame);
   virtual void *Entry();
   Def_MTODlg *m_Def_MTODlg;
   //unsigned m_count;
   virtual void OnExit();
};
*/

/*
wxThreadCli::wxThreadCli(Def_MTODlg *frame)
        : wxThread()
{
    //m_count = 0;
    m_Def_MTODlg = frame;
}
*/
/*void wxThreadCli::OnExit()
{

}
*/
#endif
