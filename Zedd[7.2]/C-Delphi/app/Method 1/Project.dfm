object App: TApp
  Left = 0
  Top = 0
  Caption = 'App'
  ClientHeight = 111
  ClientWidth = 333
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Size: TLabel
    Left = 5
    Top = 8
    Width = 19
    Height = 13
    Caption = 'Size'
  end
  object Show: TButton
    Left = 65
    Top = 3
    Width = 75
    Height = 25
    Caption = 'Show array'
    TabOrder = 0
    OnClick = ShowClick
  end
  object SEdit: TEdit
    Left = 28
    Top = 5
    Width = 33
    Height = 21
    Alignment = taRightJustify
    NumbersOnly = True
    TabOrder = 1
    Text = '5'
    OnChange = SEditChange
  end
  object Ara: TEdit
    Left = 144
    Top = 5
    Width = 185
    Height = 21
    ReadOnly = True
    TabOrder = 2
  end
  object Exit: TButton
    Left = 250
    Top = 83
    Width = 75
    Height = 25
    Caption = 'Exit'
    TabOrder = 3
    OnClick = ExitClick
  end
  object StE: TEdit
    Left = 8
    Top = 56
    Width = 112
    Height = 21
    TabOrder = 4
    OnChange = StEChange
  end
  object ResC: TEdit
    Left = 184
    Top = 56
    Width = 141
    Height = 21
    ReadOnly = True
    TabOrder = 5
  end
  object Copy: TButton
    Left = 121
    Top = 54
    Width = 62
    Height = 25
    Caption = 'Copy'
    TabOrder = 6
    OnClick = CopyClick
  end
end
