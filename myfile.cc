#include "myFile.hh"

int creteFileName(char* fileName){
    time_t now = time(0);  // Get current time
    tm *ltm = localtime(&now);  // Convert to local time format

    std::stringstream ss;
    ss  << (ltm->tm_mday) << "-"
        << (1 + ltm->tm_mon) << "-"
        << (1900 + ltm->tm_year) << "_"
        << (ltm->tm_hour) << ":"
        << (ltm->tm_min) << ":"
        << (ltm->tm_sec) << ".txt";

    std::string filenameStr = ss.str();
    strcpy(fileName, filenameStr.c_str());

    return 0;
}

int createFile(char* path){
    FILE* fp;
    fp = fopen(path, "w+");
    fclose(fp);
    return 0;
}

int writeInAFile(char* path, char* text){
    FILE* fp; 
    fp = fopen(path, "a");
    fprintf(fp, text);
    return 0;
}