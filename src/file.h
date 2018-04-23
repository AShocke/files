
/*
 * file.h
 * Author: Aisosa Efemwonkieke <isosceles.aisosa@gmail.com>
 * 
 */

#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include<fstream>
std::ofstream open_file_output(std::string filename);
std::ifstream open_file_input(std::string filename);
int word_count(std::string filename);
int line_count(std::string filename);
int words_in_file(std::string filename, std::string search);
void replace_words(std::string filename, std::string to_replace, std::string replacement);
void append(std::string filename, std::string to_append);


#endif


 
