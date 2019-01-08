#include <iostream>
#include <tuple>
#include <functional>

#define MAKE_SOURCE_LAMBDA(...) std::make_tuple(#__VA_ARGS__, [](){ __VA_ARGS__ })
#define MAKE_SOURCE_LAMBDA_FILTER(...) std::make_tuple(#__VA_ARGS__, [](int a){ __VA_ARGS__ })

int main(int argc, const char *argv[])
{
	const char* code;
	std::function<int()> func;
	
	std::tie(code, func) = MAKE_SOURCE_LAMBDA(
			return int(5);
	);

	std::cout << "MAKE_SOURCE_LAMBDA" << std::endl;

	std::cout << "code: " << code << std::endl;
	std::cout << "func: " << func() << std::endl;

	return 0;
}
