#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int uniqueMorseCode(vector<string>&words){
    vector<string> dictionary = {".-","-...","-.-.","-..",".","..-.","--.","....",
                  "..",".---","-.-",".-..","--","-.","---",".--.",
                  "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

  	unordered_set<string> s;

  	for (auto word : words) {
  		string t;
  		for (auto c : word) t += dictionary[c - 'a'];
  		s.insert (t);
  	 }

  return s.size ();
}

int main()
{
    vector<string> words{"gin","zen","gig","msg"};
    cout<<uniqueMorseCode(words);
    return 0;
}