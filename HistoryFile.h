#pragma once

#include <string>
#include <vector>

class History {
private:
    std::vector<std::string> historia; 


public:
    // Dodawanie operacji do historii
    void dodajDoHistorii(const std::string& wpis) {
        historia.push_back(wpis);
    }

    // Pobieranie historii operacji
    std::vector<std::string> pobierzHistorie() const {
        return historia;
    }

    // Zapis i odczyt z pliku
    void zapiszDoPliku(const std::string& nazwaPliku) {
        std::ofstream plik(nazwaPliku);
        for (const auto& wpis : historia) {
            plik << wpis << std::endl;
        }
    }

    void wczytajZPliku(const std::string& nazwaPliku) {
        std::ifstream plik(nazwaPliku);
        std::string linia;
        while (std::getline(plik, linia)) {
            historia.push_back(linia);
        }
    }
};