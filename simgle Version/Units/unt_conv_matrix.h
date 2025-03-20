//---------------------------------------------------------------------------

#ifndef unt_conv_matrixH
#define unt_conv_matrixH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TWndMatrix : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TEdit *mtrx1;
    TEdit *mtrx2;
    TEdit *mtrx3;
    TEdit *mtrx4;
    TEdit *mtrx5;
    TEdit *mtrx6;
    TEdit *mtrx7;
    TEdit *mtrx8;
    TEdit *mtrx9;
    TLabel *Label1;
    TEdit *mtrx10;
    TSpeedButton *BtnOK;
    void __fastcall mtrx1KeyPress(TObject *Sender, char &Key);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall BtnOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TWndMatrix(TComponent* Owner);
    TEdit *matrix[10];
};
//---------------------------------------------------------------------------
extern PACKAGE TWndMatrix *WndMatrix;
//---------------------------------------------------------------------------
#endif
