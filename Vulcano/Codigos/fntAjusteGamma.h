//---------------------------------------------------------------------------

#ifndef fntAjusteGammaH
#define fntAjusteGammaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TfrmGamma : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupGamma;
    TSpeedButton *BtnAjustar;
    TSpeedButton *BtnCancelar;
    TTrackBar *TrckGamma;
    TBevel *Bevel1;
    TStaticText *Posicao;
    void __fastcall TrckGammaChange(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall BtnCancelarClick(TObject *Sender);
    void __fastcall BtnAjustarClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmGamma(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGamma *frmGamma;
//---------------------------------------------------------------------------
#endif
