/*
 * csv.h
 * Author: Aisosa Efemwonkieke <isosceles.aisosa@gmail.com>
 * 
 */
#ifndef CSV_H
#define CSV_H

#include <string>
#include <cstdio>
#include <fstream>
#include <vector>
const std::string tr = "<tr>";
const std::string tr_c = "</tr>";
const std::string td = "<td>";
const std::string td_c = "</td>";
const std::string tab = "  "; // two space indentation
class csv
{
public:
	/*
	 * Assumes that the csv file is valid
	 */
	csv(std::string csv_file) {
		init(csv_file);
	}
	int rows() {
		return rows_;
	}
	
	int columns() {
		return columns_;
	}
	/*
	 * returns the row that contains the first instance of key
	 */
	std::string get_row(std::string key);
	void print_table();
	/* 
	 * color options:
	 * rgb(x,x,x)
	 * #xxxxxx
	 * colorname
	 *
	 * 
	 * align: 
	 * right
	 * left
	 * center
	 * justify
	 */
	void export_to(std::string path,std::string color, std::string bgcolor,
	               std::string font, std::string border, std::string align); 
private:
	void init(std::string csv_file);
	std::vector<std::vector<std::string>> table_;
	/*
	 * Lists the values of table_[row] seperated by a space (' ') character
	 */
	std::string get_row_string(int row);
	int rows_;
	int columns_;
};
#endif
