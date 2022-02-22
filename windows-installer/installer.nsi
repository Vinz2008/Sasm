Name "Sasm-installer"
OutFile "sasm_installer.exe"
InstallDir $PROGRAMFILES\SASM
DirText "This installer will install the sasm compiler. Choose a directory"
Unicode True
Section ""
SetOutPath $INSTDIR
File ..\sasm.exe
WriteUninstaller $INSTDIR\Uninstall.exe
File .\PathEd.exe
ExecWait '$INSTDIR\PathEd.exe add "$INSTDIR"'
SectionEnd

Section "Uninstall"
Delete $INSTDIR\Uninstall.exe
Delete $INSTDIR\sasm.exe
Delete  "$INSTDIR\PathEd.exe"
RMDir $INSTDIR
Delete  "$SMPROGRAMS\Sasm\Sasm.lnk"
RMDir "$SMPROGRAMS\Sasm"
ExecWait '$INSTDIR\PathEd.exe remove "$INSTDIR"'
SectionEnd