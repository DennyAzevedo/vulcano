//---------------------------------------------------------------------------

#ifndef unt_ajudaH
#define unt_ajudaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SHDocVw_OCX.h"
#include <OleCtrls.hpp>
//---------------------------------------------------------------------------
class TWndAjuda : public TForm
{
__published:	// IDE-managed Components
    TCppWebBrowser *BrowserAjuda;
private:	// User declarations
public:		// User declarations
    __fastcall TWndAjuda(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWndAjuda *WndAjuda;
//---------------------------------------------------------------------------
#endif
