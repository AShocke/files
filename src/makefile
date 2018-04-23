CC:= g++

main: file csv
	$(CC) file.cc csv.cc main.cc -o $@
csv: file
	$(CC) -c file.cc main.cc 
file:
	$(CC) -c file.cc

