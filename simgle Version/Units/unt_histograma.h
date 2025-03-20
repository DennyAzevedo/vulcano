//---------------------------------------------------------------------------

#ifndef unt_histogramaH
#define unt_histogramaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TWndHistograma : public TForm
{
__published:	// IDE-managed Components
    TBevel *Bevel1;
    TImage *ImgHisto;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TWndHistograma(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWndHistograma *WndHistograma;
//---------------------------------------------------------------------------
#endif
