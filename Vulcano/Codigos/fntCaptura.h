//---------------------------------------------------------------------------

#ifndef fntCapturaH
#define fntCapturaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include "../include/vicdefs.h"
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include "SHDocVw_OCX.h"
#include <OleCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>

//---------------------------------------------------------------------------
class TfrmCaptura : public TForm
{
__published:	// IDE-managed Components
  TBevel *Quadro;
  TTimer *Timer1;
  TToolBar *ToolBar1;
  TImageList *ImageList1;
  TToolButton *btnConfigurar;
  TToolButton *Separador1;
  TToolButton *btnFrame;
  TToolButton *btnLive;
  TToolButton *btnCaptura;
  TToolButton *Separador2;
  TToolButton *Separador3;
  TToolButton *btnSair;
  TPaintBox *ImgCam;
  TToolButton *btnArquivo;
  TOpenPictureDialog *opnImagem;
  void __fastcall Sair1Click(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall Timer1Timer(TObject *Sender);
  void __fastcall Iniciar1Click(TObject *Sender);
  void __fastcall Configurar1Click(TObject *Sender);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall btnCapturaClick(TObject *Sender);
  void __fastcall btnLiveClick(TObject *Sender);
  void __fastcall btnFrameClick(TObject *Sender);
  void __fastcall btnSairClick(TObject *Sender);
  void __fastcall btnArquivoClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  int flag_ativado;
  unsigned int baseseg;
  imgdes imagem;
  HPALETTE paleta;
  HANDLE ThreadID;
  __fastcall TfrmCaptura(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCaptura *frmCaptura;
//---------------------------------------------------------------------------

#endif

