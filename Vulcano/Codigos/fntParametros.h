//---------------------------------------------------------------------------

#ifndef fntParametrosH
#define fntParametrosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "JvComponent.hpp"
#include "JvxCtrls.hpp"
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "JvBevel.hpp"
#include "JvObservibleCheckBox.hpp"
#include "JvArrow.hpp"
#include "JvPanel.hpp"
#include "JvRadioButton.hpp"
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "CSPIN.h"


//---------------------------------------------------------------------------
class TfrmParametros : public TForm
{
__published:	// IDE-managed Components
  TBevel *Bevel1;
  TJvxLabel *JvxLabel2;
  TJvxLabel *JvxLabel3;
  TJvxLabel *JvxLabel4;
  TJvxLabel *JvxLabel5;
  TJvxLabel *JvxLabel6;
  TJvxLabel *JvxLabel7;
  TJvxLabel *JvxLabel8;
  TJvxLabel *JvxLabel9;
  TJvxLabel *JvxLabel10;
  TJvxLabel *JvxLabel11;
  TJvxLabel *JvxLabel12;
  TJvxLabel *JvxLabel13;
  TJvxLabel *JvxLabel15;
  TJvxLabel *JvxLabel16;
  TJvxLabel *JvxLabel18;
  TJvObservibleCheckBox *edtPerc;
  TJvBevel *JvBevel1;
  TJvBevel *JvBevel2;
  TJvObservibleCheckBox *edtEqua;
  TJvObservibleCheckBox *edtConv;
  TJvObservibleCheckBox *edtBina;
  TJvPanel *pnlTipoDiag;
  TJvxLabel *JvxLabel17;
  TJvArrow *JvArrow1;
  TJvArrow *JvArrow2;
  TJvRadioButton *TipoDiagNeg;
  TJvRadioButton *TipoDiagPos;
  TJvPanel *pnlBDiag;
  TJvxLabel *JvxLabel19;
  TJvRadioButton *BDiagInf;
  TJvRadioButton *BDiagSup;
  TJvxLabel *JvxLabel20;
  TJvxLabel *JvxLabel21;
  TJvxLabel *JvxLabel22;
  TJvxLabel *JvxLabel23;
  TJvxLabel *JvxLabel24;
  TJvxLabel *JvxLabel25;
  TJvxLabel *JvxLabel26;
  TJvxLabel *JvxLabel27;
  TJvxLabel *JvxLabel28;
  TJvxLabel *JvxLabel29;
  TJvxLabel *JvxLabel30;
  TJvxLabel *JvxLabel31;
  TJvxLabel *JvxLabel32;
  TJvxLabel *JvxLabel33;
  TJvxLabel *JvxLabel34;
  TJvxLabel *JvxLabel35;
  TJvxLabel *JvxLabel36;
  TJvObservibleCheckBox *edtPercTe;
  TJvBevel *JvBevel3;
  TJvBevel *JvBevel4;
  TJvObservibleCheckBox *edtEquaTe;
  TJvObservibleCheckBox *edtConvTe;
  TJvObservibleCheckBox *edtBinaTe;
  TJvPanel *pnlTipoDiagTe;
  TJvxLabel *JvxLabel37;
  TJvArrow *JvArrow3;
  TJvArrow *JvArrow4;
  TJvRadioButton *TipoDiagNegTe;
  TJvRadioButton *TipoDiagPosTe;
  TJvPanel *pnlBDiagTe;
  TJvxLabel *JvxLabel38;
  TJvxLabel *JvxLabel39;
  TJvxLabel *JvxLabel40;
  TJvRadioButton *BDiagInfTe;
  TJvRadioButton *BDiagSupTe;
  TJvPanel *JvPanel1;
  TJvxLabel *JvxLabel1;
  TJvPanel *JvPanel2;
  TJvxLabel *JvxLabel14;
  TToolBar *ToolBar1;
  TToolButton *btnPadrao;
  TToolButton *btnAceita;
  TCSpinEdit *edtValPad;
  TCSpinEdit *edtValNull;
  TCSpinEdit *edtValPadD;
  TCSpinEdit *edtValNullD;
  TCSpinEdit *edtPTolSup;
  TCSpinEdit *edtPTolInf;
  TCSpinEdit *edtTolSupP;
  TCSpinEdit *edtTolInfP;
  TCSpinEdit *edtTolFalha;
  TCSpinEdit *edtNivelBina;
  TCSpinEdit *edtValPadTe;
  TCSpinEdit *edtValNullTe;
  TCSpinEdit *edtValPadDTe;
  TCSpinEdit *edtValNullDTe;
  TCSpinEdit *edtPTolSupTe;
  TCSpinEdit *edtPTolInfTe;
  TCSpinEdit *edtTolSupPTe;
  TCSpinEdit *edtTolInfPTe;
  TCSpinEdit *edtTolFalhaTe;
  TCSpinEdit *edtNivelBinaTe;
  TEdit *edtKern0;
  TEdit *edtKern1;
  TEdit *edtKern2;
  TEdit *edtKern3;
  TEdit *edtKern4;
  TEdit *edtKern5;
  TEdit *edtKern6;
  TEdit *edtKern7;
  TEdit *edtKern8;
  TEdit *edtKern9;
  TEdit *edtKern0Te;
  TEdit *edtKern1Te;
  TEdit *edtKern2Te;
  TEdit *edtKern3Te;
  TEdit *edtKern5Te;
  TEdit *edtKern4Te;
  TEdit *edtKern6Te;
  TEdit *edtKern7Te;
  TEdit *edtKern8Te;
  TEdit *edtKern9Te;
  void __fastcall btnPadraoClick(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall btnAceitaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TfrmParametros(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmParametros *frmParametros;
//---------------------------------------------------------------------------
#endif
