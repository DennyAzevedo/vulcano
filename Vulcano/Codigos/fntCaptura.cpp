/*******************************************************************************
*                                                                              *
*   Autores:  Walter da Silva Porto Neto                                       *
*             Alexandre Monteiro de Oliveira                                   *
*             Paulo Rogério da C Santos                                        *
*                                                                              *
*   Título TGI: Aplicativo para Aquisição e Tratamento de Imagens              *
*                                                                              *
*   Orientadores: Francisco Carlos Parquet Bizarria                            *
*                 José Walter Parquet Bizarria                                 *
*                                                                              *
*   Modificado por: Denny Paulista Azevedo Filho                               *
*                                                                              *
*   Tese de Mestrado - Engenharia Mecânica (Automação Industrial)              *
*                                                                              *
*   Título: Técnicas de Vizinhança Aplicadas a Validação Funcional de          *
*           Matriz de Cristal Líquido                                          *
*                                                                              *
*   Orientador: Francisco Carlos Parquet Bizarria                              *
*                                                                              *
*   Colaborador: José Walter Parquet Bizarria                                  *
*                                                                              *
*   Criado em : ??/??/2003                                                     *
*   Modificado em : 20/07/2004                                                 *
*                                                                              *
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*   Finalidade : Captura de Imagens através da Placa HRT e filmadora           *
*                Captura quadro a quadro ou continua                           *
*                Configuração da Placa HRT - Endereço Base                     *
*                                                                              *
*******************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "../include/vicdefs.h"
#include "fntCaptura.h"
#include "fntConfig.h"
#include "fntImagem.h"
#include "fntHistograma.h"
#include "fntSplash.h"
#include "fntAjuda.h"
#include "../include/Funcoes.h"

//--------- variáveis global ----------
unsigned int enderecobase;
int modo_video;
bool Arquivo=false;

//------------ Protótipo da Thread de video em tempo "Real" -----------------
DWORD WINAPI RealTimeVideo( LPVOID lpParam );
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"

TfrmCaptura *frmCaptura;
//---------------------------------------------------------------------------
__fastcall TfrmCaptura::TfrmCaptura(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmCaptura::FormCreate(TObject *Sender)
{
  int x;

  flag_ativado=0;
  enderecobase = 0xd400;
  allocimage(&imagem, HRTcol, HRTlin, 8);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCaptura::FormPaint(TObject *Sender)
{
  PAINTSTRUCT PaintStructure;

  BeginPaint(frmCaptura->Handle,&PaintStructure);
  DeleteObject(paleta);
  viewimage(ImgCam->Canvas,ImgCam->Canvas->Handle,&paleta,0,0,&imagem);
  EndPaint(frmCaptura->Handle,&PaintStructure);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCaptura::Sair1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmCaptura::Timer1Timer(TObject *Sender)
{
  int x;

  Timer1->Enabled = false;
  if(flag_ativado)
    LerImagem(&imagem);
  else
    if (imagem.ibuff[1] == 0)
      loadjpg("imgteste.jpg",&imagem);
  DeleteObject(paleta);
  viewimage(ImgCam->Canvas,ImgCam->Canvas->Handle,&paleta,0,0,&imagem);
  Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCaptura::Iniciar1Click(TObject *Sender)
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
    flag_ativado = 1;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCaptura::Configurar1Click(TObject *Sender)
{
  frmConfig->ShowModal();
  enderecobase = baseseg;
}
//---------------------------------------------------------------------------


void __fastcall TfrmCaptura::btnCapturaClick(TObject *Sender)
{
  if (!Arquivo)
    if (!flag_ativado)
      loadjpg("imgteste.jpg",&imagem);
  copyimage(&imagem,&frmImagem->Figura);
  resize(&imagem,&frmImagem->ImageOrg);
  Timer1->Enabled = false;
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmCaptura::btnLiveClick(TObject *Sender)
{
  int erro;
  DWORD id_thread;
  AnsiString codigo;

  Arquivo = false;
  Timer1->Enabled = true;
  erro = InicializarHRT();
  if(erro != NO_ERROR)
    {
    codigo.sprintf("%x : %d", enderecobase, erro);
    Application->MessageBoxA("Erro ao inicializar o FrameGrabber",codigo.c_str(),64);
    flag_ativado = 0;
    }
  else
    flag_ativado = 1;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCaptura::btnFrameClick(TObject *Sender)
{
  int erro;
  DWORD id_thread;
  AnsiString codigo;

  Arquivo = false;
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
    viewimage(ImgCam->Canvas,ImgCam->Canvas->Handle,&paleta,0,0,&imagem);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmCaptura::btnSairClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------


void __fastcall TfrmCaptura::btnArquivoClick(TObject *Sender)
{
  if (opnImagem->Execute())
    {
    loadjpg(opnImagem->FileName.c_str(),&imagem);
    viewimage(ImgCam->Canvas,ImgCam->Canvas->Handle,&paleta,0,0,&imagem);
    }
  Arquivo = true;

}
//---------------------------------------------------------------------------

