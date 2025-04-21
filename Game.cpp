#include<iostream>
#include "Game.h"

#include <algorithm>

#include "Player.h"
#include "KenoNumbers.h"

// complete the implementation of the Game class here

Game :: Game() {

}
void Game::printMatches(std::vector<int>playerPicks,std::vector<int>kenoNumbers) {
    std::sort(playerPicks.begin(),playerPicks.end());
    std::sort(kenoNumbers.begin(),kenoNumbers.end());
    for(int i=0;i<playerPicks.size();i++) {
        if(playerPicks[i]==kenoNumbers[i]) {
            m_matches.push_back(playerPicks[i]);
        }
    }
}
void Game::displayResults() {
    Player temp;
    KenoNumbers knom;
    int winnings;
    std::cout << "Keno Numbers: " << knom.printKenoNumbers() << std::endl;  // have to overload operator
    std:: cout << "Player Picks: " << temp.printPlayerNumbers() << std::endl;

    for(int i=0;i<m_matches.size();i++) {
        std::cout << "You matched: " << std::endl;
        std::cout<<m_matches[i]<<" ";
    }
    if(m_matches.size() ==5) {
        winnings = 5;
    }
    if(m_matches.size() ==6) {
        winnings = 10;
    }
    if(m_matches.size() ==7) {
        winnings = 50;
    }
    if(m_matches.size() ==8) {
        winnings = 250;
    }
    if(m_matches.size() ==9) {
        winnings = 2,500;
    }
    if(m_matches.size() ==10) {
        winnings = 25,000;
    }

    std::cout << "Matching " << m_matches.size() << "  of 20 numbers wins $" << winnings << std::endl;

}
void Game::playGame()  {
    std::cout << "**************" << std::endl;
    std::cout << " * Play Keno! *" << std::endl;
    std::cout << "**************" << std::endl;
    std::cout << std::endl;

    Player player;
    KenoNumbers knom;

    player.inputPlayerNumbers();
    displayResults();
    char choice;
    std:: cout << "Play again? (y/n): " << std::endl;
    std::cin >> choice;
    if(choice == 'y') {
        player.clearPlayerNumbers();
        knom.clearKenoNumbers();
    }
    else if(choice == 'n') {
        std::cout << "THANKS FOR PLAYING!!" << std::endl;
    }





}