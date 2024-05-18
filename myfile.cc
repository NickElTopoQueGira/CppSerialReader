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
    // If it returns 0 it means the file was opened correctly otherwise  
    // if it returns 1 the file was not opened

    FILE* fp = fopen(path, "a");
    if(fp == nullptr){
        return 1;
    }
    fprintf(fp,"%s",text);
    fclose(fp);
    return 0;
}

int isFileExist(char* path){
    // If it returns 0 the file exists otherwise 
    // if it returns 1 the file does not exist
    
    FILE* fp;
    fp = fopen(path, "r");
    if(fp == NULL){
        return 1;
        fclose(fp);    
    }
    fclose(fp); 
    return 0;
}