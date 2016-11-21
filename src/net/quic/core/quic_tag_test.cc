// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/quic/core/quic_tag.h"

#include "net/quic/core/crypto/crypto_protocol.h"
#include "testing/gmock/include/gmock/gmock.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace net {
namespace test {
namespace {

TEST(QuicTagTest, TagToString) {
  EXPECT_EQ("SCFG", QuicTagToString(kSCFG));
  EXPECT_EQ("SNO ", QuicTagToString(kServerNonceTag));
  EXPECT_EQ("CRT ", QuicTagToString(kCertificateTag));
  EXPECT_EQ("CHLO", QuicTagToString(MakeQuicTag('C', 'H', 'L', 'O')));
  // A tag that contains a non-printing character will be printed as a decimal
  // number.
  EXPECT_EQ("525092931", QuicTagToString(MakeQuicTag('C', 'H', 'L', '\x1f')));
}

}  // namespace
}  // namespace test
}  // namespace net