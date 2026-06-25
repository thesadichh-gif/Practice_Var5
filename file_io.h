#ifndef FILE_IO_H
#define FILE_IO_H


int* load_from_csv(const char* filename, int* size);


void save_to_csv(const char* filename, int* arr, int n);

#endif 
