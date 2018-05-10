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
using namespace std;

int check_command(int argc, char *argv[]) {
	
	if (argc < 4) {
		// so few input command
		cout << "please enter at least three arguments" << endl;
		cout << "please input the command as following style: -> Lab2.exe <GameName> <playerName> <playerName>" << endl;

		throw card1::command_line::too_few;
	}
	for (int i = 2; i < argc-1;i++) {
		for (int j = i + 1; j < argc;j++) {
			//cout << 1 << endl;
			//cout << argv[i] << ": " << argv[j] << endl;
			string my_string1(argv[i]);
			string my_string2(argv[j]);
			if (my_string1== my_string2) {
				cout << "you can't add the same player twice " << endl;
				throw(card1::success_fail::already_playing);
			}
		}
	}

	// return 0
	return card1::command_line::all_right;
}

void usage1(int argc, char *argv[]) {

	cout << "Please do as fllowing to use Lab3.exe:  ";
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
	
	try {
		game::start_game(argv[1]);
		shared_ptr<game> game = game::instance();
		for (int i = 2; i < argc; ++i) {
			game->add_player(argv[i]);
		}
		int round = 0;
		//While there are still at least two players in the game, the main function 
		//should repeatedly call the game object's before_round, round, and after_round methods.
		while (game->player_size() >=2) {
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
		if (game->player_size() < 2) {
			cout << "sorry, only | " << game->player_size() << " | player, we have to cancel the game" << endl;
		}

		//game->add_player("wushuo");
		
		//pointer->add_player("wushuo1");
		//pointer->add_player("wushuo2");
		game->stop_game();
	}
	//instance_not_available = -104, game_already_started = -105, unknown_game = -106, no_game_in_progress =-107, already_playing=-108
	//, no_enough_card_in_both_deck = -109,unclear_error =-110

	catch (success_fail &e) {
		game::stop_game();
		
		if (e == -104) {
			cout <<"instance_not_available"  << endl;
		}
		if (e == -105) {
			cout <<"game_already_started " << endl;
		}
		if (e == -106) {
			cout <<"unknown_game" << endl;
		}
		if (e == -107) {
			cout <<"no_game_in_progress" << endl;
		}
		if (e == -108) {
			cout << "already_playing"<< endl;
		}
		if (e == -109) {
			cout << "no_enough_card_in_both_deck "<< endl;
		}
		cout << "some thing goes wrong" << endl;
		usage1(argc, argv);
		return e;
	}
	catch (...) {
		game::stop_game();

		cout << "oppps! I not sure about what happened" << endl;
		usage1(argc, argv);
		return card1::success_fail::unclear_error;
	}

	return success;

}



