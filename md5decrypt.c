#include <stdio.h>
#include <string.h>

#define MLL 128 // Max Line Length

int main(int argc, char **argv) {
	
	// if has 3 arguments
	if (argc == 3) {  
		
		// if hash length is 32
		if (32 == strlen(argv[1])) {

			FILE *hashes;
			// Opening the file (argv[2])
			hashes = fopen(argv[2], "r");
		
			// if file exists
			if (hashes != NULL) {

				char fHash[MLL];
				char *hash;
				char *string;

				while (fgets(fHash, MLL, hashes) != NULL) {

					// hash receive the chars before ":"
					hash = strtok(fHash, ":");
					// string receive the chars after ":"
					string = strtok(NULL, "\n");

					// Comparing if hash and argv are equal
					if (strcmp(hash, argv[1]) == 0) {
						printf("Hash found! %s\n", string);
						break;
					}
				}

				fclose(hashes);

			} else 
				printf("File \"%s\" not found!\n", argv[2]);
			
		} else 
			printf("Invalid Hash\n");
		
	} else
		printf("Usage: ./md5decrypt <hash> <hashes_file>\n");

	return 0;
}

