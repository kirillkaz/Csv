#include "Csv.h"
#include "logger/logFactory/logger.h"

/// \brief parsing your file to csv format
/// \param filename: name fo your file
void Csv::parsing(std::string filename){
    //создаю логгер
    logger* logFactory = new logger();
    Ilogger* log = logFactory->create();

    std::ifstream file(filename);
    std::string stroke;
    int countOfStroke = 1;
    while(getline(file,stroke)){
        std::vector<std::string> tmp;
        this->CsvArray.push_back(tmp);
        int cpyPos = 0;
        bool isMarks = false;
        bool isFirstMark = true;
        for(int i=0;i<stroke.length();i++){
            if (stroke[i] == '"') {

                //если встретилась закрывающая ковычка, то копирую строку в ячейку массива

                //reworked
                //if(isMarks) this->CsvArray[countOfStroke-1].push_back(stroke.substr(cpyPos,i-cpyPos));
                if(isMarks && ((i == stroke.length()-1) || stroke[i+1] == ','))
                    this->CsvArray[countOfStroke-1].push_back(stroke.substr(cpyPos,i-cpyPos));

                if (!isMarks || ((i == stroke.length()-1) || stroke[i+1] == ',')) isMarks = !isMarks;

                //если встретилась первая ковычка
                if(isMarks && isFirstMark) {
                    isFirstMark = false;
                    cpyPos = i+1;
                }

                //если встретилась последняя ковычка
                else if (!isMarks) {
                    isFirstMark = true;
                    cpyPos = i+2;
                }
            }

            else if(stroke[i] == ',' && isMarks == false){
                if (stroke[i-1] != '"') {
                    std::string tmpstroke = stroke.substr(cpyPos, i - cpyPos);
                    this->CsvArray[countOfStroke - 1].push_back(tmpstroke);
                    cpyPos = i + 1;
                }
            }
            else if(i == stroke.length()-1) this->CsvArray[countOfStroke - 1].push_back(stroke.substr(cpyPos, i - cpyPos+1));
        }
        countOfStroke++;
    }
    //проверка на Csv фармат (во всех строках должно быть одинаковое кол-во полей)
    if(this->CsvArray.size() > 1 && this->CsvArray[this->CsvArray.size()-1].size() != this->CsvArray[this->CsvArray.size()-2].size()){
        //очищаю массив со строками Csv
        log->logError("Внимание! Файл не соответствует CSV фармату! В строках разное число полей!");
        log->logInfo("Инициализация очистки данных из структуры...");
        while(this->CsvArray.size()>0) this->CsvArray.pop_back();
        log->logInfo("Данные были успешно удалены!");
        return;
    }
    file.close();
}
