#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

using vs = vector<string>;

string getFill(const string& v) {
	const auto& n = v.length();
	const auto& a = n / 4;
	const auto& b = (n % 4) / 2;

	auto oss = ostringstream{};
	for (auto i = 0; i < a; ++i) {
		oss << "AAAA";
	}

	for (auto i = 0; i < b; ++i) {
		oss << "BB";
	}

	return static_cast<string>(oss.str());
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto x = string{};
	cin >> x;

	const auto& n = x.length();

	auto p = vs{};
	auto b = int{ -1 };
	for (auto i = 0; i < n; ++i) {
		if ('.' == x[i]) {
			p.push_back(x.substr(b + 1, i - b - 1));
			b = i;
			p.push_back(".");
		}
	}
	p.push_back(x.substr(b + 1, n - b - 1));

	auto oss = ostringstream{};
	for (const auto& v : p) {
		const auto& vn = v.length();
		if ("." == v) {
			oss << ".";
			continue;
		}

		if (1 == vn % 2) {
			cout << -1;
			return 0;
		}

		oss << getFill(v);
	}

	cout << oss.str();

	return 0;
}