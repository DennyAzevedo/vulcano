//---------------------------------------------------------------------------

#ifndef fntImagemH
#define fntImagemH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include "../include/vicdefs.h"
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <ExtDlgs.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include "JvSwitch.hpp"
#include "JvComponent.hpp"
#include "JvxCtrls.hpp"
#include "JvZoom.hpp"
#include "JvTransLED.hpp"
#include "SHDocVw_OCX.h"
#include <OleCtrls.hpp>
#include "JvBalloonHint.hpp"
#include "JvTrayIcon.hpp"
#include "JvBevel.hpp"

#define HRTcol 512
#define HRTlin 460

#define MAX 960  // tamanho máximo da fila circular

struct ponto_colorido {
    char blue;
    char green;
    char red;
    };
typedef struct {
                int Coluna;
                int Linha;
               } Ponto;
const crMyCursor = 5;
const crTarget = 6;



//---------------------------------------------------------------------------
class TfrmImagem : public TForm
{
__published:	// IDE-managed Components
  TMainMenu *MenuImagem;
  TBevel *QuadroImg;
  TMenuItem *Imagem1;
  TMenuItem *Histograma1;
  TSaveDialog *DlgSalvar;
  TMenuItem *Binarizar1;
  TMenuItem *Gamma1;
  TMenuItem *Equalizar1;
  TMenuItem *Ajuda1;
  TMenuItem *Blur1;
  TMenuItem *Sharpen1;
  TMenuItem *Brilho1;
  TToolBar *ToolBar1;
  TImageList *ImageList1;
  TToolButton *btnHisto;
  TToolButton *btnVoltar;
  TToolButton *btnSalvar;
  TToolButton *Separador1;
  TMenuItem *Filtros1;
  TMenuItem *Outline1;
  TMenuItem *RemoverRuido1;
  TMenuItem *Pixellize1;
  TMenuItem *MatrizConvoluo1;
  TToolButton *Separador2;
  TToolButton *btnIniciar;
  TToolButton *Separador3;
  TToolButton *btnSair;
  TToolButton *btnPaleta;
  TToolButton *btnPegImg;
  TPaintBox *ImgTrab;
  TToolButton *btnTolera;
  TShape *Quadro1;
  TShape *Quadro2;
  TLabel *lblQuadro1;
  TLabel *lblQuadro2;
  TToolButton *Separador4;
  TToolButton *btnCentroide;
  TImage *ImgOrg;
  TImage *RImage;
  TBevel *QuadroOrg;
  TJvSwitch *swtDelay;
  TJvSwitch *swtConvo;
  TJvSwitch *swtEqua;
  TBevel *QuadroEqua;
  TBevel *QuadroConv;
  TBevel *QuadroDelay;
  TBevel *PanTrab;
  TJvxLabel *JvxLabel1;
  TBevel *PanOrg;
  TJvxLabel *JvxLabel2;
  TStatusBar *StatusBar1;
  TBevel *QuadroZoom;
  TJvZoom *Zoom;
  TBevel *QuadroTolBus;
  TJvSwitch *swtTolBusca;
  TBevel *QuadroTolDiag;
  TJvSwitch *swtTolDiag;
  TBevel *QuadroAmplia;
  TJvSwitch *swtAmplia;
  TJvxLabel *JvxLabel3;
  TBevel *MoldZoom;
  TJvTransLED *StatusLed;
  TJvxLabel *JvxLabel4;
  TJvSwitch *swtBina;
  TBevel *Bevel1;
  TJvSwitch *swtLivre2;
  TBevel *Bevel2;
  TJvxLabel *JvxLabel5;
  TJvxLabel *JvxLabel6;
  TJvxLabel *JvxLabel7;
  TJvxLabel *JvxLabel8;
  TJvxLabel *JvxLabel9;
  TJvxLabel *JvxLabel10;
  TJvxLabel *JvxLabel11;
  TJvxLabel *JvxLabel12;
  TToolButton *btnCapturar;
  TToolButton *btnGamma;
  TToolButton *btnBrilho;
  TMenuItem *Relatrios1;
  TMenuItem *Completo1;
  TMenuItem *Aprovados1;
  TMenuItem *Rejeitados1;
  TJvTrayIcon *JvTrayIcon1;
  TJvBalloonHint *JvBalloonHint1;
  TPopupMenu *PopupMenu1;
  TMenuItem *Sair1;
  TMenuItem *N2;
  TMenuItem *Ativar1;
  TMenuItem *Sobre1;
  TToolButton *btnConv;
  TToolButton *btnEqua;
        TToolButton *btnOriginal;
  TToolButton *btnTerInsp;
  TToolButton *btnCanInsp;
  TToolButton *btnIniPara;
  TToolButton *btnTerPara;
  TToolButton *Separador5;
  TToolButton *Separador7;
        TMenuItem *N3;
        TMenuItem *Salvar1;
        TToolButton *btnIniInsp;
        TToolButton *Separador6;
        TToolButton *btnIniTeste;
        TToolButton *btnTerTeste;
        TToolButton *Separador8;
  TToolButton *btnIniPeca;
  TToolButton *btnTerPeca;
  TLabel *lblElem;
  TJvxLabel *JvxLabel13;
  TJvTransLED *StatusPeca;
  TBevel *Bevel3;
  TPanel *pnlCores;
  TPanel *pnlElemento;
  TPanel *pnlMascara2;
  TJvxLabel *JvxLabel14;
  TJvxLabel *JvxLabel15;
  TJvxLabel *JvxLabel16;
  TJvxLabel *lblAtu;
  TJvxLabel *lblProx;
  TJvxLabel *JvxLabel17;
  TJvxLabel *JvxLabel18;
  TJvxLabel *lblLinF;
  TJvxLabel *lblColF;
  TPanel *pnlMascara1;
  TShape *QuadroD1;
  TLabel *lblQuadroD1;
  TJvxLabel *JvxLabel19;
  TJvxLabel *JvxLabel20;
  TShape *QuadroD2;
  TLabel *lblQuadroD2;
  TJvxLabel *JvxLabel21;
  TJvxLabel *JvxLabel22;
  TJvBevel *JvBevel1;
  TJvBevel *JvBevel2;
  TJvBevel *JvBevel3;
  TJvBevel *JvBevel4;
  TPanel *pnlIniciar;
  TJvxLabel *JvxLabel23;
  TJvxLabel *JvxLabel24;
  TLabel *lblDiag;
  TJvTransLED *StatusEle;
  void __fastcall Fechar1Click(TObject *Sender);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall Histograma1Click(TObject *Sender);
  void __fastcall Salvar1Click(TObject *Sender);
  void __fastcall Gamma1Click(TObject *Sender);
  void __fastcall Equalizar1Click(TObject *Sender);
  void __fastcall AtualizarHistograma();
  void __fastcall Blur1Click(TObject *Sender);
  void __fastcall Sharpen1Click(TObject *Sender);
  void __fastcall Brilho1Click(TObject *Sender);
  void __fastcall Outline1Click(TObject *Sender);
  void __fastcall RemoverRuido1Click(TObject *Sender);
  void __fastcall Pixellize1Click(TObject *Sender);
  void __fastcall MatrizConvoluo1Click(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall Desfazer1Click(TObject *Sender);
  void __fastcall RestaurarOriginal1Click(TObject *Sender);
  void __fastcall btnIniciarClick(TObject *Sender);
  void __fastcall QInit(void);
  int __fastcall QisEmpty(void);
  int __fastcall QisFull(void);
  int __fastcall adc(int i);
  void __fastcall Enqueue(int Col, int Lin);
  Ponto __fastcall Dequeue(void);
  void __fastcall Varredura(void);
  void __fastcall Busca(void);
  void __fastcall VarreduraD(void);
  void __fastcall BuscaD(void);
  void __fastcall GuardaDados(int Col, int Lin);
  void __fastcall GuardaDadosD(int Col, int Lin);
  void __fastcall btnPaletaClick(TObject *Sender);
  void __fastcall btnToleraClick(TObject *Sender);
  void __fastcall btnPegImgClick(TObject *Sender);
  void __fastcall btnSairClick(TObject *Sender);
  void __fastcall ImgTrabMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall ImgTrabMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall ImgTrabMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
  void __fastcall btnCentroideClick(TObject *Sender);
  void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
  void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
  void __fastcall btnCapturarClick(TObject *Sender);
  void __fastcall Binarizar1Click(TObject *Sender);
  void __fastcall swtAmpliaOn(TObject *Sender);
  void __fastcall swtAmpliaOff(TObject *Sender);
  void __fastcall MontaPaleta(void);
  void __fastcall Ativar1Click(TObject *Sender);
  void __fastcall JvTrayIcon1Click(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall btnIniInspClick(TObject *Sender);
  void __fastcall btnIniTesteClick(TObject *Sender);
  void __fastcall btnTerInspClick(TObject *Sender);
  void __fastcall btnIniParaClick(TObject *Sender);
  void __fastcall btnCanInspClick(TObject *Sender);
  void __fastcall btnIniPecaClick(TObject *Sender);
  void __fastcall btnTerTesteClick(TObject *Sender);
  void __fastcall btnTerParaClick(TObject *Sender);
  void __fastcall btnTerPecaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  imgdes Figura;
  imgdes FigBak;
  imgdes ImageOrg;
  HPALETTE Palleta;
  char Kern[10];
  struct {
      int Total;
      int Comeco;
      int Final;
      Ponto Memo[MAX];
      } Fila;
  int LinDado,LinPonto,Linha,Coluna,Lin1Pon;
  int LinhaF,ColunaF;
  Ponto MDados[HRTcol][HRTlin];
  int fig,NElem,NDiag;
  int PTolInf,PTolSup,TolInf,TolSup,TolSupP,TolInfP,TolFalha;
  int ValPad,ValNull,ValPadD,ValNullD;
  char TDiag,BDiag;
  TColor NCor[256];
  bool Perc,Alvo,Pintar;
  bool Equa,Conv,Bina;
  int NivelBina;
  TRect MyRect, MyOther;
  __fastcall TfrmImagem(TComponent* Owner);

};


//---------------------------------------------------------------------------
extern PACKAGE TfrmImagem *frmImagem;
//---------------------------------------------------------------------------
#endif
