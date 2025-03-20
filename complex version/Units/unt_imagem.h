//---------------------------------------------------------------------------

#ifndef unt_imagemH
#define unt_imagemH
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
#include <JvSwitch.hpp>
#include "JvComponent.hpp"
#include "JvxCtrls.hpp"
#include "JvZoom.hpp"
#include "JvTransLED.hpp"

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
class TWndImagem : public TForm
{
__published:	// IDE-managed Components
  TMainMenu *MenuImagem;
  TMenuItem *Arquivo1;
  TMenuItem *N1;
  TMenuItem *Fechar1;
  TBevel *QuadroImg;
  TMenuItem *Imagem1;
  TMenuItem *Histograma1;
  TMenuItem *Salvar1;
  TSaveDialog *DlgSalvar;
  TMenuItem *Mirror1;
  TMenuItem *N8bpp1bpp1;
  TMenuItem *Gamma1;
  TMenuItem *N1bpp8bpp1;
  TMenuItem *Equalizar1;
  TMenuItem *Ajuda1;
  TMenuItem *Blur1;
  TMenuItem *Sharpen1;
  TMenuItem *Brilho1;
  TToolBar *ToolBar1;
  TImageList *ImageList1;
  TToolButton *ToolButton3;
  TToolButton *ToolButton4;
  TToolButton *ToolButton8;
  TToolButton *ToolButton9;
  TToolButton *ToolButton5;
  TToolButton *ToolButton6;
  TMenuItem *Converter8bpptoRGB1;
  TMenuItem *OperaesLgicas1;
  TMenuItem *EAND1;
  TMenuItem *OUOR1;
  TMenuItem *OUEXCLUSIVOXOR1;
  TMenuItem *NoOUNOR1;
  TMenuItem *Filtros1;
  TMenuItem *Outline1;
  TMenuItem *RemoverRuido1;
  TMenuItem *Pixellize1;
  TMenuItem *MatrizConvoluo1;
  TOpenPictureDialog *AbrirArquivo;
  TMenuItem *Contedo1;
  TMenuItem *Editar1;
  TMenuItem *Desfazer1;
  TMenuItem *RestaurarOriginal1;
  TToolButton *ToolButton10;
  TToolButton *btnIniciar;
  TTimer *Timer1;
  TLabel *lblNumEle;
  TToolButton *ToolButton11;
  TToolButton *Sair;
  TToolButton *Paleta;
  TToolButton *PegImg;
  TPaintBox *ImgTrab;
  TLabel *lblElem;
  TToolButton *btnTole;
  TShape *Quadro1;
  TShape *Quadro2;
  TLabel *lblCorFun;
  TLabel *lblCorBus;
  TToolButton *btnPasso;
  TLabel *lblQuadro1;
  TLabel *lblQuadro2;
  TTable *tblPontos;
  TDataSource *dsPontos;
  TTable *tblTeste;
  TTable *tblElemento;
  TAutoIncField *tblTesteCodigo;
  TDateField *tblTesteData;
  TTimeField *tblTesteHora;
  TStringField *tblTesteCorBusca;
  TSmallintField *tblTesteIndCorBusca;
  TStringField *tblTesteCorFundo;
  TSmallintField *tblTesteIndCorFundo;
  TSmallintField *tblTesteTolSup;
  TSmallintField *tblTesteTolInf;
  TBooleanField *tblTestePerc;
  TIntegerField *tblElementoCodTeste;
  TSmallintField *tblElementoNumElem;
  TSmallintField *tblElementoNumPontos;
  TSmallintField *tblElementoDMGCol;
  TSmallintField *tblElementoDMGLin;
  TIntegerField *tblPontosCodTeste;
  TSmallintField *tblPontosNumElem;
  TSmallintField *tblPontosNuPonto;
  TSmallintField *tblPontosColuna;
  TSmallintField *tblPontosLinha;
  TStringField *tblPontosCor;
  TSmallintField *tblPontosIndice;
  TToolButton *ToolButton12;
  TToolButton *btnCentroide;
  TToolButton *btnAlvo;
  TToolButton *btnAjustar;
  TLabel *lblBaseY;
  TDataSource *dsTeste;
  TLabel *lblBaseX;
  TLabel *lblAlvoX;
  TLabel *lblAlvoY;
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
  TJvSwitch *swtLivre1;
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
  void __fastcall Fechar1Click(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall Histograma1Click(TObject *Sender);
  void __fastcall Salvar1Click(TObject *Sender);
  void __fastcall Mirror1Click(TObject *Sender);
  void __fastcall N8bpp1bpp1Click(TObject *Sender);
  void __fastcall Gamma1Click(TObject *Sender);
  void __fastcall N1bpp8bpp1Click(TObject *Sender);
  void __fastcall Equalizar1Click(TObject *Sender);
  void __fastcall AtualizarHistograma();
  void __fastcall ConfirmarAtualizacao();
  void __fastcall Blur1Click(TObject *Sender);
  void __fastcall Sharpen1Click(TObject *Sender);
  void __fastcall Brilho1Click(TObject *Sender);
  void __fastcall ToolButton4Click(TObject *Sender);
  void __fastcall Converter8bpptoRGB1Click(TObject *Sender);
  void __fastcall OperacaoLogica(int tipo_operacao);
  void __fastcall AjustaCor(ponto_colorido *ponto);
  void __fastcall EAND1Click(TObject *Sender);
  void __fastcall OUEXCLUSIVOXOR1Click(TObject *Sender);
  void __fastcall OUOR1Click(TObject *Sender);
  void __fastcall NoOUNOR1Click(TObject *Sender);
  void __fastcall Outline1Click(TObject *Sender);
  void __fastcall RemoverRuido1Click(TObject *Sender);
  void __fastcall Pixellize1Click(TObject *Sender);
  void __fastcall MatrizConvoluo1Click(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall Desfazer1Click(TObject *Sender);
  void __fastcall RestaurarOriginal1Click(TObject *Sender);
  void __fastcall Contedo1Click(TObject *Sender);
  void __fastcall btnIniciarClick(TObject *Sender);
  void __fastcall QInit(void);
  int __fastcall QisEmpty(void);
  int __fastcall QisFull(void);
  int __fastcall adc(int i);
  void __fastcall Enqueue(int Col, int Lin);
  Ponto __fastcall Dequeue(void);
  void __fastcall Varredura(void);
  void __fastcall Busca(void);
  void __fastcall GuardaDados(int Col, int Lin);
  void __fastcall PaletaClick(TObject *Sender);
  void __fastcall btnToleClick(TObject *Sender);
  void __fastcall PegImgClick(TObject *Sender);
  void __fastcall SairClick(TObject *Sender);
  void __fastcall ImgTrabMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall ImgTrabMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall ImgTrabMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
  void __fastcall btnAlvoClick(TObject *Sender);
  void __fastcall btnCentroideClick(TObject *Sender);
  void __fastcall btnAjustarClick(TObject *Sender);
  void __fastcall swtAmpliaClick(TObject *Sender);
  void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
  void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
private:	// User declarations
public:		// User declarations
  imgdes Figura;
  imgdes timage;
  imgdes ImageOrg;
  HPALETTE Palleta;
  __fastcall TWndImagem(TComponent* Owner);
  char Kern[12];
  //--------- variáveis global ----------
  struct {
      int Total;
      int Comeco;
      int Final;
      Ponto Memo[MAX];
      } Fila;
  int LinDado,LinPonto,Linha,Coluna,Lin1Pon;
  Ponto MDados[HRTcol][HRTlin];
  int fig,NElem;
  int PTolInf,PTolSup,TolInf,TolSup,ValPad,ValNull;
  TColor NCor[256];
  bool Perc;
};


//---------------------------------------------------------------------------
extern PACKAGE TWndImagem *WndImagem;
//---------------------------------------------------------------------------
#endif
