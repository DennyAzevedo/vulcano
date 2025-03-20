//---------------------------------------------------------------------------

#ifndef fntConfigH
#define fntConfigH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmConfig : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *Grupo;
    TComboBox *ListaBaseSeg;
  TSpeedButton *btnOK;
  TSpeedButton *btnCancelar;
    void __fastcall btnCancelarClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall btnOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmConfig(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmConfig *frmConfig;
//---------------------------------------------------------------------------
#endif
