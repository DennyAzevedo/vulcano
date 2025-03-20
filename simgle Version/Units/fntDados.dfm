object dmDados: TdmDados
  OldCreateOrder = False
  Left = 452
  Top = 277
  Height = 231
  Width = 312
  object tbTeste: TTable
    Active = True
    DatabaseName = 'HRT'
    TableName = 'Teste.db'
    Left = 24
    Top = 104
    object tbTesteCodigo: TAutoIncField
      FieldName = 'Codigo'
      ReadOnly = True
    end
    object tbTesteData: TDateField
      FieldName = 'Data'
    end
    object tbTesteHora: TTimeField
      FieldName = 'Hora'
    end
    object tbTesteCorBusca: TStringField
      FieldName = 'CorBusca'
    end
    object tbTesteIndCorBusca: TSmallintField
      FieldName = 'IndCorBusca'
    end
    object tbTesteCorDiagonal: TStringField
      FieldName = 'CorDiagonal'
    end
    object tbTesteIndCorDiagonal: TSmallintField
      FieldName = 'IndCorDiagonal'
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
  end
  object tbElemento: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iFKElemento'
    MasterFields = 'Codigo'
    MasterSource = dsTeste
    TableName = 'Elemento.db'
    Left = 24
    Top = 56
    object tbElementoCodTeste: TIntegerField
      FieldName = 'CodTeste'
    end
    object tbElementoNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbElementoNumPontos: TSmallintField
      FieldName = 'NumPontos'
    end
    object tbElementoCenCol: TSmallintField
      FieldName = 'CenCol'
    end
    object tbElementoCenLin: TSmallintField
      FieldName = 'CenLin'
    end
    object tbElementoDistDiag: TFloatField
      FieldName = 'DistDiag'
    end
    object tbElementoDistElem: TFloatField
      FieldName = 'DistElem'
    end
    object tbElementoStatus: TStringField
      FieldName = 'Status'
      Size = 1
    end
  end
  object tbPontos: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iFKPontos'
    MasterFields = 'CodTeste;NumElem'
    MasterSource = dsElemento
    TableName = 'Pontos'
    TableType = ttParadox
    Left = 24
    Top = 8
    object tbPontosCodTeste: TIntegerField
      FieldName = 'CodTeste'
    end
    object tbPontosNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbPontosNuPonto: TSmallintField
      FieldName = 'NuPonto'
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
  object dsPontos: TDataSource
    AutoEdit = False
    DataSet = tbPontos
    Left = 88
    Top = 8
  end
  object dsElemento: TDataSource
    AutoEdit = False
    DataSet = tbElemento
    Left = 88
    Top = 56
  end
  object dsTeste: TDataSource
    AutoEdit = False
    DataSet = tbTeste
    Left = 88
    Top = 104
  end
  object tbDiagonal: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexName = 'iFKDiag'
    MasterFields = 'CodTeste;NumElem'
    MasterSource = dsElemento
    TableName = 'Diag.db'
    Left = 152
    Top = 56
    object tbDiagonalCodTeste: TIntegerField
      FieldName = 'CodTeste'
    end
    object tbDiagonalNumElem: TSmallintField
      FieldName = 'NumElem'
    end
    object tbDiagonalNuDiag: TSmallintField
      FieldName = 'NuDiag'
    end
    object tbDiagonalCenCol: TSmallintField
      FieldName = 'CenCol'
    end
    object tbDiagonalCenLin: TSmallintField
      FieldName = 'CenLin'
    end
  end
  object dsDiagonal: TDataSource
    AutoEdit = False
    DataSet = tbDiagonal
    Left = 208
    Top = 56
  end
  object tbPoDiag: TTable
    Active = True
    DatabaseName = 'HRT'
    IndexFieldNames = 'CodTeste;NumElem;NuDiag'
    MasterFields = 'CodTeste;NumElem;NuDiag'
    MasterSource = dsDiagonal
    TableName = 'PoDiag.db'
    Left = 152
    Top = 8
    object tbPoDiagCodTeste: TIntegerField
      FieldName = 'CodTeste'
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
  object dsPoDiag: TDataSource
    AutoEdit = False
    DataSet = tbPoDiag
    Left = 209
    Top = 8
  end
end
