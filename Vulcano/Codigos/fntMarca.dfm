object frmMarca: TfrmMarca
  Left = 388
  Top = 329
  Width = 397
  Height = 289
  Caption = 'Manuten'#231#227'o de Marcas'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 6
    Top = 3
    Width = 107
    Height = 48
    Caption = ' C'#243'digo '
    TabOrder = 0
    object DBEdit1: TDBEdit
      Left = 8
      Top = 16
      Width = 90
      Height = 24
      TabStop = False
      Color = clSkyBlue
      DataField = 'Codigo'
      DataSource = dmDados.dsMarca
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
  end
  object GroupBox2: TGroupBox
    Left = 111
    Top = 3
    Width = 270
    Height = 48
    Caption = ' Marca '
    TabOrder = 1
    object DBEdit2: TDBEdit
      Left = 10
      Top = 16
      Width = 251
      Height = 24
      DataField = 'Marca'
      DataSource = dmDados.dsMarca
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
  end
  object DBNavigator1: TDBNavigator
    Left = 8
    Top = 56
    Width = 369
    Height = 27
    DataSource = dmDados.dsMarca
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbInsert, nbDelete, nbEdit, nbPost, nbCancel]
    TabOrder = 2
  end
  object JvDBGrid1: TJvDBGrid
    Left = 6
    Top = 88
    Width = 372
    Height = 154
    DataSource = dmDados.dsMarca
    ReadOnly = True
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
end
