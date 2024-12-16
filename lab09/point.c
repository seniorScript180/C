#include <stdio.h>

// Ορισμός της δομής point
struct point {
    double x; // Συντεταγμένη x
    double y; // Συντεταγμένη y
};

// Συνάρτηση που υπολογίζει το μέσο δύο σημείων
struct point middle(struct point a, struct point b) {
    struct point m;
    m.x = (a.x + b.x) / 2.0; // Μέσος όρος των x
    m.y = (a.y + b.y) / 2.0; // Μέσος όρος των y
    return m;
}

// Παράδειγμα χρήσης (μπορείτε να το αφαιρέσετε αν δεν χρειάζεται δοκιμή εδώ)
int main() {
    struct point p1 = {0.0, 0.0};
    struct point p2 = {4.0, 6.0};

    struct point m = middle(p1, p2);

    printf("Middle point: (%.2f, %.2f)\n", m.x, m.y);

    return 0;
}

