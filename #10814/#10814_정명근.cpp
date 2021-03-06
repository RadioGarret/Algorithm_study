/////////////////////////////////////////////////////////////
// title : 백준 10814 (이중 pair 와 STL sort함수를 이용한 정렬)
// date : 2019.12.20
// writer : jeong
// result : 그냥 pair 를 한번만 쓰면 나이순으로는 정렬이 되지만,
//          입력된 데이터 순서대로는 정렬이 되지 않았다. 그래서
//          이중pair 를 써서 데이터값을 하나 더 늘려서 입력된 
//          데이터 순서를 저장하였고, 그걸로 정렬하였다. 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int number; // 회원 수
vector <pair <int, pair <int, string>>>  v;


bool compare(pair<int, pair<int, string>>a,
			pair<int, pair<int, string>>b) {

	if (a.second.first == b.second.first) { // 나이가 같으면
		return a.first < b.first;           // 데이터 입력순에따라
	}
	else { // 나이가 다르면 나이순에 따라.
		return a.second.first < b.second.first;
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);       // cin 속도 향상 위해
	cin >> number;    // 회원 수

	v.resize(number); //회원 수 만큼 벡터크기 재설정

	for (int i = 0; i < number; i++) {
		cin >> v[i].second.first >> v[i].second.second;
		v[i].first = i;
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < number; i++) {
		cout << v[i].second.first << " " << v[i].second.second << "\n";
	}
}
