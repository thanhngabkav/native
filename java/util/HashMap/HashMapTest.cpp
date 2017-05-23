<<<<<<< HEAD
//
// Created by Tu Cao on 5/23/17.
//
=======
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
>>>>>>> 54cf30d6357efc69e09d2ba5cd79378e65d9f11b

extern "C" {
#include "../../../unit_test.h"
}

#include "HashMap.hpp"
<<<<<<< HEAD
#include "../../Lang.hpp"

using namespace Java::Util;

template <class K, class V>
class SampleClass {
private:
    std::map<K, V> hashMap;
public:
    SampleClass();
    ~SampleClass();

    V get(K key);
    void put(K key, V value);
};

template<class K, class V>
SampleClass<K, V>::SampleClass() { }

template<class K, class V>
SampleClass<K, V>::~SampleClass() { }

TEST(JavaUtil, HashMap) {

    //SampleClass<string, string> qwe = SampleClass<string, string>();

    HashMap<string, string> asd = HashMap<string, string>();

=======

using namespace Java::Lang;
using namespace Java::Util;

TEST(JavaUtil, HashMap) {
    // Given empty hash map - return NULL
    HashMap<string, string> emptyHashMap;
    ASSERT_NULL(emptyHashMap.get("key"));

    // Given <int, String> hash map - return value is exist
    HashMap<int, String> intStringHashMap;
    intStringHashMap.put(1, "Abcd");
    ASSERT_TRUE(String("Abcd") == intStringHashMap.get(1));

    // Given <Integer, string> hash map - return value is exist
    HashMap<Integer, string> integerStringHashMap;
    Integer integerNumber = 1;
//    integerStringHashMap.put(integerNumber, "Abcd");
//    ASSERT_STR("Abcd", integerStringHashMap.get(1));
>>>>>>> 54cf30d6357efc69e09d2ba5cd79378e65d9f11b
}