//---------------------------------------------------------------------------

#ifndef fntFinalidadeH
#define fntFinalidadeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "JvDBCtrl.hpp"
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfrmFinalidade : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *GroupBox1;
  TDBEdit *DBEdit1;
  TGroupBox *GroupBox2;
  TDBEdit *DBEdit2;
  TDBNavigator *DBNavigator1;
  TJvDBGrid *JvDBGrid1;
private:	// User declarations
public:		// User declarations
  __fastcall TfrmFinalidade(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmFinalidade *frmFinalidade;
//---------------------------------------------------------------------------
#endif
