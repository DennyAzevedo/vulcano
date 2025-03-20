//---------------------------------------------------------------------------

#ifndef fntsplashH
#define fntsplashH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include "JvGIF.hpp"
#include "JvImage.hpp"
//---------------------------------------------------------------------------
class TfrmSplash : public TForm
{
__published:	// IDE-managed Components
    TTimer *TmrSplash;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall TmrSplashTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmSplash(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSplash *frmSplash;
//---------------------------------------------------------------------------
#endif
