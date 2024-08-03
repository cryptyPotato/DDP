<QucsStudio Schematic 4.3.1>
<Properties>
View=-18,114,1169,2208,1,0,471
Grid=10,10,1
DataSet=*.dat
DataDisplay=*.dpl
OpenDisplay=1
showFrame=0
FrameText0=Title
FrameText1=Drawn By:
FrameText2=Date:
FrameText3=Revision:
</Properties>
<Symbol>
</Symbol>
<Components>
.DC DC1 1 300 360 0 38 0 0 "0.001" 0 "1 nA" 0 "500" 0 "none" 0
GND * 1 290 190 0 0 0 0
GND * 1 470 190 0 0 0 0
Vdc VD 1 320 190 -20 -56 1 1 "Vd" 1 "battery" 0 "SIL-2" 0
Vdc VG 1 440 190 -26 -56 0 1 "Vg " 1 "battery" 0 "SIL-2" 0
IProbe Pr1 1 300 250 0 16 1 2 "SIL-2" 0
GND * 1 270 250 0 0 0 0
GND * 1 640 190 0 0 0 0
GND * 1 820 190 0 0 0 0
Vdc VD1 1 670 190 -20 -56 1 1 "Vd" 1 "battery" 0 "SIL-2" 0
Vdc VG1 1 790 190 -26 -56 0 1 "Vg " 1 "battery" 0 "SIL-2" 0
IProbe Pr2 1 650 250 0 16 1 2 "SIL-2" 0
GND * 1 620 250 0 0 0 0
GND * 1 640 360 0 0 0 0
Vdc VD2 1 670 360 -20 -56 1 1 "Vd" 1 "battery" 0 "SIL-2" 0
IProbe Pr3 1 650 420 0 16 1 2 "SIL-2" 0
GND * 1 620 420 0 0 0 0
Cpp X1 1 380 220 -26 51 0 0 "nmos-at.va" 0 "1.2" 0 "3.4" 0 "3.1e-6" 0
GND * 1 330 1470 0 0 0 0
GND * 1 510 1470 0 0 0 0
Vdc VD3 1 360 1470 -20 -56 1 1 "Vd" 1 "battery" 0 "SIL-2" 0
Vdc VG3 1 480 1470 -26 -56 0 1 "Vg " 1 "battery" 0 "SIL-2" 0
IProbe Pr4 1 340 1530 0 16 1 2 "SIL-2" 0
GND * 1 310 1530 0 0 0 0
Eqn Eqn1 1 440 460 0 8 0 0 "Vd=10=" 1 "yes" 0
.SW SW1 1 280 430 0 63 0 0 "DC1" 1 "Vg" 1 "lin" 1 "0" 1 "12" 1 "1001" 1
Vdc VG2 1 790 360 -26 -56 0 1 "Vg " 1 "battery" 0 "SIL-2" 0
GND * 1 820 360 0 0 0 0
Cpp X4 1 420 1500 -26 51 0 0 "nmos-dibl-lam.va" 0 "1.2" 0 "3.4" 0 "3.1e-6" 0 "3" 0 "0.03" 0 "0.95" 0 "1.7" 0 "6.93e-7" 0 "0.8" 0 "0.07" 0 "3000" 0 "1e-30" 0 "3" 0 "1" 0 "1" 0 "1" 0
Cpp X3 1 730 390 -26 81 0 0 "nmos-tot.va" 0 "1.2" 0 "3.4" 0 "3.1e-6" 0 "3" 0 "4" 0 "0.026" 0
Cpp X2 1 730 220 -26 51 0 0 "nmos-sub.va" 0 "1.2" 0 "3.4" 0 "3.1e-6" 0 "3" 0 "0.026" 0 "4" 0
</Components>
<Wires>
330 250 350 250 "" 0 0 0 ""
680 250 700 250 "" 0 0 0 ""
680 420 700 420 "" 0 0 0 ""
370 1530 390 1530 "" 0 0 0 ""
</Wires>
<Diagrams>
<Rect 150 2130 480 520 31 #c0c0c0 1 01 1 0 2 12 1 0.0003 1 0.001 1 0 0 0 315 0 225 "" "" "">
	<Legend 10 -100 0>
	<"Pr4.I" "" #0000ff 0 3 0 0 0 0 "">
</Rect>
<Tab 750 1950 200 250 71 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 1001 315 0 225 "" "" "">
	<"Pr4.I" "" #0000ff 0 3 1 0 0 0 "">
</Tab>
<Rect 260 1150 580 410 31 #c0c0c0 5 01 2 0.227586 0.5 3.14483 2 1.73205e-10 1 6.85405e-07 1 0 0 0 315 0 225 "V_{GS} in V" "I_{DS} in A" "">
	<Legend 320 -140 1>
	<"Pr3.I" "" #000000 3 3 0 0 0 1 "Total-current">
</Rect>
</Diagrams>
<Paintings>
</Paintings>
