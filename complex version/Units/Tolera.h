//---------------------------------------------------------------------------

#ifndef ToleraH
#define ToleraH
//---------------------------------------------------------------------------
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TfrmTolera : public TForm
{
__published:	// IDE-managed Components
  TLabel *Label1;
  TLabel *Label2;
  TTrackBar *BarTolSup;
  TTrackBar *BarTolInf;
  TToolBar *ToolBar1;
  TToolButton *Sair;
  TEdit *edtToSup;
  TEdit *edtToInf;
  TRadioButton *rbValor;
  TRadioButton *rbPerc;
  TLabel *Label3;
  void __fastcall BarTolSupChange(TObject *Sender);
  void __fastcall BarTolInfChange(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall SairClick(TObject *Sender);
  void __fastcall edtToSupChange(TObject *Sender);
  void __fastcall edtToInfChange(TObject *Sender);
  void __fastcall rbValorClick(TObject *Sender);
  void __fastcall rbPercClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TfrmTolera(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTolera *frmTolera;
//---------------------------------------------------------------------------
#endif
