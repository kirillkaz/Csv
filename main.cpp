#include <iostream>
#include "Csv.h"
#include <windows.h>
#include "logger/logFactory/logger.h"
#include "tests.h"
int main() {
    SetConsoleOutputCP(CP_UTF8);
/*
    logger* logFactory = new logger();
    Ilogger* log = logFactory->create();

    Csv data;
    data.parsing("mydata");

    if(data.CsvArray.size() == 0) log->logWarning("Внимание! структура с CSV фарматом пуста!");
*/
    test run;
    run.runTests();
    return 0;
}
