#include "../crypto.h"
#include "../string.h"
#include "../common.h"

/**
 * MD5 Encode
 *
 * @param target
 * @return md5 string
 */
char *md5_encode(unsigned char *target) {
	if (NULL == target) {
		return "";
	}
	int length_target = length_pointer_char((char *) target);
	unsigned char digest[16];
	
	MD5_CTX ctx;
	MD5_Init(&ctx);
	MD5_Update(&ctx, target, (size_t) length_target);
	MD5_Final(digest, &ctx);
	
	char mdString[33];
	int index;
	for (index = 0; index < 16; index++) {
		sprintf(&mdString[ index * 2 ], "%02x", (unsigned int) digest[ index ]);
	}
	
	char *result = strdup(mdString);
	return result;
}

