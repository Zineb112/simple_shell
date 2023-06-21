#include "shell.h"

char* _strtok(char* str, const char* delimiters) {
	static char* token1 = NULL;
	static char* tokens = NULL;   

	if (str != NULL) {
		token1 = str;
	} else if (tokens == NULL) {
		return NULL;
	} else {
		token1 = tokens;
	}

	char* delim_pos = token1;
	while (*delim_pos != '\0') {
		if (*delim_pos == *delimiters) {
			*delim_pos = '\0';
			tokens = delimi_pos + 1;
			return token1;
		}
		delim_pos++;
	}

	tokens = NULL;  
	return token1;
}
