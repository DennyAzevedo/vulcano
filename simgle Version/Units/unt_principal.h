//---------------------------------------------------------------------------

#ifndef unt_principalH
#define unt_principalH
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
class TWndPrincipal : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MenuPrincipal;
    TMenuItem *FrameGrabber1;
    TMenuItem *Iniciar1;
    TMenuItem *N1;
    TMenuItem *Sair1;
    TBevel *Quadro;
    TMenuItem *Configurar1;
    TTimer *Timer1;
    TMenuItem *Imagem1;
    TMenuItem *Capturar1;
    TMenuItem *Ajuda1;
    TMenuItem *Tutorial1;
    TToolBar *ToolBar1;
    TImageList *ImageList1;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
  TToolButton *btnFrame;
  TToolButton *btnLive;
  TToolButton *btnCaptura;
  TToolButton *ToolButton3;
  TToolButton *ToolButton4;
  TToolButton *ToolButton5;
  TOpenPictureDialog *AbrirArquivo;
  TMenuItem *Abrir1;
    void __fastcall Sair1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall Iniciar1Click(TObject *Sender);
    void __fastcall Configurar1Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall Tutorial1Click(TObject *Sender);
  void __fastcall btnCapturaClick(TObject *Sender);
  void __fastcall btnLiveClick(TObject *Sender);
  void __fastcall btnFrameClick(TObject *Sender);
  void __fastcall ToolButton5Click(TObject *Sender);
  void __fastcall Abrir1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    int flag_ativado;
    unsigned int baseseg;
    imgdes figura;
    HPALETTE palleta;
    imgdes imagem;
    HPALETTE paleta;
    HANDLE ThreadID;
    __fastcall TWndPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWndPrincipal *WndPrincipal;
//---------------------------------------------------------------------------

#endif

