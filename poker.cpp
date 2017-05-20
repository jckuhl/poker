#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

//Card Suits (hand.card.suit)
#define HEARTS 1 
#define SPADES 2
#define DMONDS 3
#define CLUBS 4

//Card Values (hand.card.val)
#define ACE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define TEN 10
#define JACK 11
#define QUEEN 12
#define KING 13

//Scoring Hands
//these go into aScore[] in this order.
#define NOVAL 0			//0 worthless hand, check only who has highest card
#define ACEHIGH 50		//1
#define PAIR 100		//2
#define TPAIR 150		//3
#define THRKIND 200		//4
#define FOURKIND 250	//5
#define FLUSH 300		//6
#define FULLHOUSE 350	//7
#define STRFLUSH 400	//8
#define RYLFLUSH 450	//9

//A class Hand containing the class Card
class hand {
	public:
		int score;			//given a value from NOVAL to RYLFLUSH to determine winner
		// void dealCards();
		class card {
			public:
				int suit; 	//1-4, 1 Heart, 2 Spade, 3 Diamond, 4 Club
				int val;	//1-13
		} card1, card2, card3, card4, card5;
} hand1, hand2;

//dislays the hand on screen
void displayHand(const hand& myHand) {
	std::cout << "[" << myHand.card1.suit << "," << myHand.card1.val << "] ";
	std::cout << "[" << myHand.card2.suit << "," << myHand.card2.val << "] ";
	std::cout << "[" << myHand.card3.suit << "," << myHand.card3.val << "] ";
	std::cout << "[" << myHand.card4.suit << "," << myHand.card4.val << "] ";
	std::cout << "[" << myHand.card5.suit << "," << myHand.card5.val << "]\n";
}

//determines the value and score of the hand
int valueHand(const hand& myHand) {
	int value = NOVAL;										//int value intialized with no value.  ironic.
	int matches = 0;
	int kinds[8] = {};		//even indices are value, odd for suit (%2 == 0 and %2 != 0)
	int n = 0;
	int cards[5];
	int aScore[10];
	int aScoreIndex;
	
	//check for pairs, triples, and four of a kind
	//check if Card1 matches Card2
	if(myHand.card1.val == myHand.card2.val) { 
		// std::cout << "First if branch in valueHand\n";
		kinds[n] = myHand.card1.val;
		n++;
		kinds[n] = myHand.card1.suit;
		n++;
		kinds[n] = myHand.card2.val;
		n++;
		kinds[n] = myHand.card2.suit;
	}

	//check if Card1 matches Card3
	if(myHand.card1.val == myHand.card3.val) { 
		// std::cout << "Second if branch in valueHand\n";
		kinds[n] = myHand.card1.val;
		n++;
		kinds[n] = myHand.card1.suit;
		n++;
		kinds[n] = myHand.card3.val;
		n++;
		kinds[n] = myHand.card3.suit;
	}

	//check if Card1 matches Card4
	if(myHand.card1.val == myHand.card4.val) { 
		// std::cout << "Third if branch in valueHand\n";
		kinds[n] = myHand.card1.val;
		n++;
		kinds[n] = myHand.card1.suit;
		n++;
		kinds[n] = myHand.card4.val;
		n++;
		kinds[n] = myHand.card4.suit;
	}

	//check if Card1 matches Card5
	if(myHand.card1.val == myHand.card5.val) { 
		// std::cout << "Fourth if branch in valueHand\n";
		kinds[n] = myHand.card1.val;
		n++;
		kinds[n] = myHand.card1.suit;
		n++;
		kinds[n] = myHand.card5.val;
		n++;
		kinds[n] = myHand.card5.suit;
	}

	//check if Card2 matches Card3
	if(myHand.card2.val == myHand.card3.val) { 
		// std::cout << "Fifth if branch in valueHand\n";
		kinds[n] = myHand.card2.val;
		n++;
		kinds[n] = myHand.card2.suit;
		n++;
		kinds[n] = myHand.card3.val;
		n++;
		kinds[n] = myHand.card3.suit;
	}

	//check if Card2 matches Card4
	if(myHand.card2.val == myHand.card4.val) { 
		// std::cout << "Sixth if branch in valueHand\n";
		kinds[n] = myHand.card2.val;
		n++;
		kinds[n] = myHand.card2.suit;
		n++;
		kinds[n] = myHand.card4.val;
		n++;
		kinds[n] = myHand.card4.suit;
	}

	//check if Card2 matches Card5
	if(myHand.card2.val == myHand.card5.val) { 
		// std::cout << "Seventh if branch in valueHand\n";
		kinds[n] = myHand.card2.val;
		n++;
		kinds[n] = myHand.card2.suit;
		n++;
		kinds[n] = myHand.card5.val;
		n++;
		kinds[n] = myHand.card5.suit;
	}

	//check if Card3 matches Card4
	if(myHand.card3.val == myHand.card4.val) { 
		// std::cout << "Eigth if branch in valueHand\n";
		kinds[n] = myHand.card3.val;
		n++;
		kinds[n] = myHand.card3.suit;
		n++;
		kinds[n] = myHand.card4.val;
		n++;
		kinds[n] = myHand.card4.suit;
	}

	//check if Card3 matches Card5
	if(myHand.card3.val == myHand.card5.val) { 
		// std::cout << "Ninth if branch in valueHand\n";
		kinds[n] = myHand.card3.val;
		n++;
		kinds[n] = myHand.card3.suit;
		n++;
		kinds[n] = myHand.card5.val;
		n++;
		kinds[n] = myHand.card5.suit;
	}

	//check if Card4 matches Card5
	if(myHand.card4.val == myHand.card5.val) { 
		// std::cout << "Tenth if branch in valueHand\n";
		kinds[n] = myHand.card4.val;
		n++;
		kinds[n] = myHand.card4.suit;
		n++;
		kinds[n] = myHand.card5.val;
		n++;
		kinds[n] = myHand.card5.suit;
	}

	//count the cards placed in the array
	for(int i = 0; i < 8; i++) {
		if((i % 2 == 0) && (kinds[i] != 0)) {
			matches += 1;
			std::cout << "Matches: " << matches << "\n";
		}
	}

	//if there are any matches in the array
	if(matches > 0) {
		//find out if it's a pair, two pair or whatever
		std::cout << "There are matching cards\n";
	} else {
		std::cout << "There are no matching cards\n";
	}
	cards[0] = myHand.card1.val;
	cards[1] = myHand.card2.val;
	cards[2] = myHand.card3.val;
	cards[3] = myHand.card4.val;
	cards[4] = myHand.card5.val;
	//sortAscending(myHand.cards, 5);
	if((cards[0] - cards[1] == 1) &&
		(cards[1] - cards[2] == 1) &&
		(cards[3] - cards[4] == 1)) {
		//Its a straight!
			std::cout << "It's a straight!";
			//determine what the highest card is, if highest = 13 (ace) RYLFLUSH
	} else {
		value += 0;
		//it's not a straight
	}

	//check for flushes.
	if((myHand.card1.suit == myHand.card2.suit) &&
		(myHand.card1.suit == myHand.card3.suit) &&
		(myHand.card1.suit == myHand.card4.suit) &&
		(myHand.card1.suit == myHand.card5.suit)) {
			aScore[] = FLUSH
	}
	//this if *MUST* be at the bottom
	if(value == NOVAL) {
		//determine the highest card
		//value = NOVAL + myHand.card1.val + myHand.card2.val + . . . ?
		return value;
	}
	for(aScoreIndex = 0; aScoreIndex < 10; aScoreIndex++) {
		value += aScore[aScoreIndex];
	}
	return value;
}

//gives a random number, multiplied by x, in the range 0-range
int randomNum(int x, int range) {
	return std::abs(x * rand() % range) + 1;
}

//Starts the program and the game
int main(void) {
	srand((int)time(0));
	char response[0];
	bool isPlaying = true;
	int money = 200;
	while((isPlaying) && (money > 0)) {
		hand1.card1.suit = randomNum(1,4);
		hand1.card1.val = randomNum(2,13);
		hand1.card2.suit = randomNum(3,4);
		hand1.card2.val = randomNum(4,13);
		hand1.card3.suit = randomNum(5,4);
		hand1.card3.val = randomNum(6,13);
		hand1.card4.suit = randomNum(7,4);
		hand1.card4.val = randomNum(8,13);
		hand1.card5.suit = randomNum(9,4);
		hand1.card5.val = randomNum(10,4);
		// dealCards();
		std::cout << "Here is your hand:\n";
		displayHand(hand1); 
		hand1.score = valueHand(hand1);
		std::cout << hand1.score << "\n";		//this ouptput is for testing purposes only
		std::cout << "You have $" << money << "\n";
		std::cout << "[R]aise ($25) or [F]old\n";
		std::cin >> response;
		if((strncmp(response, "R", 1) == 0) || (strncmp(response, "r", 1) == 0)) {
			//raise
			money -= 25;
			std::cout << "You have $" << money << "\n";
		}
		else {
			//computer declares itself the victor, reveals cards, and offers a new game.
			std::cout << "This is what I had!\n";
			displayHand(hand2);
			isPlaying = false;
		}
	}
	std::cout << "Well that was fun.  See you next time.\n";
	return 0;
}