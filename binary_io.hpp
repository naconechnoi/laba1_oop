#pragma once

#include <string>
using namespace std;

namespace binary_io {

    unsigned readUnsigned(ifstream& fin) {
        unsigned buffer;
        fin.read((char*)&buffer, 4);
        return buffer;
    }

    string readString(ifstream& fin) {
        unsigned len;
        fin.read((char*)&len, 4);
        char* buffer = new char[len];
        fin.read(buffer, len);
        return string(buffer);
    }

    void writeUnsigned(ofstream& fout, unsigned& buffer) {
        fout.write((char*)&buffer, 4);
    }

    void writeString(ofstream& fout, string& buffer) {
        unsigned len = buffer.length() + 1;
        fout.write((char*)&len, 4);
        fout.write(buffer.c_str(), len);
    }

};