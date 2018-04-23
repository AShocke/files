/*
 * file.cc
 * Author: Aisosa Efemwonkieke <isosceles.aisosa@gmail.com>
 * 
 */
#include "file.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


std::ofstream open_file_output(std::string filename) {
	std::ofstream o;
	o.open(filename);
	if (!o.is_open()) {
		std::cerr << "ERROR: Could not open file " << filename << ".\n";
		return o;
	}
	return o;
}

std::ifstream open_file_input(std::string filename) {
	std::ifstream f;
	f.open(filename);
	if (!f.is_open()) {
		std::cerr << "ERROR: Could not open file " << filename << ".\n";
		return f;
	}
	return f;
}
int word_count(std::string filename) {
	int count = 0;
	std::ifstream f = open_file_input(filename);
	std::string word;
	while (f >> word) {
		count++;
	}
	f.close();
	return count;
}

int line_count(std::string filename) {
	int count = 0;
	std::ifstream f = open_file_input(filename);
	char line[256];
	while ( f.getline(line, 256)) {
		count++;
	}
	f.close();
	return count;
}
int words_in_file(std::string filename, std::string search) {
	int count = 0;
	std::ifstream f = open_file_input(filename);
	std::string word;
	while (f >> word) {
		if (word == search) {
			count++;
		}
	}
	f.close();
	return count;

}
void replace_words(std::string filename, std::string to_replace, std::string replacement) {
	std::ifstream f;
	std::ofstream o;
	std::string line;
	std::string text;
	f = open_file_input(filename);
	while (std::getline(f, line)) {
		std::stringstream stream (line);
		std::string word;
		while (stream >> word) {
			if (word == to_replace) {
				word = replacement;
			}
			text += word + " ";
		}
		text += "\n";
	}
	f.close();
	o = open_file_output(filename);
	o << text;
}
void append(std::string filename, std::string to_append) {
	std::ifstream f = open_file_input(filename);
	std::string line;
	std::string text = "";
	while (std::getline(f, line)) {
		text += line;
		text += "\n";
	}
	f.close();
	text += to_append;
	std::ofstream o = open_file_output(filename);
	o << text;
	o.close();
}


