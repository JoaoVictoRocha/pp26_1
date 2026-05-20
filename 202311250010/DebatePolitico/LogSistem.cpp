#include "LogSistem.h"

LogSistem* LogSistem::instance = nullptr;

LogSistem::LogSistem() {
    arquivo.open("log.txt", std::ios::app); // Append mode para não apagar logs anteriores
}

LogSistem* LogSistem::getInstance() {
    if(instance == nullptr)
        instance = new LogSistem();
    return instance;
}

void LogSistem::registrar(const std::string& msg) {
    if(arquivo.is_open()) {
        arquivo << msg << std::endl;
    }
}