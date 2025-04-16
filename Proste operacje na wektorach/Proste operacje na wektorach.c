#include <stdio.h>

void linspace(double v[], double start, double stop, int n) {
    if (n == 0) return;
    if (n == 1) {
        v[0] = start;
        return;
    }
    double step = (stop - start) / (n - 1);
    for (int i = 0; i < n; i++)
        v[i] = start + i * step;
}

void add(double v1[], const double v2[], int n) {
    for (int i = 0; i < n; i++)
        v1[i] += v2[i];
}

double dot_product(const double v1[], const double v2[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += v1[i] * v2[i];
    return sum;
}

void multiply_by_scalar(double v[], int n, double s) {
    for (int i = 0; i < n; i++)
        v[i] *= s;
}

void range(double v[], int n, double start, double step) {
    for (int i = 0; i < n; i++)
        v[i] = start + i * step;
}

void read_vector(double v[], int n) {
    for (int i = 0; i < n; i++)
        scanf("%lf", &v[i]);
}

void print_vector(const double v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f%c", v[i], i == n - 1 ? '\n' : ' ');
}

int main() {
    int F;
    scanf("%d", &F);

    if (F == 1) {
        int n;
        double start, stop;
        scanf("%d %lf %lf", &n, &start, &stop);
        double v[1000];
        linspace(v, start, stop, n);
        print_vector(v, n);
    }
    else if (F == 2) {
        int n;
        scanf("%d", &n);
        double v1[1000], v2[1000];
        read_vector(v1, n);
        read_vector(v2, n);
        add(v1, v2, n);
        print_vector(v1, n);
    }
    else if (F == 3) {
        int n;
        scanf("%d", &n);
        double v1[1000], v2[1000];
        read_vector(v1, n);
        read_vector(v2, n);
        printf("%.2f\n", dot_product(v1, v2, n));
    }
    else if (F == 4) {
        int n;
        double s;
        scanf("%d %lf", &n, &s);
        double v[1000];
        read_vector(v, n);
        multiply_by_scalar(v, n, s);
        print_vector(v, n);
    }
    else if (F == 5) {
        int n;
        double start, step;
        scanf("%d %lf %lf", &n, &start, &step);
        double v[1000];
        range(v, n, start, step);
        print_vector(v, n);
    }

    return 0;
}