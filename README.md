# CCP Serial Reader

“CCP Serial reader” is a simple serial moniotr for linux.
This program allows the saving of logs that are written to the serial.

## To build the program:

To build the program, simply invoke the make command in the shell (no root privileges required)

```
$ make
```

## To run the program:

To run the program, when you launch it, you need to specify (as parameters):
Arg[1] -> Serial port name
Arg[2] -> Serial port speed (9600 by default)
Arg[3] -> Path of the log file (optional)

The path must have read and write permissions and must be written in the following format: 

```
PATH -> "/home/<your_name>/"
COMMAND FOR RUN PORGRAM: $ ./serialReaderOut.out <arg1> <arg2> <arg3>
```
