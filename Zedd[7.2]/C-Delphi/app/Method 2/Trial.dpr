program Trial;

uses
  Vcl.Forms,
  MyUnit in 'MyUnit.pas' {App};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TApp, App);
  Application.Run;
end.
