//---------------------------------------------------------------------------

#ifndef fntHistogramaH
#define fntHistogramaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TfrmHistograma : public TForm
{
__published:	// IDE-managed Components
    TBevel *Bevel1;
    TImage *ImgHisto;
  TToolBar *ToolBar1;
  TToolButton *btnSair;
        void __fastcall FormShow(TObject *Sender);
  void __fastcall btnSairClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmHistograma(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmHistograma *frmHistograma;
//---------------------------------------------------------------------------
#endif
