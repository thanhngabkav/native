#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../string.h"
#include "../general.h"

#define MAX_SIZE 1000000

// Find and replace
char  *string_replace(char *target, char* find, char* replace_with) {
	char *result;
	register int i, count = 0;
	int oldlen = strlen(find);
	int newlen = strlen(replace_with);

	for (i = 0; target[i] != '\0'; i++)
	{
		if (strstr(&target[i], find) == &target[i])
		{
			count++;
			i += oldlen - 1;
		}
	}
	result = (char*) malloc(i + count * (newlen - oldlen));
	if (result == NULL) {
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (*target)
	{
		if (strstr(target, find) == target)
		{
			strcpy(&result[i], replace_with);
			i += newlen;
			target += oldlen;
		} else result[i++] = *target++;
	}
	result[i] = '\0';
	return result;
}

// Split string to one dimession array by delimiter
char **string_split(char *target, const char *delim_) {
	char* delim = (char*) delim_;
	int len_target = length_pointer_char(target);
	int len_delim = length_pointer_char(delim);
	int distance = len_target - len_delim + 1;
	int len_item = 0;
	char *segment = calloc(len_delim, sizeof(char));
	char **data = malloc(MAX_SIZE * sizeof(char*));
	register int count = 0, from = 0, to = 0;
	// Compare delimiter per target segment
	while (to <= distance) {
		memcpy(segment, &target[to], len_delim);
		if (strcmp(segment, delim) == 0) {
			if (to - from > 0) {
				len_item = to - from;
				char *item = malloc((len_item + 1) * sizeof(char));
				memcpy(item, &target[from], len_item);
				item[len_item] = '\0';
				// Append element to result
				data[count++] = item;
				from = to + len_delim;
			} else from += len_delim;
			to = from;
			continue;
		}
		++to;
	}
	if (to - from > 0) {
		len_item = to - from;
		char *item = malloc((len_item + 1) * sizeof(char));
		memcpy(item, &target[from], len_item + 1);
		item[len_item] = '\0';
		// Append element to result
		data[count++] = item;
	}
	// Saving memory
	char **result = malloc((count + 1) * sizeof(char*));
    memcpy(result, data, count * sizeof(char*));
	// End array
	result[count] = '\0';
	// Deallocate memory
	free(segment);
	free(data);
	return result;
}

// Join string with delimiter
char *string_join(char *target[], const char *delim) {
	int num = length_pointer_pointer_char(target) - 1;
	int len = 0, wlen = 0;
	char *tmp = calloc(MAX_SIZE, sizeof(char));
	for (int i=0; i<num; i++) {
		// Copy memory segment
		wlen = strlen(target[i]);
		memcpy(tmp + len, target[i], wlen);
		len += wlen;
		// Copy memory segment
		wlen = strlen(delim);
		memcpy(tmp + len, delim, wlen);
		len += wlen;
	}
	// Copy memory segment
	wlen = strlen(target[num]);
	memcpy(tmp + len, target[num], wlen);
	len += wlen;
	len += 1;
	// Saving memory
	char *result = calloc(len, sizeof(char));
	memcpy(result, tmp, len);
	// Deallocate memory
	free(tmp);
	return result;
}

// Trim all space left and right
char *string_trim(char *target) {
	int len, left, right;
	left = 0;
	right = strlen(target) - 1;
	while (target[left] == ' ') left++;
	while (target[right] == ' ') right--;
	len = right - left + 1;
	char *result = calloc(len, sizeof(char));
	memcpy(result, &target[left], len);
	return result;
}

int string_start(char *target, const char *prefix) {
    int target_length = length_pointer_char(target);
    int prefix_length = length_pointer_char(prefix);
    if (target_length < prefix_length) {
		return 0;
	}

    register int i;
    for (i = 0; i < prefix_length; i++) {
        if (prefix[i] != target[i]) {
            return 0;
        }
    }
    return 1;
}

int string_end(char *target, const char *suffix) {
    int target_length = length_pointer_char(target);
    int suffix_length = length_pointer_char(suffix);
    if (target_length < suffix_length) {
		return 0;
	}

    register int i;
    for (i = suffix_length - 1; i >= 0; i--) {
        if (suffix[i] != target[target_length - suffix_length + i]) {
            return 0;
        }
    }
    return 1;
}

int string_index(char *target, char *subtarget) {
    int target_length = length_pointer_char(target);
    int subtarget_length = length_pointer_char(subtarget);
    if (target_length < subtarget_length) {
		return -1;
	}

    register int i, j;
    for (i = 0; i <= (target_length - subtarget_length); i++) {
        if (target[i] != subtarget[0]) {
			continue;
		}
        for (j = 1; j < subtarget_length; j++) {
            if (target[i + j] != subtarget[j]) {
				break;
			}
        }
        if (j == subtarget_length) {
			return i;
		}
    }
    return -1;
}

char *string_random(char *target, int size) {
    srand(time(NULL));
	int target_length = length_pointer_char(target);
	char *result = malloc((size + 1) * sizeof(char));
	register int i;
	for (i = 0; i < size; i++) {
		result[i] = target[rand() % target_length];
	}
    result[size] = '\0';
	return result;
}

char *string_concat(char *target, char *subtarget) {
	int target_length = length_pointer_char(target);
	int subtarget_length = length_pointer_char(subtarget);

	char *result = malloc((target_length + subtarget_length + 1) * sizeof(char));
	memcpy(result, target, target_length);
	memcpy(result + target_length, subtarget, subtarget_length);
    result[target_length + subtarget_length] = '\0';

	return result;
}