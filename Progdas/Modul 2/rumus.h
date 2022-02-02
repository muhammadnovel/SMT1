#define phi 3.14

// Balok
int l_balok(int p, int l, int t) {
    int luas;

    luas = 2 * (p * l + p * t + l * t);
    return luas;
}

int v_balok(int p, int l, int t) {
    int volume;

    volume = p * l * t;
    return volume;
}

// Kubus
int l_kubus(int s) {
    int luas;

    luas = 6 * pow(s,2);
    return luas;
}

int v_kubus(int s) {
    int volume;

    volume = pow(s,3);
    return volume;
}

// Tabung
float l_tabung(int r, int t) {
    float luas;

    luas = 2 * phi * r * (r + t);
    return luas;
}

float v_tabung(int r, int t) {
    float volume;

    volume = phi * pow(r,2) * t;
    return volume;
}

// Kerucut
float l_kerucut(int r, int s) {
    float luas;

    luas = phi * r * (r + s);
    return luas;
}

float v_kerucut(int r, int t) {
    float volume;

    volume = phi * pow(r,2) * t / 3;
    return volume;
}
