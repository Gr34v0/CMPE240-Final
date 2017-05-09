Using standard C libraries and GCC to compile.

**INSTALLATION**

To disable Debug mode: in errorhandle.h, change the line
    #define debug 1
to 
    #define debug 0

To disable No-Network mode: in errorhandler.h, change the line
    #define nonetwork 1
to 
    #define nonetwork 0

To complile on...

Cygwin:           $gcc -o SensorNode *.c

Bash on Windows 
Linux Subsystem:  $gcc -o SensorNode *.c -lm

Debian Bash:      $gcc -o SensorNode *.c -lm

NOTE: Will not compile on standard MinGW installations.

Compiler will spit out a standalone, portable executable (unless you compile on Cygwin, where it will only work from a Cygwin terminal).


**RUNNING SensorNode**

To run the SensorNode program, from a terminal, run 
    $./SensorNode <Your Target IP Address Here>
where <Your Target IP Address Here> is the IP address of the server you are generating information for.
