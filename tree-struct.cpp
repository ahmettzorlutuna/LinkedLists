struct node {
    int veri;
    node *sol;
    node *sag;
};

// Ağaç düğümünü işleyen bir fonksiyon
void dugumIsle(node *r) {
    // Fonksiyon içinde node * r kullanabiliriz
    // Örneğin, r'nin sol ve sağ alt ağaçlarına erişebiliriz.
    if (r != nullptr) {
        // r'nin verisini kullan
        int veri = r->veri;

        // r'nin sol alt ağacını işle
        dugumIsle(r->sol);

        // r'nin sağ alt ağacını işle
        dugumIsle(r->sag);
    }
}

int main() {
    // Örnek bir ağaç düğümü oluştur
    node *kok = new node{10, nullptr, nullptr};

    // Ağaç düğümünü işle
    dugumIsle(kok);

    // Bellekten ayrılan alanı serbest bırak
    delete kok;

    return 0;
}