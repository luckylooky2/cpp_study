// 10.1 객체들의 관계

// 객체 지향 프로그래밍
// 1. 그 프로그램이 수행하는 기능 정의
// 2. 기능을 수행할 때 객체들이 어떻게 업무를 나눌 것인가
// 어떻게 도움을 주고받을 것인가 설계

// c : class, m : member class

// 1. 구성(요소) : composition, part-of
// 멤버 클래스는 클래스가 없으면 존재할 수 없음
// 멤버 클래스는 클래스의 전체에 대해 알고 있지 않음
// e.g., 두뇌(m)는 육체(c)의 일부이다.
// 두뇌는 육체가 없으면 존재할 수 없음

// 2. 집합 : aggregation, has-a
// 구성보다는 느슨한 연결 관계
// 클래스가 없어도, 멤버 클래스가 존재할 수 있음
// e.g., 어떤 사람(c)이 자동차(m)를 가지고 있다.
// 사람이 없어도 자동차가 존재할 수 있음

// 3. 연계, 제휴 : association, uses-a
// 더 느슨한 연결 관계, 단순히 사용하는 관계
// 서로 도움을 주고 받을 수 있는 관계?
// e.g., 환자(c)는 의사(m)의 치료를 받는다.
// e.g., 의사(c)는 환자들(m)로부터 치료비를 받는다.
// 환자는 의사 여러 명에게 치료를 받을 수 있음, 의사도 환자 여러 명을 치료할 수 있음

// 4. 의존 : dependency, depends-on
// 더 느슨한 관계
// e.g., 나(c)는 (다리가 부러져서 한 달 동안) 목발(m)을 짚었다.
// 다리가 다 나은 후에는 목발이 필요 없음, 내가 존재하지 않는다고 목발이 존재하지 않는 것은 아님