#pragma once

#include <vector>
#include <string>

using namespace std;

/**
 * @brief Odstraní duplikáty ze sady celých čísel.
 * 
 * @param set Sada celých čísel, ze které se mají odstranit duplikáty.
 */
void removeDuplicates(vector<int>& set);

/**
 * @brief Najde průnik dvou sad celých čísel.
 * 
 * @param setA První sada celých čísel.
 * @param setB Druhá sada celých čísel.
 * @return Vektor obsahující prvky, které jsou přítomny v obou sadách.
 */
vector<int> findIntersection(vector<int>& setA, vector<int>& setB);

/**
 * @brief Vytiskne prvky sady na standardní výstup.
 * 
 * @param set Sada celých čísel k vytisknutí.
 */
void printSet(vector<int> set);

/**
 * @brief Načte sadu celých čísel ze souboru.
 * 
 * @param path Cesta k souboru, ze kterého se má načíst sada.
 * @return Vektor obsahující načtená celá čísla.
 */
vector<int> loadSetFromFile(string path);

/**
 * @brief Uloží sadu celých čísel do souboru.
 * 
 * @param path Cesta k souboru, do kterého se má uložit sada.
 * @param set Sada celých čísel k uložení.
 */
void saveSetToFile(string path, vector<int> set);
