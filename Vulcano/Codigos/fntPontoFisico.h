//---------------------------------------------------------------------------

#ifndef fntPontoFisicoH
#define fntPontoFisicoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include "JvComponent.hpp"
#include "JvxCtrls.hpp"
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TfrmPontoFisico : public TForm
{
__published:	// IDE-managed Components
  TCSpinEdit *edtColuna;
  TCSpinEdit *edtLinha;
  TJvxLabel *JvxLabel1;
  TJvxLabel *JvxLabel2;
  TToolBar *ToolBar1;
  TToolButton *btnSair;
  void __fastcall btnSairClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TfrmPontoFisico(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPontoFisico *frmPontoFisico;
//---------------------------------------------------------------------------
#endif
