# Marionette
Here's an example C code snippet for connecting to a AM0N-Eye and Cobalt Strike beacon using a TCP socket on Linux.
In this code, replace the call to write with the code that sends the command to the AM0N-Eye and Cobalt Strike beacon over a TCP socket, and replace the call to read with the code that receives the response from the beacon over the same socket. 
Note that you will need to provide the IP address and port number of the AM0N-Eye and Cobalt Strike beacon as command-line arguments when you run the program.
Replace ip_address and port with the IP address and port number of the AM0N-Eye and Cobalt Strike beacon you want to connect to.

Hiding  Target Process
Since function already calls the original read() function  have all the information we need to hide the process in the buf pointer.


Build: gcc MARIONETTE.c -o MARIONETTE
Use : ./command_control ip_address port


![Screenshot from 2023-05-03 08-49-13](https://user-images.githubusercontent.com/121706460/235921050-c476eed7-ff85-4b20-89fd-899318af3573.png)



