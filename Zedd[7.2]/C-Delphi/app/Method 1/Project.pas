unit Project;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, MyUnit, Vcl.StdCtrls;

type
  TApp = class(TForm)
    Size: TLabel;
    Show: TButton;
    SEdit: TEdit;
    Ara: TEdit;
    Exit: TButton;
    StE: TEdit;
    ResC: TEdit;
    Copy: TButton;
    procedure SEditChange(Sender: TObject);
    procedure ShowClick(Sender: TObject);
    procedure ExitClick(Sender: TObject);
    procedure StEChange(Sender: TObject);
    procedure CopyClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  App: TApp;

implementation

{$R *.dfm}

procedure TApp.CopyClick(Sender: TObject);
var
  N: Integer;
  Res: string;
begin
  ResC.Clear;

  N := copy_uniq(PChar(StE.Text), nil, 0);    // why N = 2 ?!

  SetLength(Res, N);

  if copy_uniq(PChar(StE.Text), PChar(Res), N) = 0 then
    ResC.Text := Res;
end;

procedure TApp.ExitClick(Sender: TObject);
begin
  Close;
end;

procedure TApp.SEditChange(Sender: TObject);
begin
  Ara.Clear;
end;

procedure TApp.ShowClick(Sender: TObject);
var
  I, N: Integer;
  A: array of Integer;
begin
  Ara.Clear;
  N := StrToInt(SEdit.Text);
  if (N > 48) then
    ShowMessage('Error: Such a big size! Try again..')
  else
  begin
    SetLength(A, N);
    Fill_Array(@A[0], N);
    for I := Low(A) to High(A) do
      Ara.Text := Ara.Text + IntToStr(A[I]) + #32;
  end;
end;

procedure TApp.StEChange(Sender: TObject);
begin
  ResC.Clear;
end;

end.
