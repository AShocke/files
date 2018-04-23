#include <string>
#include <cstdio>
#include <fstream>
#include <vector>
#include <sstream>
#include "csv.h"
#include "file.h"

void csv::init(std::string csv_file) {
	std::ifstream f(csv_file);
	if (f.is_open()) {
		std::string line;
		while (std::getline(f, line)) {
			std::stringstream s(line);
			std::string value;
			std::vector<std::string> row;
			while (std::getline(s, value, ',')) {
				row.push_back(value);
			}
			table_.push_back(row);
		}
		f.close();
	}
	else {
		std::cerr << "ERROR opening file: " + csv_file + "\n";
	}
	rows_ = table_.size();
	columns_ = table_[0].size();
}

void csv::print_table() {
	for (int i = 0; i < table_.size(); i++) {
		std::cout << get_row_string(i);
		std::cout << "\n";
	}
}

std::string csv::get_row(std::string key) {
	for (int i = 0; i < table_.size(); i++) {
		for (int j = 0; j < table_[0].size(); j++) {
			if (table_[i][j] == key) {
				return get_row_string(i);
			}
		}
	}
	return "";
}
std::string csv::get_row_string(int row) {
	std::string line = "";
	for (int i = 0; i < table_[0].size(); i++ ){
		line += table_[row][i] + " ";
	}
	return line;
}
void csv::export_to(std::string path, std::string color, std::string bgcolor,
				    std::string font, std::string border, std::string align) {
	std::string pre_code = "<!DOCTYPE html>\n<html>\n";
	std::string pre_options = "<head>\n<style>\n";
	std::string tbl_options = "table {\n" + tab + "font-family: " + font + "\n"
		+ tab + "color: " + color + "\n}\n";
	std::string data_options = "td {\n" + tab + "border: " + border + "\n" + tab + "align: " + align + "\n}\n";
	std::string row_options =  "tr {\n" + tab + "background-color: " + bgcolor + "\n}\n";
	std::string options =  tbl_options + data_options + row_options;
	std::string post_options = "</style>\n</head>\n";
	std::string pre_table = "<body>\n<table>\n";
	std::string post_table = "</table>\n</table>\n";
	std::string post_code = "</html>\n";
	std::string html = pre_code + pre_options + options + post_options + pre_table;
	for (int i = 0; i < table_.size(); i++) {
		html += tab + tr + "\n";
		for (int j = 0; j < table_[0].size(); j++) {
			html += (tab + tab) + td + table_[i][j] + td_c + "\n";
		}
	}
	html += post_table + post_code;
	std::ofstream o(path);
	if (o.is_open()) {
		o << html;
		o.close();
	}
	else {
		std::cerr << "ERROR opening file: " + path + "\n";
	}
	
}
