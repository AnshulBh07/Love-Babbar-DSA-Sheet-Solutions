#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int uniqueMorseCode(vector<string>&words){
    vector<string> a = {".-","-...","-.-.","-..",".","..-.","--.","....",
                  "..",".---","-.-",".-..","--","-.","---",".--.",
                  "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

  	unordered_set<string> u;

  	for (auto word : words) {
  		string t;
  		for (auto c : word) t += a[c - 'a'];
  		u.insert (t);
  	 }

  return u.size ();
}

int main()
{
    vector<string> words{"gin","zen","gig","msg"};
    cout<<uniqueMorseCode(words);
    return 0;
}