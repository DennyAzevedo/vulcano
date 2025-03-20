//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fntParametros.h"
#include "fntDados.h"
#include "fntImagem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "JvComponent"
#pragma link "JvxCtrls"
#pragma link "JvBevel"
#pragma link "JvObservibleCheckBox"
#pragma link "JvArrow"
#pragma link "JvPanel"
#pragma link "JvRadioButton"
#pragma link "CSPIN"
#pragma resource "*.dfm"
TfrmParametros *frmParametros;
//---------------------------------------------------------------------------
__fastcall TfrmParametros::TfrmParametros(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmParametros::FormShow(TObject *Sender)
{
  //Dados Default - apenas as cores
  edtValPad->Value    = frmImagem->ValPad   ;
  edtValPadD->Value   = frmImagem->ValPadD  ;
  edtValNull->Value   = frmImagem->ValNull  ;
  edtValNullD->Value  = frmImagem->ValNullD ;
  //Dados do Teste
  edtEquaTe->Checked    = frmImagem->Equa      ;
  edtConvTe->Checked    = frmImagem->Conv      ;
  edtBinaTe->Checked    = frmImagem->Bina      ;
  edtNivelBinaTe->Value = frmImagem->NivelBina ;
  edtPTolInfTe->Value   = frmImagem->PTolInf   ;
  edtPTolSupTe->Value   = frmImagem->PTolSup   ;
  edtValPadTe->Value    = frmImagem->ValPad    ;
  edtValPadDTe->Value   = frmImagem->ValPadD   ;
  edtValNullTe->Value   = frmImagem->ValNull   ;
  edtValNullDTe->Value  = frmImagem->ValNullD  ;
  edtTolSupPTe->Value   = frmImagem->TolSupP   ;
  edtTolInfPTe->Value   = frmImagem->TolInfP   ;
  edtTolFalhaTe->Value  = frmImagem->TolFalha  ;
  edtPercTe->Checked    = frmImagem->Perc      ;
  edtKern0Te->Text      = frmImagem->Kern[0]   ;
  edtKern1Te->Text      = frmImagem->Kern[1]   ;
  edtKern2Te->Text      = frmImagem->Kern[2]   ;
  edtKern3Te->Text      = frmImagem->Kern[3]   ;
  edtKern4Te->Text      = frmImagem->Kern[4]   ;
  edtKern5Te->Text      = frmImagem->Kern[5]   ;
  edtKern6Te->Text      = frmImagem->Kern[6]   ;
  edtKern7Te->Text      = frmImagem->Kern[7]   ;
  edtKern8Te->Text      = frmImagem->Kern[8]   ;
  edtKern9Te->Text      = frmImagem->Kern[9]   ;
  if (frmImagem->TDiag=='P')
    TipoDiagPos->Checked = true;
  else
    TipoDiagNeg->Checked = true;
  if (frmImagem->BDiag=='S')
    BDiagSup->Checked    = true;
  else
    BDiagInf->Checked    = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmParametros::btnPadraoClick(TObject *Sender)
{
  frmImagem->Equa      = edtEqua->Checked   ;
  frmImagem->Conv      = edtConv->Checked   ;
  frmImagem->Bina      = edtBina->Checked   ;
  frmImagem->NivelBina = edtNivelBina->Value;
  frmImagem->PTolInf   = edtPTolInf->Value  ;
  frmImagem->PTolSup   = edtPTolSup->Value  ;
  frmImagem->ValPad    = edtValPad->Value   ;
  frmImagem->ValPadD   = edtValPadD->Value  ;
  frmImagem->ValNull   = edtValNull->Value  ;
  frmImagem->ValNullD  = edtValNullD->Value ;
  frmImagem->TolSupP   = edtTolSupP->Value  ;
  frmImagem->TolInfP   = edtTolInfP->Value  ;
  frmImagem->TolFalha  = edtTolFalha->Value ;
  frmImagem->Perc      = edtPerc->Checked   ;
  frmImagem->Kern[0]   = edtKern0->Text[0]  ;
  frmImagem->Kern[1]   = edtKern1->Text[0]  ;
  frmImagem->Kern[2]   = edtKern2->Text[0]  ;
  frmImagem->Kern[3]   = edtKern3->Text[0]  ;
  frmImagem->Kern[4]   = edtKern4->Text[0]  ;
  frmImagem->Kern[5]   = edtKern5->Text[0]  ;
  frmImagem->Kern[6]   = edtKern6->Text[0]  ;
  frmImagem->Kern[7]   = edtKern7->Text[0]  ;
  frmImagem->Kern[8]   = edtKern8->Text[0]  ;
  frmImagem->Kern[9]   = edtKern9->Text[0]  ;
  if (TipoDiagPos->Checked)
    frmImagem->TDiag = 'P';
  else
    frmImagem->TDiag = 'N';
  if (BDiagSup->Checked)
    frmImagem->BDiag = 'S';
  else
    frmImagem->BDiag = 'I';
  frmImagem->swtEqua->StateOn  = frmImagem->Equa;
  frmImagem->swtConvo->StateOn = frmImagem->Conv;
  frmImagem->swtBina->StateOn  = frmImagem->Bina;
  //Guarda os dados na tabela de Testes
  dmDados->tbTeste->Edit();
  dmDados->tbTesteEqualizado->Value = frmImagem->Equa     ;
  dmDados->tbTesteConvolucao->Value = frmImagem->Conv     ;
  dmDados->tbTesteBinarizado->Value = frmImagem->Bina     ;
  dmDados->tbTesteNiveBin->Value    = frmImagem->NivelBina;
  dmDados->tbTesteTolInf->Value     = frmImagem->PTolInf  ;
  dmDados->tbTesteTolSup->Value     = frmImagem->PTolSup  ;
  dmDados->tbTesteCorBusca->Value   = frmImagem->ValPad   ;
  dmDados->tbTesteCorBDiag->Value   = frmImagem->ValPadD  ;
  dmDados->tbTesteCorFundo->Value   = frmImagem->ValNull  ;
  dmDados->tbTesteCorFDiag->Value   = frmImagem->ValNullD ;
  dmDados->tbTesteTolSupProp->Value = frmImagem->TolSupP  ;
  dmDados->tbTesteTolInfProp->Value = frmImagem->TolInfP  ;
  dmDados->tbTesteTolFalhas->Value  = frmImagem->TolFalha ;
  dmDados->tbTestePerc->Value       = frmImagem->Perc     ;
  dmDados->tbTesteMat0->Value       = frmImagem->Kern[0]  ;
  dmDados->tbTesteMat1->Value       = frmImagem->Kern[1]  ;
  dmDados->tbTesteMat2->Value       = frmImagem->Kern[2]  ;
  dmDados->tbTesteMat3->Value       = frmImagem->Kern[3]  ;
  dmDados->tbTesteMat4->Value       = frmImagem->Kern[4]  ;
  dmDados->tbTesteMat5->Value       = frmImagem->Kern[5]  ;
  dmDados->tbTesteMat6->Value       = frmImagem->Kern[6]  ;
  dmDados->tbTesteMat7->Value       = frmImagem->Kern[7]  ;
  dmDados->tbTesteMat8->Value       = frmImagem->Kern[8]  ;
  dmDados->tbTesteMat9->Value       = frmImagem->Kern[9]  ;
  dmDados->tbTesteTipoDiag->Value   = frmImagem->TDiag    ;
  dmDados->tbTesteBaseDiag->Value   = frmImagem->BDiag    ;
  dmDados->tbTeste->Post();
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmParametros::btnAceitaClick(TObject *Sender)
{
  frmImagem->Equa      = edtEquaTe->Checked   ; 
  frmImagem->Conv      = edtConvTe->Checked   ;
  frmImagem->Bina      = edtBinaTe->Checked   ;
  frmImagem->NivelBina = edtNivelBinaTe->Value;
  frmImagem->PTolInf   = edtPTolInfTe->Value  ; 
  frmImagem->PTolSup   = edtPTolSupTe->Value  ; 
  frmImagem->ValPad    = edtValPadTe->Value   ; 
  frmImagem->ValPadD   = edtValPadDTe->Value  ; 
  frmImagem->ValNull   = edtValNullTe->Value  ; 
  frmImagem->ValNullD  = edtValNullDTe->Value ; 
  frmImagem->TolSupP   = edtTolSupPTe->Value  ; 
  frmImagem->TolInfP   = edtTolInfPTe->Value  ; 
  frmImagem->TolFalha  = edtTolFalhaTe->Value ; 
  frmImagem->Perc      = edtPercTe->Checked   ; 
  frmImagem->Kern[0]   = edtKern0->Text[0]    ;
  frmImagem->Kern[1]   = edtKern1->Text[0]    ;
  frmImagem->Kern[2]   = edtKern2->Text[0]    ;
  frmImagem->Kern[3]   = edtKern3->Text[0]    ;
  frmImagem->Kern[4]   = edtKern4->Text[0]    ;
  frmImagem->Kern[5]   = edtKern5->Text[0]    ;
  frmImagem->Kern[6]   = edtKern6->Text[0]    ;
  frmImagem->Kern[7]   = edtKern7->Text[0]    ;
  frmImagem->Kern[8]   = edtKern8->Text[0]    ;
  frmImagem->Kern[9]   = edtKern9->Text[0]    ;
  if (TipoDiagPosTe->Checked)
    frmImagem->TDiag = 'P';
  else
    frmImagem->TDiag = 'N';
  if (BDiagSupTe->Checked)
    frmImagem->BDiag = 'P';
  else
    frmImagem->BDiag = 'N';
  frmImagem->swtEqua->StateOn  = frmImagem->Equa;
  frmImagem->swtConvo->StateOn = frmImagem->Conv;
  frmImagem->swtBina->StateOn  = frmImagem->Bina;
  //Guarda os dados na tabela de Testes
  dmDados->tbTeste->Edit();
  dmDados->tbTesteEqualizado->Value = frmImagem->Equa     ;
  dmDados->tbTesteConvolucao->Value = frmImagem->Conv     ;
  dmDados->tbTesteBinarizado->Value = frmImagem->Bina     ;
  dmDados->tbTesteNiveBin->Value    = frmImagem->NivelBina;
  dmDados->tbTesteTolInf->Value     = frmImagem->PTolInf  ;
  dmDados->tbTesteTolSup->Value     = frmImagem->PTolSup  ;
  dmDados->tbTesteCorBusca->Value   = frmImagem->ValPad   ;
  dmDados->tbTesteCorBDiag->Value   = frmImagem->ValPadD  ;
  dmDados->tbTesteCorFundo->Value   = frmImagem->ValNull  ;
  dmDados->tbTesteCorFDiag->Value   = frmImagem->ValNullD ;
  dmDados->tbTesteTolSupProp->Value = frmImagem->TolSupP  ;
  dmDados->tbTesteTolInfProp->Value = frmImagem->TolInfP  ;
  dmDados->tbTesteTolFalhas->Value  = frmImagem->TolFalha ;
  dmDados->tbTestePerc->Value       = frmImagem->Perc     ;
  dmDados->tbTesteMat0->Value       = frmImagem->Kern[0]  ;
  dmDados->tbTesteMat1->Value       = frmImagem->Kern[1]  ;
  dmDados->tbTesteMat2->Value       = frmImagem->Kern[2]  ;
  dmDados->tbTesteMat3->Value       = frmImagem->Kern[3]  ;
  dmDados->tbTesteMat4->Value       = frmImagem->Kern[4]  ;
  dmDados->tbTesteMat5->Value       = frmImagem->Kern[5]  ;
  dmDados->tbTesteMat6->Value       = frmImagem->Kern[6]  ;
  dmDados->tbTesteMat7->Value       = frmImagem->Kern[7]  ;
  dmDados->tbTesteMat8->Value       = frmImagem->Kern[8]  ;
  dmDados->tbTesteMat9->Value       = frmImagem->Kern[9]  ;
  dmDados->tbTesteTipoDiag->Value   = frmImagem->TDiag    ;
  dmDados->tbTesteBaseDiag->Value   = frmImagem->BDiag    ;
  dmDados->tbTeste->Post();
  Close();
}
//---------------------------------------------------------------------------

