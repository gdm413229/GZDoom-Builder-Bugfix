; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=Ultimate Doom Builder
AppVerName=Ultimate Doom Builder
AppPublisher=ZZYZX
AppPublisherURL=https://forum.zdoom.org/memberlist.php?mode=viewprofile&u=7527
AppSupportURL=https://forum.zdoom.org/viewtopic.php?f=232&t=66745
AppUpdatesURL=https://devbuilds.drdteam.org/ultimatedoombuilder/
DefaultDirName={pf}\GZDoom Builder
DefaultGroupName=GZDoom Builder
AllowNoIcons=true
LicenseFile=..\LICENSE.txt
OutputDir=..\Release
OutputBaseFilename=Setup
Compression=lzma/ultra64
SolidCompression=true
SourceDir=..\Build
SetupLogging=false
AppMutex=gzdoombuilder
PrivilegesRequired=admin
ShowLanguageDialog=no
LanguageDetectionMethod=none
MinVersion=0,6.0
UninstallDisplayIcon={app}\Updater.exe
WizardImageFile=..\Setup\WizModernImage-IS.bmp
WizardSmallImageFile=..\Setup\WizModernSmallImage-IS.bmp

[Languages]
Name: english; MessagesFile: compiler:Default.isl

[Tasks]
Name: desktopicon; Description: {cm:CreateDesktopIcon}; GroupDescription: {cm:AdditionalIcons}; Flags: unchecked

[Files]
Source: Setup\dotnetfx35setup.exe; DestDir: {tmp}; Flags: dontcopy
Source: Setup\vcredist_x86.exe; DestDir: {tmp}; Flags: dontcopy
Source: Builder.exe; DestDir: {app}; Flags: ignoreversion
Source: GZBuilder.default.cfg; DestDir: {app}; Flags: ignoreversion
Source: Updater.exe; DestDir: {app}; Flags: ignoreversion
Source: Updater.ini; DestDir: {app}; Flags: ignoreversion
Source: Refmanual.chm; DestDir: {app}; Flags: ignoreversion
Source: DevIL.dll; DestDir: {app}; Flags: ignoreversion
Source: SharpCompress.dll; DestDir: {app}; Flags: ignoreversion
Source: ScintillaNET.dll; DestDir: {app}; Flags: ignoreversion
Source: TabControlEX.dll; DestDir: {app}; Flags: ignoreversion
Source: LICENSE.txt; DestDir: {app}; Flags: ignoreversion
Source: Compilers\*; DestDir: {app}\Compilers; Flags: ignoreversion recursesubdirs
Source: Configurations\*; DestDir: {app}\Configurations; Flags: ignoreversion recursesubdirs
Source: Scripting\*; DestDir: {app}\Scripting; Flags: ignoreversion recursesubdirs
Source: Snippets\*; DestDir: {app}\Snippets; Flags: ignoreversion recursesubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files
Source: Plugins\BuilderModes.dll; DestDir: {app}\Plugins; Flags: ignoreversion
Source: Plugins\BuilderEffects.dll; DestDir: {app}\Plugins; Flags: ignoreversion
Source: Plugins\ColorPicker.dll; DestDir: {app}\Plugins; Flags: ignoreversion
Source: Plugins\CommentsPanel.dll; DestDir: {app}\Plugins; Flags: ignoreversion
Source: Plugins\NodesViewer.dll; DestDir: {app}\Plugins; Flags: ignoreversion
Source: Plugins\SoundPropagationMode.dll; DestDir: {app}\Plugins; Flags: ignoreversion
Source: Plugins\StairSectorBuilder.dll; DestDir: {app}\Plugins; Flags: ignoreversion
Source: Plugins\TagExplorer.dll; DestDir: {app}\Plugins; Flags: ignoreversion
Source: Plugins\TagRange.dll; DestDir: {app}\Plugins; Flags: ignoreversion
Source: Plugins\VisplaneExplorer.dll; DestDir: {app}\Plugins; Flags: ignoreversion
Source: Plugins\Loadorder.cfg; DestDir: {app}\Plugins; Flags: ignoreversion onlyifdoesntexist
Source: Sprites\*; DestDir: {app}\Sprites; Flags: ignoreversion recursesubdirs
Source: Textures\*; DestDir: {app}\Textures; Flags: ignoreversion

[Icons]
Name: {group}\GZDoom Builder; Filename: {app}\Builder.exe
Name: {group}\{cm:UninstallProgram,GZDoom Builder}; Filename: {uninstallexe}
Name: {commondesktop}\GZDoom Builder; Filename: {app}\Builder.exe; Tasks: desktopicon

[UninstallDelete]
Name: {app}; Type: filesandordirs

[InstallDelete]
Name: {app}\Builder.pdb; Type: files
Name: {app}\Builder.xml; Type: files

[Registry]
Root: HKLM; Subkey: SOFTWARE\MaxED\GZDoom Builder\; ValueType: string; ValueName: Location; ValueData: {app}; Flags: uninsdeletevalue

[Messages]
ReadyLabel2a=Continue to begin with the installation, or click Back if you want to review or change any settings.

[Code]
// Global variables
var
	page_info_net: TOutputMsgWizardPage;
	page_info_netfailed: TOutputMsgWizardPage;
	page_setup_net: TOutputProgressWizardPage;
	page_info_vc: TOutputMsgWizardPage;
	page_info_vcfailed: TOutputMsgWizardPage;
	page_setup_vc: TOutputProgressWizardPage;
	restartneeded: Boolean;
	netinstallfailed: Boolean;
	netisinstalled: Boolean;
	vcinstallfailed: Boolean;
	vcisinstalled: Boolean;

// Prerequisites checks
function CheckNetIsInstalled(): Boolean;
begin
	Result := RegKeyExists(HKLM, 'SOFTWARE\Microsoft\NET Framework Setup\NDP\v3.5') or
					  RegKeyExists(HKLM, 'SOFTWARE\Wow6432Node\Microsoft\NET Framework Setup\NDP\v3.5');
end;

function CheckVCIsInstalled(): Boolean;
begin
	//mxd. Any VC++ 2008 package will do, I assume...
	//mxd. Registry values gartered from http://blogs.msdn.com/b/astebner/archive/2009/01/29/9384143.aspx
	Result := RegKeyExists(HKLM, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{1F1C2DFC-2D24-3E06-BCB8-725134ADF989}') or
			  RegKeyExists(HKLM, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{9A25302D-30C0-39D9-BD6F-21E6EC160475}') or
			  RegKeyExists(HKLM, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{FF66E9F6-83E7-3A3E-AF14-8DE9A809A6A4}');
end;

// When the wizard initializes
procedure InitializeWizard();
begin
	restartneeded := false;
	netinstallfailed := false;
	netisinstalled := CheckNetIsInstalled();
	vcinstallfailed := false;
	vcisinstalled := CheckVCIsInstalled();

	// Create .NET Framework pages
	page_info_net := CreateOutputMsgPage(wpPreparing,
		'Installing Microsoft .NET Framework 3.5', '',
		'Setup has detected that your system is missing the required version of the Microsoft .NET Framework. ' +
		'Setup will now install or update your Microsoft .NET Framework. This may take several minutes to complete.' + #10 + #10 +
		'WARNING: The installer will download the Microsoft .NET Framework from the internet, but the progress bar will not ' +
		'go forward until the download is complete. You may send Microsoft an angry letter about that.' + #10 + #10 +
		'Click Install to begin.');

	page_info_netfailed := CreateOutputMsgPage(page_info_net.ID,
		'Installing Microsoft .NET Framework  3.5', '',
		'Setup could not install the Microsoft .NET Framework  3.5.' + #10 + #10 +
		'Click Back to try again, or Cancel to exit Setup.');

	page_setup_net := CreateOutputProgressPage('Installing Microsoft .NET Framework 3.5', 'Setup is installing Microsoft .NET Framework 3.5, please wait...');

	// Create VC++ 2008 pages
	page_info_vc := CreateOutputMsgPage(wpPreparing,
		'Installing Visual C++ 2008 SP1 ATL Security Update', '',
		'Setup has detected that your system is missing the required version of the Visual C++ Runtime. ' +
		'Setup will now install or update your Visual C++ Runtime. This may take several minutes to complete.' + #10 + #10 +
		'Click Install to begin.');

	page_info_vcfailed := CreateOutputMsgPage(page_info_net.ID,
		'Installing Visual C++ 2008 SP1 ATL Security Update', '',
		'Setup could not install Visual C++ 2008 SP1 ATL Security Update.' + #10 + #10 +
		'Click Back to try again, or Cancel to exit Setup.');

	page_setup_vc := CreateOutputProgressPage('Installing Visual C++ 2008 SP1 ATL Security Update', 'Setup is installing Visual C++ 2008 SP1 ATL Security Update, please wait...');
end;

// This is called to check if a page must be skipped
function ShouldSkipPage(PageID: Integer): Boolean;
begin
	if(PageID = page_info_net.ID) then // Skip .NET pages?
		Result := netisinstalled
	else if(PageID = page_info_netfailed.ID) then
		Result := (not netinstallfailed) and netisinstalled
	else if(PageID = page_info_vc.ID) then // Skip VC++ pages?
		Result := vcisinstalled
	else if(PageID = page_info_vcfailed.ID) then
		Result := (not vcinstallfailed) and vcisinstalled
	else
		Result := false;
end;

// This is called to determine if we need to restart
function NeedRestart(): Boolean;
begin
	Result := restartneeded;
end;

// This is called when the current page changes
procedure CurPageChanged(CurPageID: Integer);
begin
	if(CurPageID = wpReady) then begin
		if(netisinstalled = false) or (vcisinstalled = false) then
			WizardForm.NextButton.Caption := 'Next';
	end
	else if(CurPageID = page_info_net.ID) or (CurPageID = page_info_vc.ID) then begin
		WizardForm.NextButton.Caption := 'Install';
	end
	else if(CurPageID = page_info_netfailed.ID) or (CurPageID = page_info_vcfailed.ID) then begin
		WizardForm.NextButton.Visible := true;
		WizardForm.NextButton.Enabled := false;
		WizardForm.BackButton.Visible := true;
		WizardForm.BackButton.Enabled := true;
		WizardForm.CancelButton.Visible := true;
		WizardForm.CancelButton.Enabled := true;
	end;
end;

// This is called when the Next button is clicked
function NextButtonClick(CurPage: Integer): Boolean;
var
	errorcode: Integer;
	tempfile: String;
begin

	// Next pressed on .NET info page?
	if(CurPage = page_info_net.ID) then begin
		// Show progress page and run setup
		page_setup_net.Show;
		try
		begin
			netinstallfailed := false;
			ExtractTemporaryFile('dotnetfx35setup.exe');
			// We copy the file to the real temp directory so that it isn't removed when Setup is closed.
			// Judging from the return codes, this installer may want to run again after a reboot.
			// See the return codes here: http://msdn.microsoft.com/en-us/library/cc160716.aspx
			tempfile := RemoveBackslash(GetTempDir()) + '\dotnetfx35setup.exe';
			FileCopy(ExpandConstant('{tmp}\dotnetfx35setup.exe'), tempfile, false);
			Exec(tempfile, '/qb /norestart', '', SW_SHOW, ewWaitUntilTerminated, errorcode);

			if((errorcode = 1641) or (errorcode = 3010)) then begin
				// Success, but restart needed!
				restartneeded := true;
			end
			else if(errorcode <> 0) then begin
				netinstallfailed := true;
			end;

			netisinstalled := CheckNetIsInstalled();
		end
		finally
			page_setup_net.Hide;
		end;
	end
	// Next pressed on VC info page?
	else if(CurPage = page_info_vc.ID) then begin
		// Show progress page and run setup
		page_setup_vc.Show;
		try
		begin
			vcinstallfailed := false;
			ExtractTemporaryFile('vcredist_x86.exe');
			// We copy the file to the real temp directory so that it isn't removed when Setup is closed.
			// Judging from the return codes, this installer may want to run again after a reboot.
			// See the return codes here: http://blogs.msdn.com/b/astebner/archive/2010/10/20/10078468.aspx
			tempfile := RemoveBackslash(GetTempDir()) + '\vcredist_x86.exe';
			FileCopy(ExpandConstant('{tmp}\vcredist_x86.exe'), tempfile, false);
			Exec(tempfile, '/q /norestart', '', SW_SHOW, ewWaitUntilTerminated, errorcode);

			if(errorcode = 3010) then begin
				// Success, but restart needed!
				restartneeded := true;
			end
			else if(errorcode <> 0) then begin
				vcinstallfailed := true;
			end;

			vcisinstalled := CheckVCIsInstalled();
		end
		finally
			page_setup_vc.Hide;
		end;
	end;

	Result := True;
end;

//Remove configs?
procedure DeinitializeUninstall();
begin
	if MsgBox('Delete map restore data and program configuration files?', mbConfirmation, MB_YESNO) = IDYES then
	begin
		// Remove restore data
		DelTree(ExpandConstant('{localappdata}\Doom Builder\Restore'), True, True, True);

		// Remove configs
		DeleteFile(ExpandConstant('{localappdata}\Doom Builder\GZBuilder.cfg'));
		DeleteFile(ExpandConstant('{localappdata}\Doom Builder\GZBuilder.log'));
		DeleteFile(ExpandConstant('{localappdata}\Doom Builder\GZCrash.txt'));
	end;
end;