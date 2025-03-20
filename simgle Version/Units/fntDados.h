//---------------------------------------------------------------------------

#ifndef fntDadosH
#define fntDadosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TdmDados : public TDataModule
{
__published:	// IDE-managed Components
  TTable *tbTeste;
  TTable *tbElemento;
  TTable *tbPontos;
  TDataSource *dsPontos;
  TDataSource *dsElemento;
  TDataSource *dsTeste;
  TAutoIncField *tbTesteCodigo;
  TDateField *tbTesteData;
  TTimeField *tbTesteHora;
  TStringField *tbTesteCorBusca;
  TSmallintField *tbTesteIndCorBusca;
  TStringField *tbTesteCorDiagonal;
  TSmallintField *tbTesteIndCorDiagonal;
  TSmallintField *tbTesteTolSup;
  TSmallintField *tbTesteTolInf;
  TBooleanField *tbTestePerc;
  TIntegerField *tbPontosCodTeste;
  TSmallintField *tbPontosNumElem;
  TSmallintField *tbPontosNuPonto;
  TSmallintField *tbPontosColuna;
  TSmallintField *tbPontosLinha;
  TSmallintField *tbPontosCor;
  TTable *tbDiagonal;
  TIntegerField *tbDiagonalCodTeste;
  TSmallintField *tbDiagonalNumElem;
  TSmallintField *tbDiagonalNuDiag;
  TSmallintField *tbDiagonalCenCol;
  TSmallintField *tbDiagonalCenLin;
  TDataSource *dsDiagonal;
  TTable *tbPoDiag;
  TIntegerField *tbPoDiagCodTeste;
  TSmallintField *tbPoDiagNumElem;
  TSmallintField *tbPoDiagNuDiag;
  TSmallintField *tbPoDiagPonto;
  TSmallintField *tbPoDiagColuna;
  TSmallintField *tbPoDiagLinha;
  TSmallintField *tbPoDiagCor;
  TDataSource *dsPoDiag;
  TIntegerField *tbElementoCodTeste;
  TSmallintField *tbElementoNumElem;
  TSmallintField *tbElementoNumPontos;
  TSmallintField *tbElementoCenCol;
  TSmallintField *tbElementoCenLin;
  TFloatField *tbElementoDistDiag;
  TFloatField *tbElementoDistElem;
  TStringField *tbElementoStatus;
private:	// User declarations
public:		// User declarations
  __fastcall TdmDados(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TdmDados *dmDados;
//---------------------------------------------------------------------------
#endif
