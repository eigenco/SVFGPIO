gcc -c liberror.c
gcc -c libgpiojtag.c -I . -std=c99
gcc -c svf2csvf.c -I .
gcc -c core.c -I .
gcc -c util.c -I .
gcc -c libusbwrap.c -I .
gcc -c unbounded_queue.c -I .
gcc main.c liberror.o core.o libgpiojtag.o util.o svf2csvf.o libusbwrap.o unbounded_queue.o -lwiringPi -lusb-1.0
