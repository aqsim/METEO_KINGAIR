/////////////////////////////////////////////////////////////////////////////
// Name:        server.cpp
// Purpose:     Server for wxSocket demo
// Author:      Guillermo Rodriguez Garcia <guille@iies.es>
// Modified by:
// Created:     1999/09/19
// RCS-ID:      $Id: server.cpp,v 1.21 2005/09/23 12:52:25 MR Exp $
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

#include <wx/socket.h>
#include "FSUIPC_User.h"
#include "IPCuser.h"
#include <wx/timer.h>
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

  // event handlers (these functions should _not_ be virtual)
  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnServerEvent(wxSocketEvent& event);
  void OnSocketEvent(wxSocketEvent& event);

  //void MTO(wxSocketBase *sock);
  void Avion(wxSocketBase *sock);
  void Creation_Sock();
  void OpenFSUIPC(wxTimerEvent& event);
  // convenience functions
  void UpdateStatusBar();
    DWORD dwResultat;
    wxTimer *WxTimer;
    DWORD dwAlti;
    DWORD dwUnite;
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
    
    
private:
  wxSocketServer *m_server;
  wxTextCtrl     *m_text;
  wxMenu         *m_menuFile;
  wxMenuBar      *m_menuBar;
  bool            m_busy;
  int             m_numClients;

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
  SERVER_QUIT = wxID_EXIT,
  SERVER_ABOUT = wxID_ABOUT,

  // id for sockets
  SERVER_ID = 100,
  SOCKET_ID,
  ID_TIMER
};

// --------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// --------------------------------------------------------------------------

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
  EVT_MENU(SERVER_QUIT,  MyFrame::OnQuit)
  EVT_MENU(SERVER_ABOUT, MyFrame::OnAbout)
  EVT_SOCKET(SERVER_ID,  MyFrame::OnServerEvent)
  EVT_SOCKET(SOCKET_ID,  MyFrame::OnSocketEvent)
  EVT_TIMER(ID_TIMER,    MyFrame::OpenFSUIPC)
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

  // Success
  return true;
}

// --------------------------------------------------------------------------
// main frame
// --------------------------------------------------------------------------

// frame constructor

MyFrame::MyFrame() : wxFrame((wxFrame *)NULL, wxID_ANY,
                             _("MTO_Serveur : RZO"),
                             wxDefaultPosition, wxSize(300, 200))
{
  // Give the frame an icon
  SetIcon(wxICON(mondrian));

  // Make menus
  m_menuFile = new wxMenu();
  m_menuFile->Append(SERVER_ABOUT, _("&About...\tCtrl-A"), _("Show about dialog"));
  m_menuFile->AppendSeparator();
  m_menuFile->Append(SERVER_QUIT, _("E&xit\tAlt-X"), _("Quitter serveur"));

  // Append menus to the menubar
  m_menuBar = new wxMenuBar();
  m_menuBar->Append(m_menuFile, _("&Fichier"));
  SetMenuBar(m_menuBar);

#if wxUSE_STATUSBAR
  // Status bar
  CreateStatusBar(2);
#endif // wxUSE_STATUSBAR

  // Make a textctrl for logging
  m_text  = new wxTextCtrl(this, wxID_ANY,
                           _("Bienvenue dans le monde MTO:\n Serveur en attente\n"),
                           wxDefaultPosition, wxDefaultSize,
                           wxTE_MULTILINE | wxTE_READONLY);

  // Create the address - defaults to localhost:0 initially
  WxTimer = new wxTimer();
  WxTimer->SetOwner(this,ID_TIMER);
  WxTimer->Start(100);
  dwUnite=1;
}
void MyFrame::OpenFSUIPC(wxTimerEvent& event)
{
    WxTimer->Stop();
    if(FSUIPC_Open(SIM_ANY,&dwResultat))
    {
        //bConnect=true;
        m_text->AppendText(_("Connexion FSUIPC réussie.\n"));
        m_text->AppendText(_("Création Connexion.\n"));              
        Creation_Sock();
        
    }
    WxTimer->Start(50);
}

void MyFrame::Creation_Sock()
{
    wxIPV4address addr;
  addr.Service(3000);

  // Create the socket
  m_server = new wxSocketServer(addr);

  // We use Ok() here to see if the server is really listening
  if (! m_server->Ok())
  {
    m_text->AppendText(_("Erreur écoute port !\n"));
    return;
  }
  else
  {
    m_text->AppendText(_("Serveur en écoute.\n"));
  }

  // Setup the event handler and subscribe to connection events
  m_server->SetEventHandler(*this, SERVER_ID);
  m_server->SetNotify(wxSOCKET_CONNECTION_FLAG);
  m_server->Notify(true);

  m_busy = false;
  m_numClients = 0;
  UpdateStatusBar();
}

MyFrame::~MyFrame()
{
  // No delayed deletion here, as the frame is dying anyway
  delete m_server;
}

// event handlers

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
  // true is to force the frame to close
  FSUIPC_Close();
  Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
  wxMessageBox(_("wxSocket demo: Serveur\n(c) 1999 Guillermo Rodriguez Garcia\nAppliquée pour synchroniser la MTO\nAquitaine Simulation\n"),

               _("A propos du serveur"),
               wxOK | wxICON_INFORMATION, this);
}
/*
void MyFrame::MTO(wxSocketBase *sock)
{
    char *buff;
    buff= new char [296];
    FSUIPC_Read(0x09A,296,&buff,&dwResultat);
    FSUIPC_Process(&dwResultat);
    sock->Write(buff,296);
}
*/
void MyFrame::Avion(wxSocketBase *sock)
{
         //unsigned char d;// // code Bloc 6

         sock->SetFlags(wxSOCKET_WAITALL);
         /*
           char *buf;
         buf=new char[80];      
         buf[0]=0x01;
         //buf[38]=0x00; // qui vivra verra ( bvisi )
         //FSUIPC_Read(0x0574,4,&dwAlti,&dwResultat);
         //FSUIPC_Process(&dwResultat);
         //dwAlti=dwAlti+dwUnite;
         //buf[22]=dwAlti;
         buf[41]=1; // !idem            (bmto)             
         FSUIPC_Read(0x0560,36,&buf[1],&dwResultat); // alt avion
         //FSUIPC_Read(0x578,12,&buf[25],&dwResultat);
         //FSUIPC_Read(0x0E8A,2,&buf[39],&dwResultat);
         FSUIPC_Read(0x9100,14,&buf[42],&dwResultat);    
         FSUIPC_Read(0x023B,7,&buf[60],&dwResultat);
         FSUIPC_Read(0x0D0C,2,&buf[77],&dwResultat);
         if(!FSUIPC_Process(&dwResultat))
         {
               FSUIPC_Close();
                
            }                            
         //bVisi=false;
         //bMTO=false;
         //buf[21]=buf[21]+1;
         sock->Write(buf,80); 
        */ 
         
       FSUIPC_Read(0x0560,4,&PM.LatLO,&dwResultat);
       FSUIPC_Read(0x0564,4,&PM.LatHi,&dwResultat);
       FSUIPC_Read(0x0568,4,&PM.LongLo,&dwResultat);
       FSUIPC_Read(0x056C,4,&PM.LongHi,&dwResultat);
       FSUIPC_Read(0x0570,4,&PM.AltLo,&dwResultat);
       FSUIPC_Read(0x0574,4,&PM.AltHI,&dwResultat);
       FSUIPC_Read(0x0578,4,&PM.Pitch,&dwResultat);
       FSUIPC_Read(0x057C,4,&PM.Bank,&dwResultat);
       FSUIPC_Read(0x0580,4,&PM.Heading,&dwResultat);
       FSUIPC_Read(0x023B,1,&PM.ZuluHour,&dwResultat);
       FSUIPC_Read(0x023C,2,&PM.ZuluMin,&dwResultat);
       FSUIPC_Read(0x023E,2,&PM.Day,&dwResultat);
       FSUIPC_Read(0x0240,2,&PM.year,&dwResultat);
       FSUIPC_Read(0x0D0C,2,&PM.Light,&dwResultat);
       FSUIPC_Read(0x9100,1,&PM.MTO,&dwResultat);
       FSUIPC_Read(0x9101,1,&PM.Zone,&dwResultat);
       FSUIPC_Read(0x9102,1,&PM.Val,&dwResultat);
       FSUIPC_Read(0x9103,2,&PM.ZRef,&dwResultat);
       FSUIPC_Read(0x9105,2,&PM.QNH,&dwResultat);
       FSUIPC_Read(0x9107,1,&PM.Temp,&dwResultat);
       FSUIPC_Read(0x9108,1,&PM.AltZ,&dwResultat);
       FSUIPC_Read(0x9109,1,&PM.WindDir,&dwResultat);
       FSUIPC_Read(0x910A,1,&PM.Kts,&dwResultat);
       FSUIPC_Read(0x910B,1,&PM.Visi,&dwResultat);
       FSUIPC_Read(0x910C,1,&PM.Trans,&dwResultat);
       FSUIPC_Read(0x910D,1,&PM.Clouds,&dwResultat); 
       FSUIPC_Read(0x910E,2,&PM.Rien,&dwResultat); 
       FSUIPC_Process(&dwResultat); 
         sock->Write(&PM,61);  
         
}

void MyFrame::OnServerEvent(wxSocketEvent& event)
{
  wxString s = _("OnServerEvent: ");
  wxSocketBase *sock;

  switch(event.GetSocketEvent())
  {
    case wxSOCKET_CONNECTION : s.Append(_("wxSOCKET_CONNECTION\n")); break;
    default                  : s.Append(_("Evénement inconnu !\n")); break;
  }

  m_text->AppendText(s);

  // Accept new connection if there is one in the pending
  // connections queue, else exit. We use Accept(false) for
  // non-blocking accept (although if we got here, there
  // should ALWAYS be a pending connection).

  sock = m_server->Accept(false);

  if (sock)
  {
    m_text->AppendText(_("Connexion nouveau client acceptée\n\n"));
  }
  else
  {
    m_text->AppendText(_("Erreur: Connexion refusée\n\n"));
    return;
  }

  sock->SetEventHandler(*this, SOCKET_ID);
  sock->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
  sock->Notify(true);

  m_numClients++;
  UpdateStatusBar();
}

void MyFrame::OnSocketEvent(wxSocketEvent& event)
{
  wxString s = _("OnSocketEvent: ");
  wxSocketBase *sock = event.GetSocket();

  // First, print a message
  switch(event.GetSocketEvent())
  {
    case wxSOCKET_INPUT : s.Append(_("wxSOCKET_INPUT\n")); break;
    case wxSOCKET_LOST  : s.Append(_("wxSOCKET_LOST\n")); break;
    default             : s.Append(_("Unexpected event !\n")); break;
  }

  //m_text->AppendText(s);

  // Now we process the event
  switch(event.GetSocketEvent())
  {
    case wxSOCKET_INPUT:
    {
      // We disable input events, so that the test doesn't trigger
      // wxSocketEvent again.
      sock->SetNotify(wxSOCKET_LOST_FLAG);

      // Which test are we going to run?
      unsigned char c;
      sock->Read(&c, 1);

      switch (c)
      {

        case 0x0A:  Avion(sock); break;
        //case 0x0B: MTO(sock); break;      
        default:
          m_text->AppendText(_("Commande inconnue \n\n"));
          break;

      }

      // Enable input events again.
      sock->SetNotify(wxSOCKET_LOST_FLAG | wxSOCKET_INPUT_FLAG);
      break;
    }
    case wxSOCKET_LOST:
    {
      m_numClients--;
      m_text->AppendText(_("Destruction socket.\n\n"));
      sock->Destroy();
      break;
    }
    default: ;
  }

  UpdateStatusBar();
}

// convenience functions

void MyFrame::UpdateStatusBar()
{
#if wxUSE_STATUSBAR
  wxString s;
  s.Printf(_("%d clients"), m_numClients);
  SetStatusText(s, 1);
#endif // wxUSE_STATUSBAR
}
