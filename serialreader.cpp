#include <iostream>
#include "myFile.hh"

using namespace std;

int main(int argc, char* argv[]) { 
    char* serialPort;
    int speed = 9600;

    char* logPath;
    char* fileName;
    
    if (argc > 1) {
        serialPort = argv[1];
        if (argc > 2 && argv[2][0] != '\0') {
            speed = atoi(argv[2]);
        }
        if (argc > 3 && argv[3][0] != '\0') {
            logPath = argv[3];
            creteFileName(fileName);
            logPath = strcat(logPath, fileName);
            if (createFile(logPath) == 0){
                cout << "The log file was successfully created" << endl;
            }
        }
    } else {
        cout << "Incorrect or missing serial port" << endl;
        
        cout << "---------------------" << endl;
        cout << "arg[1] -> port name" << endl;
        cout << "arg[2] -> port speed" << endl;
        cout << "arg[3] -> log path" << endl;
        cout << "The log file will be created if you enter the log path (arg[3])" << endl;
        cout << "---------------------" << endl;
        
        return 1;
    }

    cout << "Serial port     : " << serialPort << endl;
    cout << "Transfer speed  : " << speed << endl;
    cout << "Log file path   : " << logPath << endl;
    cout << "Log file name   : " << fileName << endl;

    

    return 0;
}
