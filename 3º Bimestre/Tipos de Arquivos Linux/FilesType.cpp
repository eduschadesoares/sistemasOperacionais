#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	DIR *dir;
	struct dirent *entry;

	int choice;
	int result = 1;

	// ----- HELP

	if (strcmp(argv[1], "--help") == 0) {
		printf(" Select an option to display files in a directory.\n\n");
		printf(" Usage: ./program [PATH]... [FILE_TYPE]...\n\n");
		printf("  -a 	to display all types files\n");
		printf("  -u 	to display unknown type [DT_UNKNOWN]\n");
		printf("  -f 	to display fifo type [DT_FIFO]\n");
		printf("  -c 	to display character type [DT_CHR]\n");
		printf("  -d 	to display directory type [DT_DIR]\n");
		printf("  -b 	to display block type [DT_BLK]\n");
		printf("  -r 	to display regular type [DT_REG]\n");
		printf("  -l 	to display link type [DT_LNK]\n");
		printf("  -s 	to display socket type [DT_SOCK]\n\n");
		printf(" Example: \"./program /etc -r\"\n\n");
		return -1;
	}

	// ----- HELP 2

	if (argc <= 1) {
		printf("Error!\nYou need to insert a path!\n");
		printf("Try '--help' for more information.\n");
		return -1;
	} else if (argc < 3) {
		printf("Error!\nYou need to insert a file type!\n");
		printf("Try '--help' for more information.\n");
		return -1;
	}

	// ----- OPTIONS

	if (strcmp(argv[2], "-u") == 0) {
		printf("Displaying 'Unknown type'...\n");
		choice = DT_UNKNOWN;
		} else if (strcmp(argv[2], "-f") == 0) {
			printf("Displaying 'Fifo type'...\n");
			choice = DT_FIFO;
			} else if (strcmp(argv[2], "-c") == 0) {
				printf("Displaying 'Character type'...\n");
				choice = DT_CHR;
				} else if (strcmp(argv[2], "-d") == 0) {
					printf("Displaying 'Directory type'...\n");
					choice = DT_DIR;
					} else if (strcmp(argv[2], "-b") == 0) {
						printf("Displaying 'Block type'...\n");
						choice = DT_BLK;
						} else if (strcmp(argv[2], "-r") == 0) {
							printf("Displaying 'Regular type'...\n");
							choice = DT_REG;
							} else if (strcmp(argv[2], "-l") == 0) {
								printf("Displaying 'Link type'...\n");
								choice = DT_LNK;
								} else if (strcmp(argv[2], "-s") == 0) {
									printf("Displaying 'Socket type'...\n");
									choice = DT_SOCK;
									} else if (strcmp(argv[2], "-a") == 0) {
										printf("Displaying all types files...\n");
										choice = 16;
										} else {
											printf("Insert a valid option!\n");
											printf("Try '--help' for more information.\n");
											return -1;
											}
	
	if (dir = opendir (argv[1])) {
		int counter = 0;
		while ((entry = readdir (dir))) {
			if(choice == 16) {
				printf("File of type %2.d | %s\n", entry->d_type, entry->d_name);
				counter += 1;
			} else if(entry->d_type == choice) {
				printf("File of type %2.d | %s\n", entry->d_type, entry->d_name);
				counter += 1;
				}
	}
		closedir (dir);
		result = 0;
		if (counter == 0) {
			printf("No results for this found type in \"%s\"\n", argv[1]);
		} else if(counter == 1) {
			printf("Displayed %d file found in \"%s\".\n", counter, argv[1]);
			} else {
				printf("Displayed %d files found in \"%s\".\n", counter, argv[1]);
				}
	} else {
		perror ("openddir()");
		}
	return result;
}
