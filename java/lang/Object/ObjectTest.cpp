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

TEST(JavaLang, DataTypeBoolean) {
	boolean a = true;
	ASSERT_TRUE(a);
}

TEST(JavaLang, DataTypeByte) {
	byte a = 65;
	char A = (char) a;
	ASSERT_TRUE(A == 'A');
}

TEST(JavaLang, DataTypeArray) {
	// Array from initialize list and length property
	Array<byte> bytes = {64, 65, 66};
	ASSERT_EQUAL(3, bytes.length);
	
	// Push new element and loop in array
	bytes.push(67);
	bytes.push(68);
	int length = 0;
	for (byte byte : bytes) {
		length ++;
	}
	ASSERT_EQUAL(5 , length);
	
	// Modify element in array
	bytes[0] = 63;
	ASSERT_EQUAL(63, bytes[0]);
	
	// Test merging array
	Array<String>strings = { "Food", "Tiny"};
	strings += {"Hello", "World"};
	ASSERT_EQUAL(4, strings.length);
}
