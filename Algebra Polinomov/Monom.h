#pragma once
#include <string>
using namespace std;
class Monom {
private:
	int coeff;
	int svt;
	Monom* next;
public:
	Monom(int _coeff, int _svt = -1) {
		coeff = _coeff;
		svt = _svt;
		next = this;
	}
	~Monom() {
		next = nullptr;
	}
	Monom(const Monom& tmp) {
		coeff = tmp.coeff;
		svt = tmp.svt;
		next = this;
	}
	Monom& operator= (Monom tmp) {
		coeff = tmp.coeff;
		svt = tmp.svt;
		next = this;
		return *this;
	}
	string ToString(int countv, int maxst) {
		if (svt == -1) {
			return "0";
		}
		int *K;
		K = new int[countv];
		for (int i = 0; i < countv; i++) {
			K[i] = 0;
		}
		string monom = to_string(coeff);
		int tm = svt;
		int i = countv - 1;
		while (tm != 0) {
			K[i--] = tm % maxst;
			tm = tm / maxst;
		}
		for (int i = 0; i < countv; i++) {
			if (K[i] > 1) {
				monom = monom + "x" + to_string(i) + "^" + to_string(K[i]);
			}
			else {
				if (K[i] == 1) {
					monom = monom + "x" + to_string(i);
				}
			}
		}
		return monom;
	}
	Monom operator+ (Monom tmp) {
		int N = coeff + tmp.coeff;
		if (N != 0) {
			Monom res(N, svt);
			return res;
		}
		else {
			Monom res(0, -1);
			return res;
		}
	}
	Monom operator- (Monom tmp) {
		int N = coeff - tmp.coeff;
		if (N != 0) {
			Monom res(N, svt);
			return res;
		}
		else {
			Monom res(0, -1);
			return res;
		}
	}
	Monom operator* (int K) {
		Monom res(0);
		if (K != 0) {
			res.coeff = coeff * K;
			res.svt = svt;
		}
		return res;
	}
	Monom multiply (Monom tmp, int maxst, int n) {
		int* p1, * p2, * pres;
		p1 = new int[n];
		p2 = new int[n];
		pres = new int[n];
		for (int i = 0; i < n; i++) {
			p1[i] = 0;
			p2[i] = 0;
			pres[i] = 0;
		}
		int priznak = 0;
		int tm1 = svt;
		int i = n - 1;
		while (tm1 > 0) {
			while (tm1 != 0) {
				p1[i--] = tm1 % maxst;
				tm1 = tm1 / maxst;
			}
		}
		int tm2 = tmp.svt;
		i = n - 1;
		while (tm2 > 0) {
			while (tm2 != 0) {
				p2[i--] = tm2 % maxst;
				tm2 = tm2 / maxst;
			}
		}
		for (int i = 0; i < n; i++) {
			pres[i] = p1[i] + p2[i];
			if (pres[i] > maxst) {
				priznak = -1;
			}
		}
		int svtres = -1;
		if (priznak == 0) {
			svtres = 0;
			for (int i = 0; i < (n-1); i++) {
				svtres = (svtres + pres[i]) * maxst;
			}
			svtres = svtres + pres[n - 1];
		}
		Monom res(coeff * tmp.coeff, svtres);
		return res;
	}
	Monom (string str, int n = 6, int maxst = 10) {
		int* P;
		P = new int[n];
		for (int i = 0; i < n; i++) {
			P[i] = 0;
		}
		string var = "x";
		int priznak = 0;
		for (int i = (n-1); i >= 0; i--) {
			var = "x" + to_string(i);
			int l = str.find(var);
			if (l >= 0 && l < str.length()) {
				str.erase(l, var.length());
				if (str == "") {
					P[i] = 1;
				}
				else {
					if (str[l] == '^') {
						str.erase(l, 1);
						string pv = "";
						while (l <= str.length() && str[l] >= '0' && str[l] <= '9') {
							pv = pv + str[l];
							str.erase(l, 1);
						}
						if (pv != "") {
							P[i] = stoi(pv);
						}
						else {
							P[i] = 1;
						}
					}
					else {
						P[i] = 1;
					}
				}
			}
		}
		svt = 0;
		for (int i = 0; i < (n - 1); i++) {
			svt = (svt + P[i]) * maxst;
		}
		svt = svt + P[n - 1];
		if (str == "-") {
			coeff = -1;
		}
		else {
			if (str == "+") {
				coeff = 1;
			}
			else {
				if (str == "") {
					coeff = 1;
				}
				else {
					coeff = stoi(str);
				}
			}
		}
		next = this;
	}
};