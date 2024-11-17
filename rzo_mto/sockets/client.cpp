/////////////////////////////////////////////////////////////////////////////
// Name:        client.cpp
// Purpose:     Client for wxSocket demo
// Author:      Guillermo Rodriguez Garcia <guille@iies.es>
// Modified by:
// Created:     1999/09/19
// RCS-ID:      $Id: client.cpp,v 1.33 2005/09/23 12:52:25 MR Exp $
// Copyright:   (c) 1999 Guillermo Rodriguez Garcia
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// ==========================================================================
// declarations
// ==========================================================================

// --------------------------------------------------------------------------
// headers
// --------------------------------------------------------------------------

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#  pragma hdrstop
#endif

// for all others, include the necessary headers
#ifndef WX_PRECOMP
#  include "wx/wx.h"
#endif

#include "wx/socket.h"
#include "wx/url.h"
#include "wx/wfstream.h"
#include <FSUIPC_User.h>
#include <IPCUser.h>
#include "wx/timer.h"
// --------------------------------------------------------------------------
// resources
// --------------------------------------------------------------------------

// the application icon
#if defined(__WXGTK__) || defined(__WXX11__) || defined(__WXMOTIF__) || defined(__WXMAC__)
#  include "mondrian.xpm"
#endif

// --------------------------------------------------------------------------
// classes
// --------------------------------------------------------------------------

// Define a new application type
class MyApp : public wxApp
{
public:
  virtual bool OnInit();
};

// Define a new frame type: this is going to be our main frame
class MyFrame : public wxFrame
{
public:
  MyFrame();
  ~MyFrame();

  // event handlers for File menu
  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);

  // event handlers for Socket menu
  // void OnOpenConnection(wxCommandEvent& event);
  void OnTest3(wxCommandEvent& event);
  void OnCloseConnection(wxCommandEvent& event);

  // socket event handler
  void OnSocketEvent(wxSocketEvent& event);
  void OpenFSUIPC(wxTimerEvent& event);
void RelanceSock(wxTimerEvent& event);
  void OnAvion();
  // convenience functions
  void UpdateStatusBar();
  void Create_Sock();
    wxTimer *WxTimer;
    DWORD dwResultat;
    bool  boucle;
      char RepCourant[256];
  int NbCar;
  char CarLu[256];
  wxString Serveur;
  short Port;
  float dbCoefAlt;
  float dbCoefAtt;
  float dbCoefPos;
  double dbCoefLat; 
  
  float fLat;
  DWORD dwAlti;
  DWORD dwLatHi;
  DWORD dwLatLo;
  float fLong;
  DWORD dwLongHi;
  DWORD dwLongLo;
  float dwAlt;
  DWORD dwAltHi;
  DWORD dwAltLo;
  DWORD dwBank;
  float fBank;
  DWORD dwPitch;
  float fPitch;
  DWORD dwHeading;
  float fHeading;
unsigned int dwAltiT;
    struct Param_Mto
    {
       DWORD  LatLO;
       DWORD LatHi;
       DWORD LongLo;
       DWORD LongHi;
       DWORD AltLo;
       DWORD AltHI;
       DWORD Pitch;
       DWORD Bank;
       DWORD Heading;
       short ZuluHour;
       short ZuluMin;
       short Day;
       byte year;
       short Light;
       byte MTO;
       byte Zone;
       byte Val;
       short ZRef;
       short QNH;
       byte Temp;
       byte AltZ;
       byte WindDir;
       byte Kts;
       byte Visi;
       byte Trans;       
        byte Clouds;      
       short Rien;
    } PM;

  float dbCoefLong;
private:
  wxSocketClient *m_sock;
  wxTextCtrl     *m_text;
  wxMenu         *m_menuFile;
  wxMenu         *m_menuSocket;
  wxMenuBar      *m_menuBar;
  bool            m_busy;

  // any class wishing to process wxWidgets events must use this macro
  DECLARE_EVENT_TABLE()
};

// --------------------------------------------------------------------------
// constants
// --------------------------------------------------------------------------

// IDs for the controls and the menu commands
enum
{
  // menu items
  CLIENT_QUIT = wxID_EXIT,
  CLIENT_ABOUT = wxID_ABOUT,
  //CLIENT_OPEN = 100,
  //CLIENT_Avion,
  CLIENT_CLOSE=100,
  //Client_Avion,

  // id for socket
  SOCKET_ID,
  TIMER_ID


};

// --------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// --------------------------------------------------------------------------

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
  EVT_MENU(CLIENT_QUIT,     MyFrame::OnQuit)
  EVT_MENU(CLIENT_ABOUT,    MyFrame::OnAbout)
  // EVT_MENU(CLIENT_OPEN,     MyFrame::OnOpenConnection)
  //EVT_MENU(CLIENT_Avion,    MyFrame::OnAvion)
  EVT_MENU(CLIENT_CLOSE,    MyFrame::OnCloseConnection)
  EVT_SOCKET(SOCKET_ID,     MyFrame::OnSocketEvent)
  EVT_TIMER(TIMER_ID,       MyFrame::OpenFSUIPC)

END_EVENT_TABLE()

IMPLEMENT_APP(MyApp)

// ==========================================================================
// implementation
// ==========================================================================

// --------------------------------------------------------------------------
// the application class
// --------------------------------------------------------------------------

bool MyApp::OnInit()
{
  // Create the main application window
  MyFrame *frame = new MyFrame();

  // Show it and tell the application that it's our main window
  frame->Show(true);
  SetTopWindow(frame);

  // success
  return true;
}

// --------------------------------------------------------------------------
// main frame
// --------------------------------------------------------------------------

// frame constructor
MyFrame::MyFrame() : wxFrame((wxFrame *)NULL, wxID_ANY,
                             _("MTO_Client RZO"),
                             wxDefaultPosition, wxSize(300, 300))
{
  // Give the frame an icon
  SetIcon(wxICON(mondrian));

  // Make menus
  m_menuFile = new wxMenu();
  m_menuFile->Append(CLIENT_ABOUT, _("&About...\tCtrl-A"), _("Show about dialog"));
  m_menuFile->AppendSeparator();
  m_menuFile->Append(CLIENT_QUIT, _("E&xit\tAlt-X"), _("Quit client"));

  m_menuSocket = new wxMenu();
  //m_menuSocket->Append(CLIENT_OPEN, _("&Open session"), _("Connect to server"));
  m_menuSocket->AppendSeparator();
  //m_menuSocket->Append(CLIENT_Avion, _("Avion"), _("Informations Avion "));
  m_menuSocket->AppendSeparator();
  m_menuSocket->Append(CLIENT_CLOSE, _("&Close session"), _("Close connection"));
  // Append menus to the menubar
  m_menuBar = new wxMenuBar();
  m_menuBar->Append(m_menuFile, _("&Fichier"));
  m_menuBar->Append(m_menuSocket, _("&Commandes"));

  SetMenuBar(m_menuBar);
WxTimer = new wxTimer();
WxTimer->SetOwner(this,TIMER_ID);


WxTimer->Start(100);
#if wxUSE_STATUSBAR
  // Status bar
  CreateStatusBar(2);
  dbCoefAlt=((3.28084/65536)/65536);
  dbCoefLat=(90/10001750);
  dbCoefLong=(360/65536)/65536;
#endif // wxUSE_STATUSBAR
GetCurrentDirectory(258,RepCourant);
strcat(RepCourant,"\\VISUClient_MTO.ini");
NbCar=GetPrivateProfileString("CONFIG","serveur",NULL,CarLu,15,RepCourant);
Serveur.Printf(wxT(CarLu));

//Serveur=wxString::wxConvUTF8(CarLu);


//NbCar=GetPrivateProfileString("CONFIG","cycle",NULL,CarLu,15,RepCourant);
//Cycle=atoi(CarLu);
NbCar=GetPrivateProfileString("CONFIG","port",NULL,CarLu,15,RepCourant);
Port=atoi(CarLu);
  // Make a textctrl for logging
  m_text  = new wxTextCtrl(this, wxID_ANY,
                           _("Bienvenue sur Client RZO\nConnexion FSUIPC en attente\n"),
                           wxDefaultPosition, wxDefaultSize,
                           wxTE_MULTILINE | wxTE_READONLY);

  // Create the socket
     m_sock = new wxSocketClient();

  // Setup the event handler and subscribe to most events
  m_sock->SetEventHandler(*this, SOCKET_ID);
  m_sock->SetNotify(wxSOCKET_CONNECTION_FLAG |
                    wxSOCKET_INPUT_FLAG |
                    wxSOCKET_LOST_FLAG);
  m_sock->Notify(true);

  m_busy = false;
  UpdateStatusBar();

}

MyFrame::~MyFrame()
{
  // No delayed deletion here, as the frame is dying anyway
  delete m_sock;
 
}

// event handlers

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
  boucle=false;
  FSUIPC_Close();
m_sock->Destroy();
  // true is to force the frame to close
  Close(true);
  Destroy();
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
  wxMessageBox(_("wxSocket demo: Client\n(c) 1999 Guillermo Rodriguez Garcia\nAdaptation pour Aquitaine Simulation (MTO_RZO)\n"),
               _("About Client"),
               wxOK | wxICON_INFORMATION, this);
}


void MyFrame::OpenFSUIPC(wxTimerEvent& event)
{
    WxTimer->Stop();
    if(FSUIPC_Open(SIM_ANY,&dwResultat))
    {
        //bConnect=true;
        m_text->AppendText(_("Connexion FSUIPC réussie.\n"));        
        Create_Sock();

        //m_text->AppendText(_("Création socket.\n\n")); 
        return;    
    }
         m_text->AppendText(_("Connexion FSUIPC Echec.\n"));   
    WxTimer->Start(50);
}


/*
void MyFrame::OnOpenConnection(wxCommandEvent& WXUNUSED(event))
{
  wxIPV4address addr;

  m_menuSocket->Enable(CLIENT_OPEN, false);
  m_menuSocket->Enable(CLIENT_CLOSE, false);

  // Ask user for server address
  wxString hostname = wxGetTextFromUser(
    _("Entrer le nom ou l'adresse du serveur :"),
    _("Connect ..."),
    _("localhost"));

  addr.Hostname(Serveur);
  addr.Service(Port);

  m_text->AppendText(_("\nAttente connexion (timeout = 10 sec) ...\n"));
  m_sock->Connect(addr, false);
  m_sock->WaitOnConnect(10);

  if (m_sock->IsConnected())
    m_text->AppendText(_("Succés ! Connexion établie\n"));
  else
  {
    m_sock->Close();
    m_text->AppendText(_("Failed ! Unable to connect\n"));
    wxMessageBox(_("Can't connect to the specified host"), _("Alert !"));
  }

  UpdateStatusBar();
}
*/
void MyFrame::Create_Sock()
{

   wxIPV4address addr;

  //m_menuSocket->Enable(CLIENT_OPEN, false);
  m_menuSocket->Enable(CLIENT_CLOSE, false);
/*
  // Ask user for server address
  wxString hostname = wxGetTextFromUser(
    _("Entrer le nom ou l'adresse du serveur :"),
    _("Connect ..."),
    _("localhost"));
*/
  addr.Hostname(Serveur);
  addr.Service(Port);

  m_text->AppendText(_("\nAttente connexion serveur (timeout = 10 sec) ...\n"));
  m_sock->Connect(addr, false);
  m_sock->WaitOnConnect(10);

  if (m_sock->IsConnected())
  {
    m_text->AppendText(_("Succés ! Connexion établie avec le serveur MTO\n"));
            OnAvion();
    }
  else
  {
    FSUIPC_Close();
    m_sock->Close();
    m_text->AppendText(_("Erreur Connexion\n"));
    //wxMessageBox(_("Connexion impossible au serveur"), _("Alerte !"));
    m_text->AppendText(_("Connexion impossible au serveur\n"));
    WxTimer->Start(100);
  }

  UpdateStatusBar();   
}



void MyFrame::OnCloseConnection(wxCommandEvent& WXUNUSED(event))
{
  FSUIPC_Close();
  m_sock->Close();
  m_text->AppendText(_("\nDéconnexion Serveur et FSUIPC\n"));

  UpdateStatusBar();
}

void MyFrame::OnSocketEvent(wxSocketEvent& event)
{
  wxString s = _("Evénement : ");

  switch(event.GetSocketEvent())
  {
    case wxSOCKET_INPUT      : s.Append(_("Connexion en entrée\n")); break;
    case wxSOCKET_LOST       : s.Append(_("Connexion perdue\n")); boucle=false;Create_Sock();break;
    case wxSOCKET_CONNECTION : s.Append(_("Connexion\n")); break;
    default                  : s.Append(_("inconnu !\n")); break;
  }

  m_text->AppendText(s);
  UpdateStatusBar();
}

// convenience functions

void MyFrame::UpdateStatusBar()
{
  wxString s;

  if (!m_sock->IsConnected())
  {
    s.Printf(_("Non connecté"));
  }
  else
  {
    wxIPV4address addr;

    m_sock->GetPeer(addr);
    s.Printf(_("%s : %d"), (addr.Hostname()).c_str(), addr.Service());
  }

#if wxUSE_STATUSBAR
  SetStatusText(s, 1);
#endif // wxUSE_STATUSBAR

  //m_menuSocket->Enable(CLIENT_OPEN, !m_sock->IsConnected() && !m_busy);
  //m_menuSocket->Enable(CLIENT_Avion, m_sock->IsConnected() && !m_busy);
  m_menuSocket->Enable(CLIENT_CLOSE, m_sock->IsConnected());
}
void MyFrame::OnAvion()
{
 // int cptr=0;
 boucle=true;
  wxString s;
  m_text->AppendText(_("\n=== Echange RZO ===\n"));  
   //char     *buf2;
//////////////////////////////////////////////////////
/*
 char *buf2;
unsigned char c = 0x0B;

  buf2=new char[296];
  m_sock->Write(&c, 1);
  m_sock->Read(&buf2,296);
   FSUIPC_Write(0x0E9A,296,&buf2,&dwResultat);
   if(!FSUIPC_Process(&dwResultat)) 
 */
/////////////////////////////////////////////////////
//bool bVisi=false;
//bool bMTO=false;

unsigned char c = 0x0A;
  do
  {  
        /*
  buf2=new char[80];
//unsigned char d;
  m_sock->SetFlags(wxSOCKET_WAITALL);
  m_sock->Write(&c, 1);
   //m_text->AppendText(_("\n=== Envoi 0x0A ===\n")); 
   m_sock->Read(buf2,80);
//dwAltiT=buf2[21]+buf2[22]+buf2[23]+buf2[24];


//dwAltiT=dwAltiT+1;
   //bMTO=buf2[41];
   FSUIPC_Write(0x0560,36,&buf2[1],&dwResultat);
   //FSUIPC_Write(0x0578,12,&buf2[25],&dwResultat);
   //if(bVisi==true) FSUIPC_Write(0x0E8A,2,&buf2[39],&dwResultat);
   FSUIPC_Write(0x9100,14,&buf2[42],&dwResultat);
   FSUIPC_Write(0x023B,7,&buf2[60],&dwResultat);
   FSUIPC_Write(0x0D0C,2,&buf2[77],&dwResultat);
   FSUIPC_Write(0x0574,4,&dwAltiT,&dwResultat);
   if(!FSUIPC_Process(&dwResultat))
   {
       FSUIPC_Close();
        m_sock->Close();
        boucle=false;
       WxTimer->Start(10); 
    }
    FSUIPC_Read(0x0574,4,&dwAltiT,&dwResultat);
    FSUIPC_Process(&dwResultat);
    dwAltiT=dwAltiT+1;
    FSUIPC_Write(0x0574,4,&dwAltiT,&dwResultat);
    FSUIPC_Process(&dwResultat);
    */
    m_sock->SetFlags(wxSOCKET_WAITALL);
  m_sock->Write(&c, 1);
   //m_text->AppendText(_("\n=== Envoi 0x0A ===\n"));
   m_sock->Read(&PM,61);  
    
             //sock->Write(&PM,59);  
 PM.AltHI=PM.AltHI+1;
       FSUIPC_Write(0x0560,4,&PM.LatLO,&dwResultat);
       FSUIPC_Write(0x0564,4,&PM.LatHi,&dwResultat);
       FSUIPC_Write(0x0568,4,&PM.LongLo,&dwResultat);
       FSUIPC_Write(0x056C,4,&PM.LongHi,&dwResultat);
       FSUIPC_Write(0x0570,4,&PM.AltLo,&dwResultat);
       FSUIPC_Write(0x0574,4,&PM.AltHI,&dwResultat);
       FSUIPC_Write(0x0578,4,&PM.Pitch,&dwResultat);
       FSUIPC_Write(0x057C,4,&PM.Bank,&dwResultat);
       FSUIPC_Write(0x0580,4,&PM.Heading,&dwResultat);
       FSUIPC_Write(0x023B,1,&PM.ZuluHour,&dwResultat);
       FSUIPC_Write(0x023C,2,&PM.ZuluMin,&dwResultat);
       FSUIPC_Write(0x023E,2,&PM.Day,&dwResultat);
       FSUIPC_Write(0x0240,2,&PM.year,&dwResultat);
       FSUIPC_Write(0x0D0C,2,&PM.Light,&dwResultat);
       FSUIPC_Write(0x9100,1,&PM.MTO,&dwResultat);
       FSUIPC_Write(0x9101,1,&PM.Zone,&dwResultat);
       FSUIPC_Write(0x9102,1,&PM.Val,&dwResultat);
       FSUIPC_Write(0x9103,2,&PM.ZRef,&dwResultat);
       FSUIPC_Write(0x9105,2,&PM.QNH,&dwResultat);
       FSUIPC_Write(0x9107,1,&PM.Temp,&dwResultat);
       FSUIPC_Write(0x9108,1,&PM.AltZ,&dwResultat);
       FSUIPC_Write(0x9109,1,&PM.WindDir,&dwResultat);
       FSUIPC_Write(0x910A,1,&PM.Kts,&dwResultat);
       FSUIPC_Write(0x910B,1,&PM.Visi,&dwResultat);
       FSUIPC_Write(0x910C,1,&PM.Trans,&dwResultat);
       FSUIPC_Write(0x910D,1,&PM.Clouds,&dwResultat);
       FSUIPC_Write(0x910E,2,&PM.Rien,&dwResultat);
       FSUIPC_Process(&dwResultat);
 
    
    
    
    
    
    
    
 /*  
   FSUIPC_Write(0x9200,36,&buf2[1],&dwResultat);
   FSUIPC_Process(&dwResultat);
   FSUIPC_Read(0x9200,4,&dwLatLo,&dwResultat);
   FSUIPC_Read(0x9204,4,&dwLatHi,&dwResultat);
   FSUIPC_Read(0x9208,4,&dwLongLo,&dwResultat);
   FSUIPC_Read(0x920C,4,&dwLongHi,&dwResultat);
   FSUIPC_Read(0x9210,4,&dwAltLo,&dwResultat);
   FSUIPC_Read(0x9214,4,&dwAltHi,&dwResultat);
   FSUIPC_Read(0x9218,4,&dwPitch,&dwResultat);
   FSUIPC_Read(0x921C,4,&dwBank,&dwResultat);
   FSUIPC_Read(0x9220,4,&dwHeading,&dwResultat);
   FSUIPC_Process(&dwResultat);
   
   
  m_text->Clear();   
   dwLatLo=(DWORD&)buf2[1];
   dwLatHi=(DWORD&)buf2[5];
   dwLongLo=(DWORD&)buf2[9];
   dwLongHi=(DWORD&)buf2[13];
   dwAltLo=(DWORD&)buf2[17];
   dwAltHi=(DWORD&)buf2[21];
   dwPitch=buf2[25];
   dwBank=buf2[29];
   dwHeading=buf2[33];
   //dwLat=dwLatLo;
 
    fLat=(float)((dwLatHi*90.0/10001750)+dwLatLo);
 
   fLong=(float)(((dwLongHi/65536)*((3600.0/65536)/10.0))+dwLongLo);
   dwAlt=(float)(dwAltHi*3.28084)+(float)((dwAltLo/65536)*(3.28084/65536)); //+;
   fPitch=(float)((dwPitch/65536)*(3600.0/65536)/10.0);
   fBank=(float)((dwBank/65536)*((3600.0/65536)/10.0));
   fHeading=(float)((dwHeading/65536)*((3600.0/65536)/10.0));
   
 m_text->AppendText(_("Informations RZO\n"));
 s.Printf("Latitude \t : %f \n",fLat);
 m_text->AppendText(s);
 s.Printf("Longitude\t : %f\n",fLong);
 m_text->AppendText(s); 
  s.Printf("Altitude \t : %f \n",dwAlt);
 m_text->AppendText(s);
  s.Printf("Pitch \t : %f \n",fPitch);
 m_text->AppendText(s);
  s.Printf("Bank \t : %f \n",fBank);
 m_text->AppendText(s);
  s.Printf("Heading \t : %f \n",fHeading);
 m_text->AppendText(s);
 */
 

   //m_text->AppendText(_("\n=== Test Avion  fin ===\n")); 
   //cptr++;
   //s.Printf("%d",cptr);
   //SetTitle(s);
   //Sleep(10);
       }
  while(boucle);  
}
