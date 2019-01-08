#include <iostream>
#include <tuple>
#include <functional>

#define STRINGIZE_SOURCE(...) #__VA_ARGS__ ; __VA_ARGS__

#define MAKE_LAMBDA(...) []() { __VA_ARGS__  }

#define MAKE_SOURCE_LAMBDA(...) std::make_tuple(#__VA_ARGS__, [](){ __VA_ARGS__ })

using t_func = std::function<int()>;

std::tuple<const char*, t_func> create_kernel()
{
	auto func = []() {
		return int(5);
	};
	return std::make_tuple("code", func);
}

int main(int argc, const char *argv[])
{

	const char source[] = STRINGIZE_SOURCE(
			int a = 10;
			int b = a + 5;
	);

	auto lfunc = MAKE_LAMBDA(
			return int(5);
	);

	std::cout << "Source: " << source << std::endl;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;



	const char* code;
	std::function<int()> func;

	std::tie(code, func) = create_kernel();

	std::cout << "func: " << func() << std::endl;

	std::tie(code, func) = std::make_tuple("code", []() { return int(5); });

	std::tie(code, func) = MAKE_SOURCE_LAMBDA(
			return int(5);
	);

	std::cout << "MAKE_SOURCE_LAMBDA" << std::endl;

	std::cout << "code: " << code << std::endl;
	std::cout << "func: " << func() << std::endl;

	
	return 0;
}
