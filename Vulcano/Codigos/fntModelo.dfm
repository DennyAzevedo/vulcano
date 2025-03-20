object frmModelo: TfrmModelo
  Left = 363
  Top = 266
  Width = 397
  Height = 327
  Caption = 'Manuten'#231#227'o de Modelos'
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
      DataSource = dmDados.dsModelo
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
    object JvDBLookupCombo1: TJvDBLookupCombo
      Left = 7
      Top = 16
      Width = 254
      Height = 24
      DropDownCount = 8
      DataField = 'CodMarca'
      DataSource = dmDados.dsModelo
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      LookupField = 'Codigo'
      LookupDisplay = 'Marca'
      LookupSource = dmDados.dsMarca
      ParentFont = False
      TabOrder = 0
    end
  end
  object GroupBox3: TGroupBox
    Left = 6
    Top = 44
    Width = 376
    Height = 48
    Caption = 'Modelo'
    TabOrder = 2
    object DBEdit3: TDBEdit
      Left = 10
      Top = 16
      Width = 356
      Height = 24
      DataField = 'Modelo'
      DataSource = dmDados.dsModelo
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
    Top = 98
    Width = 369
    Height = 27
    DataSource = dmDados.dsModelo
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbInsert, nbDelete, nbEdit, nbPost, nbCancel]
    TabOrder = 3
  end
  object JvDBGrid1: TJvDBGrid
    Left = 6
    Top = 130
    Width = 372
    Height = 154
    DataSource = dmDados.dsModelo
    ReadOnly = True
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Marca'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Codigo'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Modelo'
        Visible = True
      end>
  end
end
