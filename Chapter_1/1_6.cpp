// 1.6 키워드와 식별자 이름 짓기

// 식별자(identifier) : 변수의 이름, 함수의 이름, 객체의 이름
// 메모리 주소를 인식할 수 있는 이름으로 바꿔주는 기능
// 내용을 충분히 이해할 수 있는 수준에서 최대한 짧게 짓자 => 코딩 스타일

// 1. 중복될 수 없음
// 2. 숫자로 시작할 수 없음
// 3. 특수 문자를 사용할 수 없음
// 4. 빈칸을 포함할 수 없음
// 5. (관습적으로)lower case로 씀(upper case도 컴파일은 가능)
// 6. 스네이크 케이스? 캐멀 케이스?
// 7. underscore로 시작할 수 있음(class member variables)

// 함수 이름
// 1. 동사 + 명사로 구성하는 경우가 많음
// 2. 파스칼 케이스? 캐멀 케이스?
// 3. 함수 이름이 너무 길어지면? 주석으로 처리

// 키워드(reserved keyword)
// 식별자로 사용할 수 없는 예약된 이름

int	total;
int	_orange;
int VALUE; 				// 사용하지 말 것
int	my variable  name; 	// 사용할 수 없음
int TotalCustomers; 	// 사용하지 말 것
int void; 				// 사용할 수 없음
int numFruit;
int 2some; 				// 사용할 수 없음
int meters_of_pipe;
