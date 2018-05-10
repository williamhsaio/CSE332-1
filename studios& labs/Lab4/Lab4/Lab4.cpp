#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "card1.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "Game.h"
#include "FiveCardDraw.h"
#include "SevenCardStud.h"
using namespace std;

int check_command(int argc, char *argv[]) {
	cout << argv[0] << endl;
	if (argc < 4) {
		// so few input command
		/*
		cout << "please enter at least three arguments" << endl;
		cout << "please input the command as following style: -> Lab4.exe <GameName> <playerName> <playerName>" << endl;
		*/
		throw card1::command_line::too_few;
	}

	string check_s = argv[1];
	//cout << "1" << endl;
	
	if (check_s.find("FiveCardDraw") == std::string::npos && check_s.find("SevenCardStud") == std::string::npos) {
		
		cout << "please enter a correct game name which is FiveCardDraw or SevenCardStud" << endl;
		cout << "please input the command as following style: -> Lab4.exe <GameName> <playerName> <playerName>" << endl;
		throw card1::success_fail::unknown_game;
	}
	
	if (argc >12&& check_s.find("FiveCardDraw") != std::string::npos) {
		// check if too many players 
		cout << " too many players , not enough cards" << endl;
		
		throw card1::command_line::too_much;
	}

	if (argc >9 && check_s.find("SevenCardStud") != std::string::npos) {
		// check if too many players 
		cout << " too many players , not enough cards" << endl;

		throw card1::command_line::too_much;
	}

	for (int i = 2; i < argc - 1; i++) {
		for (int j = i + 1; j < argc; j++) {
			//cout << 1 << endl;
			//cout << argv[i] << ": " << argv[j] << endl;
			string my_string1(argv[i]);
			string my_string2(argv[j]);
			if (my_string1 == my_string2) {
				cout << "you can't add the same player twice " << endl;
				throw(card1::success_fail::already_playing);
			}
		}
	}

	// return 0
	return card1::command_line::all_right;
}

void usage1(int argc, char *argv[]) {

	cout << "Please do as fllowing to use Lab4.exe:  ";
	cout << "with at least 4 arguments as " << argv[0];
	cout << "  FiveCardDraw   <playerName> <playerName> ...and <playerName>" << endl;
	cout << "YOU wrong input was : ";
	for (int i = 0; i < argc; ++i) {
		cout << argv[i] << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[])
{


	try {
		check_command(argc, argv);

	}
	catch (command_line &e) {
		usage1(argc, argv); // print out the usage function
		return e;
	}
	catch (success_fail &e) {

		if (e == -104) {
			cout << "instance_not_available" << endl;
		}
		if (e == -105) {
			cout << "game_already_started " << endl;
		}
		if (e == -106) {
			cout << "unknown_game" << endl;
		}
		if (e == -107) {
			cout << "no_game_in_progress" << endl;
		}
		if (e == -108) {
			cout << "already_playing" << endl;
		}
		if (e == -109) {
			cout << "no_enough_card_in_both_deck " << endl;
		}
		cout << "some thing goes wrong" << endl;
		usage1(argc, argv);
		return e;
	}
	catch (...) {

		cout << "oppps! I not sure about what happened" << endl;
		usage1(argc, argv);
		return card1::success_fail::unclear_error;
	}

	string np = argv[1];
	string finish_;
	while (np.find("FiveCardDraw") != std::string::npos || np.find("SevenCardStud") != std::string::npos) {
		
		
		
		if (np.find("FiveCardDraw") != std::string::npos) {
			try {

				cout << "you try to play FiveCardDraw Game" << endl;
				game::start_game(np);

				shared_ptr<game> game = game::instance();

				for (int i = 2; i < argc; ++i) {
					game->add_player(argv[i]);
				}

				int round = 0;
				
				//While there are still at least two players in the game, the main function 
				//should repeatedly call the game object's before_round, round, and after_round methods.
				while (game->player_size() >= 2) {
					try {
						++round;
						cout << endl << "-round number : " << round << "------------" << endl;
						cout << endl << "---------------------------" << endl;
						cout << " new game started " << endl;
						game->before_round(); //
						cout << endl << "going into _round()------------" << endl;
						game->round(); //
						cout << endl << "-after_round()------------" << endl;
						game->after_round();
						
					}
					catch (success_fail &e) {
						if (e == -113) {
							cout << "all but one players chose to fold" << endl;
							cout << "let's start a new round" << endl;
							game->after_round();
						}
						else if (e == -112) {
							cout << "no_enough_player_in_game" << endl;
							break;
						}
						else if (e == 0) {
							cout << "finish the game" << endl;
							break;
						}
						else {
							cout << "something unknow happened" << endl;
							game->after_round();
						}
						continue;
					}
					catch (...) {
						cout << "something unknow happened in the second catch" << endl;
						game->after_round();
						continue;
					}

				}
				if (game->player_size() < 2) {
					cout << "sorry, only | " << game->player_size() << " | player, we have to cancel the game" << endl;
				}

				game->stop_game();
			}
			//instance_not_available = -104, game_already_started = -105, unknown_game = -106, no_game_in_progress =-107, already_playing=-108
			//, no_enough_card_in_both_deck = -109,unclear_error =-110

			catch (success_fail &e) {
				game::stop_game();
				if (e == 0) {
					cout << "you finished the current game " << endl;

				}
				else {
					if (e == -104) {
						cout << "instance_not_available" << endl;
					}
					if (e == -105) {
						cout << "game_already_started " << endl;
					}
					if (e == -106) {
						cout << "unknown_game" << endl;
					}
					if (e == -107) {
						cout << "no_game_in_progress" << endl;
					}
					if (e == -108) {
						cout << "already_playing" << endl;
					}
					if (e == -109) {
						cout << "no_enough_card_in_both_deck " << endl;
					}

					if (e == -112) {
						cout << "no_enough_player_in_game " << endl;
					}

					cout << "some thing goes wrong" << endl;
					usage1(argc, argv);
					return e;
				}
			}
			catch (...) {
				game::stop_game();

				cout << "oppps! I not sure about what happened" << endl;
				usage1(argc, argv);
				return card1::success_fail::unclear_error;
			}
		}

		else if (np.find("SevenCardStud") != std::string::npos) {
			try {
				cout << "you try to play SevenCardStud Game" << endl;
				game::start_game(np);

				shared_ptr<game> game = game::instance();

				for (int i = 2; i < argc; ++i) {
					game->add_player(argv[i]);
				}

				int round = 0;

				//While there are still at least two players in the game, the main function 
				//should repeatedly call the game object's before_round, round, and after_round methods.
				while (game->player_size() >= 2) {
					try {
						++round;
						cout << endl << "-round number : " << round << "------------" << endl;
						cout << endl << "---------------------------" << endl;
						cout << " new game started " << endl;
						game->before_round(); //
						cout << endl << "-before_round()------------------" << endl;
						game->round();
						cout << endl << "-after_round()------------" << endl;
						game->after_round();
						
					}
					catch (success_fail &e) {
						if (e == -113) {
							cout << "all but one players chose to fold" << endl;
							cout << "let's start a new round" << endl;
							game->after_round();
						}
						
						else if (e == -112) {
							cout << "no_enough_player_in_game" << endl;
							break;
						}
						else if (e == 0) {
							cout << "finish the game" << endl;
							break;
						}
						else {
							cout << "something unknow happened" << endl;
							game->after_round();
						}
						continue;
					}
					catch (...) {
						cout << "something unknow happened in the second catch" << endl;
						game->after_round();
						continue;
					}

				}

				if (game->player_size() < 2) {
					cout << "sorry, only | " << game->player_size() << " | player, we have to cancel the game" << endl;
				}

				game->stop_game();
			}
			//instance_not_available = -104, game_already_started = -105, unknown_game = -106, no_game_in_progress =-107, already_playing=-108
			//, no_enough_card_in_both_deck = -109,unclear_error =-110

			catch (success_fail &e) {
				game::stop_game();
				if (e == 0) {
					cout << "you finished the current game " << endl;

				}
				else {
					if (e == -104) {
						cout << "instance_not_available" << endl;
					}
					if (e == -105) {
						cout << "game_already_started " << endl;
					}
					if (e == -106) {
						cout << "unknown_game" << endl;
					}
					if (e == -107) {
						cout << "no_game_in_progress" << endl;
					}
					if (e == -108) {
						cout << "already_playing" << endl;
					}
					if (e == -109) {
						cout << "no_enough_card_in_both_deck " << endl;
					}

					if (e == -112) {
						cout << "no_enough_player_in_game " << endl;
					}

					cout << "some thing goes wrong" << endl;
					usage1(argc, argv);
					return e;
				}
			}
			catch (...) {
				game::stop_game();

				cout << "oppps! I not sure about what happened" << endl;
				usage1(argc, argv);
				return card1::success_fail::unclear_error;
			}
		}
		else {
			cout << "please enter a correct game name which is FiveCardDraw or SevenCardStud" << endl;
			cout << "please input the command as following style: -> Lab4.exe <GameName> <playerName> <playerName>" << endl;
			return card1::success_fail::unknown_game;
		}

		cout << "Please type <FiveCardDraw> or <SevenCardStud> to keep play one of those games " << endl;
		cout << "Or type in any other arguments to exit the game.exe" << endl;
		getline(cin, np);
		cout << "your input string is : " << np<< endl;
		if (!(np.find("FiveCardDraw") != std::string::npos || np.find("SevenCardStud") != std::string::npos)) {
			cout << "Ok, you end the game, have a good night" << endl;
			break;
		}
	}
	return success;

}



