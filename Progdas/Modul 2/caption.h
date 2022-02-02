void header(void);

// BALOK
void cl_balok(void) {
    int p, l, t, hasil;
    printf("[*] Masukan nilai panjang, lebar, tinggi : ");
    scanf("%d %d %d", &p, &l, &t);

    system("cls");
    header();

    printf("[-] Diketahui : \n\n");
    printf("Nilai Panjang = %d cm\n", p);
    printf("Nilai Lebar   = %d cm\n", l);
    printf("Nilai Tinggi  = %d cm\n\n", t);

    printf("[-] Dijawab : \n\n");
    printf("Lp = 2 x (p x l) + (p x t) + (l x t)\n");
    printf("Lp = 2 x (%d x %d) + (%d x %d) + (%d x %d)\n", p, l, p, t, l, t);
    printf("Lp = 2 x (%d + %d + %d)\n", p*l, p*t, l*t);
    printf("Lp = 2 x %d\n", p * l + p * t + l * t);

    hasil = l_balok(p, l, t);
    printf("Lp = %d cm^2\n\n", hasil);
    printf("[*] Hasil luas permukaan balok adalah %d cm^2\n", hasil);
}

void cv_balok(void) {
    int p, l, t, hasil;
    printf("[*] Masukan nilai panjang, lebar, tinggi : ");
    scanf("%d %d %d", &p, &l, &t);

    system("cls") ;
    header();

    printf("[-] Diketahui : \n\n");
    printf("Nilai Panjang  = %d cm\n", p);
    printf("Nilai Lebar    = %d cm\n", l);
    printf("Nilai Tinggi   = %d cm\n\n", t);

    printf("[-] Dijawab : \n\n");
    printf("V = p x l x t\n");
    printf("V = %d x %d x %d\n", p, l, t);

    hasil = v_balok(p, l, t);
    printf("V = %d cm^3\n\n", hasil);
    printf("[*] Hasil volume balok adalah %d cm^3\n", hasil);
}

// KUBUS
void cl_kubus(void) {
    int s, hasil;
    printf("[*] Masukan nilai sisi : ");
    scanf("%d", &s);

    system("cls");
    header();

    printf("[-] Diketahui : \n\n");
    printf("Nilai Sisi = %d cm\n\n", s);

    printf("[-] Dijawab : \n\n");
    printf("Lp = 6 x s^2\n");
    printf("Lp = 6 x %d^2\n", s);
    printf("Lp = 6 x %i\n", s*s);

    hasil = l_kubus(s);
    printf("Lp = %d cm^2\n\n", hasil);
    printf("[*] Hasil luas permukaan kubus adalah %d cm^2\n", hasil);
}

void cv_kubus(void) {
    int s, hasil;
    printf("[*] Masukan nilai sisi : ");
    scanf("%d", &s);

    system("cls");
    header();

    printf("[-] Diketahui : \n\n");
    printf("Nilai Sisi = %d cm\n\n", s);

    printf("[-] Dijawab : \n\n");
    printf("V = s^3\n");
    printf("V = %d^3\n", s);

    hasil = v_kubus(s);
    printf("V = %d cm^3\n\n", hasil);
    printf("[*] Hasil volume kubus adalah %d cm^3\n", hasil);
}

// TABUNG
void cl_tabung(void) {
    int r, t;
    float hasil;
    printf("[*] Masukan nilai jari-jari, tinggi : ");
    scanf("%d %d", &r, &t);

    system("cls");
    header();

    printf("[-] Diketahui : \n\n");
    printf("Nilai Jari-Jari = %d cm\n", r);
    printf("Nilai Tinggi    = %d cm\n\n", t);

    printf("[-] Dijawab : \n\n");
    printf("Lp = 2 x phi x r x (r + t)\n");
    printf("Lp = 2 x 3,14 x %d x (%d + %d)\n", r, r, t);
    printf("Lp = 2 x 3,14 x %d x %d\n", r, r+t);
    printf("Lp = %.2f x %d\n", 2*3.14, r*(r+t));

    hasil = l_tabung(r, t);
    printf("Lp = %.2f cm^2\n\n", hasil);
    printf("[*] Hasil luas permukaan tabung adalah %.2f cm^2\n", hasil);
}

void cv_tabung(void) {
    int r, t;
    float hasil;
    printf("[*] Masukan nilai jari-jari, tinggi : ");
    scanf("%d %d", &r, &t);

    system("cls");
    header();

    printf("[-] Diketahui : \n\n");
    printf("Nilai Jari-Jari = %d cm\n", r);
    printf("Nilai Tinggi    = %d cm\n\n", t);

    printf("[-] Dijawab : \n\n");
    printf("V = phi x r^2 x t\n");
    printf("V = 3,14 x %d^2 x %d\n", r, t);
    printf("V = 3,14 x %d x %d\n", r*r, t);

    hasil = v_tabung(r, t);
    printf("V = %.2f cm^3\n\n", hasil);
    printf("[*] Hasil volume tabung adalah %.2f cm^3\n", hasil);
}

// KERUCUT
void cl_kerucut(void) {
    int r, s;
    float hasil;
    printf("[*] Masukan nilai jari-jari, garis pelukis : ");
    scanf("%d %d", &r, &s);

    system("cls");
    header();

    printf("[-] Diketahui : \n\n");
    printf("Nilai Jari-Jari     = %d cm\n", r);
    printf("Nilai Garis Pelkis  = %d cm\n\n", s);

    printf("[-] Dijawab : \n\n");
    printf("Lp = phi x r x (r + s)\n");
    printf("Lp = 3,14 x %d x (%d + %d)\n", r, r, s);
    printf("Lp = 3,14 x %d x %d\n", r, r+s);

    hasil = l_kerucut(r, s);
    printf("Lp = %.2f cm^2\n\n", hasil);
    printf("[*] Hasil luas permukaan kerucut adalah %.2f cm^2\n", hasil);
}

void cv_kerucut(void) {
    int r, t;
    float hasil;
    printf("[*] Masukan nilai jari-jari, tinggi : ");
    scanf("%d %d", &r, &t);

    system("cls");
    header();

    printf("[-] Diketahui : \n\n");
    printf("Nilai Jari-Jari = %d cm\n", r);
    printf("Nilai Tinggi    = %d cm\n\n", t);

    printf("[-] Dijawab : \n\n");
    printf("V = phi x r^2 x t / 3\n");
    printf("V = 3,14 x %d^2 x %d / 3\n", r, t);
    printf("V = 3,14 x %d x %d / 3\n", r*r, t);

    hasil = v_kerucut(r, t);
    printf("V = %.2f cm^3\n\n", hasil);
    printf("[*] Hasil volume kerucut adalah %.2f cm^3\n", hasil);
}

