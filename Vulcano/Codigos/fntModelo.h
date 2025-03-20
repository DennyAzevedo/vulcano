//---------------------------------------------------------------------------

#ifndef fntModeloH
#define fntModeloH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "JvDBCtrl.hpp"
#include "JvLookup.hpp"
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TfrmModelo : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *GroupBox1;
  TDBEdit *DBEdit1;
  TGroupBox *GroupBox2;
  TGroupBox *GroupBox3;
  TDBEdit *DBEdit3;
  TJvDBLookupCombo *JvDBLookupCombo1;
  TDBNavigator *DBNavigator1;
  TJvDBGrid *JvDBGrid1;
private:	// User declarations
public:		// User declarations
  __fastcall TfrmModelo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmModelo *frmModelo;
//---------------------------------------------------------------------------
#endif
