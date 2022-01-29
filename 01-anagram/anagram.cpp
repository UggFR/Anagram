#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <vector>
#include <cstdio>

std::vector<std::string> load(std::string fichier) {
  std::vector<std::string> tab={};
  std::ifstream file(fichier);
  std::string ligne;
  while(std::getline(file, ligne)){
    tab.push_back(ligne);
  }
  return tab;
}

std::string normalize(std::string const &v) {
  std::vector<char> lettre={};
  std::string v_alph="";
  for(size_t i=0;i<v.size();i++){
    lettre.push_back(v[i]);
  }
  std::sort(lettre.begin(),lettre.end());
  for(size_t j=0;j<lettre.size();j++){
    v_alph +=lettre[j];
  }
  return v_alph;
}

bool anagram(std::string const &v1, std::string const &v2) {
  std::string v1_alph = normalize(v1);
  std::string v2_alph = normalize(v2);
  if(v1_alph == v2_alph){
    return true;
  }
  else{
    return false;
  }
}

using dictionary = std::multimap<std::string, std::string>;

dictionary convert(std::vector<std::string> &vect) {
  // A REMPLIR
  dictionary dico ;
  for(size_t i=0;i<vect.size();i++){
    dico.insert(std::pair<std::string,std::string>(normalize(vect.at(i)),vect.at(i)));
  }
  return dico;
}

// std::vector<std::string> anagrams(dictionary const &dict, std::string const &s) {
//   std::vector<std::string> v={};
//   //std::pair<std::string,std::string> value = {"?",s};
//   //auto ip = equal_range(dict.begin(), dict.end(), normalize(s));
//   auto ip = dict.equal_range(normalize(s));
//   for(auto i=ip.first; i != ip.second; i++){
//     auto val = i->second;
//     v.push_back(val);
//   }
//   return v;
// }

//Fonction anagramme sans equal_range
std::vector<std::string> anagrams(dictionary const &dict, std::string const &s) {
  std::vector<std::string> v={};
  for(auto mot=dict.begin();mot != dict.end();mot++){
    if(mot->second == normalize(s) && mot->first != s){
      v.push_back(mot->first);
    }
  }
  return v;
}

int main() {
  std::string alph = normalize("badc");
  std::cout << alph << "\n";
  std::string test1 = "test";
  std::string test2 = "tsst";
  std::string test3 = "tste";
  std::string mot_a_test = "parrot";
  bool ana = anagram(test1,test3);
  if(ana == true){
    std::cout << "Les mots " << test1 << " et " << test3 << " sont des anagrammes." << "\n";
  }
  else{
        std::cout << "Les mots " << test1 << " et " << test3 << " ne sont pas des anagrammes." << "\n";
  }
  std::vector<std::string> tab_string={};
  tab_string = load("/home/tp-home006/hmarti3/Desktop/TP_01-02-03/anagramme_sujet/01-anagram/words.txt");
  //std::cout << "Le nombre de mots du fichier est de " << tab_string.size() << " et le dernier mot du fichier est " << tab_string.back() << ".\n";
  dictionary mot_fichier = convert(tab_string);
  std::vector<std::string> tab_ana;
  anagrams(mot_fichier, mot_a_test);
  tab_ana = anagrams(mot_fichier, mot_a_test);
  std::cout << tab_ana.at(0);
  for(size_t i=0;i<tab_ana.size()-1;i++){
    std::cout << tab_ana.at(i) << ",";
  }
  std::cout << tab_ana.back() << ".\n";
}
