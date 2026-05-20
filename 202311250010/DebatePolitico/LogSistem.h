#ifndef LOGSISTEM_H
#define LOGSISTEM_H

#include <iostream>
#include <fstream>
#include <string>

class LogSistem {
private:
    static LogSistem* instance;
    std::ofstream arquivo;
    LogSistem();

public:
    static LogSistem* getInstance();
    void registrar(const std::string& msg);
};

#endif