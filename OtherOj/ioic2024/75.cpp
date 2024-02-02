#include <bits/stdc++.h>
#define point complex<double>
#define e *exp(-20i)
// eps = e^ -20 ~= 2e-9
using namespace std;


// circle with radius r intersects line ax + by + c = 0
vector<point> circIntersectLine(double x, double y, double r, double a, double b, double c) {
    double f = (a * x + b * y + c), n = a * a + b * b;
    point p(x - f / n * a, y - f / n * b);
    double d = r * r - f * f / n;
    if (abs(d) < 1e-9)
        return {p};
    else if (d < 0)
        return {};
    else {
        double t = sqrt(d / n);
        return {p - point(-b, a) * t, p + point(-b, a) * t};
    }
}

vector<point> circIntersectCirc(double x0, double y0, double r0, double x1, double y1, double r1) {
    return circIntersectLine(x0, y0, r0, 2 * (x1 - x0), 2 * (y1 - y0), x0 * x0 - x1 * x1 + y0 * y0 - y1 * y1 - r0 * r0 + r1 * r1);
}

pair<double, double> convert(point p) {
    return make_pair(p.real(),p.imag());
}

int n, x[3], y[3], r[3];
vector<point> v;

signed main() {
    cin >> n;
    int cc = n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> r[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            auto u = circIntersectCirc(x[i], y[i], r[i], x[j], y[j], r[j]);
            if (!u.empty())
                cc = max(1, cc - 1);
            for (auto p : u)
                v.emplace_back(p);
        }

    sort(v.begin(), v.end(), [](auto p, auto q){
        return convert(p e) < convert(q e);});

    v.resize(unique(v.begin(), v.end(), [](auto p, auto q)
                    { return norm(p - q) < 1e-9; }) -
             v.begin());

    int E = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (auto p : v)
            if (abs(norm(p - point(x[i], y[i])) - r[i] * r[i]) < 1e-9)
                cnt++;

        E += cnt;
    }
    // V - E + F = cc + 1
    cout << cc - v.size() + E + 1 << '\n';
}
