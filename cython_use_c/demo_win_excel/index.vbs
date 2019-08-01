Option Explicit

Private Declare Function great_function _
	Lib "C:\Users\tiany\Desktop\c_python\cython_use_c\demo_win_excel\dllmain.dll" _
	Alias "__great_function@8" _
	(ByVal a As String, ByVal b As Integer) _
	As Integer

Sub main()
	Dim sheet As Worksheet
	Set sheet = Worksheets(1)
	sheet.Cells(1,3).value = _
		Chr(great_function( _
			CStr(sheet.Cells(1, 1).Value), _
			CStr(sheet.Cells(1, 2).Value) _
		))

End Sub