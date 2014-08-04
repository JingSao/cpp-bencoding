/**
* @file      Decoder.cpp
* @copyright (c) 2014 by Petr Zemek (s3rvac@gmail.com) and contributors
* @license   BSD, see the @c LICENSE file for more details
* @brief     Implementation of the Decoder class.
*/

#include "Decoder.h"

#include <sstream>

#include "BInteger.h"

namespace bencoding {

/**
* @brief Constructs a decoder.
*/
Decoder::Decoder() {}

/**
* @brief Creates a new decoder.
*/
std::unique_ptr<Decoder> Decoder::create() {
	return std::unique_ptr<Decoder>(new Decoder());
}

/**
* @brief Decodes the given bencoded data and returns them.
*/
std::unique_ptr<BItem> Decoder::decode(const std::string &data) const {
	std::istringstream input{data};
	return decode(input);
}

/**
* @brief Reads all the data from the given @a input, decodes them and returns
*        them.
*/
std::unique_ptr<BItem> Decoder::decode(std::istream &input) const {
	// TODO
	return BInteger::create(0);
}

} // namespace bencoding
