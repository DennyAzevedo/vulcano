object frmPontoFisico: TfrmPontoFisico
  Left = 450
  Top = 427
  Width = 321
  Height = 150
  Caption = 'Coordenadas F'#237'sicas do Elemento'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object JvxLabel1: TJvxLabel
    Left = 82
    Top = 16
    Width = 57
    Height = 19
    Caption = 'Coluna'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object JvxLabel2: TJvxLabel
    Left = 82
    Top = 51
    Width = 45
    Height = 19
    Caption = 'Linha'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object edtColuna: TCSpinEdit
    Left = 149
    Top = 12
    Width = 70
    Height = 26
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object edtLinha: TCSpinEdit
    Left = 149
    Top = 47
    Width = 70
    Height = 26
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 84
    Width = 313
    Align = alBottom
    AutoSize = True
    ButtonHeight = 30
    ButtonWidth = 31
    Caption = 'ToolBar1'
    Flat = True
    Images = frmImagem.ImageList1
    TabOrder = 2
    object btnSair: TToolButton
      Left = 0
      Top = 0
      Caption = 'btnSair'
      ImageIndex = 10
      OnClick = btnSairClick
    end
  end
end
