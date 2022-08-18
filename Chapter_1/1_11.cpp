// 1.11 헤더 가드가 필요한 이유

#include <iostream>

// 링킹 에러
// Undefined symbols for architecture x86_64:
//   "add(int, int)", referenced from:
//       _main in 1_11-083962.o
// ld: symbol(s) not found for architecture x86_64
// clang: error: linker command failed with exit code 1 (use -v to see invocation)

// 이유 ? Declaration과 Definition이 분리했기 때문
// 컴파일할 때 소스 파일을 같이 컴파일하지 않은 경우
// 프로토타입은 헤더파일에 선언이 되어 있음
// 프로토타입만 발견하면 다음 단계로 넘어감(오브젝트 파일을 생성?)
// 링킹 과정에서 몸체를 참조해야 하는데 없기 때문에 링킹 에러 발생

// 헤더 가드가 필요한 이유
// error: redefinition of 'add'
// 불필요하게 include가 2번 발생한 경우 redefinition 에러 발생
// 헤더 가드 : 중복될 경우 한 번만 include 헤라

#include "1_11_doSomething.hpp"
// 불필요한 include
#include "1_11_add.hpp"

int main()
{
	std::cout << doSomething() << std::endl;

	return (0);
}