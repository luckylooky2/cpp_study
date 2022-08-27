// 6.6 C언어 스타일의 배열 문자열

#include <iostream>
#include <cstring>

int	main()
{
	// null character 때문에 7칸이 할당
	char	myString[] = "string";

	for (int i = 0; i < 7; i++)
		std::cout << (int)myString[i] << " ";
	std::cout << std::endl;
	std::cout << sizeof(myString) / sizeof(myString[0]) << std::endl;	// 7

	char	myString2[255];
	char	myString3[255];
	int		i = 0;

	// 방법 1
	std::cin >> myString2;
	myString2[4] = '\0';
	std::cout << myString2 << std::endl;
	std::cin.ignore(32767, '\n');

	// 방법 2
	std::cin.getline(myString3, 255);
	while (myString3[i])
		std::cout << myString3[i++];
	std::cout << std::endl;

	char	source[] = "Copy this!";
	char	dest[50];

	// source 보다 dest 크기가 더 작을 경우
	// null character가 복사되지 않아 다른 메모리를 침범해 읽을 가능성이 존재
	// copy
	strcpy(dest, source);
	std::cout << "strcpy : " << dest << std::endl;
	// concatenate
	strcat(dest, source);
	std::cout << "strcat : " << dest << std::endl;
	// compare : 같으면 0, 다르면 not 0을 return
	int	res = strcmp(dest, source);
	std::cout << "strcmp : " << res << std::endl;

	return (0);
}