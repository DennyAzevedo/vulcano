//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "../include/vicdefs.h"


#include "unt_principal.h"
#include "Units/unt_config.h"
#include "unt_imagem.h"
#include "unt_histograma.h"
#include "unt_splash.h"
#include "unt_ajuda.h"
#include "../include/FuncoesTGI.h"

//--------- variáveis global ----------
unsigned int enderecobase;
int modo_video;
int hrtlargura, hrtaltura;

//-------------------------------------

//------------ Protótipo da Thread de video em tempo "Real" -----------------
DWORD WINAPI RealTimeVideo( LPVOID lpParam );
//DWORD WINAPI ThreadFunc( LPVOID );
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"


TWndPrincipal *WndPrincipal;
//---------------------------------------------------------------------------
__fastcall TWndPrincipal::TWndPrincipal(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TWndPrincipal::Sair1Click(TObject *Sender)
{
WndPrincipal->Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndPrincipal::FormCreate(TObject *Sender)
{
int x;

flag_ativado=0;
enderecobase = 0xd400;

hrtlargura = HRTcol;
hrtaltura = HRTlin;

allocimage(&imagem, HRTcol, HRTlin, 8);

WndSplash->Show();

}
//---------------------------------------------------------------------------

void __fastcall TWndPrincipal::Timer1Timer(TObject *Sender)
{
int x;

Timer1->Enabled = false;

if(flag_ativado)
    LerImagem(&imagem);
else
    if (imagem.ibuff[1] == 0)
        loadjpg("imgteste.jpg",&imagem);

DeleteObject(paleta);

viewimage(WndPrincipal->Canvas,WndPrincipal->Canvas->Handle,&paleta,-4,-4,&imagem);

Timer1->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TWndPrincipal::Iniciar1Click(TObject *Sender)
{
int erro;
DWORD id_thread;
AnsiString codigo;

erro = InicializarHRT();

if(erro != NO_ERROR)
    {
    codigo.sprintf("%x : %d", enderecobase, erro);
    Application->MessageBoxA("Erro ao inicializar o FrameGrabber",codigo.c_str(),64);
    flag_ativado = 0;
    }
else
    {
    flag_ativado = 1;
    }
}
//---------------------------------------------------------------------------


void __fastcall TWndPrincipal::Configurar1Click(TObject *Sender)
{

WndConfig->ShowModal();
enderecobase = baseseg;

}
//---------------------------------------------------------------------------



void __fastcall TWndPrincipal::FormClose(TObject *Sender,
      TCloseAction &Action)
{
WndSplash->Close();
}
//---------------------------------------------------------------------------


void __fastcall TWndPrincipal::FormPaint(TObject *Sender)
{
PAINTSTRUCT PaintStructure;

BeginPaint(WndPrincipal->Handle,&PaintStructure);

DeleteObject(paleta);
viewimage(WndPrincipal->Canvas,WndPrincipal->Canvas->Handle,&paleta,-4,-4,&imagem);

EndPaint(WndPrincipal->Handle,&PaintStructure);


}
//---------------------------------------------------------------------------

void __fastcall TWndPrincipal::Tutorial1Click(TObject *Sender)
{
AnsiString url;
wchar_t pagina[100];

url = "file://c:/hrt/help/ajuda.html";

url.WideChar(pagina,100);

WndAjuda->BrowserAjuda->Navigate(pagina,0,0,0,0);
WndAjuda->Show();
}
//---------------------------------------------------------------------------

void __fastcall TWndPrincipal::btnCapturaClick(TObject *Sender)
{
allocimage(&WndImagem->Figura, HRTcol, HRTlin, 8);
allocimage(&WndImagem->FigBckup, HRTcol, HRTlin, 8);
allocimage(&WndImagem->Original, HRTcol, HRTlin, 8);

if (!flag_ativado)
  loadjpg(AbrirArquivo->FileName.c_str(),&WndImagem->Figura);

backup(&WndImagem->Figura,&WndImagem->Original);

Timer1->Enabled = false;

backup(&WndImagem->Figura,&WndImagem->FigBckup);
WndImagem->ShowModal();

Timer1->Enabled = true;  
}
//---------------------------------------------------------------------------

void __fastcall TWndPrincipal::btnLiveClick(TObject *Sender)
{
int erro;
DWORD id_thread;
AnsiString codigo;

Timer1->Enabled = true;
erro = InicializarHRT();
if(erro != NO_ERROR)
    {
    codigo.sprintf("%x : %d", enderecobase, erro);
    Application->MessageBoxA("Erro ao inicializar o FrameGrabber",codigo.c_str(),64);
    flag_ativado = 0;
    }
else
    {
    flag_ativado = 1;
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndPrincipal::btnFrameClick(TObject *Sender)
{
int erro;
DWORD id_thread;
AnsiString codigo;

Timer1->Enabled = false;
flag_ativado = 1;
erro = InicializarHRT();
if(erro != NO_ERROR)
  {
  codigo.sprintf("%x : %d", enderecobase, erro);
  Application->MessageBoxA("Erro ao inicializar o FrameGrabber",codigo.c_str(),64);
  }
else
  {
  LerImagem(&imagem);
  DeleteObject(paleta);
  viewimage(WndPrincipal->Canvas,WndPrincipal->Canvas->Handle,&paleta,-4,-4,&imagem);
  }
}
//---------------------------------------------------------------------------

void __fastcall TWndPrincipal::ToolButton5Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TWndPrincipal::Abrir1Click(TObject *Sender)
{
  if ( AbrirArquivo->Execute() )
    if ( AbrirArquivo->FileName != NULL )
      loadjpg(AbrirArquivo->FileName.c_str(),&imagem);
}
//---------------------------------------------------------------------------

