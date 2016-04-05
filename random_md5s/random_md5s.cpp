#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <random>
#include <string>

#include <cryptopp/hex.h>
#include <cryptopp/md5.h>

std::string
computeMD5(std::string const& rsMessage)
{
	CryptoPP::MD5 hash;
	byte digest[CryptoPP::MD5::DIGESTSIZE];

	hash.CalculateDigest( digest, (byte*) rsMessage.c_str(), rsMessage.length() );

	CryptoPP::HexEncoder encoder;
	std::string output;
	encoder.Attach(new CryptoPP::StringSink(output));
	encoder.Put(digest, sizeof(digest));
	encoder.MessageEnd();
	return output;
}

int
main(int argc, const char* argv[])
{
	std::string const alphanums = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	size_t const uiMaxAplha = alphanums.size();
	size_t uiRound = 1;
	size_t maxRound = std::pow(uiMaxAplha, ++uiRound);
	for (;;)
	{
		for (size_t i = 0; i < maxRound; i++)
		{
			std::string sRandomString;
			sRandomString.reserve(uiRound);
			std::generate_n(std::back_inserter(sRandomString), uiRound,
					[&]() -> char
					{
						return alphanums[static_cast<std::size_t>(std::rand() * (1.0 / (RAND_MAX + 1.0 )) *  uiMaxAplha)];
					});

			std::cout << sRandomString << " HASH: " << computeMD5(sRandomString) << std::endl;
		}
		maxRound = std::pow(uiMaxAplha, ++uiRound);
	}
}
