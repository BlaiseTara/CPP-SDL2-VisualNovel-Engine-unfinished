# include "interpreter.h"

char ReadBinaryByte(unsigned int ByteNumber){
    std::ifstream file("code.bin", std::ios::binary);

    if (!file.is_open()) {
        return -1;
    }


    // Seek to the specified position
    file.seekg(ByteNumber);

    // Read the byte at the current position
    char byte;
    file.read(&byte, 1);

    if (!file) {
        return -1;
    }

    file.close();

    // return the byte converted to decimal
    return byte;
}