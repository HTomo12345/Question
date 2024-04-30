Option Explicit

Dim i,endnum

endnum = InputBox("ãŒÀ‚Ì”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢")

For i = 1 To endnum
    If(i mod 3 = 0 AND i mod 5 = 0) then
        Msgbox("fizzbuzz")
    ElseIf(i mod 3 = 0) then
        Msgbox("fizz")
    ElseIf(i mod 5 = 0) then
        Msgbox("buzz")
    End If
Next