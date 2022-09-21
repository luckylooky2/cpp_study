// 18.7 파일의 임의 위치 접근하기

// 이미 존재하는 파일의 중간을 수정하는 방법

#include <iostream>
#include <string>
#include <fstream>

int	main()
{
	const std::string	filename = "my_file.txt";

	// make a file
	{
		std::ofstream	ofs(filename);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << std::endl;
	}

	// read a file
	{
		std::ifstream	ifs(filename);
		std::string		str;

		// 파일 처음부터 5 바이트 이동 후 read
		ifs.seekg(5);
		// 시작 위치로부터 5 바이트
		// ifs.seekg(5, std::ios::beg);
		std::cout << (char)ifs.get() << std::endl;		// f

		// 커서(현재까지 읽은 위치)로부터 5 바이트 이동 후 read
		ifs.seekg(5, std::ios::cur);
		std::cout << (char)ifs.get() << std::endl;		// l

		std::getline(ifs, str);
		std::cout << str << std::endl;					// mnopqrstuvwxyz

		// end로부터 5 바이트 이동 후 read
		ifs.seekg(-5, std::ios::end);
		std::cout << ifs.tellg() << std::endl;			// 22

		ifs.seekg(0, std::ios::end);
		// 현재 커서를 알려줌
		std::cout << ifs.tellg() << std::endl;			// 27
	}

	// both read and write 
	{
		// fstream iofs(filename, std::ios::in | std::ios::out)
		std::fstream	iofs(filename);

		iofs.seekg(5);
		std::cout << (char)iofs.get() << std::endl;		// f
		iofs.seekg(5);
		iofs.put('A');
		iofs.seekg(5);
		std::cout << (char)iofs.get() << std::endl;		// A
	}

	return (0);
}