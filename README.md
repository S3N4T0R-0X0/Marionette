# Marionette
This repository contains a C code snippet that can be used to connect to an AM0N-Eye and Cobalt Strike beacon using a TCP socket on Linux. The code establishes a connection to the beacon, sends commands to it, and receives the responses. Note that you will need to provide the IP address and port number of the AM0N-Eye and Cobalt Strike beacon as command-line arguments when you run the program.

The code also includes a function for hiding the target process, which can be achieved by calling the original read() function and using the information obtained to conceal the process in the buf pointer.

To build the program, use the following command: gcc MARIONETTE.c -o MARIONETTE

Once compiled, the program can be executed with the following command: ./command_control ip_address port

                                       


![Screenshot from 2023-05-03 08-49-13](https://user-images.githubusercontent.com/121706460/235921849-c3766e12-ec4e-4e03-995d-2f038bf05127.png)
