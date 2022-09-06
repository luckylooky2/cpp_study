// 6.3 배열과 반복문

// 배열은 연속된 메모리를 사용하는 자료형
// 따라서 반복문과 함꼐 사용하기 좋음

#include <iostream>

int	main()
{
	int	num_students = 5;
	int	score0 = 84;
	int	score1 = 92;
	int	score2 = 76;
	int	score3 = 81;
	int	score4 = 56;
	int	total_score = score0 + score1 + score2 + score3 + score4;
	// double(total_score) / num_student vs. double(total_score / num_students)
	// 결과가 다를 가능성이 있음
	double		avg_score = static_cast<double>(total_score) / num_students;

	// 훨씬 간단함
	int			scores[] = {84, 92, 76, 81, 56};
	int			max_score = 0;

	total_score = 0;
	num_students = sizeof(scores) / sizeof(int);
	for (int i = 0; i < num_students; i++)
	{
		total_score += scores[i];
		if (max_score < scores[i])
			max_score = scores[i];
	}
	avg_score = static_cast<double>(total_score) / num_students;
	std::cout << max_score << std::endl;	// 92
}