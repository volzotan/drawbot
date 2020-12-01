# Note:

the cheap chinese Arduino Nano clones come with an old Bootloader (1.5kb) which barely allows to fit grbl in the flash.
When enabling corexy in grbl, the size increases slightly and it won't fit anymore.
Flash the Arduino Uno bootloader to the Arduino that runs grbl and any bootloader to the one running the Co-Processor code.

$100 = 250.000    (X-axis travel resolution, step/mm)
$101 = 250.000    (Y-axis travel resolution, step/mm)
$102 = 250.000    (Z-axis travel resolution, step/mm)
$110 = 500.000    (X-axis maximum rate, mm/min)
$111 = 500.000    (Y-axis maximum rate, mm/min)
$112 = 500.000    (Z-axis maximum rate, mm/min)
$120 = 10.000    (X-axis acceleration, mm/sec^2)
$121 = 10.000    (Y-axis acceleration, mm/sec^2)
$122 = 10.000    (Z-axis acceleration, mm/sec^2)
$130 = 200.000    (X-axis maximum travel, millimeters)
$131 = 200.000    (Y-axis maximum travel, millimeters)
$132 = 200.000    (Z-axis maximum travel, millimeters)

$100 = 100.000    
$101 = 100.000    
$102 = 100.000    
$110 = 10000.000    
$111 = 10000.000    
$112 = 500.000   
$120 = 500.000   
$121 = 500.000   
$122 = 30.000   
$130 = 800.000    
$131 = 800.000    
$132 = 10.000    