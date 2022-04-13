#include <bits/stdc++.h>
using namespace std;


using Polynomial = std::vector<double>;
using Complex = std::complex<double>;

void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    // clock_t start = clock();
    auto start = chrono::system_clock::now();


    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    auto end = std::chrono::system_clock::now();
    cerr << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    // cerr << "time taken : " << float(clock() - start) / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


void solve_quadratic(double a, double b, double c, Complex &root1, Complex &root2)
{
    Complex det = b * b - 4 * a * c;
    root1 = (-b + sqrt(det)) / (2.0 * a);
    root2 = -(b / a + root1);
}

// Evaluate polynomial P(z)
Complex evaluate(const Polynomial &P, Complex z)
{
    Complex result = 0;
    for (int i = P.size() - 1; i >= 0; i--)
        result = P[i] + z * result;
    return result;
}

// Bairstow's method
// Seek to write polynomial A as (x^2 + ux + v)B
// where B is a polynomial of (2-)lower degree
void quadratic_factor(const Polynomial &A, double &u, double &v, Polynomial &B)
{
    const double TOLSQ = 1.0e-40; // convergence tolerance
    const int ITERMAX = 100;      // maximum number of iterations

    int n = A.size() - 1; // degree of polynomial
    double c = 1, d = 1;
    int iter = 0;

    while (c * c + d * d >= TOLSQ && iter < ITERMAX)
    {
        Polynomial F(1 + n, 0.0);
        B = Polynomial(1 + n, 0.0);
        for (int i = n - 2; i >= 0; i--)
        {
            B[i] = A[i + 2] - u * B[i + 1] - v * B[i + 2];
            F[i] = B[i + 2] - u * F[i + 1] - v * F[i + 2];
        }
        c = A[1] - u * B[0] - v * B[1];
        d = A[0] - v * B[0];
        double g = B[1] - u * F[0] - v * F[1];
        double h = B[0] - v * F[0];
        double det = v * g * g + h * (h - u * g);
        u -= (-h * c + g * d) / det;
        v -= (-g * v * c + (g * u - h) * d) / det;
        iter++;
    }
    if (iter >= ITERMAX)
        std::cout << "Not converged\n";
    B.pop_back();
    B.pop_back(); // quotient polynomial has degree two less
}

// Apply Bairstow's approach to successively remove quadratic factors
std::vector<Complex> Bairstow(Polynomial A)
{
    std::vector<Complex> roots; // roots of polynomial

    while (A.size() > 2) // at least quadratic
    {
        Polynomial B; // quotient polynomial
        int n = A.size();
        double u = A[n - 2] / A[n - 1]; // guessed start values
        double v = A[n - 3] / A[n - 1];
        quadratic_factor(A, u, v, B); // seek quadratic factor x^2 + ux + v

        Complex root1, root2;
        solve_quadratic(1.0, u, v, root1, root2); // solve quadratic
        roots.push_back(root1);
        roots.push_back(root2);
        A = B; // continue with quotient
    }
    // any remaining linear factor
    if (A.size() == 2)
        roots.push_back(-A[0] / A[1]);

    return roots;
}

void solve()
{
    int degree = 0;
    std::cout << "Enter degree of polynomial: \n";
    std::cin >> degree;
    Complex coeffs_sum = 0;
    Polynomial P(degree + 1);
    for (size_t i = 0; i < degree; i++)
    {
        double coeff;
        std::cout << "Enter coefficient of x^" << i << ": \n";
        std::cin >> coeff;
        P[i] = coeff;
        coeffs_sum += coeff * coeff;
    }
    P[degree] = 1;

    std::vector<Complex> roots = Bairstow(P); // get roots
    Complex roots_sum = 0;
    for (Complex z : roots)
        roots_sum += z * z;
    std::cout << "Beauty = " << (coeffs_sum - roots_sum).real() << '\n';
}
