#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

#include "myFile.hh"

#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

int main(int argc, char* argv[]) {
    char* serialPort = nullptr;
    int speed = 9600;

    char* logPath = nullptr;
    char fileName[30];

    if (argc > 1) {
        // serial port
        serialPort = argv[1];

        if (argc > 2 && argv[2][0] != '\0') {
            // get speed
            speed = atoi(argv[2]);
        }
        if (argc > 3 && argv[3][0] != '\0'){
            // get log path
            logPath = argv[3];
            
            // create file name and file path
            creteFileName(fileName);
            logPath = strcat(logPath, fileName);

            // create file
            if (createFile(logPath) == 0) {
                cout << "The log file was successfully created" << endl;
            } 
            else {
                cerr << "Failed to create log file" << endl;
                return 1;
            }
        }
    } 
    else {
        cerr << "Incorrect or missing serial port" << endl;
        cerr << "---------------------" << endl;
        cerr << "arg[1] -> port name" << endl;
        cerr << "arg[2] -> port speed" << endl;
        cerr << "arg[3] -> log path" << endl;
        cerr << "The log file will be created if you enter the log path (arg[3])" << endl;
        cerr << "---------------------" << endl;
        return 1;
    }

    // log on screen
    cout << "Serial port     : " << serialPort << endl;
    cout << "Transfer speed  : " << speed << endl;
    cout << "Log file path   : " << logPath << endl;
    cout << "Log file name   : " << fileName << endl;
    // log on file 
    char message[CHAR_MAX] = "";
    snprintf(message, CHAR_MAX, "Serial port     : %s\n", serialPort);
    writeInAFile(logPath, message);
    snprintf(message, CHAR_MAX, "Transfer speed  : %d\n", speed);
    writeInAFile(logPath, message);

    // I/O set up
    io_context io;
    serial_port serial(io, serialPort);

    // Serial port parameters
    serial.set_option(serial_port_base::baud_rate(speed));
    serial.set_option(serial_port_base::character_size(8));
    serial.set_option(serial_port_base::parity(serial_port_base::parity::none));
    serial.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));
    serial.set_option(serial_port_base::flow_control(serial_port_base::flow_control::none));

    char buff[CHAR_MAX];
    boost::system::error_code ec;

    while (true) {
        size_t len = serial.read_some(buffer(buff), ec);

        if (ec) {
            cerr << "Error reading from serial port: " << ec.message() << endl;
            break;
        }

        cout.write(buff, len);
    }

    return 0;
}
