#define REP(i, n) for (int i = 0; i < (n); i++)
struct Matrix
{
    double a[2][2] = {{0, 0}, {0, 0}};
    Matrix operator*(const Matrix &other)
    {
        Matrix product;
        REP(i, 2)
        REP(j, 2) REP(k, 2)
        {
            product.a[i][k] += a[i][j] * other.a[j][k];
        }
        return product;
    }
};
Matrix expo_power(Matrix a, ll k)
{
    Matrix product;
    REP(i, 2)
    product.a[i][i] = 1;
    while (k > 0)
    {
        if (k % 2)
        {
            product = product * a;
        }
        a = a * a;
        k /= 2;
    }
    return product;
}