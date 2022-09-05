// 10.4 제휴 관계

// composition, aggregation은 주, 부가 확실히 나뉨

// association은 주, 부가 명확하게 나뉘지 않음
// 두 class가 내부에 상대방을 멤버 변수로서 가지고 있음
// 서로 동등한 관계이기 때문에 전방 선언이 필요 => 코드가 복잡해짐
// association은 이러한 불편함 때문에 확실히 사용 빈도가 적음
// 하지만, 사용해야 할 수 밖에 없는 떄가 있으므로 선택을 잘 해야 함
// 코드에 class 전방 선언이 있다 => association relationship을 확인하고 이해

// 1. 다른 클래스에도 속할 수 있는가? => Yes
// 서로 동등한 관계, 여러 의사/환자
// 2. 멤버의 존재를 클래스가 관리할 수 있는가? => No
// p1이 소멸되어도, d1은 소멸되지 않음
// 3. 방향성 => 단방향 or 양방향

// 다대다 구조에서는
// hospital처럼 중계하는 class가 필요함
// Database에서도 마찬가지(새로운 테이블을 만들어서 키클 빼오는 방식)

#include <iostream>
#include <vector>
#include <string>

class Doctor;

class Patient
{
private:
	std::string				m_name;
	// error: use of undeclared identifier 'Doctor'
	// 두 class가 서로 참조하고 있기 떄문 => 전방 선언
	// 다른 방식
	// 1. Doctor * => int : id를 통해 해당 자료를 찾아서 처리
	// 2. reflective association
	// Doctor *doctor; // 의사가 의사를 만나는 경우
	std::vector<Doctor *>	m_doctors;

public:
	Patient(const std::string name_in)
	{
		m_name = name_in;
		std::cout << "class Patient constructor" << std::endl;
	}

	void	addDoctors(Doctor *new_doctor)
	{
		m_doctors.push_back(new_doctor);
	}

	// 전방 선언 떄문에 현 시점에서 Doctor안에 m_name이 있는지 없는지 모름
	// 해결 class 밖으로 빼기
	void	meetDoctors();

	~Patient()
	{
		std::cout << "class Patient destructor" << std::endl;
	}

	// Doctor class의 멤버 변수 직접 접근 가능
	friend class Doctor;
};

void	Patient::meetDoctors()
{
	// error: member access into incomplete type 'Doctor'
	for (Doctor *elem : m_doctors)
		std::cout << "Meet Doctor : " << elem->m_name << std::endl;
}

class Doctor
{
private:
	std::string				m_name;
	std::vector<Patient *>	m_patients;

public:
	Doctor(const std::string name_in)
	{
		m_name = name_in;
		std::cout << "class Doctor constructor" << std::endl;
	}

	void	addPatients(Patient *new_patient)
	{
		m_patients.push_back(new_patient);
	}

	void	meetPatients()
	{
		for (Patient *elem : m_patients)
			std::cout << "Meet Patient : " << elem->m_name << std::endl;
	}

	~Doctor()
	{
		std::cout << "class Doctor destructor" << std::endl;
	}

	friend class Patient;
};

int	main()
{
	Patient	*p1 = new Patient("Jack Jack");
	Patient	*p2 = new Patient("Dash");
	Patient	*p3 = new Patient("Violet");

	Doctor	*d1 = new Doctor("Doctor K");
	Doctor	*d2 = new Doctor("Doctor L");

	p1->addDoctors(d1);
	d1->addPatients(p1);
	p2->addDoctors(d2);
	d2->addPatients(p2);
	p2->addDoctors(d1);
	d1->addPatients(p2);

	// patients meet doctors
	p1->meetDoctors();	// Meet Doctor : Doctor K

	// doctors meet patients
	d1->meetPatients();
	// Meet Patient : Jack Jack
	// Meet Patient : Dash

	// deletes
	delete p1;
	delete p2;
	delete p3;
	delete d1;
	delete d2;

	return (0);
}