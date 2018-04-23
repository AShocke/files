#include <string> 
#include <iostream>
#include "csv.h"
#include "file.h"

const std::string TEST = "test.txt";
int main() {
	std::cout << word_count(TEST) << "\n";
	std::cout << words_in_file(TEST, "test") << "\n";
    replace_words(TEST, "test", "theorem");
	append(TEST, "cheese");
	csv v("text.csv");
	std::cout << "rows: " << v.rows() << "\ncolumns: " << v.columns() << "\n";
	std::cout << "(key = 1) " << v.get_row("1") << "\n";
	v.export_to("text.html", "black", "brown", "monospace", "1pt solid black", "right");
	v.print_table(); 
} 

