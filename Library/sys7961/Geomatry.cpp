#include<bits/stdc++.h>
using std::vector;
using std::pair;
using lint = long long;

using data_Ty = long double;
const data_Ty INF = LLONG_MAX;
const double PI = 2.0*acos(0.0);
const double EPSILON = 1e-9;
struct point {
	data_Ty x, y;
	bool operator==(point p) { return x == p.x && y == p.y; }
	point operator*(double p)const { return{ data_Ty(x*p), data_Ty(y*p) }; }
	point operator+(const point& p)const { return{ x + p.x, y + p.y }; }
	point operator-(const point& p)const { return{ x - p.x, y - p.y }; }
	bool operator<(const point& p)const { return x < p.x || (x == p.x && y < p.y); }
	double norm()const { return hypot(x, y); }
	point normalize()const { return{ data_Ty(x / norm()), data_Ty(y / norm()) }; }
	double polar()const {//radian
		return fmod(atan2(y, x) + 2 * PI, 2 * PI); }
	double dot(const point& p)const { return x*p.x + y*p.y; }
	double cross(const point& p)const { return x*p.y - p.x*y; }
	point project(const point& p)const {
		point r = p.normalize();
		return r*r.dot(*this);
	}
};
data_Ty abss(data_Ty a) {
	if (a < 0)return -a;
	return a;
}
data_Ty ccw(data_Ty ax, data_Ty ay, data_Ty bx, data_Ty by, data_Ty cx, data_Ty cy) {
	return bx*cy - ay*bx - ax*cy - by*cx + ax*by + ay*cx;
}
data_Ty ccw(point a, point b, point c) {
	return ccw(a.x, a.y, b.x, b.y, c.x, c.y);
}
struct line {
	data_Ty a, b, c;//ax+by+c=0
	line() {}
	line(point A, point B) {
		a = B.y - A.y;
		b = -(B.x - A.x);
		c = A.y*(B.x - A.x) - A.x*(B.y - A.y);
		/*	data_Ty g = std::abs(gcd(gcd(a, b), c));
		a /= g; b /= g; c /= g;*/
	}
	line(data_Ty m_u, data_Ty m_d, data_Ty B) { // y=(m_u/m_d)x+B
		a = m_u;
		b = -m_d;
		c = B;
		/*	data_Ty g = std::abs(gcd(gcd(a, b), c));
		a /= g; b /= g; c /= g;*/
	}
	line(data_Ty m_u, data_Ty m_d, point p) { // (y-p.y)=(m_u/m_d)*(x-p.x)
		a = m_u;
		b = -m_d;
		c = -(a*p.x + b*p.y);
	}
	data_Ty getX(data_Ty y) { return (-b*y - c) / a; }
	data_Ty getY(data_Ty x) { return (-a*x - c) / b; }
	double DistToPoint(point p) { // Distance
		return std::abs(a*p.x + b*p.y + c) / sqrt((double)(a*a + b*b));
	}
	bool getLineIntersectionPoint(line p, point& q) {// return : 교차 여부 ,point p: 교차점
		point a, b, c, d;
		if (this->b == 0) {
			a = { getX(0), 0 };
			b = { getX(1), 1 };
		}
		else {
			a = { 0, getY(0) };
			b = { 1, getY(1) };
		}
		if (p.b == 0) {
			c = { p.getX(0), 0 };
			d = { p.getX(1), 1 };
		}
		else {
			c = { 0, p.getY(0) };
			d = { 1, p.getY(1) };
		}
		double det = (b - a).cross(d - c);
		if (fabs(det) < EPSILON)return false;
		q = a + (b - a)*((c - a).cross(d - c) / det);
		return true;
	}
};
struct segment {
	point a, b;
	data_Ty diffX() {
		return abss(b.x - a.x);
	}
	data_Ty diffY() {
		return abss(b.y - a.y);
	}
	long long sign(long long a) { // inner method
		if (a > 0) return 1;
		if (a < 0)return -1;
		return 0;
	}
	bool intersect(segment p) {
		long long a1 = ccw(a, b, p.a);
		long long a2 = ccw(a, b, p.b);
		long long b1 = ccw(p.a, p.b, a);
		long long b2 = ccw(p.a, p.b, b);
		bool A = sign(a1)*sign(a2) < 0;
		bool B = sign(b1)*sign(b2) < 0;
		return A&&B;
	}
	bool inner(point p) {
		long long A = ccw(a, b, p);
		bool X = false;
		bool Y = false;
		if (std::min(a.x, b.x) <= p.x && p.x <= std::max(a.x, b.x)) {
			X = true;
		}
		if (std::min(a.y, b.y) <= p.y && p.y <= std::max(a.y, b.y)) {
			Y = true;
		}
		return A == 0 && X&&Y;
	}
	bool endpoint(point p) {
		return a == p || b == p;
	}
	bool overlap(segment p) {
		long long a1 = ccw(a, b, p.a);
		long long a2 = ccw(a, b, p.b);
		long long b1 = ccw(p.a, p.b, a);
		long long b2 = ccw(p.a, p.b, b);
		if (a1 == 0 && a2 == 0 && b1 == 0 && b2 == 0) {
			if ((inner(p.a) && inner(p.b)) || (p.inner(a) && p.inner(b))) {
				return true;
			}
			if (a == p.a && (sign(b.x - a.x) != sign(p.b.x - p.a.x) || sign(b.y - a.y) != sign(p.b.y - p.a.y))) {
				return false;
			}
			if (a == p.b && (sign(b.x - a.x) != sign(p.a.x - p.b.x) || sign(b.y - a.y) != sign(p.a.y - p.b.y))) {
				return false;
			}
			if (b == p.a && (sign(a.x - b.x) != sign(p.b.x - p.a.x) || sign(a.y - b.y) != sign(p.b.y - p.a.y))) {
				return false;
			}
			if (b == p.b && (sign(a.x - b.x) != sign(p.a.x - p.b.x) || sign(a.y - b.y) != sign(p.a.y - p.b.y))) {
				return false;
			}
			if (inner(p.a) || inner(p.b) || p.inner(a) || p.inner(b)) {
				return true;
			}
		}
		return false;
	}
	long double distToPoint(point p, point& q) {
		line A(a, b);
		line B(-A.b, -A.a, p);
		A.getLineIntersectionPoint(B, q);
		if (inner(q)) {
			return (p - q).norm();
		}
		return std::min((p - a).norm(), (p - b).norm());
	}
};
struct polygon : vector<point> {
	data_Ty ccw(int a, int b, int c) {
		return ::ccw(at(a), at(b), at(c));
	}
	data_Ty ccw(point a, point b, point c) {
		return ::ccw(a, b, c);
	}
	bool isInsider(point p) {
		segment q = { p,{ p.x + 1000000007, p.y + 1000000009 } };
		int sz = size();
		int cnt = 0;
		for (int i = 0; i < sz; i++) {
			segment k = { at(i), at((i + 1) % sz) };
			if (q.intersect(k)) {
				cnt++;
			}
			if (k.inner(p)) { // 선분위에 점 있는 경우
				return true;
			}
		}
		return cnt % 2 == 1;
	}
	bool isInsider(polygon& p) {
		int size = p.size();
		for (int i = 0; i < size; i++) {
			if (!isInsider(p[i])) {
				return false;
			}
		}
		return true;
	}
	long double getArea() {
		int sz = size();
		long double ret = 0;
		for (int i = 0; i < sz; i++) {
			ret += ccw(0, i, (i + 1) % sz);
		}
		return fabs(ret / 2);
	}
	polygon getConvexHull() {
		polygon P = *this;
		if (P.size() <= 2) {
			return P;
		}
		std::sort(P.begin(), P.end());
		polygon Convex;
		for (int _ : {0, 0}) {
			polygon half;
			for (point& p : P) {
				while (half.size() >= 2) {
					point A = *(half.end() - 2);
					point B = *(half.end() - 1);
					if (ccw(A, B, p) <= 0) {
						half.pop_back();
						continue;
					}
					break;
				}
				half.push_back(p);
			}
			half.pop_back();
			Convex.insert(Convex.end(), half.begin(), half.end());
			std::reverse(P.begin(), P.end());
		}
		return Convex;
	}
	polygon cutPolygontoSegment(const segment& p) {
		int sz = size();
		vector<bool> inside;
		auto next = [&](int i) { return (i + 1) % sz; };
		for (auto& q : *this) inside.push_back(ccw(p.a, p.b, q) >= 0);
		polygon ret;
		for (int i = 0; i < sz; i++) {
			int j = next(i);
			if (inside[i]) ret.push_back(at(i));
			if (inside[i] != inside[j]) {
				line a(at(i), at(j));
				line b(p.a, p.b);
				point q;
				assert(a.getLineIntersectionPoint(b, q));
				ret.push_back(q);
			}
		}
		return ret;
	}
	polygon cutPolygontoConvexhull(polygon& p) {
		int sz = p.size();
		if (isInsider(p)) {
			return p;
		}
		if (p.isInsider(*this)) {
			return *this;
		}
		polygon ret = *this;
		auto next = [&](int i) {return (i + 1) % sz; };
		for (int i = 0; i < sz; i++) {
			ret = ret.cutPolygontoSegment({ p[i], p[next(i)] });
		}
		return ret;
	}
	data_Ty getDistToFarthest() {
		polygon Convex = getConvexHull();
		int idx = 1;
		data_Ty dist = -1;
		int n = Convex.size();
		for (int i = 0; i < n; i++) {
			while (true) {
				point vec1 = Convex[(i + 1) % n] - Convex[i];
				point vec2 = Convex[(idx + 1) % n] - Convex[idx];
				if (ccw({ 0,0 }, vec1, vec2) > 0) {
					idx = (idx + 1) % n;
					continue;
				}
				break;
			}
			dist = std::max<data_Ty>(dist, (Convex[i]- Convex[idx]).norm());
		}
		return dist;
	}
	bool isPolygonOverlap(polygon poly) {
		for (point &p : *this) {
			if (poly.isInsider(p)) {
				return true;
			}
		}
		for (point &p : poly) {
			if (isInsider(p)) {
				return true;
			}
		}
		for (int i = 0; i < size(); i++) {
			for (int j = 0; j < poly.size(); j++) {
				segment p = { at(i),at((i + 1) % size()) };
				segment q = { poly[j],poly[(j + 1) % poly.size()] };
				if (p.intersect(q)) {
					return true;
				}
			}
		}
		return false;
	}
};
