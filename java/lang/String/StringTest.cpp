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

extern "C" {
#include "../../../unit_test.h"
}
#include "../String/String.hpp"

using namespace Java::Lang;

TEST(JavaLang, StringConstructor) {
    // Given empty value for String constructor and assign value - Return string
    String emptyString;
    emptyString = (string) "Hello world";
    ASSERT_STR("Hello world", emptyString.toCharArray());

    // Given byte array for String constructor - Return string
//    Array<byte> bytes = {65, 66, 67, 0};
//    String byteString = bytes;
//    ASSERT_STR("ABC", byteString.toCharArray());

    // Given constant string for String constructor - Return string
    String normalString ="Hello world";
    ASSERT_STR("Hello world", normalString.toCharArray());
}

TEST(JavaLang, StringValueOf) {
    // Value of boolean
    boolean isChecked = true;
    String valueOfBoolean = String::valueOf(isChecked);
    ASSERT_STR((string) "1", valueOfBoolean.toCharArray());

    // Value of single character
    char givenChar = '\0';
    String valueOfChar = String::valueOf(givenChar);
    ASSERT_STR((string) "\0", valueOfChar.toCharArray());

    // Value of string
    string givenString = "Hello world";
    String valueOfString = String::valueOf(givenString);
    ASSERT_STR(givenString, valueOfString.toCharArray());

    // Value of short number
    short givenShortNumber = 5;
    String valueOfShort = String::valueOf(givenShortNumber);
    ASSERT_STR("5", valueOfShort.toCharArray());

    // Value of integer number
    int givenIntegerNumber = 34567;
    String valueOfInt = String::valueOf(givenIntegerNumber);
    ASSERT_STR("34567", valueOfInt.toCharArray());

    // Value of long number
    long givenLongNumber = (long) 12345678893;
    String valueOfLong = String::valueOf(givenLongNumber);
    ASSERT_STR("12345678893", valueOfLong.toCharArray());

    // Value of float number
    float givenFloatNumber = (float) 5.68;
    String valueOfFloat = String::valueOf(givenFloatNumber);
    ASSERT_STR("5.68", valueOfFloat.toCharArray());

    // Value of double number
    double givenDoubleNumber = (double) 456.32423423424;
    String valueOfDouble = String::valueOf(givenDoubleNumber);
    ASSERT_STR("456.32423423424", valueOfDouble.toCharArray());
}

TEST(JavaLang, StringOperator) {
    // Given two strings and concatenate them - Return string
    String textPlus1 = "Hello ";
    String textPlus2 = "World";
    String textResult = textPlus1 + textPlus2;
    ASSERT_STR("Hello World", textResult.toCharArray());

    // Given two string and compare equal them - Return comparable
    String textCompare1 = "Hello";
    String textCompare2 = "Hello";
    int comparable = FALSE;
    if (textCompare1 == textCompare2) {
        comparable = TRUE;
    }
    ASSERT_TRUE(comparable);

    // Given two Strings and compare not equal them - Return comparable
    textCompare1 = "Hello1";
    textCompare2 = "Hello2";
    comparable = FALSE;
    if (textCompare1 != textCompare2) {
        comparable = TRUE;
    }
    ASSERT_TRUE(comparable);
}

TEST(JavaLang, StringSplit) {

}

TEST(JavaLang, StringIndexOf) {
    String textPlus1 = "Hello Hello Hello ";

    int result2 = textPlus1.indexOf('H');
    ASSERT_EQUAL(0, result2);

    result2 = textPlus1.indexOf('l', 4);
    ASSERT_EQUAL(8, result2);

    result2 = textPlus1.indexOf("llo");
    ASSERT_EQUAL(2, result2);

//    result2 = textPlus1.indexOf("llo", 3);
//    ASSERT_EQUAL(14, result2);

    result2 = textPlus1.lastIndexOf('H');
    ASSERT_EQUAL(12, result2);

    result2 = textPlus1.lastIndexOf('H', 2);
    ASSERT_EQUAL(0, result2);
}

TEST(JavaLang, StringIsEmpty) {
    String textPlus1 = "Hello Hello Hello ";
    ASSERT_TRUE(!textPlus1.isEmpty());

    textPlus1 = "";
    ASSERT_TRUE(textPlus1.isEmpty());
}

TEST(JavaLang, StringCharAt) {
    String textPlus1 = "Hello Hello Hello ";
    char result = textPlus1.charAt(0);
    ASSERT_EQUAL('H', result);
}

TEST(JavaLang, StringConcat) {
    String textPlus1 = "Hello Hello Hello ";
    String textPlus2 = "phuoc";
    String result1 = textPlus1.concat(textPlus2);
    ASSERT_STR("Hello Hello Hello phuoc", result1.toCharArray());

    textPlus2 = "";
    result1 = textPlus1.concat(textPlus2);
    ASSERT_STR("Hello Hello Hello ", result1.toCharArray());
}
