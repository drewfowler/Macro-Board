;AutoHotkey.ahk /in "AutoHotkey.ahk"

CurrentWindow = %A_ScriptDir%\CurrentWindow.txt

;~LButton::
;		FileDelete, %CurrentWindow%
;		FileAppend, Chrome, %CurrentWindow%
;return
	
#space::
	MsgBox AutoHotkey is Running
return

+F8::						;Hide Windows
	Send {LWin down}
	Send {d}
	Send {LWin up}
return



#IfWinActive ahk_exe mcuxpressoide.exe ;MCU expresso
{

	+F1::				;debug
		Send {CTRL down}
		Send {SHIFT down}
		Send {s}
		Send {CTRL up}
		Send {SHIFT up}
		Send {ALT down}
		Send {r}
		Send {g}
		Send {2}
		Send {ALT up}
	return
	
	+F2::				;Build
		Send {CTRL down}
		Send {b}
		Send {CTRL up}
	return
	
	+F3::				;clean build
		Send {ALT down}
		Send {p}
		Send {n}
		Send {ALT up}
		Send {ENTER}
	return
		
	
	+F4::				;Run Program
		Send {F8}
	return
	
	+F5::				;Terminate Debug
		Send {CTRL down}
		Send {F2}
		Send {CTRL up}
	return
	
	+F6::				;for loop
		SendRaw for(int i=0;i<x;i++)
		Send {ENTER}
		SendRaw {
		Send {ENTER}
		;SendRaw }
		;Send {Up}
		;Send {ENTER}
	return
	
	+F7::				;Step over
		Send {F6}
	return
	
	+F8::				;Comment
		Send {CTRL down}
		Send {/}
		Send {CTRL up}
	return
}
	
#IfWinActive ahk_exe javaw.exe ;Arduino
{

	
	+F2::					;Compile
		Send {CTRL down}
		Send {CTRL down}
		Send {r}
		Send {CTRL up}
	return
	
	+F3::					;Upload
		Send {CTRL down}
		Send {u}
		Send {CTRL up}
	return
}

#IfWinActive ahk_exe X2.EXE	;Altium
{

	
	+F1::					;Place Trace
		Send {p}
		Send {t}
	return 
	
	+F2::					;Remove Errors
		Send {t}
		Send {m}
		Send {ENTER}
	return 
	
	+F3::					;Run diagnostics
		Send {t}
		Send {d}
		Send {r}
		Send {ENTER}
	return 
	
	+F4::					;Switch Signal Layers
		Send {NumpadAdd}
	return 
	

	+F5::					;SHift s layer only
		Send {SHIFT down}}
		Send {s}
		Send {SHIFT up}
	return 
	
	+F7::					;Switch Signal Layers
		Send {NumpadMult}
	return 
}

#IfWinActive ahk_exe Chrome.exe
{

	
	+F1::					;New Tab
		Send {CTRL down}
		Send {t}
		Send {CTRL up}
	return
	
	
	+F2::					;Digikey
		Send {CTRL down}
		Send {t}
		Send {CTRL up}
		SendRaw d
		Send {ENTER}
	return
	
	+F3::					;Close tab
		Send {CTRL down}
		Send {w}
		Send {CTRL up}
	return	
	
	+F4::					;Craigslist
		Send {CTRL down}
		Send {t}
		Send {CTRL up}
		SendRaw b
		Send {ENTER}
	return
	
	+F6::					;Open previous tab	
		Send {CTRL down}
		Send {SHIFT down}
		Send {t}
		Send {CTRL up}
		Send {SHIFT up}
	return 
		
	
	+F7::					;Tab Forward
		Send {CTRL down}
		Send {TAB}
		Send {CTRL up}Tim4796!
		
	return
	
	
	+F8::					;Tab Backward
		Send {CTRL down}
		Send {LWin down}
		Send {NumpadLeft}
		Send {CTRL up}
		Send {LWin up}
	return
	
}

#IfWinActive ahk_exe IarIdePm.exe	;IAR
{
	+F1::					;Debug
		Send {CTRL down}
		Send {d}
		Send {CTRL up}
	return
	
	+F2::					;Make
		Send {F7}
	return
	
	+F3::					;Clean
		Send {CTRL down}
		Send {SHIFT down}
		Send {c}
		Send {CTRL up}
		Send {SHIFT up}
	return
	
	+F4::					;Run
		Send {F5}
	return
	
	+F5::					;Stop Debug
		Send {CTRL down}
		Send {SHIFT down}
		Send {d}
		Send {CTRL up}
		Send {SHIFT up}
	return
	
	+F6::					;Compile
		Send {CTRL down}
		Send {F7}
		Send {CTRL up}
	return
		
	+F7::					;Step Over
		Send {F10}
	return
	
	+F8::					;Comment
		Send {CTRL down}
		Send {k}
		Send {CTRL up}
	return
		
	
}



