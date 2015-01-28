#ifndef ITALHEAD_H_INCLUDED
#define ITALHEAD_H_INCLUDED

enum input_arguments{ prog_name = 0, italian_file_index = 1, english_file_index = 2, expected_input = 3};

enum return_values {

    success         =       1,

    wrong_input_size  =       -1,
    bad_input_files   =       -2


};

// Here I will specify all of types of games you can play

class MatchToEng{
public:
    int score;
    void play();
    std::vector<std::string> ItalianWords;
    std::vector<std::string> EnglishWords;
    MatchToEng() : score(0), ItalianWords(), EnglishWords() {};
    MatchToEng(std::vector<std::string> & italWords, std::vector<std::string> & engWords) : score(0) {
        ItalianWords = italWords;
        EnglishWords = engWords;
    };
};

void MatchToEng::play(){
    bool playing = true;
    std::cout << "Match the Italian word to it's English word. If you want to quit, type Q.\n" << std::endl;
    int place = 0, questions = 0, total = (int) ItalianWords.size();
    int correctPlaces[total];
    for(int &x : correctPlaces){
        x = 0;
    }
    std::string answer;
    while(playing){
        if(place == (int) ItalianWords.size()){
            std::cout << "Your score was " << score << " out of " << questions << std::endl;
            if(score < questions){
                std::cout << "Would you like to go over the ones you missed? (Y/N) ";
                std::cin >> answer;

                if(answer == "Y" || answer == "y"){
                    place = 0;
                    questions = 0;
                    total = total - score;
                }
                else{
                    std::cout << "Good Job on the ones you got!" << std::endl;
                    break;
                }
            }
        }

        if(correctPlaces[place] == 0){

            std::cout << ItalianWords[place] << " : ";
            std::cin;
            std::getline(std::cin, answer);

            if(!(answer.compare(EnglishWords[place]))){
                std::cout << "Good job!\n\n----------------------------------------------------\n" << std::endl;
                score++;
                questions++;
                correctPlaces[place] = 1;
            }
            else if(!answer.compare("Q") || !answer.compare("q")){
                std::cout << "Ohhhh! Mi Dispiace! Ciao!" << std::endl;
                playing = false;
            }else{
                std::cout << "Wrong! Should be \"" << EnglishWords[place] << "\"\n\n----------------------------------------------------\n" << std::endl;
                questions++;
            }
        }
        place++;
    }
}


class MatchToItal{

};

//  This class will be a little easier on you if you don't input just like the book
//  Will most likely become the default matching game
class EasyMatchToItal{

};

#endif // ITALHEAD_H_INCLUDED
