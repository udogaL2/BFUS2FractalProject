; Имя приложения
#define   Name       "Fractal Generator"
; Версия приложения
#define   Version    "V1.0"
; Фирма-разработчик
#define   Publisher  "ShEvgy"
; Имя исполняемого модуля
#define   ExeName    "FractalGenerator.exe"

[Setup]
AppId={{3113320E-C7BE-409C-847E-25E83BD63B8D}
AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
DefaultDirName={pf}\{#Name}
DefaultGroupName={#Name}

OutputDir="G:\CLionProjects\fractal_project\output"
OutputBaseFileName=Fractal Generator setup

SetupIconFile="G:\CLionProjects\fractal_project\fractal.ico"

Compression=lzma
SolidCompression=yes

[Languages]
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"; LicenseFile: "License_RUS.txt"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[files]
Source: "G:\CLionProjects\fractal_project\installer\fractal_project.exe"; DestDir: "{app}"; Flags: ignoreversion; DestName: FractalGenerator.exe
Source: "G:\CLionProjects\fractal_project\installer\libgcc_s_seh-1.dll"; DestDir: "{app}"; Flags: ignoreversion; DestName: libgcc_s_seh-1.dll
Source: "G:\CLionProjects\fractal_project\installer\libstdc++-6.dll"; DestDir: "{app}"; Flags: ignoreversion; DestName: libstdc++-6.dll
Source: "G:\CLionProjects\fractal_project\installer\libwinpthread-1.dll"; DestDir: "{app}"; Flags: ignoreversion; DestName: libwinpthread-1.dll
Source: "G:\CLionProjects\fractal_project\installer\Qt6Core.dll"; DestDir: "{app}"; Flags: ignoreversion; DestName: Qt6Core.dll
Source: "G:\CLionProjects\fractal_project\installer\Qt6Gui.dll"; DestDir: "{app}"; Flags: ignoreversion; DestName: Qt6Gui.dll
Source: "G:\CLionProjects\fractal_project\installer\plugins\*"; DestDir: "{app}\plugins"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "G:\CLionProjects\fractal_project\installer\Qt6Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion; DestName: Qt6Widgets.dll

Source: "G:\CLionProjects\fractal_project\installer\VC_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall


[Icons]
Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"; IconFilename: "{app}\data\ico\dart.ico"; Tasks: desktopicon
Name: "{commondesktop}\{#Name}"; Filename: "{app}\{#ExeName}"; Tasks: desktopicon
[Run]
Filename: {tmp}\VC_redist.x64.exe; Parameters: "/q:a /c:""install /l /q"""; StatusMsg: VS redistributable package is installed. Please wait...