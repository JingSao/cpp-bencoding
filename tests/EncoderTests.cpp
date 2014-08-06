/**
* @file      EncoderTests.cpp
* @copyright (c) 2014 by Petr Zemek (s3rvac@gmail.com) and contributors
* @license   BSD, see the @c LICENSE file for more details
* @brief     Tests for the Encoder class.
*/

#include <gtest/gtest.h>

#include "BInteger.h"
#include "Encoder.h"

namespace bencoding {
namespace tests {

using namespace testing;

class EncoderTests: public Test {
protected:
	EncoderTests(): encoder(Encoder::create()) {}

protected:
	std::unique_ptr<Encoder> encoder;
};

//
// Integer encoding.
//

TEST_F(EncoderTests,
IntegerWithZeroValueIsCorrectlyEncoded) {
	std::shared_ptr<BItem> data{BInteger::create(0)};

	ASSERT_EQ("i0e", encoder->encode(data));
}

TEST_F(EncoderTests,
IntegerWithPositiveValueIsCorrectlyEncoded) {
	std::shared_ptr<BItem> data{BInteger::create(13)};

	ASSERT_EQ("i13e", encoder->encode(data));
}

TEST_F(EncoderTests,
IntegerWithNegativeValueIsCorrectlyEncoded) {
	std::shared_ptr<BItem> data{BInteger::create(-13)};

	ASSERT_EQ("i-13e", encoder->encode(data));
}

} // namespace tests
} // namespace bencoding
