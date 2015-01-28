#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "ItalHead.h"

using namespace std;

int main(int argc, char * argv[])
{
    if(argc != 3){
        cout << "\n\nHey you need to give two input files!" << endl;
        return return_values::wrong_input_size;
    }
    else{
        ifstream inputItalianFile(argv[input_arguments::italian_file_index]);
        ifstream inputEnglishFile(argv[input_arguments::english_file_index]);

        if(inputItalianFile && inputEnglishFile){
            string tempStoreItal, tempStoreEng;
            vector<string> ItalianWords, EnglishWords;

            while(getline(inputItalianFile, tempStoreItal) && getline(inputEnglishFile, tempStoreEng)){
                ItalianWords.push_back(tempStoreItal);
                EnglishWords.push_back(tempStoreEng);
            }

            if(ItalianWords.size() == EnglishWords.size()){
                string choice;

                bool gameCreated = false;
                while(!gameCreated){

                    cout << "\n\nPlease choose a game by entering its number: \n\n (1) Match English to Italian (2) Match Italian to English: ";
                    cin >> choice;

                    if(choice == "1"){
                        MatchToEng match2ItalGame(EnglishWords, ItalianWords);  // ...I mean what's the point in copying over the same code for a different class. Swap vectors and you have what you want!
                        match2ItalGame.play();
                        gameCreated = true;
                    }else if(choice == "2"){
                        MatchToEng match2EngGame(ItalianWords, EnglishWords);
                        //MatchToEng match2EngGame(EnglishWords, ItalianWords);
                        match2EngGame.play();
                        gameCreated = true;
                    }else
                        cout << "Bad Input!" << endl;
                }
            }
        }else
            return return_values::bad_input_files;
    }
    return return_values::success;
}
