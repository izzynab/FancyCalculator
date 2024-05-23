#include <fstream>
#include "HistoryFile.h"
#include <vector>

void zapiszHistorieDoPliku(const std::vector<std::string>& historia) {
    std::ofstream plik("historia.txt");
    for (const auto& linia : historia) {
        plik << linia << std::endl;
    }
}

std::vector<std::string> wczytajHistorieZPliku() {
    std::ifstream plik("historia.txt");
    std::vector<std::string> historia;
    std::string linia;
    while (std::getline(plik, linia)) {
        historia.push_back(linia);
    }
    return historia;
}
