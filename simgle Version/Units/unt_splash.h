//---------------------------------------------------------------------------

#ifndef unt_splashH
#define unt_splashH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TWndSplash : public TForm
{
__published:	// IDE-managed Components
    TImage *Splash;
    TTimer *TmrSplash;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall TmrSplashTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TWndSplash(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWndSplash *WndSplash;
//---------------------------------------------------------------------------
#endif
