//---------------------------------------------------------------------------

#ifndef unt_configH
#define unt_configH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TWndConfig : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *Grupo;
    TComboBox *ListaBaseSeg;
    TSpeedButton *BtOK;
    TSpeedButton *BtCancelar;
    void __fastcall BtCancelarClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall BtOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TWndConfig(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWndConfig *WndConfig;
//---------------------------------------------------------------------------
#endif
