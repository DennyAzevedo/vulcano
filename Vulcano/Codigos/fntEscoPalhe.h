//---------------------------------------------------------------------------

#ifndef fntEscoPalheH
#define fntEscoPalheH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmEscoPalhe : public TForm
{
__published:	// IDE-managed Components
  TTrackBar *Pon;
  TPaintBox *Barra;
  TShape *Quadro1;
  TCheckBox *Ver1;
  TCheckBox *Ver2;
  TShape *Quadro2;
  TLabel *Label1;
  TLabel *Label2;
  TToolBar *ToolBar1;
  TToolButton *btnSair;
  TLabel *lblQuadro1;
  TLabel *lblQuadro2;
  TBevel *Bevel1;
  TLabel *Label3;
  TCheckBox *Ver3;
  TShape *QuadroD1;
  TLabel *lblQuadroD1;
  TLabel *Label5;
  TCheckBox *Ver4;
  TShape *QuadroD2;
  TLabel *lblQuadroD2;
  TBevel *Bevel2;
  TLabel *Label4;
  TLabel *Label6;
  void __fastcall PonChange(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall btnSairClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TfrmEscoPalhe(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmEscoPalhe *frmEscoPalhe;
//---------------------------------------------------------------------------
#endif
