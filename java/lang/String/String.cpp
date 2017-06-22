/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "String.hpp"
#include "../../Lang.hpp"

using namespace Java::Lang;

String::String() {
	this->original = strdup("\0");
	this->size = 0;
}

String::String(const_string target) {
	this->original = strdup(target);
	this->size = length_pointer_char((string) target);
}

String::String(string target) {
	this->original = strdup(target);
	this->size = length_pointer_char(target);
}

String::String(Array<char> &chars) {
	free(original);
	this->original = String::fromCharArray(chars).toString();
	this->size = chars.length;
}

String::String(Array<byte> &bytes) {
	Array<char> chars;
	for (byte byte : bytes) {
		chars.push((char) byte);
	}
	this->original = strdup(String::fromCharArray(chars).toString());
	this->size = chars.length;
}

String::String(const String &target) {
	this->original = strdup(target.original);
	this->size = target.size;
}

String::~String() {
	free(original);
}

/**
 * Clone to new object
 *
 * @return String
 */
String String::clone() {
	string pointerHolder = strdup(this->original);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

/**
 * String character at index
 *
 * @param index
 * @return String
 */
char String::charAt(int index) {
	if (( index < 0 ) || ( index > this->size - 1 )) {
		return '\0';
	}
	return this->original[ index ];
}

/**
 * String compare to another string
 *
 * @param anotherString
 * @return int
 */
int String::compareTo(const String &anotherString) const {
	string anotherStringValue = anotherString.toString();
	if (string_equals(this->original, anotherStringValue)) {
		return 0;
	}
	return 0;
}

/**
 * String compare with another string but ignore case
 *
 * @param str
 * @return int
 */
int String::compareToIgnoreCase(String str) const {
	// TODO
	return 0;
}

/**
 * String concatenation
 *
 * @param str
 * @return String
 */
String String::concat(String str) {
	string stringConcat = string_concat(this->original, str.original);
	String result(stringConcat);
	free(stringConcat);
	return result;
}

/**
 * Find substring inside
 *
 * @param str
 * @return String
 */
boolean String::contains(const CharSequence &str) {
	return ( string_index(this->original, str.toString(), 1) != NOT_FOUND );
}

/**
 * Get byte array from String
 *
 * @return Array<byte>
 */
Array<byte> String::getBytes() const {
	Array<byte> bytes;
	String originalString = this->original;
	for (char character : originalString.toCharArray()) {
		bytes.push((byte) character);
	}
	return bytes;
}

/**
 * String endswith a suffix
 * @param suffix
 * @return
 */
boolean String::endsWith(const String &suffix) const {
	return ( string_endswith(this->original, suffix.original));
}

/**
 * String from character array
 *
 * @param chars
 * @return String
 */
String String::fromCharArray(Array<char> &chars) {
	string str = (string) calloc((size_t) chars.length + 1, sizeof(char));
#ifdef __linux__
	register
#endif
	int index = 0;
	
	for (char character : chars) {
		str[ index++ ] = character;
	}
	str[index] = '\0';
	String result = str;
	free(str);
	return result;
}

/**
 * String index of character
 *
 * @param ch
 * @return int
 */
int String::indexOf(int ch) const {
	string pointerHolder = string_from_char((char) ch);
	int result = string_index(this->original, pointerHolder, 1);
	free(pointerHolder);
	return result;
}

/**
 * String index of
 *
 * @param ch
 * @param fromIndex
 * @return int
 */
int String::indexOf(int ch, int fromIndex) const {
	if (fromIndex > this->size) {
		return -1;
	}

#ifdef __linux__
	register
#endif
	int index = 0;
	
	for (index = fromIndex; index < this->size; index++) {
		if (this->original[ index ] == (char) ch) {
			return index;
		}
	}
	return -1;
}

/**
 * String index of a String
 *
 * @param str
 * @return int
 */
int String::indexOf(String str) const {
	return string_index(this->original, str.original, 1);
}

/**
 * String index of a string from index position
 *
 * @param str
 * @param fromIndex
 * @return int
 */
int String::indexOf(String str, int fromIndex) const {
	return 0;
}

/**
 * String is empty or not
 *
 * @return boolean
 */
boolean String::isEmpty() const {
	return (boolean) is_empty(this->original);
}

/**
 * String last index of character
 *
 * @param ch
 * @return int
 */
int String::lastIndexOf(int ch) {
#ifdef __linux__
	register
#endif
	int index = 0;
	
	for (index = this->size - 1; index >= 0; index--) {
		if (this->charAt(index) == (char) ch) {
			return index;
		}
	}
	return -1;
}

/**
 * String last index of character
 *
 * @param ch
 * @param fromIndex
 * @return int
 */
int String::lastIndexOf(int ch, int fromIndex) {
#ifdef __linux__
	register
#endif
	int index = 0;
	
	for (index = fromIndex - 1; index >= 0; index--) {
		if (this->charAt(index) == (char) ch) {
			return index;
		}
	}
	return -1;
}

/**
 * Last index of String inside this
 *
 * @param str
 * @return int
 */
int String::lastIndexOf(String str) const {
	string reversedString = string_reverse(str.toString());
	string currentReversedString = string_reverse(this->toString());
	int result = string_index(currentReversedString, reversedString, 1);
	free(reversedString);
	free(currentReversedString);
	if (result == NOT_FOUND) {
		return result;
	}
	//Re-calculate first character of str
	result = this->size - ( result + str.size );
	return result;
}

/**
 * Last index of String start fromIndex inside this
 *
 * @param str
 * @param fromIndex
 * @return int
 */
int String::lastIndexOf(String str, int fromIndex) const {
	string subString = &( this->original )[ fromIndex ]; // get subString start fromIndex
	string reversedString = string_reverse(str.toString());
	string currentReversedString = string_reverse(subString);
	int result = string_index(currentReversedString, reversedString, 1);
	free(reversedString);
	free(currentReversedString);
	if (result == NOT_FOUND) {
		return result;
	}
	// Re-calculate first character of str
	result = this->size - ( result + str.size );
	return result;
	
}

/**
 * String length
 *
 * @return int
 */
int String::length() {
	return this->size;
}

/**
 * String matches
 *
 * @params regex pattern
 * @return TRUE | FALSE
 */
boolean String::matches(String regex) const {
	int result = string_matches(this->original, regex.toString());
	return result == TRUE;
}

/**
 * String replace
 *
 * @param oldChar
 * @param newChar
 * @return String
 */
String String::replace(char oldChar, char newChar) const {
	string oldString = string_from_char(oldChar);
	string newString = string_from_char(newChar);
	string pointerHolder = string_replace(this->original, oldString, newString);
	String result = pointerHolder;
	free(pointerHolder);
	free(oldString);
	free(newString);
	return result;
}

/**
 * String replace all matches by replacement
 *
 * @param regex
 * @param replacement
 * @return String
 */
String String::replaceAll(String regex, String replacement) const {
	// TODO fix this later
	return "";
}

/**
 * Split string by regex
 *
 * @param regex
 * @return Array<String>
 */
Array<String> String::split(String regex) const {
	string *splitStrings = string_split(this->original, regex.toString());
	Array<String> strings;

#ifdef __linux__
	register
#endif
	int index = 0;
	
	int splitStringsLength = length_pointer_pointer_char(splitStrings);
	for (index = 0; index < splitStringsLength; index++) {
		strings.push(splitStrings[ index ]);
	}

	free_pointer_pointer_char(splitStrings);
	return strings;
}

/**
 * String starts with a prefix
 *
 * @param prefix
 * @return boolean
 */
boolean String::startsWith(String prefix) const {
	return string_startswith(this->original, prefix.original);
}

/**
 * String starts with a prefix
 *
 * @param prefix
 * @param from t
 * @return boolean
 */
boolean String::startsWith(String prefix, int toffset) const {
	if (this->original == NULL || prefix.original == NULL || toffset < 0) {
		return FALSE;
	}
	int original_length = length_pointer_char(this->original);
	int prefix_length = length_pointer_char(prefix.original);
	if (original_length < prefix_length || toffset > ( original_length - prefix_length )) {
		return FALSE;
	}
#ifdef __linux__
	register
#endif
	int index = 0;

#ifdef __linux__
	register
#endif
	int j = toffset;
	
	for (; index < prefix_length; index++) {
		if (prefix.original[ index ] != this->original[ j ]) {
			return FALSE;
		}
		j++;
	}
	return TRUE;
}
/**
 * String to char array
 *
 * @return Array<char>
 */
Array<char> String::toCharArray() const {
	Array<char> chars;

#ifdef __linux__
	register
#endif
	int index = 0;
	
	while (this->original[ index ] != '\0') {
		chars.push(this->original[ index++ ]);
	}
	return chars;
}

/**
 * String to char string (char pointer)
 *
 * @return string
 */
string String::toString() const {
	const string result = this->original;
	return result;
}

/**
 * String to lowercase
 *
 * @return String
 */
String String::toLowerCase() const {
	string hodlPointer = string_lower(this->original);
	String result = hodlPointer;
	free(hodlPointer);
	return result;
}

/**
 * String to uppercase
 *
 * @return String
 */
String String::toUpperCase() {
	string hodlPointer = string_upper(this->original);
	String result = hodlPointer;
	free(hodlPointer);
	return result;
}

/**
 * String trim space
 *
 * @return String
 */
String String::trim() {
	string hodlPointer = string_trim(this->original);
	String result = hodlPointer;
	free(hodlPointer);
	return result;
}

/**
 * String value of boolean
 *
 * @param target
 * @return String
 */
String String::valueOf(boolean target) {
	if (target) {
		return (string) "1";
	}
	return (string) "0";
}

/**
 * String value of character
 *
 * @param target
 * @return String
 */
String String::valueOf(char target) {
	string pointerHolder = string_from_char(target);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

/**
 * String value of string
 *
 * @param target
 * @return String
 */
String String::valueOf(string target) {
	if (is_empty(target)) {
		return (string) "";
	}
	return target;
}

/**
 * String value of short
 *
 * @param target
 * @return String
 */
String String::valueOf(short target) {
	string pointerHolder = string_from_short(target);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

/**
 * String value of integer
 *
 * @param target
 * @return String
 */
String String::valueOf(int target) {
	string pointerHolder = string_from_int(target);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

/**
 * String value of long
 *
 * @param target
 * @return String
 */
String String::valueOf(long target) {
	string pointerHolder = string_from_long(target);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

/**
 * String value of float
 *
 * @param target
 * @return String
 */
String String::valueOf(float target) {
	string pointerHolder = string_from_float(target);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

/**
 * String value of double
 *
 * @param target
 * @return String
 */
String String::valueOf(double target) {
	string pointerHolder = string_from_double(target);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

/**
 * Operator plus for string
 *
 * @param target2
 * @return String
 */
String String::operator+(const string &target) {
	string pointerHolder = string_concat(this->original, target);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

/**
 * Operator plus for String
 *
 * @param target2
 * @return String
 */
String String::operator+(const String &target) {
	string pointerHolder = string_concat(this->original, target.original);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

/**
 * Operator plus equals
 *
 * @param target2
 */
String String::operator+=(const String &target) {
	string result = string_concat(this->original, target.original);
	*this = result;
	free(result);
	return *this;
}

String String::operator+=(const char &target) {
	string pointerHolder = this->original;
	string_append(&this->original, target);
	free(pointerHolder);
	return *this;
}

bool String::operator==(const String &target) const {
	if (string_equals(this->original, target.toString())) {
		return true;
	}
	return false;
}

String String::operator=(const String &target) {
	if (this->original != NULL) {
		free(this->original);
	}
	this->original = strdup(target.original);
	this->size = target.size;
	return *this;
}

bool String::operator!=(const String &target) const {
	return !this->operator==(target);
}

bool String::operator<(const String &target) const {
	if (strcmp(this->original, target.toString()) < 0) {
		return true;
	}
	
	return false;
}

boolean String::operator>(const String &target) const {
	if (strcmp(this->original, target.toString()) > 0) {
		return true;
	}
	
	return false;
}

boolean String::operator<=(const String &target) const {
	if (strcmp(this->original, target.toString()) > 0) {
		return false;
	}
	
	return true;
}

boolean String::operator>=(const String &target) const {
	if (strcmp(this->original, target.toString()) < 0) {
		return false;
	}
	return true;
}