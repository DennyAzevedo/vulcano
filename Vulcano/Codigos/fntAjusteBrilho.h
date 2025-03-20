//---------------------------------------------------------------------------

#ifndef fntAjusteBrilhoH
#define fntAjusteBrilhoH
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
class TfrmBrilho : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBrilho;
    TSpeedButton *BtnAjustarBrilho;
    TSpeedButton *BtnCancelarBrilho;
    TTrackBar *TrckBrilho;
    TBevel *Bevel1;
    TStaticText *Posicao;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall BtnCancelarBrilhoClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall BtnAjustarBrilhoClick(TObject *Sender);
    void __fastcall TrckBrilhoChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmBrilho(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmBrilho *frmBrilho;
//---------------------------------------------------------------------------
#endif
