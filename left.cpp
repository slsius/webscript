#include <stdio.h>
#include "serialib.h"
#include <sstream>
#include <bitset>
#include <string>
#include <iomanip>


#if defined (_WIN32) || defined( _WIN64)
#define         DEVICE_PORT             "COM9"                               // COM1 for windows
#endif

#ifdef __linux__
#define         DEVICE_PORT             "/dev/ttyO1"                         // ttyS0 for linux
#endif

int main()
{
    serialib LS;                                                            // Object of the serialib class
    int Ret;                                                                // Used for return values
    char Buffer[128];




    // Open serial port

    Ret=LS.Open(DEVICE_PORT,115200);                                        // Open serial link at 115200 bauds
    cout<<"Ret Value write:"<<Ret<<endl;
    if (Ret!=1) {                                                           // If an error occured...
        printf ("Error while opening port. Permission problem ?\n");        // ... display a message ...
        return Ret;                                                         // ... quit the application
    }
    printf ("Serial port opened successfully !\n");




    // Write the AT command on the serial port
    LS.WriteChar(128);
    LS.WriteChar(131);
    
    LS.WriteChar(148);
    LS.WriteChar(1);
    LS.WriteChar(7);
   
	LS.WriteChar(145);
	LS.WriteChar(0);
	LS.WriteChar(64);
	LS.WriteChar(0);
	LS.WriteChar(0);
	



    // Close the connection with the device

    LS.Close();

    return 0;
}
