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
//
//extern "C" {
//#include "../../../unit_test.h"
//}
//#include "URLConnection.hpp"
//
//using namespace Java::Net;
//using namespace Java::Lang;
//namespace Java {
//    namespace Net {
//        class URLConnectionTest: virtual public URLConnection {
//        public:
//            URLConnectionTest(URL url);
//            ~URLConnectionTest();
//            void connect();
//        };
//    }
//}
//
//URLConnectionTest::URLConnectionTest(URL url) {
//    this->url = url;
//}
//
//URLConnectionTest::~URLConnectionTest() {
//}
//
//void URLConnectionTest::connect() {
//    printf("Test here");
//}
//
//TEST(JavaNet, URLConstructor) {
//    String urlString = "http://test.com:3000/file/test?param=1";
//    URL url(urlString);
//    URLConnectionTest urlConnection = URLConnectionTest(url);
//    ASSERT_EQUAL(url, urlConnection.getURL());
//}