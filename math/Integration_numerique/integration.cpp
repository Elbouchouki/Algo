#include <bits/stdc++.h>
using namespace std;

class IntegrationNumerique
{
private:
    vector<double> x, fx;

public:
    IntegrationNumerique()
    {
        this->x = {};
        this->fx = {};
    }
    IntegrationNumerique(vector<double> x, vector<double> fx)
    {
        this->x = x;
        this->fx = fx;
    }
    void setX(vector<double> x)
    {
        this->x = x;
    }
    vector<double> getX()
    {
        return x;
    }
    void setFx(vector<double> fx)
    {
        this->fx = fx;
    }
    vector<double> getFx()
    {
        return fx;
    }
    double trapeze(double h = 0)
    {
        if (x.size() == 0 || fx.size() == 0)
            return 0;
        double sum = 0;
        for (int i = 1; i < x.size() - 1; i++)
            sum += fx[i];
        double H = h == 0 ? ((x[x.size() - 1] - x[0]) / (x.size() - 1)) : h;
        return H * (((fx[0] + fx[x.size() - 1]) / 2) + sum);
    }
    double simpson(double h = 0)
    {
        if (x.size() == 0 || fx.size() == 0)
            return 0;
        double sum = 0;
        for (int i = 1; i < x.size() - 1; i++)
        {
            if (i % 2 == 0)
                sum += 2 * fx[i];
            else
                sum += 4 * fx[i];
        }
        double H = h == 0 ? (x[x.size() - 1] - x[0]) / ((x.size() - 1)) : h;
        return (H / 3) * (fx[0] + sum + fx[x.size() - 1]);
    }
};

void test_sinx()
{
    vector<double> x = {0, M_PI / 8, M_PI / 4, 3 * M_PI / 8, M_PI / 2};
    vector<double> fx = {0, 0.382683, 0.707107, 0.923880, 1};
    IntegrationNumerique integration = IntegrationNumerique(x, fx);
    cout << integration.trapeze() << endl;
    cout << 1 - integration.trapeze() << endl;
    cout << integration.simpson() << endl;
    cout << 1 - integration.simpson() << endl;
}
void test_e_x2()
{
    vector<double> x = {0, 1 / 2, 1};
    vector<double> fx = {1, 0.7788, 0.36788};
    IntegrationNumerique integration = IntegrationNumerique(x, fx);
    cout << integration.trapeze() << endl;
    cout << integration.simpson() << endl;
}

void test_chx()
{
    vector<double> x, fx;
    IntegrationNumerique integration = IntegrationNumerique();
    const double chx = 1.766973094451878;
    double gap = 00;

    for (int i = 0; i < 4; i++)
    {
        gap += 0.1;
        if (i == 2)
            continue;
        double cpt = 1;
        while (cpt <= 1.81)
        {
            x.push_back(cpt);
            fx.push_back(cosh(cpt));
            cpt += gap;
        }
        integration.setFx(fx);
        integration.setX(x);
        cout << "h= " << gap << endl;
        cout << integration.trapeze() << endl;
        cout << "Erreur trapeze: " << abs(chx - integration.trapeze()) << endl;
        cout << integration.simpson() << endl;
        cout << "Erreur simpson: " << abs(chx - integration.simpson()) << endl;
        cout << endl;
        x.clear();
        fx.clear();
    }
}
void test_vitesse()
{
    vector<double> t = {0, 10, 20, 30, 40, 50, 60, 70, 80};
    vector<double> y = {30, 31.63, 33.44, 35.47, 37.75, 40.33, 43.29, 46.70, 50.67};
    IntegrationNumerique integration = IntegrationNumerique(t, y);
    cout << "V(80)= " << integration.trapeze() << endl;
    cout << "V(80)= " << integration.simpson() << endl;
}

int main()
{
    test_chx();
    return 0;
}