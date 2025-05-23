# [Platinum III] 소가 길을 건너간 이유 10 - 14458 

[문제 링크](https://www.acmicpc.net/problem/14458) 

### 성능 요약

메모리: 18272 KB, 시간: 100 ms

### 분류

자료 구조, 세그먼트 트리

### 제출 일자

2025년 5월 7일 13:49:11

### 문제 설명

<p>소가 왜 길을 건너는지는 미해결 난제지만, 농부 존의 소들이 길을 자주 건넌다는 것은 잘 알려진 사실이다. 소들이 길을 건너는 일이 너무 잦아서 건너면서 부딪히는 일도 생기는데, 존은 이 상황을 해결하고 싶다.</p>

<p>농장에는 일자형 길이 있고, 양쪽에 목초지가 N개씩 (1 ≤ N ≤ 100,000) 있다. 종별로 목초지 구조가 너무 달라서 한 목초지에는 정해진 종의 소만 방목할 수 있다. i번 목초지에는 i번 소만 방목할 수 있는 것이다. 소가 길을 건널 때는 자신의 종을 방목하는 반대편의 목초지로 이동하는 것이다.</p>

<p>목초지의 순서가 뒤죽박죽이어서, a종의 소와 b종의 소가 건너는 길이 겹칠 수도 있다. 존이 목초지 건설에 주의를 기울이지 않은 탓이다. 이때 (a,b)를 "가로지르는 쌍"이라고 하자.</p>

<p>존은 가로지르는 쌍의 수를 최소화하기 위해 농장을 옮기는 방법을 고안했다. 0 ≤ k < N인 정수 k에 대해, 맨 뒤에 있는 목초지 k개를 맨 앞으로 옮길 것이다. 예를 들어서, 목초지 번호가 차례대로 3, 7, 1, 2, 5, 4, 6이고 k=2라면, 옮긴 후의 목초지 번호는 4, 6, 3, 7, 1, 2, 5가 된다. 길의 왼쪽에 있는 목초지여도 되고 오른쪽이어도 되지만, 둘 중 하나만 된다. 가로지르는 쌍을 최소로 할 수 있도록 존을 도와주자.</p>

### 입력 

 <p>첫 줄에 N이 주어진다. 다음 N줄에는 길의 왼쪽에 있는 목초지 번호가 차례대로 주어진다. 각 종은 한 번씩 나타난다. 그 다음 N줄에는 길의 오른쪽에 있는 목초지가 같은 방식으로 주어진다.</p>

### 출력 

 <p>가로지르는 쌍의 최소 개수를 출력한다.</p>

