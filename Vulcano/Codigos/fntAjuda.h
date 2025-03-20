//---------------------------------------------------------------------------

#ifndef fntAjudaH
#define fntAjudaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SHDocVw_OCX.h"
#include <OleCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmAjuda : public TForm
{
__published:	// IDE-managed Components
    TCppWebBrowser *BrowserAjuda;
private:	// User declarations
public:		// User declarations
    __fastcall TfrmAjuda(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAjuda *frmAjuda;
//---------------------------------------------------------------------------
#endif
