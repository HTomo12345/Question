Option Explicit

Dim endnum, numCount, i
Dim divisors()

numCount = InputBox("���鐔�̌�����͂��Ă�������")
CheckInput(numCount)

ReDim divisors(numCount - 1)

For i = 0 To numCount - 1
    divisors(i) = InputBox("���鐔" & (i + 1) & "����͂��Ă�������")
    CheckInput(divisors(i))
Next

endnum = InputBox("����̐�����͂��Ă�������")

For i = 1 To endnum
    Dim msg1,msg2
    msg1 = "" 
    msg2 = ""
    
    Dim divCount, j
    divCount = 0
    
    For j = 0 To UBound(divisors)
        If i Mod divisors(j) = 0 Then
            If divCount = 0 Then
                msg1 = msg1 & divisors(j) & "zz"
            End If
            msg2 = msg2 & divisors(j) & "zz"
            divCount = divCount + 1
        End If
    Next
    
    If divCount > UBound(divisors) Then
         MsgBox msg2
    elseIf msg1 <> "" then
         MsgBox msg1
    End If
    
Next

Sub CheckInput(Value)
    If Value = "" Then
        WScript.Quit
    elseIf IsNumeric(Value) = False Then
        WScript.Quit
    End If
End Sub