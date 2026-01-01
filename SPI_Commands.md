# Commands listed in GU-D series “General Function” Software Specification

## Character code:
- [Code] 20h–FFh or 2-byte character code
[Function] Display character at cursor position.
- [Code] 08h
[Function] Cursor moves to the left by one character
- [Code] 09h
[Function] Cursor moves to the right by one character.
- [Code] 0Ah
[Function] Cursor moves to next lower line.
- [Code] 0Bh
[Function] Cursor moves to home position (top left).
- [Code] 0Dh
[Function] Cursor moves to left end of current line.
- [Code] 0Ch
[Function] Display screen is cleared
- [Code] 10h - 14h
[Function] Select current window (1-byte command).

## General setting xommand group:
- [Code] 1Bh 40h
[Function] Settings return to default values
- [Code] 1Fh 24h xL xH yL yH
xL: Cursor position x, lower byte (1 dot / unit)
xH: Cursor position x, upper byte (1 dot / unit)
yL: Cursor position y, lower byte (8 dots / unit)
yH: Cursor position y, upper byte (8 dots / unit)
[Definable area]
0000h ≤ (xL + xH × 100h) ≤ Max_Xdot
0000h ≤ (yL + yH × 100h) ≤ Max_Ybyte
[Function] Cursor moves to the specified (X, Y) position on Display Memory.
- [Code] 1Fh 43h n
[Definable area]
n = 00h, 01h
n = 00h: Cursor display OFF
n = 01h: Cursor display ON
[Default] n = 00h
[Function] Cursor display setting.
- [Code] 1Fh 58h n
[Definable area]
01h ≤ n ≤ 08h
[Default] n = 08h
[Function] Set display brightness level.
- [Code] 1Fh 72h n
[Definable area]
n = 00h, 01h
n = 00h: Reverse OFF
n = 01h: Reverse ON
[Default] n = 00h
[Function] Reverse display ON/OFF for character and image display.
- [Code] 1Fh 77h n
[Definable area]
00h ≤ n ≤ 03h
n = 00h: Normal display write (not mixture display)
n = 01h: OR display write
n = 02h: AND display write
n = 03h: EX-OR display write
[Default] n = 00h
[Function] Specifies write mixture mode

## Cursor mode command group:
- [Code] 1Fh 01h
[Function] Cursor mode set to Over-write mode.
- Code] 1Fh 02h
[Function] Cursor mode set to Vertical scroll mode.
- [Code] 1Fh 03h
[Function] Cursor mode set to Horizontal scroll mode.
- [Code] 1Fh 73h n
[Definable area]
00h ≤ n ≤ 1Fh
[Default] n = 00h
[Function] Set speed for Horizontal scroll mode

## Font commadn group:
- [Code] 1Fh 28h 67h 01h m
[Definable area]
m = 01h, 02h
[Default] m = 01h
[Function] Sets the font size for 1-byte characters
- [Code] 1Fh 28h 67h 02h m
[Definable area]
m = 00h, 01h
[Default] m = 00h
[Function] Sets 2-byte character ON/OFF
- [Code] 1Fh 28h 67h 0Fh m
[Definable area]
00h ≤ m ≤ 03h
[Default] m = 00h
[Function] Sets 2-byte character type
- [Code] 1Fh 28h 67h 03h w
[Definable area]
00h ≤ w ≤ 03h
w = 00h: Fixed character width 1 (1 dot space on right side)
w = 01h: Fixed character width 2 (1 dot space on right side and left side)
w = 02h: Proportional character width 1 (1 dot space on right side)
w = 03h: Proportional character width 2 (1 dot space on right side and left side)
[Default] w = 01h
[Function] Sets the character width
- [Code] 1Fh 28h 67h 40h x y
x: X magnification factor
y: Y magnification factor
[Definable area]
01h ≤ x ≤ 04h
01h ≤ y ≤ 02h
[Default] x = 01h
y = 01h
[Function] Set character magnification ‘x’ times to the right and ‘y’ times downward.
・Character magnification includes the space specified by Font Width command.
- [Code] 1Bh 52h n
[Definable area]
00h ≤ n ≤ 0Dh
[Default] n = 00h
[Function] Select international font set.
- [Code] 1Bh 74h n
[Definable area]
00h ≤ n ≤ 05h, 10h ≤ n ≤ 13h
[Default] n = 00h
[Function] Select Character table type.
- [Code] 1Bh 25h n
[Definable area]
n = 00h, 01h
[Default] n = 00h
[Function] Enable or disable display of download characters.
- [Code] 1Bh 26h a c1 c2 [x1 d1…d(a×x1)]…[xk d1…d(a×xk)]
a: Select character type
c1: Start character code
c2: End character code
x: Number of dots for X-direction
d: Definition data
[Definable area]
a = 01h
x = 05h, 07h
x = 05h: 5×7 dot font
x = 07h: 7×8 dot font
20h ≤ c1 ≤ c2 ≤ FFh
00h ≤ d ≤ FFh
x = 05h: Upper 7 bits are valid.
x = 07h: All 8 bits are valid.
k = (c2 - c1) + 1
[Function] Define download characters (1-byte characters) into RAM.
- [Code] 1Bh 3Fh a c
a: Select character type
c : Delete Character code
[Definable area]
a = 01h
20h ≤ c ≤ FFh
[Function] Delete defined download character.

## Display action command group:
- [Code] 1Fh 28h 61h 01h t
[Definable area]
00h ≤ t ≤ FFh
[Function] Waits for the specified time (command and data processing is stopped)
- [Code] 1Fh 28h 61h 10h wL wH cL cH s
wL: Display screen shift byte count, lower byte
wH: Display screen shift byte count, upper byte
cL: Number of cycles, lower byte
cH: Number of cycles, upper byte
s: Scroll speed
[Definable area]
0000h ≤ (wL + wH × 100h) ≤ Max_DispMemAddr
0001h ≤ (cL + cH × 100h) ≤ FFFFh
00h ≤ s ≤ FFh
[Function] Shift the display screen.
- [Code] 1Fh 28h 61h 11h p t1 t2 c
p: Blink pattern
t1: Normal display time
t2: Blank or reverse display time
c: Number of cycles
[Definable area]
00h ≤ p ≤ 02h
p = 00h: Normal display
p = 01h: Blink display (alternately Normal and Blank display)
p = 02h: Blink display (alternately Normal and Reverse display)
01h ≤ t1 ≤ FFh
01h ≤ t2 ≤ FFh
00h ≤ c ≤ FFh
[Function] Blink display action
- [Code] 1Fh 28h 61h 40h p
[Definable area]
00h ≤ p ≤ 04h
p = 00h: Display power OFF (Power save mode)
p = 01h: Display power ON
p = 02h: All dot OFF
p = 03h: All dot ON
p = 04h: Repeat blink display with normal and reverse display
(Normal: 2s, Reverse: 2s)
[Function] Control Power ON or OFF, and Start Screen saver mode

## Bit image display command group:
- [Code] 1Fh 28h 66h 10h m aL aH aE ySL ySH xL xH yL yH g
m: Select bit image data memory = 1 (fixed)
aL: Bit image data definition address, lower byte
aH: Bit image data definition address, upper byte
aE: Bit image data definition address, extension byte
ySL: Bit image defined Y size, lower byte (by 8 dots)
ySH: Bit image defined Y size, upper byte (by 8 dots)
xL: Bit image display X size, lower byte (by 1 dot)
xH: Bit image display X size, upper byte (by 1 dot)
yL: Bit image display Y size, lower byte (by 8 dots)
yH: Bit image display Y size, upper byte (by 8 dots)
g: Image information = 1 (fixed)
[Definable area]
m = 01h
000000h ≤ (aL + aH × 100h + aE × 10000h) ≤ 07FFFFh
0000h ≤ (ySL + ySH × 100h) ≤ FFFFh
0001h ≤ (xL + xH × 100h) ≤ Xdots
0001h ≤ (yL + yH × 100h) ≤ Ybytes
g = 01h
[Function] Display, at the cursor position, the bit image defined in FROM.
- 5.2.5.2 <Function 11h> Real-time bit image display [ US ( f 11h xL xH yL yH g d(1)...d(k) ]
[Code] 1Fh 28h 66h 11h xL xH yL yH g d(1)...d(k)
xL: Bit image X size, lower byte (by 1 dot)
xH: Bit image X size, upper byte (by 1 dot)
yL: Bit image Y size, lower byte (by 8 dots)
yH: Bit image Y size, upper byte (by 8 dots)
g: Image information = 1 (fixed)
d(1)–d(k): Bit image data (see below)
[Definable area]
0001h ≤ (xL + xH × 100h) ≤ Xdots
0001h ≤ (yL + yH × 100h) ≤ Ybyt

es
g = 01h
00h ≤ d ≤ FFh
k = x × y × g
[Function] Display the bit image data at the cursor position in real-time.
・Cursor position does not change.
・If bit image exceeds the bounds of the current window, only the portion within the current window
is displayed.
・If Display position or display size etc, are outside the definable area, the command is cancelled at
the point where the error is detected, and the remaining data is treated as standard data.

## Dot unit control command group:
- [Code] 1Fh 28h 64h 20h xPL xPH yPL yPH m aL aH aE ySL ySH xOL xOH yOL yOH xL xH yL yH 01h
xPL: Display position x, lower byte (by 1 dot)
xPH: Display position x, upper byte (by 1 dot)
yPL: Display position y, lower byte (by 1 dot)
yPH: Display position y, upper byte (by 1 dot)
m: Image data display memory select
aL: Bit image data definition address, lower byte
aH: Bit image data definition address, upper byte
aE: Bit image data definition address, extension byte
ySL: Bit image defined, Y size, lower byte (by 8 dots)
ySH: Bit image defined, Y size, upper byte (by 8 dots)
xOL: Image data offset x, lower byte (by 1 dot)
xOH: Image data offset x, upper byte (by 1 dot)
yOL: Image data offset y, lower byte (by 1 dot)
yOH: Image data offset y, upper byte (by 1 dot)
xL: Bit image display X size, lower byte (by 1 dot)
xH: Bit image display X size, upper byte (by 1 dot)
yL: Bit image display Y size, lower byte (by 1 dot)
yH: Bit image display Y size, upper byte (by 1 dot)
g: Image information = 1 (fixed)
[Definable area]
0000h ≤ (xPL + xPH × 100h) ≤ Max_Xdot_CurtWin
0000h ≤ (yPL + yPH × 100h) ≤ Max_Ydot_CurtWin
01h ≤ m ≤ 02h
m = 01h: FROM bit image
m = 02h: Display Memory bit image
FROM bit image:
000000h ≤ (aL + aH × 100h + aE × 10000h) ≤ 07FFFFh
0000h ≤ (ySL + ySH × 100h) ≤ FFFFh
0000h ≤ (xOL + xOH × 100h) ≤ FFFFh
0000h ≤ (yOL + yOH × 100h) ≤ FFFFh
Display Memory bit image:
(aL + aH×100h + aE × 10000 h) = XXXXXXh (fixed internally at 000000h)
(ySL + ySH × 100h) = 0000h
0000h ≤ (xOL + xOH × 100h) ≤ Max_Xdot
0000h ≤ (yOL + yOH × 100h) ≤ Max_Ydot
0001h ≤ (xL + xH × 100h) ≤ Xdots
0001h ≤ (yL + yH × 100h) ≤ Ydots
g = 01h
[Function] Display the bit image defined in FROM at the specified (x,y) position.
- [Code] 1Fh 28h 64h 21h xPL xPH yPL yPH xL xH yL yH g d(1)...d(k)
xPL: Display position x, lower byte (by 1 dot)
xPH: Display position x, upper byte (by 1 dot)
yPL: Display position y, lower byte (by 1 dot)
yPH: Display position y, upper byte (by 1 dot)
xL: Bit image display X size, lower byte (by 1 dot)
xH: Bit image display X size, upper byte (by 1 dot)
yL: Bit image display Y size, lower byte (by 1 dot)
yH: Bit image display Y size, upper byte (by 1 dot)
g: Display information = 1 (fixed)
d(1)–d(k): Bit image data (see below)
[Definable area]
0000h ≤ (xPL + xPH × 100h) ≤ Max_Xdot_CurtWin
0000h ≤ (yPL + yPH × 100h) ≤ Max_Ydot_CurtWin
0001h ≤ (xL + xH × 100h) ≤ Xdots
0001h ≤ (yL + yH × 100h) ≤ Ydots
g = 01h
00h ≤ d ≤ FFh
[Function] Display the bit image data at the specified (x,y) position in real-time.
- [Code] 1Fh 28h 64h 30h xPL xPH yPL yPH m bLen d(1)...d(bLen)
xPL: Display position x, lower byte (by 1 dot)
xPH: Display position x, upper byte (by 1 dot)
yPL: Display position y, lower byte (by 1 dot)
yPH: Display position y, upper byte (by 1 dot)
m: Response select
bLen: Character data length
d(1)–d(bLen): Character data / reverse select
[Definable area]
0000h ≤ (xPL + xPH × 100h) ≤ Max_Xdot_CurtWin, FFFFh
0000h ≤ (yPL + yPH × 100h) ≤ Max_Ydot_CurtWin
m = 00h (fixed)
00h ≤ bLen ≤ FFh
10h ≤ d ≤ 11h、20h ≤ d ≤ FFh
d = 10h: Reverse OFF
d = 11h: Reverse ON
[Function] Display the specified text characters at the specified (x,y) position.

## Window / screen command group
- [Code] 1Fh 28h 77h 10h a
[Definable area]
a = 00h, 01h
a = 00h: Display screen mode
a = 01h: All screen mode
[Default] a = 00h
[Function] Select the write screen mode.
- [Code] 1Fh 28h 77h 01h a
[Definable area]
00h ≤ a ≤ 04h
a = 00h: Base-Window
a = 01h: User-Window 1
a = 02h: User-Window 2
a = 03h: User-Window 3
a = 04h: User-Window 4
[Function] Select current window.
- [Code] 1Fh 28h 77h 02h a b [xPL xPH yPL yPH xSL xSH ySL ySH]
a: Definable window No.
b: Define or Cancel
xPL: Left position of window x, lower byte (by 1 dot)
xPH: Left position of window x, upper byte (by 1 dot)
yPL: Top position of window y, lower byte (by 8 dot)
yPH: Top position of window y, upper byte (by 8 dot)
xSL: X size of window, lower byte (by 1 dot)
xSH: X size of window, upper byte (by 1 dot)
ySL: Y size of window, lower byte (by 8 dot)
ySH: Y size of window, upper byte (by 8 dot)
[Definable area]
01h ≤ a ≤ 04h
a = 01h: User-Window 1
a = 02h: User-Window 2
a = 03h: User-Window 3
a = 04h: User-Window 4
b = 00h, 01h
b = 0: Cancel、b = 1: Define
0000h ≤ (xPL + xPH × 100h) ≤ Max_Xdot
0000h ≤ (yPL + yPH × 100h) ≤ Max_Ybyte
0001h ≤ (xSL + xSH × 100h) ≤ (Xdots - (xPL + xPH × 100h))
0001h ≤ (ySL + ySH × 100h) ≤ (Ybytes - (yPL + yPH × 100h))
[Function] Define or cancel User-Window

## General-purpose I/O port command group
- [Code] 1Fh 28h 70h 01h n a
n: I/O port number
a: Set Input / Output (bit-wise)
[Definable area]
n = 00h: Port 0
00h ≤ a ≤ 0Fh (see below)
[Default] a = 00h (All Input)
[Function] Set input or output for general-purpose I/O ports.
- [Code] 1Fh 28h 70h 10h n a
n: I/O port number
a: Output data value
[Definable area]
n = 00h: Port 0
00h ≤ a ≤ 0Fh (see below)
[Default] a = 00h (All 0)
[Function] Output data to general-purpose I/O port
- [Code] 1Fh 28h 70h 20h n
n: I/O port number
[Definable area]
n = 00h: Port 0
[Function] The state of a general-purpose I/O port at the time this command is processed is
transmitted.

## Macro / program macro command group:
- [Code] 1Fh 3Ah pL pH [d1…dk]
pL: RAM Macro data length, lower byte
pH: RAM Macro data length, upper byte
d: RAM Macro data
[Definable area]
0000h ≤ (pL + pH × 100h) ≤ 0100h
00h ≤ d ≤ FFh
[Function] Define or delete RAM Macro or RAM Program Macro
- [Code] 1Fh 5Eh a t1 t2
a: Macro processing definition number
t1: Display time interval (t1 × IntTime)
t2: Idle time for Macro repetition (t2 × IntTime)
(IntTime: Refer to "3.1 Timing Unit".)
[Definable area]
00h ≤ a ≤ 04h, 80h ≤ a ≤ 84h
a = 00h: RAM Macro
01h ≤ a ≤ 04h: FROM Macro 1–4
a = 80h: RAM Program Macro
81h ≤ a ≤ 84h: FROM Program Macro 1–4
00h ≤ t1, t2 ≤ FFh
[Function] Execute contents of defined Macro 'a'.

## User setup mode command group:
- [Code] 1Fh 28h 65h 01h d1 d2
[Definable area]
d1 = 49h (Character 'I')
d2 = 4Eh (Character 'N')
[Function] Start User setup mode.
- [Code] 1Fh 28h 65h 02h d1 d2 d3
[Definable area]
d1 = 4Fh (Character 'O')
d2 = 55h (Character 'U')
d3 = 54h (Character 'T')
[Function] End User setup mode.
- [Code] 1Fh 28h 65h 10h aL aH aE sL sH sE d(1)...d(s)
aL: Bit image data definition address, lower byte
aH: Bit image data definition address, upper byte
aE: Bit image data definition address, extension byte
sL: Bit image data length, lower byte
sH: Bit image data length, upper byte
sE: Bit image data length, extension byte
d(1)–d(s): Bit Image data (see below)
[Definable area]
000000h ≤ (aL + aH × 100h + aE × 10000h) ≤ 07FFFFh
000001h ≤ (sL + sH × 100h + sE × 10000h) ≤ 080000h
00h ≤ d ≤ FFh
[Function] Define user bit image to the FROM
- [Code] 1Fh 28h 65h 12h a pL pH t1 t2 [d1…dp]
a: FROM Macro registration number
pL: FROM Macro data length, lower byte
pH: FROM Macro data length, upper byte
t1: Display time interval (t1 × IntTime) *for execution at power-on
t2: Idle time for Macro repetition (t2 × IntTime) *for execution at power-on
(IntTime: Refer to "3.1 Timing Unit".)
d: FROM Macro data
[Definable area]
01h ≤ a ≤ 04h
0000h ≤ (pL + pH × 100h) ≤ 2000h (if using 4 Macros), 8000h (if using 1 Macro)
00h ≤ t1 ≤ FFh
00h ≤ t2 ≤ FFh
00h ≤ d ≤ FFh
[Function] Define or delete FROM Macro or FROM Program Macro.
- [Code] 1Fh 28h 65h 03h a b
a: Memory SW Number
b: Setting data
[Definable area]
00h ≤ a ≤ 3Fh
00h ≤ b ≤ FFh
[Function] Set Memory SW 'a' with the value specified by 'b'
- [Code] 1Fh 28h 65h 04h a
a: Memory SW Number
[Definable area]
00h ≤ a ≤ 3Fh
[Function] Send the contents of Memory SW data.
- [Code] 1Fh 28h 65h 40h a [b c]
[Definable area]
a = 02h: Firmware version information (b, c not used)
a = 10h: 2-byte character code information (b, c not used)
a = 11h: Language type information (b, c not used)
a = 20h: Memory checksum information
00h ≤ b ≤ FFh: Start address (Effective address = b × 10000h)
00h ≤ c ≤ FFh: Data length (Effective data length = c × 10000h)
a = 30h: Product type information (b, c not used)
a = 40h: Display x dot information (b, c not used)
a = 41h: Display y dot information (b, c not used)
a = 50h: X direction switch number information (b, c not used)
a = 51h: Y direction switch number information (b, c not used)
[Function] Send display status information

## Touch-switch command group:
- [Code] 1Fh 4Bh 10h
[Function] Send ON/OFF status information for all Touch-Switches.
- [Code] 1Fh 4Bh 11h sn
sn: SW Number
[Definable area]
00h ≤ sn ≤ SwNumMax
sn = 00h: SW1
sn = 01h: SW2
:
sn = n-1: SWn
[Function] Send ON/OFF status information for individual Touch-Switch.
- [Code] 1Fh 4Bh 14h
[Function] Sends the count-level for all Touch-Switches
- [Code] 1Fh 4Bh 15h
[Function] Sends the touch-level for all Touch-Switches.
- [Code] 1Fh 4Bh 18h m
m: TSW read mode
[Definable area]
00h ≤ m ≤ 02h
m = 00h: Manual transmit mode (Send only in response to read command)
m = 01h: Automatic transmit mode 1 (All Touch Switch status)
m = 02h: Automatic transmit mode 2 (Individual Touch Switch status)
[Default] m = 00h or Memory SW setting.
[Function] Set read action of touch switch status
- [Code] 1Fh 4Bh 70h a b
[Definable area]
00h ≤ a ≤ 03h
a = 00h: Touch sensitivity level setting
00h ≤ b ≤ 07h
a = 01h: Sampling time setting (ON decision)
01h ≤ b ≤ FEh
a = 02h: Sampling time setting (OFF decision)
01h ≤ b ≤ FEh
a = 03h: Calibration period setting
00h ≤ b ≤ 64h
[Default] Memory SW setting
[Function] Change the Touch-Switch internal parameters

## Memory re-wrtie mode command group:
- [Code] 1Ch 7Ch 4Dh m d1...d6
[Definable area]
m = D0h
d1...d6 = 4Dh 4Fh 44h 45h 49h 4Eh (Character strings "MODEIN")
[Function] Shift to "Memory re-write mode" from "Normal mode"
- [Code] 45h k
k = command keyword
[Definable area]
k = BAh
[Function] End "Memory re-write mode"
