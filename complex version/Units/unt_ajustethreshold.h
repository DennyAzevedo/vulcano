//---------------------------------------------------------------------------

#ifndef unt_ajustethresholdH
#define unt_ajustethresholdH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TWndSegmenta : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBrilho;
    TSpeedButton *BtnAjustarThreshold;
    TSpeedButton *BtnCancelarThreshold;
    TTrackBar *TrckThreshold;
    TBevel *Bevel1;
    TStaticText *Posicao;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall BtnCancelarThresholdClick(TObject *Sender);
    void __fastcall BtnAjustarThresholdClick(TObject *Sender);
    void __fastcall TrckThresholdChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TWndSegmenta(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWndSegmenta *WndSegmenta;
//---------------------------------------------------------------------------
#endif
