# manchester
v1.0 Manchester Coding App

Description: This app will take strings in a variety of ways encode them based on Oregon Weather and Manchester Encoding described in the /doc/manchester_coding_test.pdf

File Structure:
-/src - Includes all C files, obj folder, and Makefile
-/includes - Header Files
-/build - Location of the binary program.
-/doc - Included PDF of parameters coded too.
-build.sh - Building and running functions.
-input.txt - Text file used in the application input, randomly generated txt file.
-output.txt - Text file used in the application output, encoded random file.
-README.md - This file!
-.gitignore

Building: The GitHub contains a prebuilt binary, but if you want to make changes and build a new one use the ./build.sh.

"./build.sh all" - Clean and compile the code into the build directory
"./build.sh clean" - Deletes any .o files and the build directory

-Any additional C files added to the build will involve editing the Makefile in the src directory.
Running the Program: The build script also allows you to run the program.
-Build on a Linux system or WindowsSubsytemLinux
-GCC and Make need to be installed

Running: The binary can be called directly or use the build.sh to run useful cases.

"./build.sh ex1" - Will run example 1 from pdf (Ignore 0x0A in hexdump, not part of code)
"./build.sh ex2" - Will run example 2 from pdf (Example 2 adds a new line into the encoding, mine does not.)(Ignore 0x0A in hexdump, not part of code)
"./build.sh ex3" - Will run example 3 from pdf (Ignore 0x0A in hexdump, not part of code)
"./build.sh ren [args]" - Will run the program from the build.sh
"./manchester [args]" - Will run the program directly

Help Menu:
Mode = Standard In
Format: 'manchester'
Description: Type in string and press enter to encode string.

Mode = Print Select
Format: 'manchester [mode] [string] [print_type]'
Description: Encode string and print selected output.
[mode] = -s
[string]
         Any String (MAX = 1024)
[output_type]
        -b = Binary
        -h = Hex
        -a = Ascii

Mode = File Input Output
Format: 'manchester [mode] [file] [print_type]'
Description: Type string to encode in input.txt or other file. Encode saved to output.txt.
[mode] = -f
[file] = Ex. input.txt[output_type]
        -b = Binary
        -h = Hex
        -a = Ascii

Improvements/Bugs in App:
-Writing to text file in binary and hex writes the values but doesn't convert the values into ascii that's readable like binary and hex
    -Need to convert the values to ascii before writing to the file
-New line artifact
    -There's a new line artifact that makes one of the most readable but appears in the hexdump when it shouldn't
-Interactive
    -Including a real time encoding where you type characters and it automatically adds to the console encode output, next time ;-)


