#include "stdafx.h"
#include "card1.h"
#include "hand.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

card hand::operator[](size_t index) {
	if (index >this->hand_.size()-1) {
		cout << "invalid index, too much" << endl;
		throw card1::success_fail::index_over_flow;
		
	}

	return this->hand_[index];
}

void hand::remove_card(size_t index) {
	if (index > this->hand_.size() - 1) {
		cout << "invalid index, too much" << endl;
		throw card1::success_fail::index_over_flow;

	}
	this->hand_.erase(hand_.begin() + index , hand_.begin() + index +1);
}

void operator<<(hand &h, Deck &d) {

	if (d.size() <1) {
		throw(card1::success_fail::empty_deck);
	}
	card new_one = d.popBack();
	h.hand_.push_back(new_one);
	std::sort(h.hand_.begin(), h.hand_.end());
}

hand::hand() {
	hand_ = vector<card>();

}

hand::hand(const hand &another) {
	hand_ = another.hand_;

}

hand::~hand() {
	hand_.~vector();
}

hand hand::operator= (const hand &another) {
	if (this == &another) {
		return *this;
	}
	else {
		hand_ = another.hand_;
		return *this;
	}
}

const int hand::size() const {
	return this->hand_.size();
}

const bool hand::operator== (const hand &another) {
	if (this->hand_.size() != another.hand_.size()) {
		return false;
	}
	size_t number = hand_.size();
	for (size_t i = 0; i < number; ++i) {
		card a = hand_[i];
		card b = another.hand_[i];
		if (!(a == b)) {
			return false;
		}
	}
	return true;
}

const bool hand::operator< (const hand &another) {
	size_t size = hand_.size();
	for (size_t i = 0; i < size; ++i) {
		card a = hand_[i];
		card b = another.hand_[i];
		if (a == b) {
			continue;
		}
		else {
			return a < b;
		}
	}
	return false;
}

const string hand::asString() {
	string out1 = "";
	for (size_t i = 0; i < hand_.size(); ++i) {
		card temp1 = hand_[i];
		out1 = out1 + card::string_of_card_rank(temp1.rank) + card::string_of_card_suit(temp1.suits) + " ";
	}
	return out1;
}

ostream & operator<< (ostream &o, const hand &h) {
	int cardCount = h.hand_.size();
	vector<card> temp = h.hand_;
	card temp1;
	for (int i = 0; i < cardCount; ++i) {
		temp1 = temp[i];
		o << " " << card::string_of_card_rank(temp1.rank) << "" << card::string_of_card_suit(temp1.suits) << " | ";
	}
	return o;
}



/*

int hand::sorted_all_divide_5_extension(const vector<card> & deck, vector<hand> check) {
int size = deck.size();

//vector <hand> dsja= deck;
try {
if (size % 5 != 0) {
cout << "the input vector for sorted is invalid vector" << endl;
throw "invalid vector";
}
// temp vecotr to hold the five card
vector<card> sub_set;
int number = size / 5;
for (int i = 0; i < number; i++) {
for (int j = 0; j < 5; j++) {
sub_set.push_back(deck[j + i * 5]);
}

if (sub_set.size() != 5) {
throw "invalid size of sub vector";
}
vector<card> sorted = sub_set;
sort(sorted.begin(), sorted.end());
hand inter(sorted[0], sorted[1], sorted[2], sorted[3], sorted[4]);

check.push_back(inter);

sub_set.clear();

}

}
catch (const char* message) {
return invalid_vector;
}


sorted_hand_and_print_it(check);
return success;
}


int hand::sorted_hand_and_print_it(const vector<hand> & test) {
vector<hand> sorted = test;
sort(sorted.begin(), sorted.end());

for (size_t i = 0; i != sorted.size(); ++i) {
int index = static_cast<int>(i);
cout << "" << endl;
if (index == 8) {
cout << " !!!!!!!!YOU GOT StraightFlush !!!!!" << endl;
}
if (index == 7) {
cout << " !!!!!!!!YOU GOT FourOfAKind !!!!!" << endl;
}
if (index == 6) {
cout << " !!!!!!!!YOU GOT FullHouse !!!!!" << endl;
}
if (index == 5) {
cout << " !!!!!!!!YOU GOT Flush !!!!!" << endl;
}
if (index == 4) {
cout << " !!!!!!!!YOU GOT Straight !!!!!" << endl;
}
if (index == 3) {
cout << " !!!!!!!!YOU GOT ThreeOfAKind !!!!!" << endl;
}
if (index == 2) {
cout << " !!!!!!!!YOU GOT TwoPairs !!!!!" << endl;
}
if (index == 1) {
cout << " !!!!!!!!YOU GOT OnePair !!!!!" << endl;
}
if (index == 0) {
cout << " !!!!!!!!YOU GOT NO RAnk, please ask professor for the reason !!!!!" << endl;
}
cout << " The " << index << " TH hand is here : It contains the following cards: " << endl;
cout << "This card information is here: Card's rank is : " << sorted[i].a_.rank;
cout << " and Card's suit is : " << sorted[i].a_.suits << endl;
cout << "This card information is here: Card's rank is : " << sorted[i].b_.rank;
cout << " and Card's suit is : " << sorted[i].b_.suits << endl;
cout << "This card information is here: Card's rank is : " << sorted[i].c_.rank;
cout << " and Card's suit is : " << sorted[i].c_.suits << endl;
cout << "This card information is here: Card's rank is : " << sorted[i].d_.rank;
cout << " and Card's suit is : " << sorted[i].d_.suits << endl;
cout << "This card information is here: Card's rank is : " << sorted[i].e_.rank;
cout << " and Card's suit is : " << sorted[i].e_.suits << endl;
cout << "" << endl;
cout << "" << endl;



}
return success;

}
*/

int check_rank_new(const vector<card> & deck) {
	//cout << "nice: "<< no_rank << endl;
	if (IsStraightFlush(deck)) {



		return StraightFlush;
	}
	else if (IsFourOfAKind(deck)) {



		return FourOfAKind;
	}
	else if (IsFullHouse(deck)) {



		return FullHouse;
	}
	else if (IsFlush(deck)) {

		return Flush;
	}
	else if (IsStraight(deck)) {


		return Straight;
	}
	else if (IsThreeOfAKind(deck)) {


		return ThreeOfAKind;
	}
	else if (IsTwoPairs(deck)) {


		return TwoPairs;
	}
	else if (IsOnePair(deck)) {

		return OnePair;
	}

	return No_Rank;
}

void hand::check_rank_new_with_hand(hand & hand1) {
	if (hand1.hand_.size() != 5) {
		return;
	}
	//cout << "nice: "<< no_rank << endl;
	vector<card> deck;
	deck.push_back(hand1.hand_[0]);
	deck.push_back(hand1.hand_[1]);
	deck.push_back(hand1.hand_[2]);
	deck.push_back(hand1.hand_[3]);
	deck.push_back(hand1.hand_[4]);

	if (IsStraightFlush(deck)) {

		cout << " !!!!!!!!YOU GOT StraightFlush !!!!!" << endl;

		return;
	}
	else if (IsFourOfAKind(deck)) {
		cout << " !!!!!!!!YOU GOT FourOfAKind !!!!!" << endl;


		return;
	}
	else if (IsFullHouse(deck)) {
		cout << " !!!!!!!!YOU GOT FullHouse !!!!!" << endl;


		return;
	}
	else if (IsFlush(deck)) {
		cout << " !!!!!!!!YOU GOT Flush !!!!!" << endl;


		return;
	}
	else if (IsStraight(deck)) {
		cout << " !!!!!!!!YOU GOT Straight !!!!!" << endl;

		return;
	}
	else if (IsThreeOfAKind(deck)) {
		cout << " !!!!!!!!YOU GOT ThreeOfAKind !!!!!" << endl;

		return;
	}
	else if (IsTwoPairs(deck)) {
		cout << " !!!!!!!!YOU GOT TwoPairs !!!!!" << endl;

		return;
	}
	else if (IsOnePair(deck)) {
		cout << " !!!!!!!!YOU GOT OnePair !!!!!" << endl;
		return;
	}
	cout << " !!!!!!!!YOU GOT NO RAnk, please ask professor for the reason !!!!!" << endl;
	return;
}


bool IsStraightFlush(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}
	int value = case1[0].rank;
	for (size_t i = 1; i < 5; i++) {
		if (case1[i].suits != case1[i - 1].suits) {
			return false;
		}
		if (case1[i].rank != value + 1) {
			return false;
		}
		value = value + 1;
	}
	return true;
}

bool  IsFourOfAKind(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}
	//will be true if a0=a1=a2=a3and !=a4
	if (case1[0].rank == case1[1].rank&& case1[1].rank == case1[2].rank && case1[2].rank == case1[3].rank&&case1[3].rank != case1[4].rank) {
		return true;
	}
	//will be true if a1=a2=a3=a4 != a0
	if (case1[0].rank != case1[1].rank&& case1[1].rank == case1[2].rank && case1[2].rank == case1[3].rank&&case1[3].rank == case1[4].rank) {
		return true;
	}
	return false;
}

bool  IsFullHouse(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}
	//will be true if a0=a1=a2=a3and !=a4
	if (case1[0].rank == case1[1].rank&& case1[1].rank == case1[2].rank && case1[3].rank == case1[4].rank&&case1[0].rank != case1[4].rank) {
		return true;
	}
	//will be true if a1=a2=a3=a4 != a0
	if (case1[0].rank == case1[1].rank&& case1[2].rank == case1[3].rank && case1[3].rank == case1[4].rank&&case1[0].rank != case1[4].rank) {
		return true;
	}
	return false;

}

bool  IsFlush(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}
	if (case1[0].suits == case1[1].suits&&case1[1].suits == case1[2].suits&&case1[2].suits == case1[3].suits&&case1[3].suits == case1[4].suits) {
		return true;
	}
	return false;
}

bool  IsStraight(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}
	if (case1[0].rank == case1[1].rank - 1 && case1[1].rank == case1[2].rank - 1 && case1[2].rank == case1[3].rank - 1 && case1[3].rank == case1[4].rank - 1) {
		return true;
	}
	return false;
}

bool  IsThreeOfAKind(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}
	if (case1[0].rank == case1[1].rank && case1[1].rank == case1[2].rank) {
		return true;
	}
	if (case1[1].rank == case1[2].rank && case1[2].rank == case1[3].rank) {
		return true;
	}
	if (case1[2].rank == case1[3].rank && case1[3].rank == case1[4].rank) {
		return true;
	}

	return false;
}

bool  IsTwoPairs(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}

	if (case1[0].rank == case1[1].rank && case1[2].rank == case1[3].rank) {
		return true;
	}
	else if (case1[0].rank == case1[1].rank && case1[3].rank == case1[4].rank) {
		return true;
	}
	else if (case1[1].rank == case1[2].rank && case1[3].rank == case1[4].rank) {
		return true;
	}

	return false;
}


bool  IsOnePair(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}
	if (case1[0].rank == case1[1].rank) {
		return true;
	}
	if (case1[1].rank == case1[2].rank) {
		return true;
	}
	if (case1[2].rank == case1[3].rank) {
		return true;
	}
	if (case1[3].rank == case1[4].rank) {
		return true;
	}

	return false;
}


// these two hands only contains five cards, built on the main function from lab1 extra bonus
bool hand::poker_rank(const hand & hand1, const hand & another_hand) {
	if (hand1.hand_.size() == 5 && another_hand.hand_.size() == 5) {
		vector<card> that;
		that.push_back(hand1.hand_[0]);
		that.push_back(hand1.hand_[1]);
		that.push_back(hand1.hand_[2]);
		that.push_back(hand1.hand_[3]);
		that.push_back(hand1.hand_[4]);
		sort(that.begin(), that.end());
		int a1 = check_rank_new(that);

		vector<card> another;
		another.push_back(another_hand.hand_[0]);
		another.push_back(another_hand.hand_[1]);
		another.push_back(another_hand.hand_[2]);
		another.push_back(another_hand.hand_[3]);
		another.push_back(another_hand.hand_[4]);
		sort(another.begin(), another.end());
		int a2 = check_rank_new(another);

		card a_ = hand1.hand_[0];
		card b_ = hand1.hand_[1];
		card c_ = hand1.hand_[2];
		card d_ = hand1.hand_[3];
		card e_ = hand1.hand_[4];

		if (a1 < a2) {
			return false;
		}
		else if (a1 > a2) {
			return true;
		}
		else {

			if (a1 == a2&&a2 == 8) {
				if (a_.rank < another_hand.hand_[0].rank) {
					return false;
				}
				else {
					return true;
				}
			}
			else if (a1 == a2&& a2 == 7) {
				if (c_.rank < another_hand.hand_[2].rank) {
					return false;
				}
				else {
					return true;
				}
			}
			else if (a1 == a2&& a2 == 6) {
				if (c_.rank < another_hand.hand_[2].rank) {
					return false;
				}
				else if (c_.rank > another_hand.hand_[2].rank) {
					return true;
				}
				else {
					if (a_.rank == c_.rank && another_hand.hand_[0].rank == another_hand.hand_[2].rank) {
						if (d_.rank < another_hand.hand_[4].rank) {
							return false;
						}
						else {
							return true;
						}
					}
					if (a_.rank == c_.rank && another_hand.hand_[0].rank != another_hand.hand_[2].rank) {
						if (d_.rank < another_hand.hand_[0].rank) {
							return false;
						}
						else {
							return true;
						}
					}
					if (a_.rank != c_.rank && another_hand.hand_[0].rank != another_hand.hand_[2].rank) {
						if (a_.rank < another_hand.hand_[0].rank) {
							return false;
						}
						else {
							return true;
						}
					}
					if (a_.rank != c_.rank && another_hand.hand_[0].rank == another_hand.hand_[2].rank) {
						if (a_.rank < another_hand.hand_[3].rank) {
							return false;
						}
						else {
							return true;
						}
					}
				}
			}
			else if (a1 == a2&&a2 == 5) {
				if (e_.rank < another_hand.hand_[4].rank) {

					return false;
				}
				else if (e_.rank > another_hand.hand_[4].rank) {
					return true;
				}
				else {
					if (d_.rank < another_hand.hand_[3].rank) {
						return false;
					}
					else if (d_.rank > another_hand.hand_[3].rank) {
						return true;
					}
					else {
						if (c_.rank < another_hand.hand_[2].rank) {
							return false;
						}
						else if (c_.rank > another_hand.hand_[2].rank) {
							return true;
						}
						else {
							if (b_.rank < another_hand.hand_[1].rank) {
								return false;
							}
							else if (b_.rank > another_hand.hand_[1].rank) {
								return true;
							}
							else {
								if (a_.rank < another_hand.hand_[0].rank) {
									return false;
								}
								else {
									return true;
								}

							}

						}
					}
				}
			}
			else if (a1 == a2&& a2 == 4) {
				if ((card)another_hand.hand_[4]< e_) {
					return true;
				}
				else {
					return false;
				}
			}
			else if (a1 == a2&&a2 == 3) {
				if (c_.rank > another_hand.hand_[2].rank) {
					return true;
				}
				else {
					return false;
				}
			}
			else if (a1 == a2&& a2 == 2) {
				vector<int> hand_1 = GetTwoPair(hand1);
				vector<int> hand_2 = GetTwoPair(another_hand);
				card hand_1_high = hand1.hand_[hand_1[0]];
				card hand_1_low = hand1.hand_[hand_1[1]];
				card hand_1_single = hand1.hand_[hand_1[2]];
				card hand_2_high = another_hand.hand_[hand_2[0]];
				card hand_2_low = another_hand.hand_[hand_2[1]];
				card hand_2_single = another_hand.hand_[hand_2[2]];

				if (hand_2_high.rank != hand_1_high.rank) {
					return hand_2_high.rank < hand_1_high.rank;
				}
				if (hand_2_low.rank != hand_1_low.rank) {
					return hand_2_low.rank < hand_1_low.rank;
				}
				if (hand_2_single.rank != hand_1_single.rank) {
					return hand_2_single.rank < hand_1_single.rank;
				}
				return false;
			}
			//revised if two hands both are one pair 
			else if (a1 == a2&&a2 == 1) {
				// first check the rank of the pair
				card_rank hand1_pair_rank = GetThePair(hand1);
				card_rank hand2_pair_rank = GetThePair(another_hand);
				if (hand1_pair_rank > hand2_pair_rank) {
					return true;
				}
				else if (hand1_pair_rank < hand2_pair_rank) {
					return false;
				}
				else if (hand1_pair_rank == hand2_pair_rank) {
					// then check the highest unpaired card
					for (size_t i = 4; i >= 0; i--) {
						if (!((card)hand1.hand_[i] == (card)another_hand.hand_[i])) {
							if ((card)another_hand.hand_[i] <hand1.hand_[i]) {
								return true;
							}
							else {
								return false;
							}
						}
					}

				}

			}
			// revised
			else if (a1 == a2&&a2 == 0) {

				if (((card)another_hand.hand_[4]) < e_) {
					return true;
				}

				else if (e_ < another_hand.hand_[4]) {
					return false;
				}
				else if (e_ == another_hand.hand_[4]) {
					if ((card)another_hand.hand_[3] < d_) {
						return true;
					}

					else if (d_ < another_hand.hand_[3]) {
						return false;
					}
					else if (d_ == another_hand.hand_[3]) {
						if ((card)another_hand.hand_[2] < c_) {
							return true;
						}
						else if (c_ < another_hand.hand_[2]) {
							return false;
						}
						else {
							return false;
						}
					}
				}
				return false;
			}


		}
	}
	else {
		size_t size = hand1.hand_.size();
		for (size_t i = 0; i < size; ++i) {
			card a = hand1.hand_[i];
			card b = another_hand.hand_[i];
			if (a == b) {
				continue;
			}
			else {
				return b < a;
			}
		}
		return false;
	}
	return false;
};

card_rank hand::GetThePair(const hand &h) {
	card_rank a;
	if (h.hand_[0].rank == h.hand_[1].rank) {
		a = h.hand_[0].rank;
	}
	else if (h.hand_[1].rank == h.hand_[2].rank) {
		a = h.hand_[1].rank;
	}
	else if (h.hand_[2].rank == h.hand_[3].rank) {
		a = h.hand_[2].rank;
	}
	else if (h.hand_[3].rank == h.hand_[4].rank) {
		a = h.hand_[3].rank;
	}
	return a;

}
vector<int> hand::GetTwoPair(const hand &h) {
	// the first is the higher pair ,the second is the lower pair 
	vector<int> out;
	if (h.hand_[0].rank != h.hand_[1].rank) {
		// hand is : a bb cc

		out.push_back(4);
		out.push_back(2);
		out.push_back(0);


	}
	if (h.hand_[2].rank != h.hand_[1].rank &&h.hand_[2].rank != h.hand_[3].rank) {
		// hand is : aa b cc
		out.push_back(4);
		out.push_back(1);
		out.push_back(2);
	}
	if (h.hand_[4].rank != h.hand_[3].rank) {
		// hand is : aa bb c
		out.push_back(2);
		out.push_back(0);
		out.push_back(4);
	}
	return out;
}
