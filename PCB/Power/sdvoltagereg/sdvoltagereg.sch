EESchema Schematic File Version 4
LIBS:sdvoltagereg-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L sdvoltagereg-rescue:ltc3624 U2
U 1 1 5CAC0DA7
P 3750 800
F 0 "U2" H 3750 350 60  0000 C CNN
F 1 "ltc3624" H 3700 1100 60  0000 C CNN
F 2 "SOP65P490X110-13N:SOP65P490X110-13N" H 3750 800 60  0001 C CNN
F 3 "" H 3750 800 60  0001 C CNN
	1    3750 800 
	1    0    0    -1  
$EndComp
$Comp
L sdvoltagereg-rescue:ltc3624 U1
U 1 1 5CAC0DDC
P 3700 3300
F 0 "U1" H 3700 2850 60  0000 C CNN
F 1 "ltc3624" H 3650 3600 60  0000 C CNN
F 2 "SOP65P490X110-13N:SOP65P490X110-13N" H 3700 3300 60  0001 C CNN
F 3 "" H 3700 3300 60  0001 C CNN
	1    3700 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5CAC0E15
P 2300 850
F 0 "R1" V 2380 850 50  0000 C CNN
F 1 "620k" V 2300 850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2230 850 50  0001 C CNN
F 3 "" H 2300 850 50  0001 C CNN
	1    2300 850 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5CAC0E34
P 2300 1250
F 0 "R2" V 2380 1250 50  0000 C CNN
F 1 "84.5k" V 2300 1250 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 2230 1250 50  0001 C CNN
F 3 "" H 2300 1250 50  0001 C CNN
	1    2300 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5CAC0E51
P 2300 3850
F 0 "R4" V 2380 3850 50  0000 C CNN
F 1 "84.5k" V 2300 3850 50  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 2230 3850 50  0001 C CNN
F 3 "" H 2300 3850 50  0001 C CNN
	1    2300 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5CAC0EA4
P 2300 3400
F 0 "R3" V 2380 3400 50  0000 C CNN
F 1 "380k" V 2300 3400 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2230 3400 50  0001 C CNN
F 3 "" H 2300 3400 50  0001 C CNN
	1    2300 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5CAC0ECF
P 1950 3400
F 0 "C2" H 1975 3500 50  0000 L CNN
F 1 "47uF" H 1975 3300 50  0000 L CNN
F 2 "Resistors_SMD:R_1210_HandSoldering" H 1988 3250 50  0001 C CNN
F 3 "" H 1950 3400 50  0001 C CNN
	1    1950 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5CAC0F02
P 4500 3400
F 0 "C5" H 4525 3500 50  0000 L CNN
F 1 "2.2uF" H 4525 3300 50  0000 L CNN
F 2 "Resistors_SMD:R_1210_HandSoldering" H 4538 3250 50  0001 C CNN
F 3 "" H 4500 3400 50  0001 C CNN
	1    4500 3400
	0    1    1    0   
$EndComp
$Comp
L Device:C C3
U 1 1 5CAC0F2B
P 2850 3750
F 0 "C3" H 2875 3850 50  0000 L CNN
F 1 "10uF" H 2875 3650 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 2888 3600 50  0001 C CNN
F 3 "" H 2850 3750 50  0001 C CNN
	1    2850 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5CAC0FC3
P 2900 1250
F 0 "C4" H 2925 1350 50  0000 L CNN
F 1 "10uF" H 2925 1150 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 2938 1100 50  0001 C CNN
F 3 "" H 2900 1250 50  0001 C CNN
	1    2900 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5CAC103B
P 1850 900
F 0 "C1" H 1875 1000 50  0000 L CNN
F 1 "47uF" H 1875 800 50  0000 L CNN
F 2 "Resistors_SMD:R_1210_HandSoldering" H 1888 750 50  0001 C CNN
F 3 "" H 1850 900 50  0001 C CNN
	1    1850 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 5CAC106A
P 4550 900
F 0 "C6" H 4575 1000 50  0000 L CNN
F 1 "2.2uF" H 4575 800 50  0000 L CNN
F 2 "Resistors_SMD:R_1210_HandSoldering" H 4588 750 50  0001 C CNN
F 3 "" H 4550 900 50  0001 C CNN
	1    4550 900 
	0    1    1    0   
$EndComp
$Comp
L Device:L L1
U 1 1 5CAC10D9
P 2850 700
F 0 "L1" V 2800 700 50  0000 C CNN
F 1 "1.3uH" V 2925 700 50  0000 C CNN
F 2 "Inductors_SMD:L_0805_HandSoldering" H 2850 700 50  0001 C CNN
F 3 "" H 2850 700 50  0001 C CNN
	1    2850 700 
	0    1    1    0   
$EndComp
$Comp
L Device:L L2
U 1 1 5CAC112C
P 2850 3200
F 0 "L2" V 2800 3200 50  0000 C CNN
F 1 "1.1uH" V 2925 3200 50  0000 C CNN
F 2 "Inductors_SMD:L_0805_HandSoldering" H 2850 3200 50  0001 C CNN
F 3 "" H 2850 3200 50  0001 C CNN
	1    2850 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	4200 900  4300 900 
Wire Wire Line
	1300 700  1400 700 
Connection ~ 2300 700 
Wire Wire Line
	1850 750  1850 700 
Wire Wire Line
	2300 1000 2300 1100
Wire Wire Line
	4200 1100 4450 1100
Wire Wire Line
	4450 1100 4450 1800
Wire Wire Line
	4450 1800 2050 1800
Wire Wire Line
	2050 1800 2050 1100
Wire Wire Line
	2050 1100 2300 1100
Wire Wire Line
	3200 900  2900 900 
Wire Wire Line
	2900 900  2900 1000
Wire Wire Line
	3200 1000 3050 1000
Connection ~ 2900 1000
Wire Wire Line
	2900 1400 2900 2050
Wire Wire Line
	2900 2050 2250 2050
Wire Wire Line
	3200 1100 3050 1100
Wire Wire Line
	3050 1100 3050 1000
Connection ~ 3050 1000
Wire Wire Line
	4200 1000 4300 1000
Wire Wire Line
	4300 1000 4300 900 
Connection ~ 4300 900 
Wire Wire Line
	3200 800  3100 800 
Wire Wire Line
	3100 800  3100 700 
Connection ~ 3100 700 
$Comp
L power:GND #PWR01
U 1 1 5CAC36B7
P 4200 600
F 0 "#PWR01" H 4200 350 50  0001 C CNN
F 1 "GND" H 4200 450 50  0000 C CNN
F 2 "" H 4200 600 50  0001 C CNN
F 3 "" H 4200 600 50  0001 C CNN
	1    4200 600 
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5CAC36E7
P 4200 700
F 0 "#PWR02" H 4200 450 50  0001 C CNN
F 1 "GND" H 4200 550 50  0000 C CNN
F 2 "" H 4200 700 50  0001 C CNN
F 3 "" H 4200 700 50  0001 C CNN
	1    4200 700 
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5CAC3717
P 4200 800
F 0 "#PWR03" H 4200 550 50  0001 C CNN
F 1 "GND" H 4200 650 50  0000 C CNN
F 2 "" H 4200 800 50  0001 C CNN
F 3 "" H 4200 800 50  0001 C CNN
	1    4200 800 
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5CAC3847
P 4700 900
F 0 "#PWR04" H 4700 650 50  0001 C CNN
F 1 "GND" H 4700 750 50  0000 C CNN
F 2 "" H 4700 900 50  0001 C CNN
F 3 "" H 4700 900 50  0001 C CNN
	1    4700 900 
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5CAC3877
P 2300 1400
F 0 "#PWR05" H 2300 1150 50  0001 C CNN
F 1 "GND" H 2300 1250 50  0000 C CNN
F 2 "" H 2300 1400 50  0001 C CNN
F 3 "" H 2300 1400 50  0001 C CNN
	1    2300 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5CAC38A7
P 1850 1050
F 0 "#PWR06" H 1850 800 50  0001 C CNN
F 1 "GND" H 1850 900 50  0000 C CNN
F 2 "" H 1850 1050 50  0001 C CNN
F 3 "" H 1850 1050 50  0001 C CNN
	1    1850 1050
	1    0    0    -1  
$EndComp
Connection ~ 1850 700 
Wire Wire Line
	3000 700  3100 700 
Wire Wire Line
	3000 3200 3150 3200
Wire Wire Line
	2700 3200 2300 3200
Wire Wire Line
	2300 3250 2300 3200
Connection ~ 2300 3200
Wire Wire Line
	1950 3250 1950 3200
Connection ~ 1950 3200
Wire Wire Line
	2300 3550 2300 3650
Wire Wire Line
	3150 3200 3150 3300
Wire Wire Line
	3150 3400 2850 3400
Wire Wire Line
	2850 3400 2850 3600
Wire Wire Line
	3150 3400 3150 3500
Connection ~ 3150 3500
Wire Wire Line
	4150 3400 4300 3400
Wire Wire Line
	4150 3600 4350 3600
Wire Wire Line
	4350 3600 4350 4150
Wire Wire Line
	4350 4150 2550 4150
Wire Wire Line
	2550 4150 2550 3650
Wire Wire Line
	2550 3650 2300 3650
Connection ~ 2300 3650
Wire Wire Line
	2850 4400 2850 3900
$Comp
L power:GND #PWR07
U 1 1 5CAC468A
P 1950 3550
F 0 "#PWR07" H 1950 3300 50  0001 C CNN
F 1 "GND" H 1950 3400 50  0000 C CNN
F 2 "" H 1950 3550 50  0001 C CNN
F 3 "" H 1950 3550 50  0001 C CNN
	1    1950 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5CAC46BA
P 4150 3100
F 0 "#PWR08" H 4150 2850 50  0001 C CNN
F 1 "GND" H 4150 2950 50  0000 C CNN
F 2 "" H 4150 3100 50  0001 C CNN
F 3 "" H 4150 3100 50  0001 C CNN
	1    4150 3100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5CAC46EA
P 4150 3200
F 0 "#PWR09" H 4150 2950 50  0001 C CNN
F 1 "GND" H 4150 3050 50  0000 C CNN
F 2 "" H 4150 3200 50  0001 C CNN
F 3 "" H 4150 3200 50  0001 C CNN
	1    4150 3200
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5CAC474E
P 4150 3300
F 0 "#PWR010" H 4150 3050 50  0001 C CNN
F 1 "GND" H 4150 3150 50  0000 C CNN
F 2 "" H 4150 3300 50  0001 C CNN
F 3 "" H 4150 3300 50  0001 C CNN
	1    4150 3300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4150 3500 4300 3500
Wire Wire Line
	4300 3500 4300 3400
Connection ~ 4300 3400
$Comp
L power:GND #PWR011
U 1 1 5CAC4898
P 4650 3400
F 0 "#PWR011" H 4650 3150 50  0001 C CNN
F 1 "GND" H 4650 3250 50  0000 C CNN
F 2 "" H 4650 3400 50  0001 C CNN
F 3 "" H 4650 3400 50  0001 C CNN
	1    4650 3400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5CAC48C8
P 2300 4000
F 0 "#PWR012" H 2300 3750 50  0001 C CNN
F 1 "GND" H 2300 3850 50  0000 C CNN
F 2 "" H 2300 4000 50  0001 C CNN
F 3 "" H 2300 4000 50  0001 C CNN
	1    2300 4000
	1    0    0    -1  
$EndComp
$Comp
L conn:Conn_01x02_Female J1
U 1 1 5CAC4979
P 1000 3300
F 0 "J1" H 1000 3400 50  0000 C CNN
F 1 "Conn_01x02_Female" H 1000 3100 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 1000 3300 50  0001 C CNN
F 3 "" H 1000 3300 50  0001 C CNN
	1    1000 3300
	-1   0    0    1   
$EndComp
$Comp
L conn:Conn_01x02_Female J3
U 1 1 5CAC4A78
P 1300 2150
F 0 "J3" H 1300 2250 50  0000 C CNN
F 1 "Conn_01x02_Female" H 1300 1950 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 1300 2150 50  0001 C CNN
F 3 "" H 1300 2150 50  0001 C CNN
	1    1300 2150
	-1   0    0    1   
$EndComp
$Comp
L conn:Conn_01x01_Female J7
U 1 1 5CAC4B00
P 2550 1000
F 0 "J7" H 2550 1100 50  0000 C CNN
F 1 "Conn_01x01_Female" H 2550 900 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 2550 1000 50  0001 C CNN
F 3 "" H 2550 1000 50  0001 C CNN
	1    2550 1000
	1    0    0    -1  
$EndComp
$Comp
L conn:Conn_01x01_Female J4
U 1 1 5CAC4BD0
P 1600 550
F 0 "J4" H 1600 650 50  0000 C CNN
F 1 "Conn_01x01_Female" H 1600 450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 1600 550 50  0001 C CNN
F 3 "" H 1600 550 50  0001 C CNN
	1    1600 550 
	1    0    0    -1  
$EndComp
$Comp
L conn:Conn_01x01_Female J6
U 1 1 5CAC4C11
P 1650 3100
F 0 "J6" H 1650 3200 50  0000 C CNN
F 1 "Conn_01x01_Female" H 1650 3000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 1650 3100 50  0001 C CNN
F 3 "" H 1650 3100 50  0001 C CNN
	1    1650 3100
	1    0    0    -1  
$EndComp
$Comp
L conn:Conn_01x01_Female J8
U 1 1 5CAC4C54
P 2650 3550
F 0 "J8" H 2650 3650 50  0000 C CNN
F 1 "Conn_01x01_Female" H 2650 3450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 2650 3550 50  0001 C CNN
F 3 "" H 2650 3550 50  0001 C CNN
	1    2650 3550
	1    0    0    -1  
$EndComp
$Comp
L conn:Conn_01x01_Female J10
U 1 1 5CAC4C9D
P 4150 4750
F 0 "J10" H 4150 4850 50  0000 C CNN
F 1 "Conn_01x01_Female" H 4150 4650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 4150 4750 50  0001 C CNN
F 3 "" H 4150 4750 50  0001 C CNN
	1    4150 4750
	0    1    1    0   
$EndComp
Wire Wire Line
	5150 4400 5150 2400
Wire Wire Line
	5150 2400 2250 2400
Wire Wire Line
	2250 2400 2250 2050
Connection ~ 2250 2050
$Comp
L conn:Conn_01x02_Female J2
U 1 1 5CAC4F5A
P 1100 800
F 0 "J2" H 1100 900 50  0000 C CNN
F 1 "Conn_01x02_Female" H 1100 600 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 1100 800 50  0001 C CNN
F 3 "" H 1100 800 50  0001 C CNN
	1    1100 800 
	-1   0    0    1   
$EndComp
Wire Wire Line
	2450 3550 2300 3550
Wire Wire Line
	5150 4400 4150 4400
Wire Wire Line
	4150 4550 4150 4400
Connection ~ 4150 4400
Wire Wire Line
	1450 3100 1450 3200
Connection ~ 1450 3200
$Comp
L power:GND #PWR013
U 1 1 5CAC544F
P 1200 3300
F 0 "#PWR013" H 1200 3050 50  0001 C CNN
F 1 "GND" H 1200 3150 50  0000 C CNN
F 2 "" H 1200 3300 50  0001 C CNN
F 3 "" H 1200 3300 50  0001 C CNN
	1    1200 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR014
U 1 1 5CAC5523
P 1500 2150
F 0 "#PWR014" H 1500 1900 50  0001 C CNN
F 1 "GND" H 1500 2000 50  0000 C CNN
F 2 "" H 1500 2150 50  0001 C CNN
F 3 "" H 1500 2150 50  0001 C CNN
	1    1500 2150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5CAC5623
P 1300 800
F 0 "#PWR015" H 1300 550 50  0001 C CNN
F 1 "GND" H 1300 650 50  0000 C CNN
F 2 "" H 1300 800 50  0001 C CNN
F 3 "" H 1300 800 50  0001 C CNN
	1    1300 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 550  1400 700 
Connection ~ 1400 700 
Wire Wire Line
	2350 1000 2300 1000
Text Notes 3050 400  0    60   ~ 0
5v\n
Text Notes 3200 2900 0    60   ~ 0
3V\n
Text Notes 1250 1100 0    60   ~ 0
out 5\n
Text Notes 1100 3600 0    60   ~ 0
out3.3\n
$Comp
L power:+12V #PWR016
U 1 1 5CAC93DD
P 650 1400
F 0 "#PWR016" H 650 1250 50  0001 C CNN
F 1 "+12V" H 650 1540 50  0000 C CNN
F 2 "" H 650 1400 50  0001 C CNN
F 3 "" H 650 1400 50  0001 C CNN
	1    650  1400
	-1   0    0    1   
$EndComp
NoConn ~ 3150 3700
NoConn ~ 4150 3700
NoConn ~ 3200 1200
NoConn ~ 4200 1200
Wire Wire Line
	1950 2000 1950 2050
Connection ~ 1950 2050
$Comp
L power:PWR_FLAG #FLG017
U 1 1 5CAC9A49
P 650 1350
F 0 "#FLG017" H 650 1425 50  0001 C CNN
F 1 "PWR_FLAG" H 650 1500 50  0000 C CNN
F 2 "" H 650 1350 50  0001 C CNN
F 3 "" H 650 1350 50  0001 C CNN
	1    650  1350
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG018
U 1 1 5CAC9A8B
P 900 1250
F 0 "#FLG018" H 900 1325 50  0001 C CNN
F 1 "PWR_FLAG" H 900 1400 50  0000 C CNN
F 2 "" H 900 1250 50  0001 C CNN
F 3 "" H 900 1250 50  0001 C CNN
	1    900  1250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR019
U 1 1 5CAC9B4A
P 900 1250
F 0 "#PWR019" H 900 1000 50  0001 C CNN
F 1 "GND" H 900 1100 50  0000 C CNN
F 2 "" H 900 1250 50  0001 C CNN
F 3 "" H 900 1250 50  0001 C CNN
	1    900  1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  1400 650  1350
$Comp
L power:+12V #PWR020
U 1 1 5CAC9C00
P 1950 2000
F 0 "#PWR020" H 1950 1850 50  0001 C CNN
F 1 "+12V" H 1950 2140 50  0000 C CNN
F 2 "" H 1950 2000 50  0001 C CNN
F 3 "" H 1950 2000 50  0001 C CNN
	1    1950 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 700  2700 700 
Wire Wire Line
	2900 1000 2900 1100
Wire Wire Line
	3050 1000 2900 1000
Wire Wire Line
	4300 900  4400 900 
Wire Wire Line
	3100 700  3200 700 
Wire Wire Line
	1850 700  2300 700 
Wire Wire Line
	2300 3200 1950 3200
Wire Wire Line
	1950 3200 1750 3200
Wire Wire Line
	3150 3500 3150 3600
Wire Wire Line
	2300 3650 2300 3700
Wire Wire Line
	4300 3400 4350 3400
Wire Wire Line
	2250 2050 1950 2050
Wire Wire Line
	4150 4400 2850 4400
Wire Wire Line
	1450 3200 1200 3200
Wire Wire Line
	1400 700  1600 700 
$Comp
L teensy:Teensy3.5 U4
U 1 1 5CBE698F
P 8950 3150
F 0 "U4" H 8950 5537 60  0000 C CNN
F 1 "Teensy3.5" H 8950 5431 60  0000 C CNN
F 2 "custom:Teensy35_36" H 8950 3150 60  0001 C CNN
F 3 "" H 8950 3150 60  0000 C CNN
	1    8950 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 2050 1750 2050
$Comp
L Device:C C7
U 1 1 5CBEC02D
P 1750 2200
F 0 "C7" H 1865 2246 50  0000 L CNN
F 1 "100n" H 1865 2155 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1788 2050 50  0001 C CNN
F 3 "~" H 1750 2200 50  0001 C CNN
	1    1750 2200
	1    0    0    -1  
$EndComp
Connection ~ 1750 2050
Wire Wire Line
	1750 2050 1950 2050
$Comp
L power:GND #PWR0101
U 1 1 5CBED4D6
P 1750 2350
F 0 "#PWR0101" H 1750 2100 50  0001 C CNN
F 1 "GND" H 1755 2177 50  0000 C CNN
F 2 "" H 1750 2350 50  0001 C CNN
F 3 "" H 1750 2350 50  0001 C CNN
	1    1750 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5CBEF698
P 7950 1050
F 0 "#PWR0102" H 7950 800 50  0001 C CNN
F 1 "GND" V 7955 922 50  0000 R CNN
F 2 "" H 7950 1050 50  0001 C CNN
F 3 "" H 7950 1050 50  0001 C CNN
	1    7950 1050
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5CBEFC37
P 7950 3650
F 0 "#PWR0103" H 7950 3400 50  0001 C CNN
F 1 "GND" V 7955 3522 50  0000 R CNN
F 2 "" H 7950 3650 50  0001 C CNN
F 3 "" H 7950 3650 50  0001 C CNN
	1    7950 3650
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5CBF0499
P 7950 4850
F 0 "#PWR0104" H 7950 4600 50  0001 C CNN
F 1 "GND" V 7955 4722 50  0000 R CNN
F 2 "" H 7950 4850 50  0001 C CNN
F 3 "" H 7950 4850 50  0001 C CNN
	1    7950 4850
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5CBF098A
P 9950 2250
F 0 "#PWR0105" H 9950 2000 50  0001 C CNN
F 1 "GND" V 9955 2122 50  0000 R CNN
F 2 "" H 9950 2250 50  0001 C CNN
F 3 "" H 9950 2250 50  0001 C CNN
	1    9950 2250
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5CBF0EB3
P 9950 3450
F 0 "#PWR0106" H 9950 3200 50  0001 C CNN
F 1 "GND" V 9955 3322 50  0000 R CNN
F 2 "" H 9950 3450 50  0001 C CNN
F 3 "" H 9950 3450 50  0001 C CNN
	1    9950 3450
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5CBF55C7
P 9950 3550
F 0 "#PWR0107" H 9950 3300 50  0001 C CNN
F 1 "GND" V 9955 3422 50  0000 R CNN
F 2 "" H 9950 3550 50  0001 C CNN
F 3 "" H 9950 3550 50  0001 C CNN
	1    9950 3550
	0    -1   -1   0   
$EndComp
$Comp
L conn:Conn_01x08_Female J13
U 1 1 5CC0AC85
P 5800 2500
F 0 "J13" H 5692 1875 50  0000 C CNN
F 1 "Conn_01x08_Female" H 5692 1966 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 5800 2500 50  0001 C CNN
F 3 "~" H 5800 2500 50  0001 C CNN
	1    5800 2500
	-1   0    0    1   
$EndComp
$Comp
L conn:Conn_01x04_Female J9
U 1 1 5CC0C83F
P 5750 3450
F 0 "J9" H 5642 3025 50  0000 C CNN
F 1 "Conn_01x04_Female" H 5642 3116 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 5750 3450 50  0001 C CNN
F 3 "~" H 5750 3450 50  0001 C CNN
	1    5750 3450
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR0108
U 1 1 5CC0EABF
P 600 1950
F 0 "#PWR0108" H 600 1800 50  0001 C CNN
F 1 "+3.3V" H 615 2123 50  0000 C CNN
F 2 "" H 600 1950 50  0001 C CNN
F 3 "" H 600 1950 50  0001 C CNN
	1    600  1950
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5CC0F0D1
P 600 1950
F 0 "#FLG0101" H 600 2025 50  0001 C CNN
F 1 "PWR_FLAG" H 600 2123 50  0000 C CNN
F 2 "" H 600 1950 50  0001 C CNN
F 3 "~" H 600 1950 50  0001 C CNN
	1    600  1950
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR0109
U 1 1 5CC0FA6C
P 1750 3200
F 0 "#PWR0109" H 1750 3050 50  0001 C CNN
F 1 "+3.3V" H 1765 3373 50  0000 C CNN
F 2 "" H 1750 3200 50  0001 C CNN
F 3 "" H 1750 3200 50  0001 C CNN
	1    1750 3200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0110
U 1 1 5CC109A8
P 9950 4350
F 0 "#PWR0110" H 9950 4200 50  0001 C CNN
F 1 "+5V" V 9965 4478 50  0000 L CNN
F 2 "" H 9950 4350 50  0001 C CNN
F 3 "" H 9950 4350 50  0001 C CNN
	1    9950 4350
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0111
U 1 1 5CC112BE
P 1600 700
F 0 "#PWR0111" H 1600 550 50  0001 C CNN
F 1 "+5V" H 1615 873 50  0000 C CNN
F 2 "" H 1600 700 50  0001 C CNN
F 3 "" H 1600 700 50  0001 C CNN
	1    1600 700 
	1    0    0    -1  
$EndComp
Connection ~ 1600 700 
Wire Wire Line
	1600 700  1850 700 
Connection ~ 1750 3200
Wire Wire Line
	1750 3200 1450 3200
$Comp
L Raitong_Env_Sensor-rescue:XBEE-agg-kicad U3
U 1 1 5CC1B10D
P 6650 950
F 0 "U3" H 6650 1715 50  0000 C CNN
F 1 "XBEE-agg-kicad" H 6650 1624 50  0000 C CNN
F 2 "agg-unchecked:XBEE" H 6250 250 50  0001 L CNN
F 3 "" H 6150 1350 50  0001 C CNN
	1    6650 950 
	-1   0    0    1   
$EndComp
Text Notes 6150 1900 0    50   ~ 0
no2
Text Notes 5950 3050 0    50   ~ 0
bme280\n
Text Notes 5950 3850 0    50   ~ 0
lux\n
Text Notes 5950 4950 0    50   ~ 0
voltage mon
$Comp
L conn:Conn_01x04_Female J11
U 1 1 5CC1E25C
P 5750 4650
F 0 "J11" H 5778 4626 50  0000 L CNN
F 1 "Conn_01x04_Female" H 5778 4535 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 5750 4650 50  0001 C CNN
F 3 "~" H 5750 4650 50  0001 C CNN
	1    5750 4650
	-1   0    0    1   
$EndComp
Text Notes 5550 4650 2    50   ~ 0
methane
$Comp
L conn:Conn_01x07_Female J20
U 1 1 5CC1FE3B
P 9450 5900
F 0 "J20" H 9478 5926 50  0000 L CNN
F 1 "Conn_01x07_Female" H 9478 5835 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07_Pitch2.54mm" H 9450 5900 50  0001 C CNN
F 3 "~" H 9450 5900 50  0001 C CNN
	1    9450 5900
	1    0    0    -1  
$EndComp
Text Notes 9650 5850 0    50   ~ 0
5v rail\n
$Comp
L conn:Conn_01x07_Female J19
U 1 1 5CC21C09
P 7200 3150
F 0 "J19" H 7228 3176 50  0000 L CNN
F 1 "Conn_01x07_Female" H 7228 3085 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07_Pitch2.54mm" H 7200 3150 50  0001 C CNN
F 3 "~" H 7200 3150 50  0001 C CNN
	1    7200 3150
	-1   0    0    1   
$EndComp
$Comp
L conn:Conn_01x07_Female J21
U 1 1 5CC221C6
P 11000 900
F 0 "J21" H 11028 926 50  0000 L CNN
F 1 "Conn_01x07_Female" H 11028 835 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07_Pitch2.54mm" H 11000 900 50  0001 C CNN
F 3 "~" H 11000 900 50  0001 C CNN
	1    11000 900 
	1    0    0    -1  
$EndComp
Text Notes 11200 900  0    50   ~ 0
grnd\n
Text Notes 7050 3200 2    50   ~ 0
3.3v rail\n
$Comp
L power:GND #PWR0112
U 1 1 5CC28D55
P 10800 1200
F 0 "#PWR0112" H 10800 950 50  0001 C CNN
F 1 "GND" H 10805 1027 50  0000 C CNN
F 2 "" H 10800 1200 50  0001 C CNN
F 3 "" H 10800 1200 50  0001 C CNN
	1    10800 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10800 600  10800 700 
Connection ~ 10800 700 
Wire Wire Line
	10800 700  10800 800 
Connection ~ 10800 1200
Connection ~ 10800 800 
Wire Wire Line
	10800 800  10800 900 
Connection ~ 10800 900 
Wire Wire Line
	10800 900  10800 1000
Connection ~ 10800 1000
Wire Wire Line
	10800 1000 10800 1100
Connection ~ 10800 1100
Wire Wire Line
	10800 1100 10800 1200
Wire Wire Line
	7400 3450 7400 3350
Connection ~ 7400 3350
Wire Wire Line
	7400 3350 7400 3250
Connection ~ 7400 3250
Wire Wire Line
	7400 3250 7400 3150
Connection ~ 7400 3150
Wire Wire Line
	7400 3150 7400 3050
Connection ~ 7400 3050
Wire Wire Line
	7400 3050 7400 2950
Connection ~ 7400 2950
Wire Wire Line
	7400 2950 7400 2850
Wire Wire Line
	7950 3550 7600 3550
Wire Wire Line
	7400 3550 7400 3450
Connection ~ 7400 3450
Wire Wire Line
	9250 5600 9250 5700
Connection ~ 9250 5700
Wire Wire Line
	9250 5700 9250 5800
Connection ~ 9250 5800
Wire Wire Line
	9250 5800 9250 5900
Connection ~ 9250 5900
Wire Wire Line
	9250 5900 9250 6000
Connection ~ 9250 6000
Wire Wire Line
	9250 6000 9250 6100
Connection ~ 9250 6100
Wire Wire Line
	9250 6100 9250 6200
Connection ~ 2300 1000
Connection ~ 2300 1100
Connection ~ 2300 3550
Connection ~ 3150 3200
Connection ~ 3150 3400
$Comp
L power:GND #PWR0113
U 1 1 5CC5B153
P 7150 450
F 0 "#PWR0113" H 7150 200 50  0001 C CNN
F 1 "GND" H 7155 277 50  0000 C CNN
F 2 "" H 7150 450 50  0001 C CNN
F 3 "" H 7150 450 50  0001 C CNN
	1    7150 450 
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR0114
U 1 1 5CC5B22D
P 7150 1350
F 0 "#PWR0114" H 7150 1200 50  0001 C CNN
F 1 "+3.3V" H 7165 1523 50  0000 C CNN
F 2 "" H 7150 1350 50  0001 C CNN
F 3 "" H 7150 1350 50  0001 C CNN
	1    7150 1350
	-1   0    0    1   
$EndComp
Text Notes 6050 5950 0    50   ~ 0
relay
NoConn ~ 7150 1050
NoConn ~ 7150 950 
NoConn ~ 7150 850 
NoConn ~ 7150 750 
NoConn ~ 7150 650 
NoConn ~ 7150 550 
NoConn ~ 6150 450 
NoConn ~ 6150 550 
NoConn ~ 6150 650 
NoConn ~ 6150 750 
NoConn ~ 6150 850 
NoConn ~ 6150 950 
NoConn ~ 6150 1050
NoConn ~ 6150 1150
NoConn ~ 6150 1250
NoConn ~ 6150 1350
Wire Wire Line
	7450 1150 7450 1250
Wire Wire Line
	7450 1250 7150 1250
Wire Wire Line
	7450 1150 7950 1150
Wire Wire Line
	7550 1250 7550 1200
Wire Wire Line
	7150 1200 7150 1150
Wire Wire Line
	7550 1250 7950 1250
Wire Wire Line
	7150 1200 7550 1200
$Comp
L power:+5V #PWR0115
U 1 1 5CCB2429
P 9250 5700
F 0 "#PWR0115" H 9250 5550 50  0001 C CNN
F 1 "+5V" V 9265 5828 50  0000 L CNN
F 2 "" H 9250 5700 50  0001 C CNN
F 3 "" H 9250 5700 50  0001 C CNN
	1    9250 5700
	0    -1   -1   0   
$EndComp
Text GLabel 6000 2100 2    50   Input ~ 0
A9
Text GLabel 9950 4650 2    50   Input ~ 0
A9
Text GLabel 6000 2200 2    50   Input ~ 0
A8
Text GLabel 9950 4750 2    50   Input ~ 0
A8
Text GLabel 6000 2300 2    50   Input ~ 0
A7
Text GLabel 9950 4850 2    50   Input ~ 0
A7
NoConn ~ 6000 2400
NoConn ~ 6000 2500
$Comp
L power:GND #PWR0116
U 1 1 5CCC5397
P 6000 2600
F 0 "#PWR0116" H 6000 2350 50  0001 C CNN
F 1 "GND" V 6005 2472 50  0000 R CNN
F 2 "" H 6000 2600 50  0001 C CNN
F 3 "" H 6000 2600 50  0001 C CNN
	1    6000 2600
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR0117
U 1 1 5CCC555E
P 6000 2700
F 0 "#PWR0117" H 6000 2550 50  0001 C CNN
F 1 "+3.3V" V 6015 2828 50  0000 L CNN
F 2 "" H 6000 2700 50  0001 C CNN
F 3 "" H 6000 2700 50  0001 C CNN
	1    6000 2700
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR0118
U 1 1 5CCC604B
P 6000 2800
F 0 "#PWR0118" H 6000 2650 50  0001 C CNN
F 1 "+3.3V" V 6015 2928 50  0000 L CNN
F 2 "" H 6000 2800 50  0001 C CNN
F 3 "" H 6000 2800 50  0001 C CNN
	1    6000 2800
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR0119
U 1 1 5CCC7F83
P 5950 3250
F 0 "#PWR0119" H 5950 3100 50  0001 C CNN
F 1 "+3.3V" V 5965 3378 50  0000 L CNN
F 2 "" H 5950 3250 50  0001 C CNN
F 3 "" H 5950 3250 50  0001 C CNN
	1    5950 3250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 5CCC8090
P 5950 3350
F 0 "#PWR0120" H 5950 3100 50  0001 C CNN
F 1 "GND" V 5955 3222 50  0000 R CNN
F 2 "" H 5950 3350 50  0001 C CNN
F 3 "" H 5950 3350 50  0001 C CNN
	1    5950 3350
	0    -1   -1   0   
$EndComp
Text GLabel 5950 3450 2    50   Input ~ 0
scl0
Text GLabel 9950 5050 2    50   Input ~ 0
scl0
Text GLabel 5950 3550 2    50   Input ~ 0
sda0
Text GLabel 9950 5150 2    50   Input ~ 0
sda0
$Comp
L power:+3.3V #PWR0121
U 1 1 5CCCB7E1
P 5850 3700
F 0 "#PWR0121" H 5850 3550 50  0001 C CNN
F 1 "+3.3V" V 5865 3828 50  0000 L CNN
F 2 "" H 5850 3700 50  0001 C CNN
F 3 "" H 5850 3700 50  0001 C CNN
	1    5850 3700
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0122
U 1 1 5CCCC5CF
P 5850 3800
F 0 "#PWR0122" H 5850 3550 50  0001 C CNN
F 1 "GND" V 5855 3672 50  0000 R CNN
F 2 "" H 5850 3800 50  0001 C CNN
F 3 "" H 5850 3800 50  0001 C CNN
	1    5850 3800
	0    -1   -1   0   
$EndComp
Text GLabel 5850 4200 2    50   Input ~ 0
sda2
Text GLabel 7950 1550 0    50   Input ~ 0
sda2
Text GLabel 5850 4300 2    50   Input ~ 0
sc12
Text GLabel 7950 1450 0    50   Input ~ 0
sc12
$Comp
L power:+5V #PWR0123
U 1 1 5CCD50CB
P 5950 5150
F 0 "#PWR0123" H 5950 5000 50  0001 C CNN
F 1 "+5V" V 5965 5278 50  0000 L CNN
F 2 "" H 5950 5150 50  0001 C CNN
F 3 "" H 5950 5150 50  0001 C CNN
	1    5950 5150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0124
U 1 1 5CCD5863
P 5950 5250
F 0 "#PWR0124" H 5950 5000 50  0001 C CNN
F 1 "GND" V 5955 5122 50  0000 R CNN
F 2 "" H 5950 5250 50  0001 C CNN
F 3 "" H 5950 5250 50  0001 C CNN
	1    5950 5250
	0    -1   -1   0   
$EndComp
$Comp
L conn:Conn_01x04_Female J12
U 1 1 5CCD6DAE
P 5750 5350
F 0 "J12" H 5642 4925 50  0000 C CNN
F 1 "Conn_01x04_Female" H 5642 5016 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 5750 5350 50  0001 C CNN
F 3 "~" H 5750 5350 50  0001 C CNN
	1    5750 5350
	-1   0    0    1   
$EndComp
Text GLabel 5950 5350 2    50   Input ~ 0
scl1
Text GLabel 7950 4350 0    50   Input ~ 0
scl1
Text GLabel 5950 5450 2    50   Input ~ 0
sda1
Text GLabel 7950 4450 0    50   Input ~ 0
sda1
$Comp
L conn:Conn_01x03_Female J14
U 1 1 5CCDB7F2
P 5800 6100
F 0 "J14" H 5692 5775 50  0000 C CNN
F 1 "Conn_01x03_Female" H 5692 5866 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 5800 6100 50  0001 C CNN
F 3 "~" H 5800 6100 50  0001 C CNN
	1    5800 6100
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR0125
U 1 1 5CCDC4D1
P 6000 6000
F 0 "#PWR0125" H 6000 5850 50  0001 C CNN
F 1 "+5V" V 6015 6128 50  0000 L CNN
F 2 "" H 6000 6000 50  0001 C CNN
F 3 "" H 6000 6000 50  0001 C CNN
	1    6000 6000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0126
U 1 1 5CCDCC55
P 6000 6100
F 0 "#PWR0126" H 6000 5850 50  0001 C CNN
F 1 "GND" V 6005 5972 50  0000 R CNN
F 2 "" H 6000 6100 50  0001 C CNN
F 3 "" H 6000 6100 50  0001 C CNN
	1    6000 6100
	0    -1   -1   0   
$EndComp
Text GLabel 6000 6200 2    50   Input ~ 0
A6
Text GLabel 9950 4950 2    50   Input ~ 0
A6
$Comp
L power:+5V #PWR0127
U 1 1 5CCDF333
P 5950 4450
F 0 "#PWR0127" H 5950 4300 50  0001 C CNN
F 1 "+5V" V 5965 4578 50  0000 L CNN
F 2 "" H 5950 4450 50  0001 C CNN
F 3 "" H 5950 4450 50  0001 C CNN
	1    5950 4450
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0128
U 1 1 5CCDFAD9
P 5950 4550
F 0 "#PWR0128" H 5950 4300 50  0001 C CNN
F 1 "GND" V 5955 4422 50  0000 R CNN
F 2 "" H 5950 4550 50  0001 C CNN
F 3 "" H 5950 4550 50  0001 C CNN
	1    5950 4550
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0129
U 1 1 5CCE027C
P 5950 4650
F 0 "#PWR0129" H 5950 4400 50  0001 C CNN
F 1 "GND" V 5955 4522 50  0000 R CNN
F 2 "" H 5950 4650 50  0001 C CNN
F 3 "" H 5950 4650 50  0001 C CNN
	1    5950 4650
	0    -1   -1   0   
$EndComp
Text GLabel 9950 5250 2    50   Input ~ 0
A3
Text GLabel 5350 5100 2    50   Input ~ 0
A3
$Comp
L conn:Conn_01x04_Female J15
U 1 1 5CCE1BF5
P 6700 4750
F 0 "J15" H 6728 4726 50  0000 L CNN
F 1 "Conn_01x04_Female" H 6728 4635 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 6700 4750 50  0001 C CNN
F 3 "~" H 6700 4750 50  0001 C CNN
	1    6700 4750
	-1   0    0    1   
$EndComp
$Comp
L conn:Conn_01x04_Female J16
U 1 1 5CCE367F
P 6700 5250
F 0 "J16" H 6728 5226 50  0000 L CNN
F 1 "Conn_01x04_Female" H 6728 5135 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 6700 5250 50  0001 C CNN
F 3 "~" H 6700 5250 50  0001 C CNN
	1    6700 5250
	-1   0    0    1   
$EndComp
$Comp
L conn:Conn_01x04_Female J17
U 1 1 5CCE3E7B
P 6700 5800
F 0 "J17" H 6728 5776 50  0000 L CNN
F 1 "Conn_01x04_Female" H 6728 5685 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 6700 5800 50  0001 C CNN
F 3 "~" H 6700 5800 50  0001 C CNN
	1    6700 5800
	-1   0    0    1   
$EndComp
$Comp
L conn:Conn_01x02_Female J18
U 1 1 5CCE77FF
P 6850 4150
F 0 "J18" H 6878 4126 50  0000 L CNN
F 1 "Conn_01x02_Female" H 6878 4035 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 6850 4150 50  0001 C CNN
F 3 "~" H 6850 4150 50  0001 C CNN
	1    6850 4150
	1    0    0    -1  
$EndComp
Text GLabel 6650 4150 0    50   Input ~ 0
Vbat
Text GLabel 7950 3450 0    50   Input ~ 0
Vbat
$Comp
L power:GND #PWR0130
U 1 1 5CCE9E80
P 6650 4250
F 0 "#PWR0130" H 6650 4000 50  0001 C CNN
F 1 "GND" H 6655 4077 50  0000 C CNN
F 2 "" H 6650 4250 50  0001 C CNN
F 3 "" H 6650 4250 50  0001 C CNN
	1    6650 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5CCE9F48
P 5200 4900
F 0 "R5" H 5270 4946 50  0000 L CNN
F 1 "10k" H 5270 4855 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5130 4900 50  0001 C CNN
F 3 "~" H 5200 4900 50  0001 C CNN
	1    5200 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5CCEA93A
P 5200 5300
F 0 "R6" H 5270 5346 50  0000 L CNN
F 1 "20k" H 5270 5255 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5130 5300 50  0001 C CNN
F 3 "~" H 5200 5300 50  0001 C CNN
	1    5200 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 4750 5950 4850
Wire Wire Line
	5950 4850 5550 4850
Wire Wire Line
	5550 4850 5550 4750
Wire Wire Line
	5550 4750 5200 4750
Wire Wire Line
	5200 5050 5200 5100
Wire Wire Line
	5350 5100 5200 5100
Connection ~ 5200 5100
Wire Wire Line
	5200 5100 5200 5150
$Comp
L power:GND #PWR0131
U 1 1 5CCF7AE8
P 5200 5450
F 0 "#PWR0131" H 5200 5200 50  0001 C CNN
F 1 "GND" H 5205 5277 50  0000 C CNN
F 2 "" H 5200 5450 50  0001 C CNN
F 3 "" H 5200 5450 50  0001 C CNN
	1    5200 5450
	1    0    0    -1  
$EndComp
$Comp
L conn:Conn_01x07_Female J5
U 1 1 5CCF9D5D
P 5650 4000
F 0 "J5" H 5542 3475 50  0000 C CNN
F 1 "Conn_01x07_Female" H 5542 3566 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07_Pitch2.54mm" H 5650 4000 50  0001 C CNN
F 3 "~" H 5650 4000 50  0001 C CNN
	1    5650 4000
	-1   0    0    1   
$EndComp
NoConn ~ 5850 3900
NoConn ~ 5850 4000
NoConn ~ 5850 4100
Text GLabel 6900 4550 2    50   Input ~ 0
MO
Text GLabel 6900 4650 2    50   Input ~ 0
MI
Text GLabel 7950 2250 0    50   Input ~ 0
MO
Text GLabel 7950 2350 0    50   Input ~ 0
MI
Text GLabel 6900 4750 2    50   Input ~ 0
RX3
Text GLabel 6900 4850 2    50   Input ~ 0
TX3
Text GLabel 7950 1850 0    50   Input ~ 0
RX3
Text GLabel 7950 1950 0    50   Input ~ 0
TX3
Text Notes 7100 4650 0    50   ~ 0
spi\n
Text GLabel 6900 5050 2    50   Input ~ 0
A14
Text GLabel 6900 5150 2    50   Input ~ 0
A15
Text GLabel 6900 5250 2    50   Input ~ 0
A16
Text GLabel 6900 5350 2    50   Input ~ 0
A17
Text GLabel 7950 3950 0    50   Input ~ 0
A14
Text GLabel 7950 4050 0    50   Input ~ 0
A15
Text GLabel 7950 4150 0    50   Input ~ 0
A16
Text GLabel 7950 4250 0    50   Input ~ 0
A17
Text Notes 7150 5150 0    50   ~ 0
Analog\n
Text GLabel 6900 5600 2    50   Input ~ 0
scl1
Text GLabel 6900 5700 2    50   Input ~ 0
sda1
Text GLabel 6900 5800 2    50   Input ~ 0
scl0
Text GLabel 6900 5900 2    50   Input ~ 0
sda0
NoConn ~ 7950 5250
NoConn ~ 7950 5150
NoConn ~ 7950 5050
NoConn ~ 7950 4950
NoConn ~ 7950 4750
NoConn ~ 7950 4650
NoConn ~ 7950 4550
NoConn ~ 7950 3850
NoConn ~ 7950 3750
NoConn ~ 7950 3350
NoConn ~ 7950 3250
NoConn ~ 7950 3150
NoConn ~ 7950 3050
NoConn ~ 7950 2950
NoConn ~ 7950 2750
NoConn ~ 7950 2850
NoConn ~ 7950 2650
NoConn ~ 7950 2550
NoConn ~ 7950 2450
NoConn ~ 7950 2150
NoConn ~ 7950 2050
NoConn ~ 7950 1750
NoConn ~ 7950 1650
NoConn ~ 7950 1350
NoConn ~ 9950 1050
NoConn ~ 9950 1150
NoConn ~ 9950 1250
NoConn ~ 9950 1350
NoConn ~ 9950 1450
NoConn ~ 9950 1550
NoConn ~ 9950 1650
NoConn ~ 9950 1750
NoConn ~ 9950 1850
NoConn ~ 9950 1950
NoConn ~ 9950 2050
NoConn ~ 9950 2150
NoConn ~ 9950 2350
NoConn ~ 9950 2450
NoConn ~ 9950 2550
NoConn ~ 9950 2650
NoConn ~ 9950 2750
NoConn ~ 9950 2850
NoConn ~ 9950 2950
NoConn ~ 9950 3050
NoConn ~ 9950 3150
NoConn ~ 9950 3250
NoConn ~ 9950 3350
NoConn ~ 9950 3650
NoConn ~ 9950 3750
NoConn ~ 9950 3950
NoConn ~ 9950 4050
NoConn ~ 9950 4150
NoConn ~ 9950 4250
NoConn ~ 9950 4450
NoConn ~ 9950 4550
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5CDB7680
P 6600 3550
F 0 "#FLG0102" H 6600 3625 50  0001 C CNN
F 1 "PWR_FLAG" H 6600 3723 50  0000 C CNN
F 2 "" H 6600 3550 50  0001 C CNN
F 3 "~" H 6600 3550 50  0001 C CNN
	1    6600 3550
	1    0    0    -1  
$EndComp
Text GLabel 6600 3550 3    50   Input ~ 0
Vbat
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5CDBA0A7
P 7600 3550
F 0 "#FLG0103" H 7600 3625 50  0001 C CNN
F 1 "PWR_FLAG" H 7600 3723 50  0000 C CNN
F 2 "" H 7600 3550 50  0001 C CNN
F 3 "~" H 7600 3550 50  0001 C CNN
	1    7600 3550
	1    0    0    -1  
$EndComp
Connection ~ 7600 3550
Wire Wire Line
	7600 3550 7400 3550
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 5CDBBB0D
P 5950 5150
F 0 "#FLG0104" H 5950 5225 50  0001 C CNN
F 1 "PWR_FLAG" H 5950 5323 50  0000 C CNN
F 2 "" H 5950 5150 50  0001 C CNN
F 3 "~" H 5950 5150 50  0001 C CNN
	1    5950 5150
	1    0    0    -1  
$EndComp
Connection ~ 5950 5150
$EndSCHEMATC
