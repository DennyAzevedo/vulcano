object dmDados: TdmDados
  OldCreateOrder = False
  Left = 473
  Top = 211
  Height = 392
  Width = 610
  object dsInspecao: TDataSource
    AutoEdit = False
    DataSet = tbInspecao
    Left = 16
    Top = 304
  end
  object dsParamet: TDataSource
    AutoEdit = False
    DataSet = tbParamet
    Left = 16
    Top = 255
  end
  object dsElemPara: TDataSource
    AutoEdit = False
    DataSet = tbElemPara
    Left = 75
    Top = 256
  end
  object dsPontoPara: TDataSource
    AutoEdit = False
    DataSet = tbPontosPara
    Left = 140
    Top = 257
  end
  object dsDiagPara: TDataSource
    AutoEdit = False
    DataSet = tbDiagPara
    Left = 204
    Top = 257
  end
  object tbInspecao: TTable
    Active = True
    DatabaseName = 'HRT'
    TableName = 'Inspecao.db'
    Left = 24
    Top = 72
    object tbInspecaoCodigo: TAutoIncField
      FieldName = 'Codigo'
      ReadOnly = True
    end
    object tbInspecaoDtInicio: TDateField
      FieldName = 'DtInicio'
    end
    object tbInspecaoHrInicio: TTimeField
      FieldName = 'HrInicio'
    end
    object tbInspecaoDtTermino: TDateField
      FieldName = 'DtTermino'
    end
    object tbInspecaoHrTermino: TTimeField
      FieldName = 'HrTermino'
    end
    object tbInspecaoStatus: TStringField
      FieldName = 'Status'
      Size = 1
    end
  end
  object tbParamet: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexFieldNames = 'CodInsp'
    MasterFields = 'Codigo'
    MasterSource = dsInspecao
    TableName = 'Paramet.db'
    Left = 56
    Top = 16
    object tbParametCodInsp: TIntegerField
      FieldName = 'CodInsp'
    end
    object tbParametCorBusca: TSmallintField
      FieldName = 'CorBusca'
    end
    object tbParametCorFundo: TSmallintField
      FieldName = 'CorFundo'
    end
    object tbParametTolSup: TSmallintField
      FieldName = 'TolSup'
    end
    object tbParametTolInf: TSmallintField
      FieldName = 'TolInf'
    end
    object tbParametPerc: TBooleanField
      FieldName = 'Perc'
    end
    object tbParametCorBDiag: TSmallintField
      FieldName = 'CorBDiag'
    end
    object tbParametCorFDiag: TSmallintField
      FieldName = 'CorFDiag'
    end
    object tbParametTipoDiag: TStringField
      FieldName = 'TipoDiag'
      Size = 1
    end
    object tbParametBaseDiag: TStringField
      FieldName = 'BaseDiag'
      Size = 1
    end
    object tbParametTolSupProp: TSmallintField
      FieldName = 'TolSupProp'
    end
    object tbParametTolInfProp: TSmallintField
      FieldName = 'TolInfProp'
    end
    object tbParametTolFalhas: TSmallintField
      FieldName = 'TolFalhas'
    end
    object tbParametEqualizado: TBooleanField
      FieldName = 'Equalizado'
    end
    object tbParametBinarizado: TBooleanField
      FieldName = 'Binarizado'
    end
    object tbParametNiveBin: TSmallintField
      FieldName = 'NiveBin'
    end
    object tbParametConvolucao: TBooleanField
      FieldName = 'Convolucao'
    end
    object tbParametMat0: TStringField
      FieldName = 'Mat0'
      Size = 1
    end
    object tbParametMat1: TStringField
      FieldName = 'Mat1'
      Size = 1
    end
    object tbParametMat2: TStringField
      FieldName = 'Mat2'
      Size = 1
    end
    object tbParametMat3: TStringField
      FieldName = 'Mat3'
      Size = 1
    end
    object tbParametMat4: TStringField
      FieldName = 'Mat4'
      Size = 1
    end
    object tbParametMat5: TStringField
      FieldName = 'Mat5'
      Size = 1
    end
    object tbParametMat6: TStringField
      FieldName = 'Mat6'
      Size = 1
    end
    object tbParametMat7: TStringField
      FieldName = 'Mat7'
      Size = 1
    end
    object tbParametMat8: TStringField
      FieldName = 'Mat8'
      Size = 1
    end
    object tbParametMat9: TStringField
      FieldName = 'Mat9'
      Size = 1
    end
  end
  object tbElemPara: TTable
    Active = True
    OnCalcFields = tbElemParaCalcFields
    DatabaseName = 'HRT'
    IndexName = 'iCodInsp'
    MasterFields = 'CodInsp'
    MasterSource = dsParamet
    TableName = 'ElemPara.DB'
    Left = 120
    Top = 16
    object tbElemParaCodInsp: TIntegerField
      FieldName = 'CodInsp'
    end
    object tbElemParaNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbElemParaNumPontos: TSmallintField
      FieldName = 'NumPontos'
    end
    object tbElemParaCenCol: TSmallintField
      FieldName = 'CenCol'
    end
    object tbElemParaCenLin: TSmallintField
      FieldName = 'CenLin'
    end
    object tbElemParaDistDiag: TFloatField
      FieldName = 'DistDiag'
    end
    object tbElemParaDistElem: TFloatField
      FieldName = 'DistElem'
    end
    object tbElemParaColFis: TSmallintField
      FieldName = 'ColFis'
    end
    object tbElemParaLinFis: TSmallintField
      FieldName = 'LinFis'
    end
    object tbElemParaProp: TFloatField
      FieldKind = fkCalculated
      FieldName = 'Prop'
      Calculated = True
    end
  end
  object tbPontosPara: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iInspElem'
    MasterFields = 'CodInsp;NumElem'
    MasterSource = dsElemPara
    TableName = 'PontosPara.DB'
    Left = 184
    Top = 16
    object tbPontosParaCodInsp: TIntegerField
      FieldName = 'CodInsp'
    end
    object tbPontosParaNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbPontosParaPonto: TSmallintField
      FieldName = 'Ponto'
    end
    object tbPontosParaColuna: TSmallintField
      FieldName = 'Coluna'
    end
    object tbPontosParaLinha: TSmallintField
      FieldName = 'Linha'
    end
    object tbPontosParaCor: TSmallintField
      FieldName = 'Cor'
    end
  end
  object tbDiagPara: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iInspElem'
    MasterFields = 'CodInsp;NumElem'
    MasterSource = dsElemPara
    TableName = 'DiagPara.db'
    Left = 120
    Top = 72
    object tbDiagParaCodInsp: TIntegerField
      FieldName = 'CodInsp'
    end
    object tbDiagParaNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbDiagParaNuDiag: TSmallintField
      FieldName = 'NuDiag'
    end
    object tbDiagParaCenCol: TSmallintField
      FieldName = 'CenCol'
    end
    object tbDiagParaCenLin: TSmallintField
      FieldName = 'CenLin'
    end
  end
  object tbPoDiagPara: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iInspElemDiag'
    MasterFields = 'CodInsp;NumElem;NuDiag'
    MasterSource = dsDiagPara
    TableName = 'PoDiagPara.db'
    Left = 184
    Top = 72
    object tbPoDiagParaCodInsp: TIntegerField
      FieldName = 'CodInsp'
    end
    object tbPoDiagParaNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbPoDiagParaNuDiag: TSmallintField
      FieldName = 'NuDiag'
    end
    object tbPoDiagParaPonto: TSmallintField
      FieldName = 'Ponto'
    end
    object tbPoDiagParaColuna: TSmallintField
      FieldName = 'Coluna'
    end
    object tbPoDiagParaLinha: TSmallintField
      FieldName = 'Linha'
    end
    object tbPoDiagParaCor: TSmallintField
      FieldName = 'Cor'
    end
  end
  object dsPoDiagPara: TDataSource
    AutoEdit = False
    DataSet = tbPoDiagPara
    Left = 271
    Top = 257
  end
  object dsPeca: TDataSource
    AutoEdit = False
    DataSet = tbPeca
    Left = 74
    Top = 304
  end
  object dsElemen: TDataSource
    AutoEdit = False
    DataSet = tbElemen
    Left = 139
    Top = 304
  end
  object dsPontos: TDataSource
    AutoEdit = False
    DataSet = tbPontos
    Left = 204
    Top = 306
  end
  object dsDiag: TDataSource
    AutoEdit = False
    DataSet = tbDiag
    Left = 271
    Top = 305
  end
  object tbPeca: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iCodInsp'
    MasterFields = 'Codigo'
    MasterSource = dsInspecao
    TableName = 'Peca.db'
    Left = 88
    Top = 128
    object tbPecaNumSerie: TStringField
      FieldName = 'NumSerie'
      Size = 30
    end
    object tbPecaCodInsp: TIntegerField
      FieldName = 'CodInsp'
    end
    object tbPecaData: TDateField
      FieldName = 'Data'
    end
    object tbPecaHora: TTimeField
      FieldName = 'Hora'
    end
    object tbPecaStatus: TStringField
      FieldName = 'Status'
      Size = 1
    end
  end
  object tbElemen: TTable
    Active = True
    OnCalcFields = tbElemenCalcFields
    DatabaseName = 'HRT'
    IndexName = 'iNumSerie'
    MasterFields = 'NumSerie'
    MasterSource = dsPeca
    TableName = 'Elemen.db'
    Left = 144
    Top = 128
    object tbElemenNumSerie: TStringField
      FieldName = 'NumSerie'
      Size = 30
    end
    object tbElemenNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbElemenNumPontos: TSmallintField
      FieldName = 'NumPontos'
    end
    object tbElemenCenCol: TSmallintField
      FieldName = 'CenCol'
    end
    object tbElemenCenLin: TSmallintField
      FieldName = 'CenLin'
    end
    object tbElemenDistDiag: TFloatField
      FieldName = 'DistDiag'
    end
    object tbElemenDistElem: TFloatField
      FieldName = 'DistElem'
    end
    object tbElemenStatus: TStringField
      FieldName = 'Status'
      Size = 1
    end
    object tbElemenProp: TFloatField
      FieldKind = fkCalculated
      FieldName = 'Prop'
      Calculated = True
    end
  end
  object tbPontos: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iSerEle'
    MasterFields = 'NumSerie;NumElem'
    MasterSource = dsElemen
    TableName = 'Pontos.db'
    Left = 200
    Top = 128
    object tbPontosNumSerie: TStringField
      FieldName = 'NumSerie'
      Size = 30
    end
    object tbPontosNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbPontosPonto: TSmallintField
      FieldName = 'Ponto'
    end
    object tbPontosColuna: TSmallintField
      FieldName = 'Coluna'
    end
    object tbPontosLinha: TSmallintField
      FieldName = 'Linha'
    end
    object tbPontosCor: TSmallintField
      FieldName = 'Cor'
    end
  end
  object dsPoDiag: TDataSource
    AutoEdit = False
    DataSet = tbPoDiag
    Left = 320
    Top = 305
  end
  object tbDiag: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iSerEle'
    MasterFields = 'NumSerie;NumElem'
    MasterSource = dsElemen
    TableName = 'Diag.db'
    Left = 144
    Top = 184
    object tbDiagNumSerie: TStringField
      FieldName = 'NumSerie'
      Size = 30
    end
    object tbDiagNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbDiagNuDiag: TSmallintField
      FieldName = 'NuDiag'
    end
    object tbDiagCenCol: TSmallintField
      FieldName = 'CenCol'
    end
    object tbDiagCenLin: TSmallintField
      FieldName = 'CenLin'
    end
  end
  object tbPoDiag: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iSerEleDia'
    MasterFields = 'NumSerie;NumElem;NuDiag'
    MasterSource = dsDiag
    TableName = 'PoDiag.db'
    Left = 200
    Top = 184
    object tbPoDiagNumSerie: TStringField
      FieldName = 'NumSerie'
      Size = 30
    end
    object tbPoDiagNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbPoDiagNuDiag: TSmallintField
      FieldName = 'NuDiag'
    end
    object tbPoDiagPonto: TSmallintField
      FieldName = 'Ponto'
    end
    object tbPoDiagColuna: TSmallintField
      FieldName = 'Coluna'
    end
    object tbPoDiagLinha: TSmallintField
      FieldName = 'Linha'
    end
    object tbPoDiagCor: TSmallintField
      FieldName = 'Cor'
    end
  end
  object tbTeste: TTable
    Active = True
    DatabaseName = 'HRT'
    TableName = 'Teste.db'
    Left = 320
    Top = 46
    object tbTesteCodTeste: TIntegerField
      FieldName = 'CodTeste'
    end
    object tbTesteCorBusca: TSmallintField
      FieldName = 'CorBusca'
    end
    object tbTesteCorFundo: TSmallintField
      FieldName = 'CorFundo'
    end
    object tbTesteTolSup: TSmallintField
      FieldName = 'TolSup'
    end
    object tbTesteTolInf: TSmallintField
      FieldName = 'TolInf'
    end
    object tbTestePerc: TBooleanField
      FieldName = 'Perc'
    end
    object tbTesteTolFalhas: TSmallintField
      FieldName = 'TolFalhas'
    end
    object tbTesteCorBDiag: TSmallintField
      FieldName = 'CorBDiag'
    end
    object tbTesteCorFDiag: TSmallintField
      FieldName = 'CorFDiag'
    end
    object tbTesteTipoDiag: TStringField
      FieldName = 'TipoDiag'
      Size = 1
    end
    object tbTesteBaseDiag: TStringField
      FieldName = 'BaseDiag'
      Size = 1
    end
    object tbTesteTolSupProp: TSmallintField
      FieldName = 'TolSupProp'
    end
    object tbTesteTolInfProp: TSmallintField
      FieldName = 'TolInfProp'
    end
    object tbTesteEqualizado: TBooleanField
      FieldName = 'Equalizado'
    end
    object tbTesteBinarizado: TBooleanField
      FieldName = 'Binarizado'
    end
    object tbTesteNiveBin: TSmallintField
      FieldName = 'NiveBin'
    end
    object tbTesteConvolucao: TBooleanField
      FieldName = 'Convolucao'
    end
    object tbTesteMat0: TStringField
      FieldName = 'Mat0'
      Size = 1
    end
    object tbTesteMat1: TStringField
      FieldName = 'Mat1'
      Size = 1
    end
    object tbTesteMat2: TStringField
      FieldName = 'Mat2'
      Size = 1
    end
    object tbTesteMat3: TStringField
      FieldName = 'Mat3'
      Size = 1
    end
    object tbTesteMat4: TStringField
      FieldName = 'Mat4'
      Size = 1
    end
    object tbTesteMat5: TStringField
      FieldName = 'Mat5'
      Size = 1
    end
    object tbTesteMat6: TStringField
      FieldName = 'Mat6'
      Size = 1
    end
    object tbTesteMat7: TStringField
      FieldName = 'Mat7'
      Size = 1
    end
    object tbTesteMat8: TStringField
      FieldName = 'Mat8'
      Size = 1
    end
    object tbTesteMat9: TStringField
      FieldName = 'Mat9'
      Size = 1
    end
  end
  object dsTeste: TDataSource
    AutoEdit = False
    DataSet = tbTeste
    Left = 368
    Top = 256
  end
  object tbElemTeste: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iCodTeste'
    MasterFields = 'CodTeste'
    MasterSource = dsTeste
    TableName = 'ElemTeste.db'
    Left = 384
    Top = 46
    object tbElemTesteCodTeste: TIntegerField
      FieldName = 'CodTeste'
    end
    object tbElemTesteNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbElemTesteNumPontos: TSmallintField
      FieldName = 'NumPontos'
    end
    object tbElemTesteCenCol: TSmallintField
      FieldName = 'CenCol'
    end
    object tbElemTesteCenLin: TSmallintField
      FieldName = 'CenLin'
    end
    object tbElemTesteDistDiag: TFloatField
      FieldName = 'DistDiag'
    end
    object tbElemTesteDistElem: TFloatField
      FieldName = 'DistElem'
    end
  end
  object tbPontosTeste: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iTesteElem'
    MasterFields = 'CodTeste;NumElem'
    MasterSource = dsElemTeste
    TableName = 'PontosTeste.db'
    Left = 460
    Top = 47
    object tbPontosTesteCodTeste: TIntegerField
      FieldName = 'CodTeste'
    end
    object tbPontosTesteNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbPontosTestePonto: TSmallintField
      FieldName = 'Ponto'
    end
    object tbPontosTesteColuna: TSmallintField
      FieldName = 'Coluna'
    end
    object tbPontosTesteLinha: TSmallintField
      FieldName = 'Linha'
    end
    object tbPontosTesteCor: TSmallintField
      FieldName = 'Cor'
    end
  end
  object tbDiagTeste: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iTesteElem'
    MasterFields = 'CodTeste;NumElem'
    MasterSource = dsElemTeste
    TableName = 'DiagTeste.db'
    Left = 385
    Top = 103
    object tbDiagTesteCodTeste: TIntegerField
      FieldName = 'CodTeste'
    end
    object tbDiagTesteNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbDiagTesteNuDiag: TSmallintField
      FieldName = 'NuDiag'
    end
    object tbDiagTesteCenCol: TSmallintField
      FieldName = 'CenCol'
    end
    object tbDiagTesteCenLin: TSmallintField
      FieldName = 'CenLin'
    end
  end
  object tbPoDiagTeste: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iTesteElemDiag'
    MasterFields = 'CodTeste;NumElem;NuDiag'
    MasterSource = dsDiagTeste
    TableName = 'PoDiagTeste.db'
    Left = 457
    Top = 102
    object tbPoDiagTesteCodTeste: TIntegerField
      FieldName = 'CodTeste'
    end
    object tbPoDiagTesteNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbPoDiagTesteNuDiag: TSmallintField
      FieldName = 'NuDiag'
    end
    object tbPoDiagTestePonto: TSmallintField
      FieldName = 'Ponto'
    end
    object tbPoDiagTesteColuna: TSmallintField
      FieldName = 'Coluna'
    end
    object tbPoDiagTesteLinha: TSmallintField
      FieldName = 'Linha'
    end
    object tbPoDiagTesteCor: TSmallintField
      FieldName = 'Cor'
    end
  end
  object dsElemTeste: TDataSource
    AutoEdit = False
    DataSet = tbElemTeste
    Left = 424
    Top = 256
  end
  object dsPoDiagTeste: TDataSource
    AutoEdit = False
    DataSet = tbPoDiagTeste
    Left = 497
    Top = 304
  end
  object dsPontosTeste: TDataSource
    AutoEdit = False
    DataSet = tbPontosTeste
    Left = 497
    Top = 256
  end
  object dsDiagTeste: TDataSource
    AutoEdit = False
    DataSet = tbDiagTeste
    Left = 425
    Top = 306
  end
end
