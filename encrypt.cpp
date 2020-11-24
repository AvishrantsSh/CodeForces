#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Caesar{
  string *stop;
  int stop_size;
  vector<string> v;
  void to_list(const string &str);
  public:
    Caesar(){
      string stopword[] = {"that", "at", "the", "he" "she", "it"};
      stop_size = 5;
      stop = new string[5];
      for(int i = 0; i < 5; i++)
        stop[i] = stopword[i];
      
    }
    Caesar(const string *arr, int size){
      stop = new string[size];
      stop_size = size;
      for(int i = 0; i < size; i++)
        stop[i] = arr[i];
    }
    void encrypt(string &txt, int block);
    void decrypt(string &enc);
};

void Caesar::encrypt(string &txt, int block){
  block %= 26;
  for( int i = 0; i < txt.size(); i++){
    if(!ispunct(txt[i]) && !isspace(txt[i])){
      if((islower(txt[i]) && txt[i]+block > 'z') || (isupper(txt[i]) && txt[i]+block > 'Z'))
        txt[i] += block-26;
      else
        txt[i] += block;
    }
  }
}

void Caesar::to_list(const string &str){
  string word = "";
  for (auto x : str) 
  {
      if (isspace(x) || ispunct(x))
      {   
          if(word == ""){
            continue;
          }
          v.push_back(word);
          word = "";
      }
      else{
        x = tolower(x);
        word = word + x;
      }
  }
  v.push_back(word);
}

void Caesar::decrypt(string &enc){
  for(int i = 1; i < 26 ; i++){
    encrypt(enc, 1);
    to_list(enc);
    
    bool flag = false;
    for(int tmp = 0; tmp < v.size(); tmp++){
      for(int k = 0; k < stop_size; k++){
        if (stop[k] == v[tmp]){
          flag = true;
          break;
        }
      }
      if(flag)break;
    }
    if(flag){
      cout << "Decrypted Text" << endl;
      cout << enc << endl;
      cout << endl << "Block Used: "<< 26-i << endl;
      break;
    }
  }
}

int main() {
  string stop[] = {"the", "an", "in", "he", "she", "it", "we", "her", "his", "you", "this", "that", "who"};
  int size = sizeof(stop)/sizeof(string);
  string tmp = "There once was a girl whose name was Alice. She was very sweet and kind to all. But destiny wasn'y so kind to her.";
  Caesar cipher(stop, size);
  cipher.encrypt(tmp, 18);
  cout << "Encrypted Text" << endl;
  cout << tmp << endl;
  string enc = "Lzwjw gfuw osk s yajd ozgkw fsew osk Sdauw. Kzw osk nwjq kowwl sfv cafv lg sdd. Tml vwklafq oskf'q kg cafv lg zwj.";
  cipher.decrypt(enc);
  return 0;
}
