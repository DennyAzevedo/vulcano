//---------------------------------------------------------------------------

#ifndef EscoPalheH
#define EscoPalheH
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
  TToolButton *Sair;
  TLabel *lblQuadro1;
  TLabel *lblQuadro2;
  void __fastcall PonChange(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall SairClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TfrmEscoPalhe(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmEscoPalhe *frmEscoPalhe;
//---------------------------------------------------------------------------
#endif
